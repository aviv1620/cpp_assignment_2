

#include "Tree.hpp"
#include <iostream>



using ariel::Tree;
using ariel::Node;


Tree::Tree()
	: head(NULL), length(0){
		
	}
	
	
Tree::~Tree(){
	cout << "need delete all the nodes. not build yet." << endl;
	}
	
Node* Tree::newNode(int value){
	Node *node = new Node;
	node->value = value;
	node->left = NULL;
	node->right = NULL;	
	return node;
}

void Tree::insert(int i) {
	if(this->head == NULL){
		this->head = newNode(i);		
	}else{
			insert(i,this->head);
	}
	this->length++;
}

void Tree::insert(int i,Node *node) {
	 if (i < node->value){//left
		if(node->left == NULL){
			node->left = newNode(i);
		}else{
			insert(i,node->left);
		}
		
	 }else if(i > node->value){//right
		if(node->right == NULL){
			node->right = newNode(i);
		}else{
			insert(i,node->right);
		}
	 }else{
		 //THROWS not buils yet.
	 }
}

void Tree::remove(int i) {
	//cout << "remove" << endl;
}

int Tree::size(){
	return length;
}

bool Tree::contains(int i){
	return contains(i,this->head);
}

bool Tree::contains(int i,Node *node){
	if(node == NULL)
		return false;
	else if(node->value == i)
		return true;
	else if(i < node->value)
		return node->left;
	else  //i > node->value)
		return node->right;
		
}

Node* Tree::find(int i,Node *node){
	return NULL;
}

int Tree::root(){
	if(this->head == NULL)
		return 0;
	else
		return this->head->value;
}

int Tree::parent(int i){
	return 8;
}

int Tree::left(int i){
	return 8;
}

int Tree::right(int i){
	return 8;
}

void Tree::print(){
	cout << "print tree" << endl;
}