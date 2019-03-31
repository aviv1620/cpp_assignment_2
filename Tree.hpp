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
			void insert(int i,Node *node);
			Node* newNode(int value,Node* parent);
			Node* find(int i,Node *node);
			void print(Node *root, int space);
	
	};

}