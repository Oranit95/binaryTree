namespace ariel {
class Tree {
	struct node{

		int data;
		struct node *left;
		struct node *right;
		struct node *parent;
	};

	

                private:
		int Tsize;
		node *Troot;

		public:
                   
		Tree();
		void insert(int i);
		void insert2(int i, node *Troot);
		bool search(int i, node *Troot);
		node * search2(int i, node *Troot);
		void remove(int i);
		int size();
		bool contains(int i);
		int root();
		int left(int i);
		int right(int i);
		int parent (int i);	
		void print();
		void print2(node *Troot);
		node* FindMax(node* Troot);	
		node* DeleteNodeInBST(node* Troot,int i);
};

}
