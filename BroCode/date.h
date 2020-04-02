/* As a library management system requires calculation of fines and storing dates,
creating a custom date class which will help in doing these 
operations with ease */
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Date
{
	private:

	int month;
	int date;
	int year;
	string day;
	static string days[];

	public:

	Date();
	
	void printDate();	//print today's date

	string getDate();	//returns a string which contains today's date (dd/mm/yyyy)

	string getDate(int date,int month,int year);	//returns a string which contains the date
													//made from the passed parameters
	
	int getDay(string date);	//returns an int which contains the 'dd' part of dd/mm/yyyy

	int getMonth(string date);	//returns an int which contains the 'mm' part of dd/mm/yyyy

	int getYear(string date);	//returns an int which contains the 'yyyy' part of dd/mm/yyyy	
};