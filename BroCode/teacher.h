#ifndef TEACHER_H
#define TEACHER_H
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
class teacher : public person
{
	private:

	string dept;
	string designation;

	public:

	teacher();

	void input(string name,string email,string password,string dept,string designation);

	void show(string emailid);

	void issue(string emailid);
	
	void returnBook(string emailid);

	void showBooks();
};
#endif
