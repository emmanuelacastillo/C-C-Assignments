/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/14/2015
 * C1A7E1_DetermineElapsedTime.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The implementation determine the time elapse between two times: stop and start time.
 * This is determined by first converting all time attributes into seconds.
 * From there, the time difference in seconds in determined and the full seconds
 * is converted back to the individual time attributes (hours, minutes, seconds).
 */

#include "C1A7E1_MyTime.h"

const int HOUR_TO_SECONDS = 3600; 
const int MINUTES_TO_SECONDS = 60;
const long DAY_TO_SECONDS = 86400;

MyTime *DetermineElapsedTime(const MyTime *startTime, const MyTime *stopTime)
{
   static MyTime elapsedTime;

   //Convert startTime and stopTime to long for accuracy in following algorithm
   long startTimeHours = (long)startTime->hours;
   long startTimeMinutes = (long)startTime->minutes;
   long startTimeSeconds = (long)startTime->seconds;

   long stopTimeHours = (long)stopTime->hours;
   long stopTimeMinutes = (long)stopTime->minutes;
   long stopTimeSeconds = (long)stopTime->seconds;

   //Convert startTime and stopTime hours to seconds
   startTimeHours *= HOUR_TO_SECONDS;
   stopTimeHours *= HOUR_TO_SECONDS;

   //Convert startTime and stopTime minute to seconds
   startTimeMinutes *= MINUTES_TO_SECONDS;
   stopTimeMinutes *= MINUTES_TO_SECONDS;

   //Add all startTimes time attributes
   long startTimeTotalSeconds = startTimeHours + startTimeMinutes + startTimeSeconds;

   //Add all stopTimes time attributes
   long stopTimeTotalSeconds = stopTimeHours + stopTimeMinutes + stopTimeSeconds;

   //Add a days worth of seconds if stop time is a day later.
   if (startTimeTotalSeconds > stopTimeTotalSeconds || startTimeTotalSeconds == stopTimeTotalSeconds)
      stopTimeTotalSeconds += DAY_TO_SECONDS;

   //Determine time elapsed between startTime and stopTime
   long timeElapsedInSeconds = stopTimeTotalSeconds - startTimeTotalSeconds;
   //Determine time elapse hours
   elapsedTime.hours = (int)(timeElapsedInSeconds / HOUR_TO_SECONDS);
   //Determine time elapse in minutes from remaining seconds from hours calculation
   elapsedTime.minutes = (int)((timeElapsedInSeconds % HOUR_TO_SECONDS) / MINUTES_TO_SECONDS);
   //Determine time elapse in seconds from remaining seconds from minutes calculation
   elapsedTime.seconds = (int)((timeElapsedInSeconds % HOUR_TO_SECONDS) % MINUTES_TO_SECONDS);
   
   return &elapsedTime;
}
