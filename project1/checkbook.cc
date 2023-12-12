/**
 *   @file: checkbook.cc
 * @author: Hannah Culver
 *   @date: January 24, 2022
 *  @brief: implementation file for the checkbook class
 */

#include "checkbook.h"
#include "check.h"
using namespace std;

Checkbook::Checkbook(){ //default constructor
	used = 0;
	balance = 0.0;
	next_available_checknum = 1;
}

void Checkbook::load_from_file(ifstream& ifs){
	ifs >> balance;
	ifs >> next_available_checknum;
	while(!ifs.eof())
	{
		ifs >> checks[used]; //see overloaded >> operator in check.cc (had to fix write_check function)
		while(ifs.peek() == '\n' || ifs.peek() == '\r')
		{
			ifs.ignore(); //clear out last leftover newline (otherwise a blank check will be added to the end of the array)
		}
		used++;
	}
}

void Checkbook::save(ofstream& ofs){
	ofs << balance << endl;
	ofs << next_available_checknum << endl;
	for(int i = 0; i < used; i++)
	{
		ofs << checks[i].get_num() << endl;
		ofs << checks[i].get_date() << endl;
		ofs << checks[i].get_payto() << endl;
		ofs << checks[i].get_amount() << endl;
	}
}

void Checkbook::deposit(double depamount){
	balance += depamount;
}

void Checkbook::write_check(istream& ins){
	Check tmp;
	tmp.set_check_num(next_available_checknum); //the user cannot enter the check number (will be done so automatically)
	next_available_checknum++;
	tmp.write_check(ins);
	checks[used] = tmp;
	balance -= tmp.get_amount();
	if(balance < 0)
	{
		cout << "Error: not enough funds, please try again " << "(hint: remaining balance is $" << balance + tmp.get_amount() << ")" << endl;
		exit (0); //not sure how to re-prompt the user without exiting the program
	}
	used++;
}

void Checkbook::remove(int rmnum){
	for(int i = 0; i < used; i++)
	{
		if(checks[i].get_num() == rmnum)
		{
			balance += checks[i].get_amount();
			checks[i] = checks[used - 1]; //assuming order doesn't matter
			used--; //once a check is removed that check number is never available again
		}
	}
}

void Checkbook::number_sort(){
	int i, j, smallsp;
	Check tmp;
	for(i = 0; i < used - 1; i++)
	{
		smallsp = i;
		for(j = i + 1; j < used; j++)
		{
			if(checks[j].get_num() < checks[smallsp].get_num()) //comparing check numbers using selection sort
			{
				smallsp = j;
			}
		}
		tmp = checks[i];
		checks[i] = checks[smallsp];
		checks[smallsp] = tmp;
	}
}

void Checkbook::payto_sort(){ //doesn't work for lowercase vs uppercase (different ASCII values) - could use tolower or toupper
	int i, j, smallsp;
	Check tmp;
	for(i = 0; i < used - 1; i++)
	{
		smallsp = i;
		for(j = i + 1; j < used; j++)
		{
			if(checks[j].get_payto() < checks[smallsp].get_payto()) //comparing payto using selection sort
			{
				smallsp = j;
			}
		}
		tmp = checks[i];
		checks[i] = checks[smallsp];
		checks[smallsp] = tmp;
	}
}

void Checkbook::date_sort(){
	int i, j, smallsp;
	Check tmp;
	for(i = 0; i < used - 1; i++)
	{
		smallsp = i;
		for(j = i + 1; j < used; j++)
		{
			if(checks[j].get_date() < checks[smallsp].get_date()) //comparing dates using selection sort
			{
				smallsp = j;
			}
		}
		tmp = checks[i];
		checks[i] = checks[smallsp];
		checks[smallsp] = tmp;
	}
}

void Checkbook::show(string payto_find){
	double sum = 0.0;
	for(int i = 0; i < used; i++)
	{
		if(checks[i].get_payto() == payto_find)
		{
			sum += checks[i].get_amount();
		}
	}
	cout << "The total amount written to " << payto_find << " is $" << sum << "." << endl;
}

void Checkbook::show_all(ostream& outs){
	for(int i = 0; i < used; i++)
	{
		cout << "*************************" << endl;
		cout << "Check number " << checks[i].get_num() << endl;
		cout << "Date: " << checks[i].get_date() << endl;
		cout << "Pay to " << checks[i].get_payto() << endl;
		cout << "Amount: $" << checks[i].get_amount() << endl;
		cout << "*************************" << endl;
	}
}

double Checkbook::get_balance(){
	return balance;
}

double Checkbook::average(){
	double sum = 0.0;
	for(int i = 0; i < used; i++)
	{
		sum += checks[i].get_amount();
	}
	double average = sum / used; //use setprecision in main
    return average;
}