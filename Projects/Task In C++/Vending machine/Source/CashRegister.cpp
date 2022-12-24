#include "CashRegister.h"
#include <iostream>
using namespace std;

CashRegister::CashRegister()
//override default constructor and init the cash to 0
{
	cashOnHands = 0;
}
CashRegister::CashRegister(int start_cash)
//constructor that init the cash by value
{
	cashOnHands = start_cash;
}

CashRegister::~CashRegister()
//override default distractor
{
	
}

int CashRegister::getCurrentBalance() const
{
	return cashOnHands;									//return the balance of the cash register
}
void CashRegister::acceptAmount(int deposite)
{
	cashOnHands = cashOnHands + deposite;				//deposite the input money in the cash register
}