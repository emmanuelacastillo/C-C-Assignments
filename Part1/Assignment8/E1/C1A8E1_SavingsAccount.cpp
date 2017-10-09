/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/16/2015
 * C1A8E1_SavingsAccount.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This implementation initializes the attributes of the SavingsAccount class
 * from user input values.
 */
#include <iostream>
#include "C1A8E1_SavingsAccount.h"

using namespace std;

void SavingsAccount::GetInitialValues()
{
   cout << "Please provide the following savings account information:\nAccount Type:\n";
   cin >> accountType;
   cout << "Owner Name:\n";
   // ws is used to counteract the newline from the previous cin
   cin >> ws; 
   getline(cin, ownerName);
   cout << "ID Number:\n";
   cin >> IDnbr;
   cout << "Account Balance:\n";
   cin >> accountBalance;
   cout << "Account Closure Penalty Percent:\n";
   cin >> accountClosurePenaltyPercent;
}
