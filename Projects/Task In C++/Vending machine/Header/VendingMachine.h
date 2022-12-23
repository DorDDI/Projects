/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/

#include "CashRegister.h"
#include "DispenserType.h"

class VendingMachine
{
	DispenserType orange;
	DispenserType carrot;
	DispenserType pomegranate;
	CashRegister counter;

public:
	VendingMachine();
	~VendingMachine();
	void sellProduct(char);
};

void MakeDeal(DispenserType&, CashRegister&);		//function that make the purchase