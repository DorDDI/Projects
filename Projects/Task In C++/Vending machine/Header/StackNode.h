
class StackNode
{
	int data;
	StackNode* next;

public:
	StackNode();
	StackNode(int);
	~StackNode();
	int getData() const;
	StackNode* getNext() const;
	void setData(int);
	void setNext(StackNode*);
};
