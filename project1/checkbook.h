/**
 *   @file: checkbook.h
 * @author: Hannah Culver
 *   @date: January 24, 2022
 *  @brief: header file for a checkbook class
 */

#ifndef CHECKBOOK
#define CHECKBOOK

#include <iostream>
#include <fstream>
#include <string>
#include "date.h"
#include "check.h"

using namespace std;

class Checkbook{

    public:

        static const int SIZE = 200;

        Checkbook(); //default constructor

        //load from and save to functions

        void load_from_file(ifstream& ifs); //reload checkbook from the backup file
        void save(ofstream& ofs); //back up the checkbook upon exiting the program

        //manipulate functions

        void deposit(double depamount); //make a deposit into the checkbook
        void write_check(istream& ins); //write a check (the user cannot enter the check number)
        void remove(int rmnum); //remove a check by entering its check number

        //sort functions

        void number_sort(); //sort the checks by check number
        void payto_sort(); //sort the checks alphabetically by the person to whom they were written
        void date_sort(); //sort the checks by the date they were written

        //show functions

        void show(string payto_find); //find and view all the checks written to a particular payee along with the total amount of those checks
        void show_all(ostream& outs); //see a listing of all the checks

        //balance functions

        double get_balance(); //see the checkbook balance
        double average(); //find the average of all the checks written

    private:

        Check checks[SIZE];
        int used;
        double balance;
        int next_available_checknum;
		
};

#endif