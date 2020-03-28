#include <iterator>
#include <boost/algorithm/string.hpp> 
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include "picosha2.h"	//header file which contains hash function
#include <vector>
using namespace std;
class user
{
	public:
	
	bool login(string email,string password);
	
	void saveLogin(string email,string password);
	
};
