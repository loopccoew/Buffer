/* This file uses a function which requires c++ 11 support 
Hence compile as g++ -std=c++0x file1.cpp file2.cpp filen.cpp */
#include "date.h"
using namespace std;
string Date::days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
Date::Date()
{
		const int BASE_YEAR = 1900;
		time_t timer;
		tm *time;
        std::time(&timer);
        time = localtime(&timer);
        date = time->tm_mday;
        month = time->tm_mon + 1;
        day = days[time->tm_wday];
        year = time->tm_year + BASE_YEAR;		
}

void Date::printDate()
{
	cout<<"DATE = "<<day<<" "<<date<<"/"<<month<<"/"<<year;
}

string Date::getDate()
{
	string str = to_string(date);
	string str1 = to_string(month);
	string str2 = to_string(year);

	return (str + "/" + str1 + "/" + str2);
}

string Date::getDate(int date,int month,int year)
{
	string str = to_string(date);
	string str1 = to_string(month);
	string str2 = to_string(year);

	return (str + "/" + str1 + "/" + str2);	
}

int Date::getDay(string date)
{
	stringstream s(date);
	string word;
	int arr[3];
	int i = 0;

	while(getline(s,word,'/'))
	{
		arr[i] = stoi(word);
		i++;
	}

	return arr[0]; 
}

int Date::getMonth(string date)
{
	stringstream s(date);
	string word;
	int arr[3];
	int i = 0;

	while(getline(s,word,'/'))
	{
		arr[i] = stoi(word);
		i++;
	}

	return arr[1]; 
}

int Date::getYear(string date)
{
	stringstream s(date);
	string word;
	int arr[3];
	int i = 0;

	while(getline(s,word,'/'))
	{
		arr[i] = stoi(word);
		i++;
	}

	return arr[2]; 
}
