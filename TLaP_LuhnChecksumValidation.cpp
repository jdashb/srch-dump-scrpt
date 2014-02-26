/*************************************
 *     LUHN CHECKSUM VALIDATION      *
 * Allows the user to input a number *
 * of any length and uses the Luhn   *
 * formula to validate the number.   *
 * This code is based off a project  *
 * in "Think Like a Programmer"      *
 * by V. Anton Spraul                *
 * published by no starch press      *
 * **********************************/

//**********************************************
// For more on the Luhn Algorithm              *
// http://en.wikipedia.org/wiki/Luhn_algorithm *
//**********************************************

#include <iostream>
using namespace std;

int doubleDigitValue(int); //call the function

int main()
{
char digit;
int oddLengthChecksum = 0;
int evenLengthChecksum = 0;
int position = 1;

cout << "Please enter a number: ";
digit = cin.get(); //converts 'cin' to ascii value
while (digit != 10) //for digits 0-9
{
  if (position % 2 == 0) //if position is even 
  {
    oddLengthChecksum += doubleDigitValue(digit - '0'); //odd positions must be doubled 
    evenLengthChecksum += digit - '0';
  }
  else //if position is odd
  {
    oddLengthChecksum += digit - '0';
    evenLengthChecksum += doubleDigitValue(digit - '0'); //even positions must be doubled
  }
  digit = cin.get(); //fetch the next digit
  position ++; //increment counter
}
int checksum;
if ((position - 1) % 2 == 0) //position -1 because we don't want to count white space
  checksum = evenLengthChecksum; //if mod is 0, checksum is even
else
  checksum = oddLengthChecksum; //if not checksum is odd
cout << "Checksum is " << checksum << ". \n";
if (checksum % 10 == 0)  //if checksum is divisible by 10, it is VALID
{
  cout << "Checksum is divisible by 10.  Checksum VALID. \n";
}
else
{
  cout << "Checksum is not divisible by 10.  Checksum is INVALID. \n";
}
return 0;

}

//*******************************************
// Definition of doubleDigitValue function. *
//*******************************************

int doubleDigitValue(int digit)
{
  int doubleDigit = digit * 2;
  int sum;
  if (doubleDigit >= 10) sum = 1 + doubleDigit % 10;
  else sum = doubleDigit;
  return sum;
}