#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

Node *insertNode(Node **proot, int x){
	if(*proot==NULL){
		Node *newNode = (Node*)malloc(sizeof(Node));
        	newNode->key = x;
        	newNode->left = newNode->right = NULL;
		*proot=newNode;
		return NULL;
	}
	Node *root=*proot;
	if(root->key==x){
		return NULL;
	}
	if(root->key>x){
		return insertNode(&(root->left), x);
	}
	else{
		return insertNode(&(root->right), x);
	}
}

Node *findNode(Node *root, int x){
	if(root==NULL){
		return NULL;
	}
	if(root->key==x){
		return root;
	}
	if(root->key>x){
		return findNode(root->left, x);
	}
	return findNode(root->right, x);
}

Node *findMin(Node *parent, Node *root, int flag){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL){
		if(root->right==NULL){
			if(flag==0)
				parent->left=NULL;
			else
				parent->right=NULL;
		}
		else
			parent->left=root->right;
		return root;
	}
	return findMin(root, root->left,0);
}

Node *helpDelete(Node *parent, Node *root, int x, int flag)
{
	Node *temp;
	if(root==NULL){
		return NULL;
	}
	if(root->key>x){
		return helpDelete(root, root->left, x, 0);
	}
	else if(root->key<x){
		return helpDelete(root, root->right,x, 1);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			if(flag==0)
				parent->left = NULL;
			else
				parent->right = NULL;
			return root;
		}
		else if(root->left==NULL){
			if(flag==0)
				parent->left = root->right;
			else
				parent->right = root->right;
			return root;
		}
		else if(root->right==NULL){
			if(flag==0)
				parent->left = root->left;
			else
				parent->right = root->left;
			return root;
		}
		else{
			temp = findMin(root, root->right,1);
			root->key = temp->key;
			return temp;
		}
	}
}

Node *deleteNode(Node **proot, int x){
	if(*proot==NULL){
		return NULL;
	}
	if((*proot)->key>x){
		return helpDelete(*proot, (*proot)->left, x, 0);
	}
	else if((*proot)->key<x){
		return  helpDelete(*proot, (*proot)->right, x, 1);
	}
	else{
		return  helpDelete( *proot, *proot, x, 1);
	}
}

void destroyTree(Node *root){
	if(root==NULL){
		return;
	}
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
}
