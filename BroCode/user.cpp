#include <fstream>
#include <iostream>
#include <string>
#include "picosha2.h"
using namespace std;
class user
{
	
	bool login(string email,string password)
	{
				
	}
};
int main(int argc, char const *argv[])
{
	string str = "12345";
	cout<<"hash = "<<picosha2::hash256_hex_string(str)<<endl;
	return 0;
}