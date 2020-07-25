package LoopProject;
import java.util.*;
import java.io.*;

//USER DEFINED CLASS FOR STUDENTS
class Student
{
   // MEMBER VARIABLES
   int rollno;
   String name;
   String c_no;
   float marks[][];   //matrix to store marks for each subject
   int nsub;
   float total;         //variable for total marks obtained
   String[] sub_name;
   String grade = "";
   
   // Constructor
   public Student(int nsub, String[] sub)
   {
       this.rollno=0;
       this.name = "";
       c_no = "";
       this.nsub = nsub;
       marks = new  float[nsub][5];
       total = 0;
       this.sub_name = sub;
       grade = "";
   }

   //CREATING OBJECT OF SCANNER CLASS
   Scanner scan = new Scanner(System.in);
  
   
   //FUNCTION TO ACCEPT THE DEATILS FOR this STUDENT
   void accept()
   {
    
  
  int flag1 = 0;
  do
  {
    //ACCEPTING STUDENT INFORMATION
      System.out.print("\n\n ENTER THE C NUMBER : ");
      c_no = scan.next();
      c_no.toUpperCase();
      flag1 = 0;
      
      for(int i=1;i<c_no.length();i++)
      {
      if(c_no.charAt(i) < '0' || c_no.charAt(i) > '9')
          {
          flag1 =1; //SET THE FLAG
          break;//BREAKING THE LOOP
          }
      }
      
      if(flag1 == 1)
      System.out.print("\n C NUMBER CANNOT CONTAIN ALPHABETS OR SPECIAL CHARACTERS OTHER THAN C AS FIRST CHARACTER");
      
      if(c_no.charAt(0) != 'C' && c_no.charAt(0) != 'c')
      {
          flag1=1;
          System.out.print("\n INVALID INPUT...FIRST CHARACTER SHOULD BE C");
      }
      
      if(c_no.length() != 12)
      {
      	flag1=1;
          System.out.print("\n INVALID INPUT...C NUMBER SHOULD CONTENT 12 CHARACTERS ");
      }
      
  }while(flag1 == 1);    
      
      int flag=0;
      do
      { 
      //ACCEPTING THE STUDENTS NAME
      System.out.print("\n ENTER THE NAME : ");
      name = scan.nextLine();
      name = scan.nextLine();
      
      //CONVERTING NAME TO UPPERCASE
      name = name.toUpperCase();
      flag=0; //RESETTING THE FLAG
      
      //LOOPING OVER NUMBER OF CHARACTERS IN NAME
      for(int i=0;i<name.length();i++)
      {
      //IF NAME DOES NOT CONTENT ALPHABETS THEN SET THE FLAG
          if(name.charAt(i) < 'A' || name.charAt(i) > 'Z')
          {
          flag =1; //SET THE FLAG
          break;//BREAKING THE LOOP
          }
      }
      
      //IF FLAG IS SET THEN PRINT THE STATEMENT
      if(flag == 1)
      System.out.print("\n NAME CANNOT CONTAIN NUMBERS OR SPECIAL CHARACTERS ");
      
      
      }while(flag ==1);  //VALIDATING THE FLAG
      
       System.out.print("\n\n ENTER THE FOLLOWING DEATILS : ");
    
       //LOOPING OVER TOTAL NUMBER OF SUBJECTS
       for(int i=0;i<nsub;i++)
       {
        // GETTING MARKS FOR THE SUBJECT
          System.out.print("\n\n ENTER DEATILS OF SUBJECT : " + sub_name[i]);
          
          
          do
          {
          System.out.print("\n\n ENTER MARKS OBTAINED IN T1 : ");
          marks[i][0] = scan.nextFloat();
          
          }while(marks[i][0] < 0 || marks[i][0] >25);  //VALIDATING WHETHER THE MARKS PROVIDED ARE CORRECT OR NOT
          
          do
          {
          System.out.print("\n ENTER MARKS OBTAINED IN T2 : ");
          marks[i][1] = scan.nextFloat();
          
          }while(marks[i][1] < 0 || marks[i][1] >25);//VALIDATING WHETHER THE MARKS PROVIDED ARE CORRECT OR NOT
       
          do
          {
          System.out.print("\n ENTER MARKS OBTAINED IN ESE : ");
          marks[i][2] = scan.nextFloat();
          
          }while(marks[i][2] < 0 || marks[i][2] >50);  //VALIDATING WHETHER THE MARKS PROVIDED ARE CORRECT OR NOT
          
          marks[i][3] = marks[i][0] + marks[i][1]  + marks[i][2];
          
          //COMPUTING OVERALL TOTAL MARKS OBTAINED
          total = total + marks[i][3]; 
       }
   }
  
   
   //function to display the information about this student
  void display1()
  {
  
      //displaying the info
    System.out.print("\n  THE NAME : " + name);
    System.out.print("\n  THE ROLL NUMBER : " + rollno);
    System.out.print("\n THE C NUMBER : " + c_no);
    System.out.print("\n_______________________________________________________________________________________________________________________");
        System.out.println();
        System.out.format("%42s %10s %8s %8s %8s %8s", "NAME","         ","T1","T2","ESE","TOTAL");
        System.out.print("\n_______________________________________________________________________________________________________________________");
        System.out.println();
      
        //printing the marks for each subject
        
        //looping over number of subjects
        for(int i=0;i<nsub;i++)
        {
         System.out.format("%42s %10s %8d %8d %8d %8d", sub_name[i],"          ",(int)marks[i][0],(int)marks[i][1],(int)marks[i][2],(int)marks[i][3]);
         System.out.println();
        }
        System.out.print("\n_______________________________________________________________________________________________________________________");
        System.out.println();
  }
 
