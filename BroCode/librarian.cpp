#include "librarian.h"

using namespace std;

	librarian::librarian()
	{
		bookname=" ";
		author=" ";
		bookno=" ";
	    num=" ";
	}	

	void librarian::addBook()
	{

		fstream fout;
		fout.open("books.csv",ios::out | ios::app);
		cout<<"\nEnter details:";
        cin.get();
		cout<<"\nEnter name of the book:";
	    getline(cin,bookname); 
		cout<<"\nEnter author name:";
		getline(cin,author); 
		cout<<"\nEnter booknumber:";
	    getline(cin,bookno); 
		cout<<"\nEnter the number of books:";
		getline(cin,num);
		fout<<bookname<<","<<author<<","<<bookno<<","<<num<<"\n";
	}
	
    void librarian::updateBooks() 
    { 
  
    fstream fin, fout; 
  
    // Open an existing record 
    fin.open("books.csv", ios::in); 
  
    // Create a new file to store updated data 
    fout.open("booksnew.csv", ios::out); 
  
    int copies, marks, count = 0, i; 
    string name,name1; 
    int index; 
    string line, word; 
    vector<string> row; 
  
    cin.get();
    // Get the name of the book from the user 
    cout << "Enter the book name whose copies are to be updated:"; 
    getline(cin,bookname);
  
    // Get the data to be updated 
    cout <<"Enter the new number of copies:"; 
    cin >> copies; 
     
     index=3; //index number of numer of copies of that book
  
    int row_size;
    // Traverse the file 
    while (!fin.eof())
	{ 
  
        row.clear(); 
  
        getline(fin, line); 
        stringstream s(line); 
  
        while(getline(s,word,','))
		{ 
            row.push_back(word); 
        } 
  
        //strcpy(name1,name); cannot use strcpy for string
        name1 = name;    
        row_size = row.size(); 
  
        if((name.compare(name1)) == 0) 
        {
        	count = 1; 
            stringstream convert;
		
  
            // sending a number as a stream into output string 
            convert << copies; 
  
            // the str() converts number into string 
            row[index] = convert.str(); 
  
            if (!fin.eof()) 
			{ 
                for (i = 0; i < row_size - 1; i++)
				 { 
  
                    // write the updated data 
                    // into a new file 'booksnew.csv' 
                    // using fout 
                    fout << row[i] << ", "; 
                } 
  
                fout << row[row_size - 1] << "\n"; 
            } 
        } 
        else 
		{ 
            if (!fin.eof())
			 { 
                for (i = 0; i < row_size - 1; i++) 
				{ 
  
                    // writing other existing records 
                    // into the new file using fout. 
                    fout << row[i] << ", "; 
                } 
  
                // the last column data ends with a '\n' 
                fout << row[row_size - 1] << "\n"; 
            } 
        } 
        if (fin.eof()) 
            break;  
        if (count == 0) 
        cout << "Record not found\n"; 
    }

    fin.close(); 
    fout.close(); 
  
    // removing the existing file 
    remove("books.csv"); 
  
    // renaming the updated file with the existing file name 
    rename("booksnew.csv", "books.csv"); 
  } 
