#include "person.h"
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

	void input();

	void show(string emailid);

	string getEmail();

};