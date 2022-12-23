/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
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
