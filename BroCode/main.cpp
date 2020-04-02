/* This application uses a function which requires c++ 11 support 
Hence compile as g++ -std=c++0x file1.cpp file2.cpp filen.cpp */
//#include "librarian.h"
#include "student.h"
#include "user.h"
#include <iostream>
#include <fstream>
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
			
			int ch2 = 0;
			do
			{

				cout<<"\n\tOPTIONS ";
				cout<<"\n\t1. Add Books"
					<<"\n\t2. Update a book"
					<<"\n\t3. Remove a book"
					<<"\n\t4. Calculate Fine"
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
						{
							string name;
							int copies;
							cout<<"\n\tEnter the book name";
							getline(cin,name);
							cout<<"\n\tEnter number of copies";
							cin>>copies;
							l.updateBooks(name,copies);	
						}
						
						break;

						case 3:
						l.deleteBooks();
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

						if(u.login(email,password,'s'))
							cout<<"\n\tLogin Successful";
						else
							cout<<"\n\tWrong email id/password. Try Again";
					}while(u.login(email,password,'s') == false);

					cout<<"\n\tWelcome, "<<email<<" !"<<endl;
					student s;
					int ch2;
					do
					{
						cout<<"\n\tMENU";
						cout<<"\n\t1. Show my profile";
						cout<<"\n\t2. Issue a book";
						cout<<"\n\t3. Return a book";
						cout<<"\n\t4. Exit";
						cin>>ch2;

						switch(ch2)
						{
							case 1:
							s.show(email);
							break;

							case 2:
							s.issue(email);
							break;

							case 3:
							cout<<"\n\tFunction yet to be written";
							break;

							case 4:
							cout<<"\n\tExiting..";
							break;

							default:
							cout<<"\n\tPlease choose a valid option";
							break;
						}
					}while(ch2 != 4);
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
					u.saveLogin(s.getEmail(),password,'s');
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

						if(u.login(email,password,'t'))
							cout<<"\n\tLogin Successful";
						else
							cout<<"\n\tWrong email id/password. Try Again";
					}while(u.login(email,password,'t') == false);
					
					cout<<"\n\tWelcome, "<<email<<" !"<<endl;
					//teacher t;
					int ch2;
					do
					{
						cout<<"\n\tMENU";
						cout<<"\n\t1. Show my profile";
						cout<<"\n\t2. Issue a book";
						cout<<"\n\t3. Return a book";
						cout<<"\n\t4. Exit";
						cin>>ch2;

						switch(ch2)
						{
							case 1:
							//t.show();
							break;

							case 2:
							//t.issue(email);
							break;

							case 3:
							cout<<"\n\tFunction yet to be written";
							break;

							case 4:
							cout<<"\n\tExiting..";
							break;

							default:
							cout<<"\n\tPlease choose a valid option";
							break;
						}
					}while(ch != 4);

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
