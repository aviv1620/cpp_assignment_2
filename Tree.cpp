

#include "Tree.hpp"
#include <iostream>



using ariel::Tree;
using ariel::Node;
using std::string;
using std::to_string;


Tree::Tree()
	: head(NULL), length(0){
		
	}
	
	
Tree::~Tree(){//FIXME
	cout << "need delete all the nodes. not build yet." << endl;
	}
	
void Tree::freeTree(Node* node){
}
	
Node* Tree::newNode(int value,Node* parent){
	Node *node = new Node;
	node->value = value;
	node->left = NULL;
	node->right = NULL;	
	node->parent = parent;
	return node;
}

void Tree::insert(int i) {
	if(this->head == NULL){
		this->head = newNode(i,NULL);		
	}else{
			insert(i,this->head);
	}
	this->length++;
}

void Tree::insert(int i,Node *node) {
	 if (i < node->value){//left
		if(node->left == NULL){
			node->left = newNode(i,node);
		}else{
			insert(i,node->left);
		}
		
	 }else if(i > node->value){//right
		if(node->right == NULL){
			node->right = newNode(i,node);
		}else{
			insert(i,node->right);
		}
	 }else{
		 throw string( to_string(i) + "is exist" );
	 }
}


// Given a binary search tree and a key, this function deletes the key and returns the new root */
// i use geeksforgeeks guide.
Node* Tree::deleteNode(Node* root,int key){
	// base case 
    if (root == NULL){
		throw string( to_string(key) + "is bot exist" );
	}
	
	// If the key to be deleted is smaller than the root's key, then it lies in left subtree.
	 if (key < root->value) 
        root->left = deleteNode(root->left, key); 
	
	// If the key to be deleted is greater than the root's key, then it lies in right subtree.
	else if (key > root->value) 
        root->right = deleteNode(root->right, key); 
	
	// if key is same as root's key, then This is the node to be deleted.
	else{
		// node with only one child or no child 
		if (root->left == NULL) { 
            Node* temp = root->right; 
            delete root; 
			length--;
            return temp; 
        }else if (root->right == NULL){ 
            Node* temp = root->left; 
            delete root; 
			length--;
            return temp; 
        }

		
		
		// node with two children: Get the inorder successor (smallest in the right subtree) 		
		Node* temp = minValueNode(root->left); 
		
		// Copy the inorder successor's content to this nod
		root->value = temp->value; 
		 
		// Delete the inorder successor 
		root->left = deleteNode(root->left, temp->value); 
	}
	
	return root;
}

//Given a non-empty binary search tree, return the node with minimum 
//key value found in that tree. Note that the entire tree does not 
//need to be searched.
Node* Tree::minValueNode(Node* node){
	Node* current = node; 
	
	// loop down to find the rightmost leaf 
	while (current->right != NULL) 
        current = current->right; 
	
	return current; 
}


void Tree::remove(int i) {
	this->head = deleteNode(this->head,i);
}

int Tree::size(){
	return length;
}

bool Tree::contains(int i){
	Node* a = find(i,this->head);
	return(a != NULL);
}


Node* Tree::find(int i,Node *node){
	if(node == NULL)
		return NULL;
	else if(node->value == i)
		return node;
	else if(i < node->value)
		return find(i,node->left);
	else  //i > node->value)
		return find(i,node->right);
}

int Tree::root(){
	if(this->head == NULL)
		throw string( "tree is empty" );
	else
		return this->head->value;
}

int Tree::parent(int i){
	Node* node = find(i,this->head);
	if(node == NULL){
		throw string( to_string(i) + "not exist" );
		return -1;
	}else if( node->parent == NULL){
		throw string( to_string(i) + "not have parent" );
		return -1;
	}else
		return node->parent->value;
}

int Tree::left(int i){
	Node* node = find(i,this->head);
	if(node == NULL){
		throw string( to_string(i) + "not exist" );
		return -1;
	}else if( node->left == NULL){
		throw string( to_string(i) + "not have left child" );
		return -1;
	}else
		return node->left->value;
}

int Tree::right(int i){
	Node* node = find(i,this->head);
	if(node == NULL){
		throw string( to_string(i) + "not exist" );
		return -1;
	}else if( node->right == NULL){
		throw string( to_string(i) + "not have right child" );
		return -1;
	}else
		return node->right->value;
}

void Tree::print(){
	print(this->head,0);	
}

void Tree::print(Node *root, int space) {
	
	// Base case  
    if (root == NULL)  
        return;  
	
	
	// Increase distance between levels  
    space += 10;

	// Process right child first  
    print(root->right, space);
	
	
	// Print current node after space  
    // count  
	cout << endl;  
    for (int i = 10; i < space; i++)  
        cout << " ";  
    cout << root->value <<"\n"; 
	
	// Process left child  
    print(root->left, space); 
}
