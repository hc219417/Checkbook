/*************************************************************************
    This is the implementation file for the Check class. For more 
		information about the class see check.h.
    Students are expected to implement some of the functions shown 
		below.
	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/
#include "check.h"
using namespace std;

Check::Check(Date d, string p, int num, double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
}

// Input and output functions
void Check::write_check(std::istream& ins){
	if(&ins == &cin) //read from the keyboard
	{
		cout << "Please enter the date (m/d/y): ";
		ins >> date;

		cout << "Who is this check being written to? Please enter: ";
		while(ins.peek() == '\n' || ins.peek() == '\r')
		{
			ins.ignore();
		}
		getline(ins,payto);

		cout << "Please enter the amount: $";
		ins >> amount;
		do{
			cout << "Error: amount must be greater than $0" << endl;
			cout << "Please try again: ";
			ins >> amount;
		} while(amount < 0.01);
	}
	else //read from a file
	{
		ins >> checknum;
		ins >> date;
		while(ins.peek() == '\n' || ins.peek() == '\r')
		{
			ins.ignore();
		}
		getline(ins,payto);
		ins >> amount;
	}
}

void Check::output(std::ostream& outs)const{
	outs << "Your check is check number " << checknum << ", written to " << payto << " for $" << amount << " on " << date << endl;
}

ostream& operator << (ostream& outs, const Check& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Check& c){
	c.write_check(ins);
	return ins;
}