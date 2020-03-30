#include "student.h"
using namespace std;

	student::student()
	{
		dept=" ";
		cnum=" ";
		year=0;
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

