
#include "date.h"
#include "person.h"
#include "librarian.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
class teacher : public person
{
	private:

	
	string cnum;
	

	public:

	teacher();

	void input();

	void show(string emailid);

	string getEmail();

	void issue(string emailid);
	
	void returnBook(string emailid);

};