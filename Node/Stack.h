#include "List.h"

class Stack:public List{
	public:
		void push(Node &data){
			insertAtFront(data);
		}
		bool pop(Node &data){
			return removeFromFront(data);
		}
		bool isStackEmpty()const{
			return isEmpty();
		}
		void printStack()const{
			print();
		}
};
