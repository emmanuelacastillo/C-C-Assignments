/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/13/2016
 * C2A5E4_DetectFloats.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * DetectFloats determines whether a pointer to const char
 * is a float and what type of float. It can either be
 * a float, double or long double.
 */
#include "C2A5E4_StatusCode-Driver.h"

StatusCode DetectFloats(const char *chPtr)
{
   // There are 9 states that the char
   // can enter to determine
   // whether it is a float or not.
   enum States
   {
      START,
      NOWHOLE,
      WHOLE,
      FRACT,
      EXP,
      SIGN,
      EXPDIGIT,
      FLOAT,
      LONGDOUBLE
   } state = START;

   // Below loops through each char
   // and determmines if it is a float
   // by going through the above states.
   do
   {
      switch (state)
      {
         // Start state is the beginning
         // state that all char goes through
         case START:
            switch (*chPtr)
            {
               case '.':
                  state = NOWHOLE;
                  break;
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = WHOLE;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // NOWHOLE is the state where
         // a char starts with a decimal
         // point.
         case NOWHOLE:
            switch (*chPtr)
            {
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = FRACT;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // FRACT is the state when
         // a digit proceeds a decimal
         // point.
         case FRACT:
            switch (*chPtr)
            {
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = FRACT;
                  break;
               case '\0':
                  return TYPE_DOUBLE;
               case 'l':
               case 'L':
                  state = LONGDOUBLE;
                  break;
               case 'f':
               case 'F':
                  state = FLOAT;
                  break;
               case 'e':
               case 'E':
                  state = EXP;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // WHOLE is the state that occurs when
         // a char starts with a digit.
         case WHOLE:
            switch (*chPtr)
            {
               case '.':
                  state = FRACT;
                  break;
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = WHOLE;
                  break;
               case 'e':
               case 'E':
                  state = EXP;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // EXP is a state when a digit
         // sequence next char is
         // an e or E.
         case EXP:
            switch (*chPtr)
            {
               case '+':
               case '-':
                  state = SIGN;
                  break;
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = EXPDIGIT;
                  break;
               case 'e':
               case 'E':
                  state = EXP;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // SIGN is a state after EXP
         // that occurs if the e or E
         // proceeds either a + or -
         case SIGN:
            switch (*chPtr)
            {
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = EXPDIGIT;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // EXPDIGIT is the state that occurs
         // if a number proceeds either an e,
         // E, + or -.
         case EXPDIGIT:
            switch (*chPtr)
            {
               case '0':
               case '1':
               case '2':
               case '3':
               case '4':
               case '5':
               case '6':
               case '7':
               case '8':
               case '9':
                  state = EXPDIGIT;
                  break;
               case '\0':
                  return TYPE_DOUBLE;
               case 'f':
               case 'F':
                  state = FLOAT;
                  break;
               case 'l':
               case 'L':
                  state = LONGDOUBLE;
                  break;
               default:
                  return NOTFLOATING;
            }
            break;
         // FLOAT is a state when a digit
         // sequence proceeds a f or F.
         case FLOAT:
            switch (*chPtr)
            {
               case '\0':
                  return TYPE_FLOAT;
               default:
                  return NOTFLOATING;
            }
         // LONGDOULE is a state when a digit
         // sequence proceeds a l or L.
         case LONGDOUBLE:
            switch (*chPtr)
            {
               case '\0':
                  return TYPE_LDOUBLE;
               default:
                  return NOTFLOATING;
            }
      }
   } while (chPtr++);
   // If char does not meet any state
   // it is not a float
   return NOTFLOATING;
}
