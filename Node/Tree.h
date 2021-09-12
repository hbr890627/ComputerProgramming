#include "TreeNode.h"
#include <iostream>
using namespace std;


class Tree{
	public:
		Tree();
		void insertnode(int &);
		void inOrder();
		void preOrder();
		void postOrder();
		void binTreeSearch(int);
	private:
		TreeNode *rootptr;

		void insertnodeHelper(TreeNode *, int &);
		void inOrderHelper(TreeNode *);
		void preOrderHelper(TreeNode *);
		void postOrderHelper(TreeNode *);
		void binTreeSearchHelper(TreeNode *,int);
};

Tree::Tree()
:rootptr(0)
{

}
void Tree::insertnode(int &a){
	insertnodeHelper(rootptr, a);
}


void Tree::insertnodeHelper(TreeNode *rootptr, int &a){
	if(rootptr==0)
		rootptr=new TreeNode(a);
	else{
		if(a<rootptr->data)
			insertnodeHelper(rootptr->lptr, a);
		else{
			if(a>rootptr->data)
				insertnodeHelper(rootptr->rptr,a);
			else
				cout<<a<<"dup"<<endl;
		}
	}
}

void Tree::preOrder(){
	preOrderHelper(rootptr);
}

void Tree::preOrderHelper(TreeNode *ptr){
	if(ptr!=0){
		cout<<ptr->data<<' ';
		preOrderHelper(ptr->lptr);
		preOrderHelper(ptr->rptr);
	}
}

void Tree::inOrder(){
	inOrderHelper(rootptr);
}

void Tree::inOrderHelper(TreeNode *ptr){
	if(ptr!=0){
		inOrderHelper(ptr->lptr);
		cout<<ptr->data<<' ';
		inOrderHelper(ptr->rptr);
	}
}

void Tree::postOrder(){
	postOrderHelper(rootptr);
} 

void Tree::postOrderHelper(TreeNode *ptr){
	if(ptr!=0){
		postOrderHelper(ptr->lptr);
		postOrderHelper(ptr->rptr);
		cout<<ptr->data<<' ';
	}
}

void Tree::binTreeSearch(int a){
	binTreeSearchHelper(rootptr,a);
}

void Tree::binTreeSearchHelper(TreeNode *rootptr, int a){
	if(rootptr==0){
		cout<<"is empty";
		return;
	}else{
		if(a<rootptr->data)
			binTreeSearchHelper(rootptr->lptr, a);
		else if(a>rootptr->data)
			binTreeSearchHelper(rootptr->rptr, a);
		else if(a==rootptr->data)
			cout<<"found";
		else
			cout<<"not found";	
	}
}
