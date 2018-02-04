#include <iostream>

using namespace std;
//interface
class Strategy {
public:
	virtual float checkout(float price, float tax)=0; //pure virtual function
};

//Normal Bill with usual price and rates
class NormalBill: public Strategy {
public:
	virtual float checkout(float price, float tax) // indicates this is the implementation of a virtual function.
	{
		return price * (1 + tax);// returns total price from NormalBill to the customer
	}
};

//Happy hour bill with 20% discount
class HappyHourBill: public Strategy {
public:
	virtual float checkout(float price,float tax) // indicates this is the implementation of a virtual function.
	{
		return price * 0.8 * (1 + tax);// returns total price from HappyHourBill to the customer
	}
};

// Holiday Bill with 20% more extract price
class HolidayBill: public Strategy {
public:
	virtual float checkout(float price, float tax)// indicates this is the implementation of a virtual function.
	{
		return price * 1.2 * (1 + tax);// returns total price from HolidayBill to the customer
	}
};

class Customer {
private:
	Strategy* m_strategy;
public:
	Customer() {
	}
	// Set Price
	void set_Price(Strategy* s) {
		m_strategy = s;
	}

	float checkout(float price, float tax) {
		return m_strategy->checkout(price, tax);
	}
};

int main() {
	NormalBill bill1; // Normal Bill object
	HappyHourBill bill2; // Happy hour bill object
	HolidayBill bill3; // Holiday bill object

	float tax= 0.8;// tax rate

	Customer cust; //customer object
	cust.set_Price(&bill1);// setting Normal bill price for the customer
	cout << "The total price for the Normal Bill is: " << cust.checkout(123.0, tax)
			<< endl;
	cust.set_Price(&bill2);// setting Happy Hour Bill price for the customer
	cout << "The total price for the Happy Hour Bill is: " << cust.checkout(123.0, tax)
				<< endl;
	cust.set_Price(&bill3);//setting Holiday Bill price for the customer
	cout << "The total price for the Holiday Bill is: " << cust.checkout(123.0, tax)
					<< endl;

}