  // FUNCTION TO UPDATE THE MARKS OF PROVIDED SUBJECT FOR this STUDENT
  void update_sub(int s,int e)
  {
       int flag=0;
  do
  {
  flag=0;
  // GETTING UPDATED MARKS FROM USER 
  System.out.println("\n ENETER THE UPDATED MARKS CORRECTLY : ");
  marks[s-1][e-1] = scan.nextInt();
  
  //VALIDATING WHETHER THE PROVIDED MARKS IS APPROPRIATE OR NOT
  if((e == 1 || e==2) && (marks[s-1][e-1] < 0 || marks[s-1][e-1] > 25))
  {
  flag=1;
  }
  else if(e == 3 && marks[s-1][e-1] < 0 || marks[s-1][e-1] > 50)
  {
  flag=1;
  }
  
  }while(flag==1);
  
  
    System.out.println("\n MARKS UPDATED SUCCESSFULLY...");
    
    
   //recalculating total obtained marks
    total = total -  marks[s-1][3];
    
    //calculating updated total marks of s-1 subject
    marks[s-1][3] = marks[s-1][0] +  marks[s-1][1] + marks[s-1][2];
    
    //adding updated marks to total obtained marks
      total = total + marks[s-1][3];
  }
  
  
  //function to calculate the percentage
  float percentage()
  {
  //returning the percentage
      return total/nsub;
  }
 
  //function to compute the grade for ith subject
  String grade(int i)
  {
grade = ""; //initializing the grade variable

// if-else-if-else block used to check the grade

    if(marks[i][3] >=91 && marks[i][3]<=100)
    {
     grade = grade + "O";
     return grade;    //returning the grade
    }
    else if(marks[i][3]>=81 && marks[i][3]<=90)
    {
    
     grade = grade + "A";
    return grade; //returning the grade
    }
   else if(marks[i][3]>=71 && marks[i][3]<=80)
    {
     
     grade = grade + "B";
    return grade; //returning the grade
    }
   else if(marks[i][3]>=61 && marks[i][3]<=70)
    {
    
     grade = grade + "C";
     return grade; //returning the grade
    }
   else if(marks[i][3]>=51 && marks[i][3]<=60)
    {
     
     grade = grade + "D";
     return grade; //returning the grade
    }
   else if(marks[i][3]>=35 && marks[i][3]<=50)
    {
   
     grade = grade + "E";
     return grade; //returning the grade
    }
   else
   {
    
    grade = grade + "F";
    return grade; //returning the grade
   }
   
  }
 
