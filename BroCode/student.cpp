#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class student: public person
{
	private:

	string dept;
	string cnum;
	string emailid;
	string name;
	int year;

	public:

	student()
	{
		dept=" ";
		cnum=" ";
		emailid=" ";
		name=" ";
		year=0;
	}	

	void input()
	{
		fstream fout;
		fout.open("library.csv",ios::out | ios::app);
		cout<<"\nEnter details:";
		cout<<"\nEnter dept:";
		cin>>dept;
		cout<<"\nEnter cnum:";
		cin>>cnum;
		cout<<"\nEnter year:";
		cin>>year;
		cout<<"\nEnter emailid:";
		cin>>emailid;
		cout<<"\nEnter name:";
		cin>>name;
		fout<<cnum<<","<<emailid<<","<<name<<","<<dept<<","<<year<<","<<"\n";
	}

	void show(string emailid)
	{
		fstream fout;
		fout.open("library.csv", ios::in);
		vector<string> row;
		string line,word,temp;
		int flag=0;
		while(fout>temp)
		{
			row.clear();
			getline(fout,line); //stores an entire row in line variable
			stringstream s(line); //breaks into words
			while(getline(s,word,","))
			{
				row.push_back(word);
			}
			if(emailid== row[1])
			{
				flag=1;
				cout<<"Student Details:";
				cout<<"Emailid"<<row[1]<<"\n";
				cout<<"C Number:"<<row[0]<<"\n";
				cout<<"Name:"<<row[2]<<"\n";
				cout<<"Department:"<<row[3]<<"\n";
				cout<<"Year:"<<row[4]<<"\n";
				break;
			}

		}
		if(flag==0)
		{
			cout<<"\nRecord not found!";
		}
	}





};
