#include <iostream>


namespace ariel{

	struct Node{
		int value;
		Node *left;
		Node *right;
		Node *parent;
	};
	
	using std::cout, std::endl;
	class Tree{
		private:
			Node *head;
			int length;
		
		public:			
			Tree();
			~Tree();
			void insert(int i);			
			void remove(int i);
			int size();
			bool contains(int i);
			int root();
			int parent(int i);
			int left(int i);		
			int right(int i);			
			void print();
			
		private:
			//delete all the nodes from memory.
			void freeTree(Node* node);
			//recursive insert.
			void insert(int i,Node *node);
			//make new node.
			Node* newNode(int value,Node* parent);
			//recursive remove
			Node* deleteNode(Node* root,int key);
			//Given a non-empty binary search tree, return the node with minimum key value found in that tree.
			Node* minValueNode(Node* node);
			//finde nood with value. use for contains,parent,left and right function.
			Node* find(int i,Node *node);
			//print 2-Dimensions tree tank to geeksforgeeks website.
			void print(Node *root, int space);
	
	};

}