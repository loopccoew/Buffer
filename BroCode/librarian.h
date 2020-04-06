#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <vector>
using std::string;
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
	int calcFine(string dateIssued,string dateReurned);
	
};
