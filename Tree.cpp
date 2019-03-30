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

if(contains(i)==true){
	throw std::invalid_argument( "number already exist in the tree!" );
	}
else{		
	Tsize++;		

	if(Troot != NULL){

		insert2(i, Troot);
        }
	
	else{
		Troot = new node;
		Troot->data = i;
		Troot->left = NULL;
		Troot->right = NULL;
		Troot->parent = Troot;

    	}
}
}

void Tree::insert2(int i, node *Troot){

	if(i < Troot->data){
		if(Troot->left != NULL){
			insert2(i, Troot->left);

		}else{
			Troot->left = new node;
			Troot->left->data = i;
			Troot->left->left = NULL;
			Troot->left->right = NULL;
                        Troot->left->parent = Troot;

		}
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
	while(temp!=NULL){
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
	while(temp!=NULL){
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

node *temp = search2(i, Troot);
if(temp == NULL || Troot->data==i)
throw std::invalid_argument( "NULL POINTER EXCEPTION" );
return temp->parent->data;

} 

 	//prints the structure of the tree
void Tree::print()
{
print2(Troot);
}
void Tree::print2(node *Troot){
	if(Troot != NULL){
		print2(Troot->left);
		cout << Troot->data << ",";
		print2(Troot->right);
	}
}

node* Tree::FindMax(node* Troot)
{
    if(Troot==NULL)
    return NULL;

    while(Troot->right != NULL)
    {
        Troot = Troot->right;
    }
    return Troot;
}

node* Tree::DeleteNodeInBST(node* Troot,int i)
{

    if(Troot==NULL) return NULL;
    if(i<Troot->data && Troot->left!=NULL) 
        Troot->left = DeleteNodeInBST(Troot->left, i);
    else if (i > Troot->data && Troot->right!=NULL)
        Troot->right = DeleteNodeInBST(Troot->right, i);
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
        //two child
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


node *temp1 = search2(i, Troot);
if (temp1 == NULL ||contains(i) == false) throw std::invalid_argument ("This node doesnt exist in the tree");
node *temp2 = DeleteNodeInBST(Troot, i);
if (temp1 == Troot) Troot = temp2;
if (temp2 == NULL) Troot = NULL;



Tsize--;

}
