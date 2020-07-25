#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#include "user.h"
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
class student : public person
{
	private:

	string dept;
	string cnum;
	int year;

	public:

	student();

	void input(string name,string email,string password,string dept,string cnum,int year);

	void show(string emailid);

	void issue(string emailid);
	
	void returnBook(string emailid);

	void showBooks();
};
#endif
