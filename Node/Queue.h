#include "List.h"

class Queue:public List{
	public:
		void enqueue(Node &data){
			insertAtBack(data);
		}
		bool dequeue(Node &data){
			return removeFromFront(data);
		}
		bool isQueueEmpty()const{
			return isEmpty();
		}
		void printQueue()const{
			print();
		}
};
