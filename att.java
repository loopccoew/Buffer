package p;
import java.lang.* ; 
import java.awt.event.*;
import javax.swing.*;
import javafx.scene.control.PasswordField;
import java.util.*;
class node      // Class node for entities of students
{
 node right,left;
 String name;
 int rollno;
 int attend;
}
class bst      // Class bst to implement Binary search tree
{
 node root;		// Root of the tree of type node
 node H[] = new node[50];
 node H1[] = new node[50];
String[] a = new String[10];
  int no;
  int cnt;
 bst() // default constructor 
 {
  root =null;
  no = 0;
  cnt=0;
 }
 
 void insert(String n,int r,int at)		// Function definition to insert students' deatils in a Binary search tree
 {
  node prev,ptr,cur;
  int flag=0;
  ptr=new node();
  ptr.name=n;
  ptr.rollno=r;
  ptr.attend=at;
  ptr.left=null;
  ptr.right=null;
  no++;
  cur=root;
  prev=cur;
  if(root==null)
  {
   root=ptr;
   H[no] = ptr;
  }
  else
  {
   while(flag!=1)
   {
    if(ptr.rollno<cur.rollno)
    {
     if(cur.left==null)
     {
      cur.left=ptr;
      H[no] = ptr;
      flag=1;
     }
     else
     {
      cur=cur.left;
     }
    }
    else if(ptr.rollno>cur.rollno)
    {
     if(cur.right==null)
     {
      cur.right=ptr;
      H[no] = ptr;
      flag=1;
     }
     else
     {
      cur=cur.right;
     }
    }
   }
  }
 
 }
 node search(String n,int r)// Function definition to search for a student and return it
 {
  node cur;
  cur=root;
  int flag=0;
  while(flag!=1)
  {
   if(cur.rollno>r)
   {
    cur=cur.left;
   }
   else if(cur.rollno<r)
   {
    cur=cur.right;
   }
   else if(cur.rollno==r)
   {
    flag=1;
   }
  }
  if(flag==1)
  {
   return cur;
  }
  else
  {
   return null;
  }
 }
 void inorder(node localroot)// Function Definition for Recursive Inorder Traversal
 {
  if(localroot!=null)
  {
   inorder(localroot.left);
   System.out.println(localroot.name+"\t"+localroot.rollno+"\t"+localroot.attend+"\n");
   inorder(localroot.right);
  }
 }
 node update(String nm,int r)// Function definition to update attendance of a student and return the updated value
 {
  node cur;
  cur=root;
  int flag=0;
  while(flag!=1)
  {
   if(cur.rollno>r)
   {
    cur=cur.left;
   }
   else if(cur.rollno<r)
   {
    cur=cur.right;
   }
   else if(cur.rollno==r)
   {
    flag=1;
   }
  }
  if(flag==1)
  {
   cur.attend=cur.attend+1;
   return cur;
  }
  else
  {
   return null;
  }
 }
 

void downadjustment(int i) // Function definition for down adjacement in heap
{
int smallest =i;
int l=2*i;
int r=2*i+1;
if(l<=no && H[l].attend<H[i].attend)
{
smallest = l;
}
if(r<=no && H[r].attend<H[smallest].attend)
{
smallest = r;
}
if(smallest != i )
{
node temp = H[i];
H[i]= H[smallest];
H[smallest]= temp;
downadjustment(smallest);
}
}

void BuildHeap()   // Function definition to build a heap
{
int i=0;
for(i=no/2;i>0;i--)
{
downadjustment(i);
}
for(int j=1;j<=no;j++)
{
H1[j]=H[j];
if(H1[j].attend<1)    //Minimum attendance is considered 1 here as a sample case but can be set to 75% of the complete attendance in practical case
{
delete();
}
}
}
 
void delete()  // Function Definition to delete entry of a particular student
{
if(H[2*1] == null && H[2*1+1] == null)
{
H[no]=null;
H1[no]=null;
a[cnt] = H[1].name;
cnt++;
}
else
{
a[cnt] = H[1].name;
cnt++;
H[1]=H[no];
H[no]=null;
no--;
downadjustment(1);
for(int i=1;i<=no;i++)
{
H1[i]=H[i];
}
}
}

void display()		 // Function Definition to display the DEFAULTER'S LIST
{
System.out.println("\n\t Students in defaulters list : ");
for(int i=0;i<cnt;i++)
{
System.out.println(a[i]);
}
}
}


