#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class person
{
	protected:

	string name;
	string email;

	public:

	person(string name,string email);
	person();
	
	void show();
	void input(string name,string email);
	//~person();
	
};
#endif
