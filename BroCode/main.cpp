#include "user.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	cout<<"\n\tWelcome to our library";
	cout<<"\n\tSelect the type of user: ";
	cout<<"\n\t1. Librarian";
	cout<<"\n\t2. Student";
	cout<<"\n\t3. Teacher"<<endl;
	int ch = 0;
	cin>>ch;
	cin.get();
	user u;	
	switch(ch)
	{
		case 1: //Librarian
		{
			cout<<"\n\t1. Log in";
			cout<<"\n\t2. Sign up"<<endl;
			int ch1 = 0;
			cin>>ch1;
			cin.get();
			switch(ch1)
			{
				case 1:		// log in
				{
					string email,password;
					do
					{
						cout<<"\n\tEnter your email"<<endl;
						getline(cin,email);
						cout<<"\n\tEnter the password"<<endl;
						getline(cin,password);

						if(u.login(email,password))
							cout<<"\n\tLogin Successful";
						else
							cout<<"\n\tWrong email id/password. Try Again";
					}while(!u.login(email,password));
				}
				break;

				case 2:		// sign up
				{

				}				
			
			}	
		}
		break;

		case 2: //Student
		{
			cout<<"\n\t1. Log in";
			cout<<"\n\t2. Sign up"<<endl;
			int ch1 = 0;
			cin>>ch1;
			cin.get();

			switch(ch1)
			{
				case 1:		// log in
				{
					string email,password;
					do
					{
						cout<<"\n\tEnter your email"<<endl;
						getline(cin,email);
						cout<<"\n\tEnter the password"<<endl;
						getline(cin,password);

						if(u.login(email,password))
							cout<<"\n\tLogin Successful";
						else
							cout<<"\n\tWrong email id/password. Try Again";
					}while(!u.login(email,password));
				}
				break;

				case 2:		// sign up
				{

				}
				break;					
			}
		}
		break;

		case 3: //Teacher
		{
			cout<<"\n\t1. Log in";
			cout<<"\n\t2. Sign up"<<endl;
			int ch1 = 0;
			cin>>ch1;
			cin.get();

			switch(ch1)
			{
				case 1:		// log in
				{
					string email,password;

					do
					{
						cout<<"\n\tEnter your email"<<endl;
						getline(cin,email);
						cout<<"\n\tEnter the password"<<endl;
						getline(cin,password);

						if(u.login(email,password))
							cout<<"\n\tLogin Successful";
						else
							cout<<"\n\tWrong email id/password. Try Again";
					}while(!u.login(email,password));
					


				}
				break;

				case 2:		// sign up
				{

				}
				break;					
			}
		}
		break;

		default:
		cout<<"\n\tWrong input.Try Again !"<<endl;
	}

	return 0;
}
