/*
 * Author:  Jase Binkley  Date:  2/24/14
 * Class :  CSC2020
 * Purpose:  This script reads a file and separates numbers
 *           by even and odd values, storing those values in 
 *           their own files.  It then adds the even numbers
 *           and outputs the sum, then adds the odd numbers 
 *           and outputs that sum.
 * */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream inputfile;
  ofstream evenfile, oddfile;
  int number, odd_number, even_number;
  int even_total = 0, odd_total = 0; //z-out my totals

  inputfile.open("infile.txt"); //open txt file
  if (!inputfile)  //catch empty txt files
    cout << "Input file does not exist.\n";
  evenfile.open("even.txt");
  if (!evenfile)
    cout << "Output file does not exist.\n";
  oddfile.open("odd.txt");
  if (!oddfile)
    cout << "Output file does not exist.\n";

    while (inputfile >> number)  //while there is input to place in 'number'
      {
	if (number%2==0)  //are you even?  clever girl.
	{
	  even_total += number;  //even_total holds my running totals for even
	  evenfile << number << " \n";
	}
	if (number%2!=0)  //or are you not even? (aka odd)
	{
	  odd_total += number;  //odd_total holds running total for the odds
	  oddfile << number << " \n";
	}
      }
      
      cout << "\n\nYour even total is: " << even_total << endl; //print totals
      cout << "\n\nYour odd total is: " << odd_total << endl;
      
  inputfile.close();  //now tidy everything up
  evenfile.close();
  oddfile.close();

      return 0;
      
}
