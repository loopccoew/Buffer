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
		    	<<book[2]<<","
		    	<<d.getDate()<<","
		    	<<count
		    	<<"\n";
				cout<<"\n\tBook issued !";

			//saving data in issued.csv in the format
			//email,bookname,author,id,copies,date issued,count	    

			in.close();	
			f.close();
			fin.close();
	}	

void student::returnBook(string emailid)
	{
		string bookname,book_name;
		int count=0;
		cout<<"\n\tEnter the book name:";
		getline(cin,bookname);
		fstream fout,fin;
		fout.open("issued.csv",ios::in|ios::out|ios::app);
		bool flag1=false; //for emailid
		bool flag2=false; //for bookname
		int i=0;
		string book[5];
		string line,word;
		vector<string> row;
		while(!fout.eof())
		{
			row.clear();
			getline(fout,line); //stores an entire row in line variable
			stringstream s(line); //breaks into words
			while(getline(s,word,','))
			{
				row.push_back(word);
				if(i<6 && flag2==true)
				{
					book[i]=word;
					i++;
				}
				if(bookname == row[1])
				{
					flag2=true;
				}
				if(emailid==row[0])
				{
					flag1=true;
				}

			}

		}
		if(flag1==true && flag2==true)
		{
			//user has borrowed that particular book
			int copies=stoi(book[2]);
			copies++;
			librarian l;
			Date d;
			l.update(bookname,copies);  //update no of copies in books.csv
			l.calcfine(book[3],d.getDate());
			//delete line from issued.csv
			fout.open("issued.csv",ios::in); //open existing file
			// Create a new file to store the non-deleted data 
			fin.open("issuednew.csv", ios::out); 
			while(!fout.eof())
			{
				row.clear(); 
       			getline(fout, line); 
       			stringstream s(line); 
  
       			while(getline(s, word,',')) 
        		{ 
           			 row.push_back(word); 
				} 
				int row_size = row.size(); 
				book_name=bookname;
				// writing all records, 
        		// except the record to be deleted, 
       			// into the new file 'issuednew.csv' 
				// using fout pointer 
				if((bookname.compare(book_name)) != 0) 
        		{ 
          		  if (!fout.eof())
         			{ 
                		for ( int i = 0; i < row_size - 1; i++) 
               			{ 
                   			fin << row[i] << ", "; 
                		} 
               			 fin << row[row_size - 1] << "\n"; 
           			} 
       			} 
       			else 
        		{ 
           			count = 1; 
        		} 
        		if (fin.eof()) 
					break; 

			}

			if (count == 1) 
       			cout << "Record deleted\n"; 
    		else
        		cout << "Record not found\n"; 
  
    		// Close the pointers 
    		fin.close(); 
    		fout.close(); 
  
    		// removing the existing file 
    		remove("issued.csv"); 
  
    		// renaming the new file with the existing file name 
			rename("issuednew.csv", "issued.csv"); 
		}

		else
		{
			cout<<"\n\t You have not borrowed this book.";
		}

	}
	
	

	