class att implements ActionListener// Class for Graphics section
{
 JFrame f1;//  Frame
 JFrame f2;
 JFrame f3;
 JFrame f4;
 JFrame f5;
 JFrame f6 ; 
 JFrame f7 ; 
 JFrame f8 ; 
 JFrame f9 ; 
 JFrame f10 ; 
 JPasswordField pf1;// Password Field 
 JTextArea ta , ta1 , ta2  ;
 JPanel p1 ,p2,p3,p4,p5,p6,p7,p8, p9 , p10 ;
 JTextField t1,t2,t3,t4,t5,t6, t7;
 JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11 , b12 ;
 JLabel l1,l2,l3,l4,l5,l6 , l7 ;
 int x=1000;
 int code=0;
 att()
 {
  f1 = new JFrame("SELECT USER");
  f1.setBounds(50,50,450,450);
  f1.setLayout(null);
  f2= new JFrame("TEACHERS");
  f2.setBounds(50,50,450,450);
  f2.setLayout(null);
  f3= new JFrame("TEACHERS");
  f3.setBounds(50,50,450,450);
  f3.setLayout(null);
  f6= new JFrame("TEACHERS");
  f6.setBounds(50,50,450,450);
  f6.setLayout(null);
  f4= new JFrame("STUDENT");
  f4.setBounds(50,50,450,450);
  f4.setLayout(null);
  
  f5= new JFrame("STUDENT LIST");
  f5.setBounds(50,50,450,450);
  f5.setLayout(null);
  
  f7= new JFrame("STUDENT");
  f7.setBounds(50,50,450,450);
  f7.setLayout(null);
  
  f8= new JFrame("TEACHERS");
  f8.setBounds(50,50,450,450);
  f8.setLayout(null);
  
  f9= new JFrame("DEFAULTER LIST ");
  f9.setBounds(50,50,450,450);
  f9.setLayout(null);
  
  f10= new JFrame("DEFAULTER LIST ");
  f10.setBounds(50,50,450,450);
  f10.setLayout(null);
  
  p1 = (JPanel)f1.getContentPane();
  p1.setLayout(null);
  p1.setBounds(50,50,550,550);
  
  p2 = (JPanel)f2.getContentPane();
  p2.setLayout(null);
  p2.setBounds(50,50,550,550);
  
  p3 = (JPanel)f3.getContentPane();
  p3.setLayout(null);
  p3.setBounds(50,50,550,550);
  
  p4 = (JPanel)f4.getContentPane();
  p4.setLayout(null);
  p4.setBounds(50,50,550,550);
  
  p5 = (JPanel)f5.getContentPane();
  p5.setLayout(null);
  p5.setBounds(50,50,550,550);
  
  p6 = (JPanel)f6.getContentPane();
  p6.setLayout(null);
  p6.setBounds(50,50,550,550);
  
  p8 = (JPanel)f8.getContentPane();
  p8.setLayout(null);
  p8.setBounds(50,50,550,550);
  
  p7 = (JPanel)f7.getContentPane();
  p7.setLayout(null);
  p7.setBounds(50,50,550,550);
  
  p9 = (JPanel)f9.getContentPane();
  p9.setLayout(null);
  p9.setBounds(50,50,550,550);
  
  p10 = (JPanel)f10.getContentPane();
  p10.setLayout(null);
  p10.setBounds(50,50,550,550);
  
  b1=new JButton("TEACHERS");
  b1.setBounds(50, 150,100,100);
  b2=new JButton("STUDENT");
  b2.setBounds(300,150,100,100);
  b3=new JButton("LOG IN");
  b3.setBounds(50, 250, 100, 50);
  b4=new JButton("CANCEL");
  b4.setBounds(250, 250, 100, 50);
  b5=new JButton("SUBMIT");
  b5.setBounds(150, 350, 200, 50);
  b6=new JButton("GENERAT CODE");
  b6.setBounds(200, 50, 200, 50);
  b7=new JButton("LOG OUT");
  b7.setBounds(200, 350, 100, 50);
  b8=new JButton("MAKE DEFAULTER LIST");
  b8.setBounds(200,250,200, 50);
  
  b9=new JButton("GIVE ATTENDANCE ");
  b9.setBounds(200,100,150, 50);
  
  b10=new JButton("TAKE ATTENDANCE ");
  b10.setBounds(200,100,150, 50);
  
  b11=new JButton("SHOW DEFAULTER LIST ");
  b11.setBounds(200,250,200, 50);
  
  b12=new JButton("DISPLAY DEFAULTER LIST ");
  b12.setBounds(200,300,200, 50);
  
  b1.addActionListener(this);
  b2.addActionListener(this);
  b3.addActionListener(this);
  b4.addActionListener(this);
  b5.addActionListener(this);
  b6.addActionListener(this);
  b7.addActionListener(this);
  b8.addActionListener(this);
  b9.addActionListener(this);
  b10.addActionListener(this);
  b11.addActionListener(this);
  b12.addActionListener(this);

  
  
  l1=new JLabel("username");
  l1.setBounds(50, 50, 150, 50);
  
  l2=new JLabel("password");
  l2.setBounds(50, 150, 150, 50);
  
  l3=new JLabel("Name");
  l3.setBounds(50, 50, 150, 50);
  
  l4=new JLabel("Rollno");
  l4.setBounds(50, 150, 150, 50);
  
  l5=new JLabel("Enter code");
  l5.setBounds(50, 250, 150, 50);
  
  l6=new JLabel("CODE");
  l6.setBounds(50, 300, 150, 50);
  
  l7=new JLabel("Enter no of mendatory lectures for defaulters ");
  l7.setBounds(50, 50, 300, 50);
  
  t7=new JTextField(40);
  t7.setBounds(100, 100, 150, 50);
  
  t6=new JTextField(40);
  t6.setBounds(300,300,100,25);
  
  t4=new JTextField(40);
  t4.setBounds(300, 50, 150, 50);
  
 
  
  t5=new JTextField(40);
  t5.setBounds(200,150,200,50);
  t1=new JTextField(40);
  t1.setBounds(300, 50, 150, 50);
  t2=new JTextField(40);
  t2.setBounds(300, 150, 150, 50);
  t3=new JTextField(40);
  t3.setBounds(300, 250, 150, 50);
  pf1 = new JPasswordField();
  pf1.setBounds(300, 150, 150, 50);
  ta=new JTextArea();
  ta.setBounds(50, 50,400 , 400);
  
  ta=new JTextArea();
  ta.setBounds(50, 50,400 , 400);
 
  ta1=new JTextArea();
  ta1.setBounds(50, 50,400 , 400);
  
  ta2=new JTextArea();
  ta2.setBounds(50, 50,400 , 400);
  
  p1.add(b1);
  p1.add(b2);
  
 
  
  p2.add(b3);
  p2.add(b4);
  p2.add(l1);
  p2.add(l2);
  p2.add(t4);
  p2.add(pf1);
  
  p6.add(b10) ; 
  p6.add(b8) ; 
  p6.add(b7) ; 
  
  p3.add(b6);
  p3.add(b7);
  p3.add(t5);
  
  p7.add(b9) ; 
  p7.add(b11) ; 
  
  p4.add(b5);
  p4.add(l3);
  p4.add(l4);
  p4.add(l5);
  p4.add(t1);
  p4.add(t2);
  p4.add(t3);
  //p4.add(l6);
  //p4.add(t6);
  p8.add(l7) ; 
  p8.add(t7) ; 
  p8.add(b12) ; 
  
  p5.add(ta);
  p9.add(ta1) ;
  p10.add(ta2) ; 
  
  f1.setVisible(true);
 }
 public static void main(String args[])
 {
  
  new att();

 }
 int flag = 0 ;
 int h = 0 ; 
 node a[] = new node[10] ; 
 @SuppressWarnings("unlikely-arg-type")
 @Override
 public void actionPerformed(ActionEvent e) {
  // TODO Auto-generated method stub
  bst b =new bst();
  
  
  
  b.insert("samruddhi", 3,0);
  b.insert("vaibhavi",2 ,0);
  b.insert("sakshi", 1,0);
  b.insert("mayuri", 4,0);
  b.insert("sakshi", 5,0);
  b.insert("shruti",6,0);
  if(e.getSource()==b1)
  {
   f2.setVisible(true);
  }
  else if(e.getSource()==b2)
  {
   f7.setVisible(true);
   //f2.setVisible(true);
  }
  else if(e.getSource() == b9 )
  {
	  f4.setVisible(true);
  }
  else if(e.getSource()==b3)
  {
   int i=0;
   String user;
   char[] pass = null;
   user=t4.getText();
   String f = "faculty";
   pass=pf1.getPassword();
   char[] corpass= {'f','a','c','u','l','t','y'};
   for(int j=0;j<user.length();j++)
   {
    if(pass[j]==corpass[j])
    {
     i++;
    }
   }
   // System.out.println(""+i);
   if(user.equals(f)&&i==corpass.length)
   {
	   
	   //f3.setVisible(true);
	   f6.setVisible(true);
	   /*
	   if(e.getSource()==b10)
	   {
		   f3.setVisible(true);
	   }
	   */
   }
   else
   {
    JOptionPane.showMessageDialog(null,"invalid username or password");
   }
  }
  else if(e.getSource() == b10 )
  {
	  f3.setVisible(true);
  }
  else if(e.getSource() == b8 )
  {
	   f8.setVisible(true);
	   
  }
  else if(e.getSource()==b4)
  {
   f1.setVisible(true);
  }
  else if(e.getSource()==b5)
  {
   int i=0;
   node cur;
   String nm=t1.getText();
   int rn=Integer.parseInt(t2.getText());
   String co=t3.getText();
   cur=b.update(nm, rn);
   //System.out.println(nm+rn);
   if(cur!=null&&co.equals(t5.getText()))
   {
    f5.setVisible(true);
    node ptr;
    ta.append("\t"+"Name"+"\t"+"Rollno"+"\t"+"Attendence");
    Stack<node> s=new Stack<node>();
    //node ptr;
    ptr=b.root;
    do
    {
     while(ptr!=null)
     {
      s.push(ptr);
      ptr=ptr.left;
     }
     ptr=s.pop();
     //System.out.println(ptr.data+" ");
     ta.append("\n\t"+ptr.name+"\t"+ptr.rollno+"\t"+ptr.attend);
     System.out.println("\n\t"+ptr.name+"\t"+ptr.rollno+"\t"+ptr.attend);
     ptr=ptr.right;
    }while(s.empty()==false || ptr!=null);
   }
   else
   {
    JOptionPane.showMessageDialog(null,"roll number or code is invalid");
   }
b.BuildHeap();
b.display();
  }
  else if(e.getSource()==b6)
  {
   code=(int) (Math.random()*1000);
   t5.setText(""+code);
  }
  else if(e.getSource()==b7)
  {
   f2.setVisible(true);
  }
  else if(e.getSource()==b8)
  {
   f5.setVisible(true);

  }
  else if(e.getSource() == b11 )
  {
	  f10.setVisible(true);
	  if(h==0 )
	  {
		  ta2.append("list is not displayed yet " );
	  }
	  else
	  {
	  for(int  i = 0 ; i<a.length ; i++ )
	  {
		  ta2.append("ROLL NO " + a[i].rollno + a[i].name + "\n");
	  }
	  }
  }
  else if(e.getSource() == b12 )
  {
	  f8.setVisible(false);
	  f9.setVisible(true);
	   String x = t7.getText() ; 
	   int xn = Integer.parseInt(t7.getText()) ; 
	   
	   
	   ta1.append("DEFAULTER LIST DISPLAYED ");
	   node ptr;
	    Stack<node> s=new Stack<node>();
	    //node ptr;
	    ptr=b.root;
	    ta1.append("DEFAULTER LIST " + "\n");
	    do
	    {
	     while(ptr!=null)
	     {
	      s.push(ptr);
	      ptr=ptr.left;
	     }
	     ptr=s.pop();
	     //System.out.println(ptr.data+" ");
	     if(ptr.attend < xn )
	     {
	    	 a[h] = new node() ; 
	    	 a[h] = ptr ; 
	    	 
	    	 ta1.append("ROLL NO " + ptr.rollno + ptr.name + "\n") ; 
	    	 h++ ; 
	    	 flag = 1 ;
	     }
	     ptr=ptr.right;
	    }while(s.empty()==false || ptr!=null);
	    if(flag == 0 )
	    {
	    	ta1.append("NO DEFAULTERS ");
	    }
  }
 }
}


