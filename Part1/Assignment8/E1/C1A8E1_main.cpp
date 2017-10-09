/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/16/2015
 * C1A8E1_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This program exercises the characteristics of the SavingsAccount class.
 * Its attributes are set and displayed based on member functions of the class.
 */
#include <cstdlib>
#include "C1A8E1_SavingsAccount.h"

int main()
{
   SavingsAccount userSavingAccount;
   // Savings account 5 member attributes values are set from user input
   userSavingAccount.GetInitialValues();
   // Savings account 5 member attributes are displayed
   userSavingAccount.DisplayValues();
   // Savings account penalty amount is calculated and displayed
   // to show that its value actually updated
   std::cout << "Account closure penalty is: " << userSavingAccount.CalculatePenalty() << "\n";
   
   return(EXIT_SUCCESS);
}
