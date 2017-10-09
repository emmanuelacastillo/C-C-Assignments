/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/16/2015
 * C1A8E1_SavingsAccount.h
 * Win7
 * Visual C++ 11.0
 *
 * Description: This header file contains the definition of a SavingsAccount class.
 * It contains 5 attributes, account type, owner name, id number, account blanace,
 * and account closure penalty percent. Additionally, it contains three member functions, 
 * GetInitialValues, DisplayValues and CalculatePenalty. Essentially, they manipulate
 * the attributes of the class.
 */

#ifndef C1A8E1_SAVINGSACCOUNT_H
#define C1A8E1_SAVINGSACCOUNT_H
#include <iostream>
#include <string>

// constant used to transform penalty percent to decimal
const double PERCENT = 0.01;

class SavingsAccount
{
private:
   int accountType;
   std::string ownerName;
   long IDnbr;
   double accountBalance, accountClosurePenaltyPercent;
public:
   void GetInitialValues(void);
   void DisplayValues(void) const;
   // A decimal from PERCENT is multiplied to convert penalty percent to decimal form
   double CalculatePenalty(void) const { return accountBalance * accountClosurePenaltyPercent * PERCENT; }
};

inline void SavingsAccount::DisplayValues(void) const
{
   std::cout << "Account type is: " << accountType << "\nOwner name is: " << ownerName
      << "\nID number is: " << IDnbr << "\nAccount balance is: " << accountBalance
      << "\nAccount closure penalty percent is: " << accountClosurePenaltyPercent << "\n";
}
#endif
