#include "person.h"
using namespace std;
	
	person::person()
	{
		name = " ";
		email = " ";
	}


	void person::show()
	{
		cout<<"\n\tName : "<<name;
		cout<<"\n\tEmail id : "<<email;
	}

	void person::input(string name,string email)
	{
		this->name = name;
		this->email = email;
	}
