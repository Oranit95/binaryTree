#include <iostream>
#include <cstdio>
using namespace std;

class Tree {

struct Node {
  int data;
  struct Node *right, *left, *parent;	
};

private:
int size;
Node *rootNode;
public:


//inserts i to the tree in thr right place, returns true if succeeded
bool insert(int i)
{
	return false;
} 
//removes i from the tree, will return true when succeeded.
bool remove(int i)
{
	return false;
}
//returns the amount of numbers in the tree
int getsize()
{
  return size;
}
	//returns true if i is in the tree
bool contains(int i){
	return true;
	}
	//returns the number that's in the root of the tree
	int root()
	{
	return 0;
	}
	//returns the value of the left child
	int left(int i)
	{
	return 0;
	} 
	//returns the valute of the right child
	int right(int i)
	{

	return 0;
	}

	int parent (int i)
	{
	 return 0;
	}
 	//prints the structure of the tree
	void print()
	{

	}

};

