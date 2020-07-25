package LoopProject;
import java.util.*;
import java.io.*;

//DRIVER CLASS
public class driver_class
{
public static void main(String[] args) {
// TODO Auto-generated method stub
admin a = new admin();             //CREATING THE OBJECT
a.create();                       //CALLING THE CREATE FUNCTION


int ch=0;                       //INITIALIZING THE VARIABLE

 Scanner scan = new Scanner(System.in);

do
{
//DISPLAYING THE MENU
 System.out.print("\n\n\t******************* MENU ************************");
 System.out.print("\n\t\t 1.  ADMIN ");
 System.out.print("\n\t\t 2.  STUDENT. ");
 System.out.print("\n\t\t 3.  EXIT");
 System.out.print("\n\t\t ENTER YOUR CHOICE : ");
 ch = scan.nextInt();
 System.out.print("\n ");
    switch(ch)               //SWITCH CASE
    {
     case 1:
       int ch1=0;
       do
       {
       //DISPLAYING MENU FOR ADMIN
          System.out.print("\n\n\t\t***************** MENU ******************");
          System.out.print("\n\t\t\t 1. INSERT A STUDENT RECORD. ");
          System.out.print("\n\t\t\t 2. DELETE A STUDENT RECORD . ");
          System.out.print("\n\t\t\t 3. UPDATE RECORD OF STUDENT  ");
          System.out.print("\n\t\t\t 4. DISPLAY FAILED STUDENT LIST . ");
          System.out.print("\n\t\t\t 5.  EXIT");
          System.out.print("\n\t\t\t ENTER YOUR CHOICE : ");
          ch1 = scan.nextInt();
          System.out.print("\n ");
          switch(ch1)
          {
           case 1:
            a.insert();   //CALLING THE INSERT FUNCTION
            break; //BREAKING THE SWITCH CASE
            
           case 2:
            a.delete();   //CALLING THE INSERT FUNCTION
            break;
            
           case 3:
            a.update(); //CALLING THE INSERT FUNCTION
            break;
            
           case 4:
            a.failed_list();   //CALLING THE INSERT FUNCTION
            break;
            
           case 5:
            break;
            
      default:                //DEFAULT CASE FOR INVALID INPUT
       System.out.print("\n INVALID INPUT ...");
          }
          
       }while(ch1 != 5);          // VALIDATING THE WHILE CONDITION
       break;
       
     case 2:
          ch1 = 0;
       do
       {
       //PRINTING MENU FOR STUDENT
        System.out.print("\n\n\t\t************* MENU **************");
          System.out.print("\n\t\t\t 1. PRINT REPORT CARD . ");
          System.out.print("\n\t\t\t 2. EXIT. ");
          System.out.print("\n\t\t\t ENTER YOUR CHOICE ");
          ch1 = scan.nextInt();
          System.out.print("\n ");
          switch(ch1)      //SWITCH CASE 
          {
           case 1:
             a.report_card(); //CALLING report_card() function
             break;
              
           case 2:
                break;
                
           default:               //DEFAULT CASE FOR INVALID INPUT
             System.out.print("\n INVALID INPUT ...");    
               
          }
       }while(ch1 != 2);    //VALIDATING THE WHILE CONDITION
       break;
       
      case 3:
      break;
      
      default:               //DEFAULT CASE FOR INVALID INPUT
             System.out.print("\n INVALID INPUT ...");
      
    } 
 
}while(ch != 3);     //VALIDATING THE WHILE CONDITION
}
}

