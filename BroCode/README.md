# Buffer
The buffer project series repository.
Open the 'BroCode' Folder to view the source code
## Library Management System
### PROJECT DESCRIPTION  
A library Management system for teachers, students and librarian.
There are three types of users - teacher,student and librarian.
The Librarian can :
1. Add Books
2. Update number of copies of book
3. Delete Book
4. Display All books
5. Calculate Fine

The Teacher and Student can :
1. Issue a book
2. Return a book
3. Display all books
4. Display Profile

#### The application supports log in and sign up - If the user does not exist, he/she has to create an account
#### If the user exists, he/she has to input the correct emailid and password. The passwords are stored using SHA-256.

### DATA STRUCTURES USED
1. Files (.csv Files ) for storing all the data
2. Hashsmap for searching on O(1) time. Whenver the user tries to login, the <email,password> stored in the file and read and stored in a hashmap where the email is the key and the hashed password is the value. Then the input emailid and password is searched in the hashmap.
3. Arrays for manipulating data stored in the file.

### CONTRIBUTORS OF THE PROJECT: 
1. Aarya Deshmukh - library.cpp and the corresponding header file
2. Akanksha Kulkarni - student.cpp and the corresponding header file
3. Sejal Jagtap - teacher.cpp and the corresponding header file
4. Manasi Kasande - main.cpp, user.cpp, date.cpp, person.cpp and the corresponding header files

### REFERENCES
1. picosha2.h - the header file used for SHA256 - https://github.com/okdshin/PicoSHA2
2. C++ Complete Reference by Herbert Schildt 
3. www.geeksforgeeks.com
4. www.sanfoundry.com

