/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/

class CashRegister
{
	int cashOnHands;

public:
	CashRegister();
	CashRegister(int);
	int getCurrentBalance() const;
	void acceptAmount(int);
	~CashRegister();
};