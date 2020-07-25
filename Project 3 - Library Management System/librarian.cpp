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
    cout<<"\n\tUpdating number of copies in the Library"<<endl;
    fstream fin, fout; 
  
    // Open an existing record 
    fin.open("books.csv", ios::in); 
  
    // Create a new file to store updated data 
    fout.open("booksnew.csv", ios::out); 
  
    int marks, count = 0, i; 
    string name1; 
    int index; 
    string line, word; 
    vector<string> row; 
  
   
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
        name1 = row[0];    
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
                    fout << row[i] << ","; 
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
                    fout << row[i] << ","; 
                } 
  
                // the last column data ends with a '\n' 
                fout << row[row_size - 1] << "\n"; 
            } 
        } 
        if (fin.eof()) 
            break;  
         
    }

    if (count == 0) 
        cout << "Record not found\n";

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
  
        while(getline(s, word,',')) 
        { 
            row.push_back(word); 
        } 
  
        int row_size = row.size(); 
        name1= row[0];
  
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

    // This function counts number of  
    // leap years before the given date 
int librarian::countLeapYears(int m,int y)  
{
    int years = y; 
  
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (m <= 2)  
    { 
      years--; 
    } 
  
        // An year is a leap year if it is a multiple of 4, 
        // multiple of 400 and not a multiple of 100. 
        return years / 4 - years / 100 + years / 400; 
} 
  
    // This function returns number  
    // of days between two given dates 
int librarian::getDifference(int d1,int d2,int m1,int m2,int y1,int y2) 
{ 
       static int monthDays[] = {31, 28, 31, 30, 31, 30, 
                            31, 31, 30, 31, 30, 31}; 
        // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE date of issue
  
        // initialize count using years and day 
       int n1 = y1 * 365 + d1; 
  
        // Add days for months in given date 
       for (int i = 0; i < m1 - 1; i++)  
       { 
           n1 += monthDays[i]; 
       } 
  
        // Since every leap year is of 366 days, 
        // Add a day for every leap year 
       n1 += countLeapYears(m1,y1); 
  
        // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE date of return 
       int n2 = y2 * 365 + d2; 
       for (int i = 0; i < m2 - 1; i++) 
        { 
            n2 += monthDays[i]; 
        } 
        n2 += countLeapYears(m2,y2); 
  
        // return difference between two counts 
        return (n2 - n1); 
} 
    
    
void librarian::calcFine(string dateIssued,string dateReturned)
{
    cout<<"\n\tCalculating fine..."<<endl;
    int d1,m1,y1,d2,m2,y2;
    Date d;
    d1=d.getDay(dateIssued);
    d2=d.getDay(dateReturned);
    m1=d.getMonth(dateIssued);
    m2=d.getMonth(dateReturned);
    y1=d.getYear(dateIssued);
    y2=d.getYear(dateReturned);
 
    int no_of_days = getDifference(d1,d2,m1,m2,y1,y2);//get the no of days between the issue date and return date of a book
    if(no_of_days < 15)
    {
        cout<<"\n\tNo fine on this book";  //book returned before the 15 day deadline
    }
    else
    {     
        int x=no_of_days-15;              //book has been held for more than 15 days
        int fine=x*5;                     //hence a fine is imposed on a RS 5 per day basis
        cout<<"\n\tFine is Rs: "<<fine<<" on this book";
    }

}

void librarian::showBooks()
{
    fstream fout("books.csv",ios::in);
    vector<string> row;
    string line,word;

    while(getline(fout,line))
    {
        row.clear(); 
        
        stringstream s(line); 
  
        while(getline(s,word,','))
        { 
            row.push_back(word); 
        }

        cout<<"\n\tBookname - "<<row[0];
        cout<<"\n\tAuthor - "<<row[1];
        cout<<"\n\tBook ID - "<<row[2];
        cout<<"\n\tNumber of copies available - "<<row[3]<<endl;
        cout<<"----------------------------------------------------------\n"; 
    }

    fout.close();    
}
