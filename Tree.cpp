#include <iostream>
#include <cstdio>
#include "Tree.hpp"

using namespace std;
using namespace ariel;



Tree::Tree()
{
    Troot = NULL;
    Tsize = 0;
}
//destructor
Tree::~Tree() { 
  deleteTree(Troot);
}

//deleting all the nodes;
void Tree::deleteTree(node* Troot){

  if(Troot == NULL)return;
  deleteTree(Troot->right);
  deleteTree(Troot->left);
  delete Troot;
  Troot=NULL;
  Tsize=0;
}

//inserts i to the tree in thr right place, returns true if succeeded
void Tree::insert(int i){

//if i is already in the tree, throw an exception
if(contains(i)==true){
	throw std::invalid_argument( "number already exist in the tree!" );
	}
else{	
	
	Tsize++;	
	//if the tree is not empty, need another function to check where to put i	
	if(Troot != NULL){

		insert2(i, Troot);
        }
	//if the tree is empty
	else{
		Troot = new node;
		Troot->data = i;
		Troot->left = NULL;
		Troot->right = NULL;
		Troot->parent = Troot;

    	}
}
}

//insert for the case the tree is not empty
void Tree::insert2(int i, node *Troot){
	//searching int the left side
	if(i < Troot->data){
		//if we already have a left child, need to search again
		if(Troot->left != NULL){
			insert2(i, Troot->left);

		}else{//no left child, just put it in
			Troot->left = new node;
			Troot->left->data = i;
			Troot->left->left = NULL;
			Troot->left->right = NULL;
                        Troot->left->parent = Troot;

		}
	//same with the right side
	}else if(i > Troot->data){
		if(Troot->right != NULL){
			insert2(i, Troot->right);
		}else{
			Troot->right = new node;
			Troot->right->data = i;
			Troot->right->right = NULL;
			Troot->right->left = NULL;
			Troot->right->parent = Troot;

		}
	}
	
}
//binary search to know if an i is in the tree or not
bool Tree::search(int i, node* Troot){

	if(Troot != NULL){
		if(i == Troot->data){
			return true;
		}
		else if(i < Troot->data){
			return search(i, Troot->left);
		}else{
			return search(i, Troot->right);
		}
	}else{
		return false;
	}
}
//bynarty search to return the node if it's in the tree
node * Tree::search2(int i, node *Troot){

if (Troot==NULL) return NULL;
else if (i<Troot->data) return search2(i, Troot->left);
else if (i>Troot->data) return search2(i, Troot->right);
else return Troot;

}

//returns the amount of numbers in the tree
int Tree::size()
{
  return Tsize;
}
	//returns true if i is in the tree
bool Tree::contains(int i){
	
	if (search(i, Troot) == true) return true;
        return false;
}
	//returns the number that's in the root of the tree
int Tree::root()
{
	if(Troot==NULL)  throw std::invalid_argument( "NULL POINTER EXCEPTION" );
	return Troot->data;
}

	//returns the value of the left child
int Tree::left(int i)
{
	if(Troot==NULL){
	   throw std::invalid_argument( "NULL POINTER EXCEPTION" ); 
	}
	node* temp = Troot;
	while(temp!=NULL){//searching all over the tree to find it
		if (temp->data>i) temp=temp->left;
		else if(temp->data<i) temp=temp->right;
		else {
			if (temp->left!=NULL) return temp->left->data;
			else throw std::invalid_argument( "NULL POINTER EXCEPTION" ); 
		}
	}
	throw std::exception();
}

	//returns the valute of the right child
int Tree::right(int i)
{

	if(Troot==NULL){
	   throw std::invalid_argument( "NULL POINTER EXCEPTION" ); 
	}
	node* temp = Troot;
	while(temp!=NULL){//searching all over the tree to find it
		if (temp->data>i) temp=temp->left;
		else if(temp->data<i) temp=temp->right;
		else {
			if (temp->right!=NULL) return temp->right->data;
			else throw std::invalid_argument( "NULL POINTER EXCEPTION" ); 
		}
	}
	throw std::exception();
} 


int Tree::parent (int i)
{

node *temp = search2(i, Troot);//searching the right i
if(temp == NULL || Troot->data==i)//checking nothing's not null
throw std::invalid_argument( "NULL POINTER EXCEPTION" );
return temp->parent->data;

} 

 	//prints the structure of the tree in order
void Tree::print()
{
	print2(Troot);
}
void Tree::print2(node *Troot){//helper to print function
	if(Troot != NULL){
		print2(Troot->left);
		cout << Troot->data << ",";
		print2(Troot->right);
	}
}

node* Tree::FindMax(node* Troot)//helper to the remove, in order to find out hoe to change the node's location
{
    if(Troot==NULL)
    return NULL;

    while(Troot->right != NULL)
    {
        Troot = Troot->right;
    }
    return Troot;
}

node* Tree::DeleteNodeInBST(node* Troot,int i)//delete the node with i
{
	//seraching for thr right node to delete
    if(Troot==NULL) return NULL;
    if(i<Troot->data && Troot->left!=NULL) 
        Troot->left = DeleteNodeInBST(Troot->left, i);
    else if (i > Troot->data && Troot->right!=NULL)
        Troot->right = DeleteNodeInBST(Troot->right, i);
//found it
    else
    {
        //No child
        if(Troot->right == NULL && Troot->left == NULL)
        {
            delete(Troot);
            Troot = NULL;   
        }
        //One child 
        else if(Troot->right == NULL)
        {
            node* temp = Troot->left;
	    if(temp != NULL) temp->parent = Troot->parent;
            delete(Troot);
            Troot = NULL; 
	    return(temp);
        }
        else if(Troot->left == NULL)
        {
            node* temp = Troot->right;
	    if(temp != NULL) temp->parent = Troot->parent;
            delete(Troot);
            Troot = NULL; 
	    return(temp);
        }
        //two child - need to check what node will replace the deleted one
        else
        {
            node* temp = FindMax(Troot->left);
            Troot->data = temp->data;
            Troot->left = DeleteNodeInBST(Troot->left, temp->data);
        }
    }
    return Troot;
}
//removes i from the tree, will return true when succeeded.
void Tree::remove(int i)
{

	node *temp1 = search2(i, Troot);//searching the right node
	if (temp1 == NULL ||contains(i) == false) throw std::invalid_argument ("This node doesnt exist in the tree");
	node *temp2 = DeleteNodeInBST(Troot, i);
	if (temp1 == Troot) Troot = temp2;//updates the root
	if (temp2 == NULL) Troot = NULL;//if it is the root
	Tsize--;

}
