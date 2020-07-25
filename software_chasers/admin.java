package LoopProject;
import java.util.*;
import java.io.*;
 
class admin extends Exception       //CLASS ADMIN
{
//DECLARING MEMBER VARIABLES
 private int nstudents;      
 int nsub;
 public String sub[];
 private Student[] stu;          
 int count;
 
 admin()           //CONSTRUCTOR
 {
  count=0;
  nstudents = 0;
  nsub = 0;
 }
 
           Scanner scan = new Scanner(System.in);    //CREATING THE OBJECT OF SCANNER CLASS
 
 
           HashMap<Integer,Student> map = new HashMap<>();     //HASHTABLE 
 
 void create()                         //CREATE FUNTION TO ACCEPT THE NUMBER OF SUBJECTS AND STUDENTS  
 {
	  do
	  {
	   System.out.print("\n ENTER NUMBER OF STUDENTS : ");     //ASKING THE NUMBER OF STUDENTS IN THE CLASS
	   nstudents = scan.nextInt();
	  
	  }while(nstudents < 0 || nstudents > 90);           //VALIDATION FOR ACCEPTING THE CURRENT NUMBER OF STUDENTS
	
	  stu = new Student[nstudents+1];
	 
	 
	 do
	 {
	   System.out.print("\n ENTER NUMBER OF SUBJECTS : ");       //ASKING THE NUMBER OF SUBJECTS
	   nsub = scan.nextInt();
	  
	 }while(nsub < 4 || nsub > 8);             //VALIDATIONS FOR ENTERING THE CURRECT NUMBER OF SUBJECTS
	  
	  sub = new String[nsub];
	 
	  int flag = 0;
	  
	  for(int i=0;i<nsub;i++)
	  {
		  do
		  {
			  flag=0;
			  System.out.print("\n ENTER THE "  + (i+1) + "SUBJECT NAME : "); 
			  sub[i] = scan.nextLine();
			  sub[i] = scan.nextLine();
			  
			  sub[i] = sub[i].toUpperCase();
			  
			  for(int j=0;j<sub[i].length();j++)
			  {
				  if(sub[i].charAt(j) != ' ' && (sub[i].charAt(j) < 'A' || sub[i].charAt(j) > 'Z') )
				  {
					  flag=1;
					  break;
				  }
			  }
			  
			  if(flag==1)
			  {
				  System.out.print("\n SUBJECT NAME CANNOT CONTENT NUMBERS OR SPECIAL CHARACTERS!! ");
			  }
		  }while(flag != 0);
		  
	  }
   
 }
 
 void insert()              //INSERT FUNCTION FOR INSRTING THE STUDENT INFORMATION
 {
 int ch=0;
 int temp=0;
 int flag=0;
 int roll=0;
 do
 {
  do
  {
	  	flag=0;
	  	System.out.print("\n ENTER THE 4 DIGIT ROLL NO : ");        //ASKING THE ROLL NUMBER OF STUDENT
	  	roll   = scan.nextInt();

	     int count=0;
	     int tem = roll;
	     while(tem!=0)
	     {
	      tem = tem /10;
	      count++;  
	     }
	    
	     if(count != 4)         //VALIDATIONS FOR ENTERING ONLY FOUR DIGIT NUMBER 
	     {
	      flag = 1;
	     }
	    
	     if(flag == 0)
	     {
	      temp = roll%100;
	      if(temp <= 0 || temp > nstudents)
	      {
	       flag = 1;
	      }
	      
	      if(map.containsKey(roll))            //CHECKING IF IT CONTAINS THAT ROLL NUMBER         
	      {
	           System.out.print("\n TWO STUDENTS CANNOT HAVE THE SAME ROLL NUMBER...");
	           flag=1;
	      }
     
     
  
    }
  
   }while(flag == 1);
   
   //CREATING STUDENT CLASS OBJECT TO STORE DETAILS OF POVIDED ROLL NUMBER
   stu[temp] = new Student(nsub,sub);
   stu[temp].rollno = roll;
   stu[temp].accept();                      //ACCEPTING THE DATA BY CALLING accept() FUNCTION
   map.put(roll,stu[temp]);                 // INSERTING THE OBJECT IN HASH MAP
  
  
   System.out.print("\n 1. ADD MORE ");                     //ASKING FOR USER'S CHOICE
   System.out.print("\n 2. EXIT ");
   ch = scan.nextInt();
 
   if(ch >2 || ch < 1)
   {
	   System.out.print("\n INVALID INPUT...");
   }
   
 }while(ch == 1);

 }
 
