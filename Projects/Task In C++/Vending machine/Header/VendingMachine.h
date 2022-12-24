
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