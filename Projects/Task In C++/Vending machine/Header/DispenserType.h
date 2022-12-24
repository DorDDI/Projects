
class DispenserType
{
	int numberOfItems;
	int cost;

public:
	DispenserType();
	DispenserType(int, int);
	int getNoOfItems() const;
	int getCost() const;
	void makeSale();
	~DispenserType();
};