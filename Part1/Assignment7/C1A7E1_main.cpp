/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/14/2015
 * C1A7E1_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This program asked for a start and stop time from a user.
 * The time elapsed between the two times are then evaluated.
 * The results are printed out.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "C1A7E1_MyTime.h"

using namespace std;

const int MAX_LOOP = 3;
const char DELIMITER = ':';

MyTime *DetermineElapsedTime(const MyTime *startTime, const MyTime *stopTime);

int main()
{
   // setfill is used to display digits in 2 digit format.
   cout << setfill('0');

   for (int loopCount = 0; loopCount < MAX_LOOP; loopCount++)
   {
      cout << "Enter start time, than stop time, in HH:MM:SS format\n";
      MyTime startTime, stopTime;
      // Use to verify ':' inputs
      char delim1, delim2, delim3, delim4;
      cin >> startTime.hours >> delim1 >> startTime.minutes >> delim2 >> startTime.seconds
      >> stopTime.hours >> delim3 >> stopTime.minutes >> delim4 >> stopTime.seconds;

      // Verifies if valid HH:MM:SS format is used
      if (delim1 != DELIMITER || delim2 != DELIMITER || delim3 != DELIMITER || delim4 != DELIMITER)
      {
         cout << "Invalid format, Please try again.\n";
         continue;
      }

      MyTime *elapsedTime = DetermineElapsedTime((MyTime *)&startTime, (MyTime *)&stopTime);

      cout << "The time elapsed from " << setw(2) << startTime.hours << ":" << setw(2) 
         << startTime.minutes << ":" << setw(2) << startTime.seconds << " to " << setw(2) 
         << stopTime.hours << ":" << setw(2) << stopTime.minutes << ":" << setw(2) 
         << stopTime.seconds << " is " << setw(2) << elapsedTime->hours << ":" << setw(2) 
         << elapsedTime->minutes << ":" << setw(2) << elapsedTime->seconds << "\n";
   }
   return(EXIT_SUCCESS);
}
