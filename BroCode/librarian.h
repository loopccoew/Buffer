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
};
