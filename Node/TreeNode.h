

class TreeNode{
	friend class Tree;
	public:
		TreeNode(int &d)
		:rptr(0),
		lptr(0),
		data(d)
		{	}
		
	private:
		TreeNode *rptr;
		TreeNode *lptr;
		int data;
};
