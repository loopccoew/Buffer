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
	
    void librarian::updateBooks(string name,int copies) 
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
   
     index=3; //index number of number of copies of that book
  
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
void librarian::deleteBooks() 
{ 
  
    // Open FIle pointers 
    fstream fin, fout; 
  
    // Open the existing file 
    fin.open("books.csv", ios::in); 
  
    // Create a new file to store the non-deleted data 
    fout.open("booksnew.csv", ios::out); 
  
    int rollnum, roll1, marks, count = 0, i; 
    string name,name1;
    int index, new_marks; 
    string line, word; 
    vector<string> row; 
  
    // Get the roll number 
    // to decide the data to be deleted 
    cout << "Enter the name of the book to be removed: "; 
   getline(cin,name);
  
    // Check if this record exists 
    while (!fin.eof())
	 { 
  
        row.clear(); 
        getline(fin, line); 
        stringstream s(line); 
  
        while (getline(s, word, ', ')) 
	{ 
            row.push_back(word); 
        } 
  
        int row_size = row.size(); 
        name1=name;
  
        // writing all records, 
        // except the record to be deleted, 
        // into the new file 'booksnew.csv' 
        // using fout pointer 
         if((name.compare(name1)) != 0) 
	  { 
            if (!fin.eof())
	    { 
                for (i = 0; i < row_size - 1; i++) 
		{ 
                    fout << row[i] << ", "; 
                } 
                fout << row[row_size - 1] << "\n"; 
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
    remove("books.csv"); 
  
    // renaming the new file with the existing file name 
    rename("booksnew.csv", "books.csv"); 
}  
