#include "student.h"
using namespace std;

	student::student()
	{
		dept = " ";
		cnum = " ";
		year = 0;
	}	

	void student::input()
	{
		fstream fout;
		fout.open("library.csv",ios::out | ios::app);
		cout<<"\n\tEnter your details:";
		person::input();		
		cout<<"\n\tEnter dept:";
		getline(cin,dept);
		cout<<"\n\tEnter cnum:";
		getline(cin,cnum);
		cout<<"\n\tEnter year:";
		cin>>year;

		fout<<cnum<<","
			<<email<<","
			<<name<<","
			<<dept<<","
			<<year<<"\n";

		fout.close();
	}

	void student::show(string emailid)
	{
		
		fstream fout;
		fout.open("library.csv", ios::in);
		vector<string> row;
		string line,word;
		int flag = 0;	// 0 indicates record not found

		while(fout)
		{

			row.clear();
			getline(fout,line); //stores an entire row in line variable
			stringstream s(line); //breaks into words
			while(getline(s,word,','))
			{
				row.push_back(word);
			}

			if(emailid == row[1])
			{

				flag = 1;	//record found
				cout<<"\n\tStudent Details : "<<endl;
				cout<<"\n\tEmail id : "<<row[1];
				cout<<"\n\tC Number : "<<row[0];
				cout<<"\n\tName : "<<row[2];
				cout<<"\n\tDepartment : "<<row[3];
				cout<<"\n\tYear : "<<row[4]<<endl;
				break;
			}

		}

		if(flag == 0)
		{
			cout<<"\n\tRecord not found!";
		}

		fout.close();
	}

	string student::getEmail()
	{
		return email;
	}

	void student::issue(string emailid)
	{
		fstream fin;
		fin.open("issued.csv",ios::in|ios::out|ios::app); //open issued.csv in read mode
 		bool found = false;
 		string line,word;
		vector<string> row;
		int count = 0;

		while(!fin.eof())
		{
			row.clear();
			getline(fin,line);
			stringstream s(line);
			while(getline(s,word,','))	//breaks the csv lines into words
			{
				//insert word in vector
				row.push_back(word);
			}
			
			if(emailid == row[0])	//user with the email id has issued books befroe
			{
				found = true;
				count++;	//indicates the number of books borrowed by the user
			}
		}

		

		if(found == true)
		{
			if(count >= 4)	//cannot issue more than 4 books
			{
				cout<<"\n\tYou cannot issue more than 4 books at a time.";
				return;
			}
		}
						
		//user can issue books here

			string bookname;
			string bookid;
			cout<<"\n\tPlease enter details of book to be issued:\n ";
			cout<<"\n\t Enter book name:";
			cin.get();
			getline(cin,bookname);
			ifstream in("books.csv",ios::in); //open books.csv in read mode
			bool flag = false;
			int i = 0;
			string book[3] = {" "," "," "}; //an array which stores book details
			while(!in.eof())	//while we don't reach the EOF
			{
				row.clear();
				getline(in,line);
				stringstream s(line);
				while(getline(s,word,','))
				{
					row.push_back(word);					
					if((i < 3) && (flag == true))
					{
						book[i] = word;
						i++;
					}

					if(bookname.compare(row[0]) == 0)	//check if the book exists
					{
						flag = true;					
					}
				}									
				
			}

			

			if(flag == false)
			{
				cout<<"\nBook not found"<<endl;
				return;
			}

			if(stoi(book[2]) == 0)
			{
				cout<<"\n\tNot enough copies !"<<endl;
				return;
			}

			//display book details
			cout<<"\n\tBook details are -  "
				<<"\n\tBook name "<<bookname
				<<"\n\tBook Author "<<book[0]
				<<"\n\tBook ID "<<book[1]
				<<"\n\tNumber of Copies available"<<book[2]<<endl;

			Date d;
			count++;
			librarian l;
			int copies = stoi(book[2]);
			copies--;
			l.updateBooks(bookname,copies);	//for updating number of copies in books.csv
			ofstream f("issued.csv",ios::out | ios::app);	//for writing data into the file
			f 	<<emailid<<","
				<<bookname<<","
		    	<<book[0]<<","
		    	<<book[1]<<","
		    	<<d.getDate()<<","
		    	<<count
		    	<<"\n";
				cout<<"\n\tBook issued !";    

			in.close();	
			f.close();
			fin.close();
	}	
	

	