  void display()               //FUNCTION TO DISPLAY THE DATA
  {
    int roll;
    System.out.print("\n ENTER THE ROLL NO : ");
    roll = scan.nextInt();
     if(map.containsKey(roll))            //CHECKING IF IT CONTAINS THAT ROLL NUMBER         
     {
      Student temp1 = map.get(roll);            // GETTING THE STUDENT OBJECT OF THE PROVIDED KEY
      temp1.display1();                       //CALLING THE display() FUNCTION
     }
     else
    {
     System.out.print("\n SORRY!! NO RECORD PRESENT FOR ROLL NUMBER  : " + roll);
    }
     
  }
 
 
  void report_card()              //FUNCTION FOR REPORT CARD
  {
   int roll;
    System.out.print("\n ENTER THE ROLL NO : ");
    roll = scan.nextInt();
     if(map.containsKey(roll))                   //CHECKING IF ROLL NO IS PRESENT OR NOT IN HASH MAP
     {
      Student temp1 = map.get(roll);			 // GETTING THE STUDENT OBJECT OF THE PROVIDED KEY
      temp1.report();
     }
     else
    {
     System.out.print("\n SORRY!! NO RECORD PRESENT FOR ROLL NUMBER  : " + roll);
    }
  }
 
 
  void delete()           //DELETE FUNTION FOR DELETING THE STUDENT INFORMATION
 {
  int roll;
  System.out.print("\n ENTER THE ROLL NO : ");
  roll = scan.nextInt();
  
  if(map.containsKey(roll))                   //CHECKING IF ROLL NO IS PRESENT OR NOT IN HASH MAP
  {
   map.remove(roll);
   System.out.print("\nROLL NUMBER : "+roll+ "      :  DELETED");
  }
  else
  {
   System.out.print("\n DELETION UNSUCCESSFUL...");
   System.out.print("\n SORRY!! NO RECORD PRESENT FOR ROLL NUMBER  : " + roll);
  }
  
  
 }
 
  
  
  
 void update()                //UPDATE FUNCTION TO UPDATE ANY STUDENTS MARKS
 {
  int roll;
  System.out.print("\n ENTER THE ROLL NO : ");
  roll = scan.nextInt();
  if(map.containsKey(roll))				   //CHECKING IF ROLL NO IS PRESENT OR NOT IN HASH MAP
  {
   Student temp1 = map.get(roll);			 // GETTING THE STUDENT OBJECT OF THE PROVIDED KEY
   temp1.display1();
   int ch=0;
   
   do
   {
    for(int i=0;i<nsub;i++)
    {
     System.out.println((i+1)+" "+sub[i]);       //DISPLAYING THE SUBJECTS LIST           
    }
    
    System.out.println((nsub+1) +"  EXIT. ");
    System.out.print("\n ENTER YOUR CHOICE : ");
    ch=scan.nextInt();
    
    if(ch > (nsub+1))
    {
     System.out.println("\n INVALID INPUT....");
    
    }
    else if(ch >0 && ch <= nsub)
    {
     int ch1=0;                             
     System.out.println("1. T1");                   //ASKING WHICH EXAMS MARKS WANT TO UPDATE
     System.out.println("2. T2");
     System.out.println("3. ESE"); 
     System.out.print("\n ENTER YOUR CHOICE : ");
     ch1=scan.nextInt();
     
     if(ch1 > 0 && ch1<=3)
     {
      temp1.update_sub(ch,ch1);                       
      temp1.display1();
     }
     else
     {
      System.out.println("\n INVALID INPUT....");
     
     }
     
    }
    
    
    
   }while(ch != (nsub+1));
   
  } 
  else
  {
   System.out.print("\n RECORD FOR ROLL NO : " + roll + " IS NOT PRESENT...");
  }
   
 }
 
 void failed_list()                  //FUCTION TO DISPLAY THE LIST OF STUDENTS WHICH ARE FAILED
 {
	 if(map.isEmpty())
	 {
		 System.out.print("\n STUDENTS RECORDS ARE NOT PRESENT...");
	 }
	 else
	 {
		  Set<Integer> keys = map.keySet();
		  for(Integer p:keys)
		  {
		    Student temp = map.get(p);
		    //System.out.print("\n ROLL NUMBER : " + p);
		    temp.failed();
		    
		  }
   
	 }
  }
   
    }

