#include "user.h"
using namespace std;
	
	bool user::login(string email,string password,char type)
	{
		email.push_back(type);
		//hashing the password using sha256
		string hash = picosha2::hash256_hex_string(password);

		//open the file in which all the passwords are stored
		//we have to read the file here
		//hence creating an object of ifstream
		ifstream in("password.txt",ios::in|ios::binary);
		map<string,string> hashmap; 	//hashmap to store data in email,password format
		string line;
		vector<string> keyvalue;
		while(in)
		{
			in>>line;
			boost::split(keyvalue,line,boost::is_any_of(":"));
			hashmap.insert(pair<string,string>(keyvalue[0],keyvalue[1]));

		}

		map<string,string>::iterator it;

		/* 
			Display hashmap for debugging purpose

			for(it = hashmap.begin(); it != hashmap.end(); it++)
			{
				cout<<it->first<<endl;
				cout<<it->second<<endl;
			} 
		*/

		it = hashmap.find(email);	//search for the key
		if(it == hashmap.end())
		{
			//key not found
			//cout<<"\n\tA user with this email id does not exist";
			return false;
		}
		else
		{
			//key found
			//now check if the password matches
			//compare the hash with the stored hash value of the password
			if(hash.compare(it->second) == 0)
				return true;
			else
				return false;
		}

		in.close();

	}

	bool user::saveLogin(string email,string password,char type)
	{
		if(isUnique(email,type))
		{
			//hashing the password using sha256
			string hash = picosha2::hash256_hex_string(password);

			//open file in which all the passwords are stored
			//we have to write to the file here
			//hence creating an object of ofstream
			ofstream out("password.txt",ios::out|ios::app);

			if(!out.is_open())
			{
				cout<<"\n\tError - File is not open";
				return false;
			}
			else
			{	//write the email and password to file
				out<<email;
				out<<type;
				out<<":";
				out<<hash;
				out<<"\n";
				out.close();
				return true;
			}	
		}
		else
		{
			cout<<"\n\tUser already exists"<<endl;
			return false;
		}
		
			
	}

	bool user::isUnique(string email,char type)
	{

		/* This function checks whether there is an existing user with 
			the email id 'email'
			Returns false if present
			true if not i.e email id is unique
		*/
			
		email.push_back(type);

		//open the file in which all the email,passwords are stored
		//we have to read the file here
		//hence creating an object of ifstream
		ifstream in("password.txt",ios::in|ios::binary);
		map<string,string> hashmap; 	//hashmap to store data in email,password format
		string line;
		vector<string> keyvalue;
		while(in)
		{
			in>>line;
			boost::split(keyvalue,line,boost::is_any_of(":"));
			hashmap.insert(pair<string,string>(keyvalue[0],keyvalue[1]));

		}

		map<string,string>::iterator it;

		
			/*Display hashmap for debugging purpose

			for(it = hashmap.begin(); it != hashmap.end(); it++)
			{
				cout<<it->first<<endl;
				cout<<it->second<<endl;
			} */
		

		it = hashmap.find(email);	//search for the key
		if(it == hashmap.end())
		{
			//key not found
			//A user with this email id does not exist";
			return true;
		}
		else
		{
			//key found
			return false;
		}

		in.close();
	}

