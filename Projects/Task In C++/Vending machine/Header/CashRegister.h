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