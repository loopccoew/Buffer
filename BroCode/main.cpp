#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	cout<<"\n\tWelcome to our library";
	cout<<"\n\tSelect the type of user: ";
	cout<<"\n\t1. Librarian";
	cout<<"\n\t2. Student";
	cout<<"\n\t3. Teacher";
	int ch = 0;
	cin>>ch

	switch(ch)
	{
		case 1: //Librarian
		{
			cout<<"\n\t1. Log in";
			cout<<"\n\t2. Sign up";
			int ch1 = 0;
			cin>>ch1;

			switch(ch1)
			{
				string email,password;
				cout<<"\n\tEnter your email";
				getline(email,cin);
				cout<<"\n\tEnter the password";
				getline(password,cin);
				
			}	
		}
	}

	return 0;
}