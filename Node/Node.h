

class Node{
	friend class List;
	public:
		Node(int);
		void setData(int);
		int getData() const;
		void setNextPtr(Node *);
		Node getNextPtr() const;
	private:
		int data;
		Node *nextPtr;
};

Node::Node(int value)
:data(value),
nextPtr(0)
{
	
}


