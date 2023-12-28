# Checkbook

The check.h and check.cc files define a class called `Check`, which holds the information for a single check, including the *check_number*, the *date* that it was written, to *whom* it was written and the *amount* of the check. This class is dependent on the `Date` class, which already has defined the >> and << operators for `Date` objects as well as a full set of comparison operators.

Checkbook objects consist of an array capable of holding 200 checks, a number to keep track of how full that array is, a balance (which says how much money is in the checking account), ***and a variable for the next available check num***. The functions for the checkbook class give the user the ability to:

1. Have their checkbook reloaded from the backup file – so they do not re-enter their checks every time they start the program.
2. Make a deposit into their checkbook.
3. Write a check – the user **can*****not*** enter the check-number, ***the check number will be inserted by the checkbook using the set_chk_num() function of the Check class***.
4. See the checkbook balance.
5. See a listing of all the checks that they have written – for each check they can see all the information about that check.
6. Remove a check by entering its check-number. ***Once a check is removed that check number is never available again.***
7. Sort the checks by check-number.
8. Sort the checks alphabetically by the person to whom they were written.
9. Sort the checks by the date they were written.
10. Find and view all the checks written to a particular payee along with the total amount of those checks.
11. Find the average of all the checks written.
12. Have the checkbook backed up to the same file that it was read from at the beginning of the program, *upon exiting the program* (the main calls the save function).

Note that items 2 – 11 above are menu options that are done in a loop in the main. The back-up file is done without the user’s knowledge or interaction.
