#include "librarian.h"
#include "student.h"
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
					}while(u.login(email,password) == false);

					int ch2 = 0;

					do
					{

						
						cout<<"\n\tWelcome, "<<email<<" !";
						cout<<"\n\tOPTIONS ";
						cout<<"\n\t1. Add Books"
							<<"\n\t2. Update a book"
							<<"\n\t3. Remove a book"
							<<"\n\t4. Search for a specific user"
							<<"\n\t5. Display all users"
							<<"\n\t6. Exit"<<endl;
						
						librarian l;
						cin>>ch2;

						switch(ch2)
						{
							case 1:
							l.addBook();
							break;

							case 2:
							l.updateBooks();
							break;

							case 3:
							cout<<"\n\tFunction yet to be written";
							break;

							case 4:
							cout<<"\n\tFunction yet to be written";
							break;

							case 5:
							cout<<"\n\tFunction yet to be written";
							break;

							case 6:
							cout<<"\n\tExiting..";
							break;

							default:
							cout<<"\n\tPlease enter correct option";
						}

					}while(ch2 != 6);	
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
					}while(u.login(email,password) == false);
				}
				break;

				case 2:		// sign up
				{
					student s;
					string password;
					s.input();
					cin.get();
					cout<<"\n\tEnter a password";
					getline(cin,password);
					u.saveLogin(s.getEmail(),password);
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
					}while(u.login(email,password) == false);
					


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
