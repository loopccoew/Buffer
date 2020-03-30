#include "person.h"
using namespace std;
	
	person::person()
	{
		name = " ";
		email = " ";
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

	void person::input()
	{
		cout<<"\n\tEnter name"<<endl;
		getline(cin,name);
		cout<<"\n\tEnter email id"<<endl;
		getline(cin,email);
	}
