/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/

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