  // function to print the report card of this student
   void report()
   {
    System.out.print("\n____________________________________________________________________________________________________________");
    System.out.print("\n           MKSSS CUMMINS COLLEGE OF ENGINEERING FOR WOMEN'S, PUNE                ");
    System.out.print("\n____________________________________________________________________________________________________________");
    System.out.print("\n*******************************************  SY BTECH  *****************************************************");
    System.out.print("\n NAME OF THE STUDENT : "+name);
    System.out.print("\n C NUMBER : "+c_no);
    System.out.print("\n ROLL NUMBER : "+rollno);
    System.out.print("\n____________________________________________________________________________________________________________");
    System.out.println();
    System.out.format("%42s %10s %8s %8s %8s %8s %12s", "NAME","         ","T1","T2","ESE","TOTAL","GRADES");
    System.out.print("\n____________________________________________________________________________________________________________");
    System.out.println();
    
    for(int i=0;i<nsub;i++)
    {
     System.out.format("%42s %10s %8d %8d %8d %8d %12s", sub_name[i],"          ",(int)marks[i][0],(int)marks[i][1],(int)marks[i][2],(int)marks[i][3],grade(i));
     System.out.println();
    }
    System.out.print("\n_____________________________________________________________________________________________________________");
    System.out.print("\n PERCENTAGE : "+percentage());   //calling the percentage() function to get the percentage
    System.out.print("\n_____________________________________________________________________________________________________________");
    System.out.print("\n REMARK : "+remark());           // calling the remark() function
    System.out.print("\n_____________________________________________________________________________________________________________");
    
   }
  
   
   //function to return the remark for this student based on percentage
   String remark()
   {
    String remarks = ""; //creating a string for storing remark
    
    float temp = percentage();   //calling percentage() function to get the percentage
    
    //computing the remark
    if(temp>=91.0 && temp<=100)
    {
     remarks = " CONGRATULATIONS...YOU SCORED VERY WELL...KEEP IT UP!!"; //storing the remark in remarks variable
    }
    else if(temp>=81.0 && temp<=90.0)
    {
     remarks = "KEEP IT UP!! YOU CAN DO BETTER..."; //storing the remarks in remark variable
    }
    else if(temp>=71.0 && temp<=80.0)
    {
     remarks = " NEED TO WORK MORE..."; //storing the remark in remarks variable
    }
    else if(temp>=61.0 && temp<=70.0)
    {
     remarks = " NEED TO WORK VERY HARD..."; //storing the remark in remarks variable
    }
    else if(temp>=51.0 && temp<=60.0)
    {
     remarks = " TAKE STUDIES SERIOUSLLY... WORK HARD "; //storing the remark in remarks variable
    }
    else if(temp>=35.0 && temp<=50.0)
    {
     remarks = " DISAPPOINTING PERFORMANCE :( "; //storing the remark in remarks variable
    }
    else if(temp < 35.0)
    {
     remarks = " YOU ARE FAILED :( "; //storing the remark in remarks variable
    }
    
    //RETURN THE remarks VARIABLE
    return remarks;
   }
   
   //FUNCTION TO CHECK WHETHER THE STUDENT IS FAILED IN ANY SUBJECT OR NOT
   void failed()
   {
       
      int flag=0;                         //FLAG TO INDICATE WHETHER FAILED OR NOT
      
      //LOOPING OVER  NUMBER OF SUBJECTS
      for(int i=0;i<nsub;i++)
      {
     //CALLING THE grade() FUNCTION TO COMPUTE THE GRADE FOR ith SUBJECT
    grade = grade(i);
    
    // IF THE GRADE IS F i.e. FAIL THEN SET THE FLAG TO 1
    if(grade.compareToIgnoreCase("F") == 0)       
    {
    flag=1;
    }
    
      }
      
      //CHECK IF FLAG IS SET THEN DISPLAY STUDENT AS FAILED
      if(flag == 1)
      {
      System.out.print("\nROLL NUMBER : "+rollno+ "      :  FAIL");
      
      }
      
    }

   
}