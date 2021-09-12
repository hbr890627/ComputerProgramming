#include <iostream>
#include "Node.h"
using namespace std;

class List{
	public:
		List();
		~List();
		void insertAtFront(const Node &);
		void insertAtBack(const Node &);
		bool removeFromFront(Node &);
		bool removeFromBack(Node &);
		bool isEmpty() const;
		void print() const;
	private:
		Node *fptr;
		Node *lptr;
		
		Node *getNewNode(const Node &);
};

List::List()
:fptr(0),
lptr(0)
{

}

void List::insertAtFront(const Node &a){
	Node *newPtr=new Node(a);
	if(isEmpty())
		fptr=lptr=newPtr;
	else{
		newPtr->nextPtr=fptr;
		fptr=newPtr;
	}
}

void List::insertAtBack(const Node &b){
	Node *newPtr=new Node(b);
	if(isEmpty())
		fptr=lptr=newPtr;
	else{
		lptr->nextPtr=newPtr;
		lptr=newPtr;
	}
}

bool List::removeFromFront(Node &c){
	if(isEmpty())
		return false;
	else{
		Node *tempPtr=new Node(c);
		tempPtr=fptr;
		if(fptr==lptr)
			fptr=lptr=0;
		else
			fptr=fptr->nextPtr;
		c=tempPtr->data;
		delete tempPtr;
		return true;
	}
}

bool List::removeFromBack(Node &d){
	if(isEmpty())
		return false;
	else{
		Node *tempPtr=new Node(d);
		tempPtr=lptr;
		if(fptr==lptr)
			fptr=lptr=0;
		else{
			Node *currentPtr=fptr;

			while(currentPtr->nextPtr!=lptr){
				currentPtr=currentPtr->nextPtr;
			}
			lptr=currentPtr;
			currentPtr->nextPtr=0;
		}
		d=tempPtr->data;
		delete tempPtr;
		return true;
	}
}

bool List::isEmpty()const{
	return fptr==0;
}

void List::print()const{
	if(isEmpty()){
		cout<<"empty";
		return;
	}

	Node *currentPtr=fptr;

	while(currentPtr!=0){
		cout<<currentPtr->data;
		currentPtr=currentPtr->nextPtr;
	}
}
