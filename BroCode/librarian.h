#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class librarian
{
	private:

	string bookname;
	string author;
	string bookno;
	string num;
	
	public:

	librarian();
	void addBook();
	void updateBooks(string name,int copies);
	void deleteBooks();
	int  countLeapYears(int m,int y);
	int getDifference(int d1,int d2,int m1,int m2,int y1,int y2);
	void calcFine(string dateIssued,string dateReturned);
	void showBooks();
};
#endif
