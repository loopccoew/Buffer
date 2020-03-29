#include "person.h"
using namespace std;
	
	person::person()
	{
		name = NULL;
		email = NULL;
	}

	person::person(string name,string email)
	{
		this->name = name;
		this->email = email;
	}

	void person::show()
	{
		cout<<"\n\tName : "<<name;
		cout<<"\n\tEmail id : "<<email;
	}