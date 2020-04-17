
/*
*************PROJECT : CAFETERIA MANAGEMENT SYSTEM ***********************

    OBJECTIVE          : TO DESIGN A C++ PROGRAM TO MANAGE CAFETERIA SYSTEM USING APPROPRIATE DATA STRUCTURE

    FEATURES           : 1. STOCK MANAGEMENT
                         2. ACCOUNTING
                         3. CUSTOMER MANAGEMENT
                         4. TO STORE RECORDS OF ORDERED FOOD
                         5. BILLINGS
                         6. TO GIVE OFFER ON BILL

    DATA STRUCTURE     : DOUBLY LINKED LIST

    ALGORITMS          : DOUBLY LINKED LIST ALGORITMS

    TEAM MEMBER        : 1. PRATIKSHA LOKHANDE
                             ROLL NO. : 2354

                         2. MAHIMA MALAKWADE
                             ROLL NO. : 2356

                         3. DIPASHRI NAOLE
                             ROLL NO. : 2362

    CONTRIBUTION       : WE HAD EQUALLY DIVIDED ALL THE TASKS AMONG ALL THE TEAM MEMBERS.
                         SO , EVERYONE HAS CONTRIBUTED EQUALLY .
                         TASKS :
                                1. STRUCTURE OF THE PROJECT
                                2. WRITING & UNDERSTANDING FUNCTIONS
                                3. IMPLEMENTING THE FUNCTIONS
                                4. INPUT VALIDATIONS

    TASK ACCOMPLISHED   : IMPLEMENTS ALL THE FEATURES OF THE PROJECT.
    BY CAFETERIA.CPP
*/


//HEADER FILES
#include <iostream>
using namespace std;
#include <stdio.h>
#include <iomanip>

//NODE CLASS : ITEM
class item_node
{
	friend class item_list ;
	friend class p_list ;
	friend class p_node ;

	//INSTANCE VARIABLES
	int item_num ;
	string item_name ;
	double price ;
	float available_qty ;
	float sold_qty ;
	item_node *prev ;
	item_node *next ;

	public :
			//CONSTRUCTOR
			item_node() ;

			//MEMBER FUNCTIONS
			void accept_item(item_node *head) ;
			void display_item() ;
};

//LIST CLASS : ITEM
class item_list
{
	//INSTANCE VARIABLES
	int ns;
	int nd ;
	item_node *head ;

	friend class p_list ;
	friend class item_node ;
	friend class p_node ;


	public :
			//CONSTRUCTOR
			item_list() ;

			//MEMBER FUNCTIONS
			void create_menu() ;
			void display_menu() ;
			void display_admin() ;
			void insert_snacks() ;
			void pos_snacks() ;
			void insert_drinks() ;
			void pos_drinks() ;
			void delete_item() ;
			void update() ;
			item_node* search(int fitem_num) ;

};

//CONSTRUCTOR DEFINITION
item_node :: item_node()
{
	item_num = 0 ;
	item_name = "" ;
	price = 0.0 ;
	available_qty = 0.0f ;
	sold_qty = 0.0f ;
	prev = NULL ;
	next = NULL ;

}


//METHOD TO ACCEPT ITEM DETAILS
void item_node :: accept_item(item_node *head)
{
	//LOCAL VARIABLE
	int flag = 0 , temp = 0;
	item_node *ptr = new item_node() ;

	//VALIDATION FOR ITEM NUMBER
	do
	{
		flag = 0 , temp = 0;

		cout<<"\n\tENTER ITEM NUMBER : " ;
		cin>>item_num ;

		if(item_num<=0 || item_num>9999)
		{
			flag = 1 ;
			if(item_num<=0)
			{
				cout<<"\n\tINVALID ITEM NUMBER.\n\tITEM NUMBER CAN'T BE NEGATIVE OR ZERO.\n\tPLEASE RE-ENTER CORRECT ITEM NUMBER." ;
			}
			else
			{
				cout<<"\n\tINVALID ITEM NUMBER.\n\tMAXIMUM NUMBER OF DIGITS IN ITEM NUMBER CAN'T BE MORE THAN 4. \n\tPLEASE RE-ENTER CORRECT ITEM NUMBER." ;
			}
		}

		if(flag == 0)
		{
			if(head==NULL)
			{
				temp = 0 ;
			}
			else
			{
				ptr = head ; //INITIALIZATION
				while(ptr!=NULL) //LOOP TILL THE END OF LIST
				{
					if(ptr->item_num!=item_num)
					{
						temp = 0 ;
						ptr = ptr->next ; //INCREMENTATION
					}
					else
					{
						cout<<"\n\tITEM NUMBER ALREADY EXIST.\n\tPLEASE RE-ENTER UNIQUE ITEM NUMBER."<<endl  ;
						temp = 1 ;
						break ;
					}
				}
			}
		}

	}while(flag==1 || temp==1) ;

	//VALIDATION FOR NAME OF ITEM
	do
	{
		cout<<"\n\tENTER NAME OF ITEM : " ;
		scanf("\t") ;
		getline(cin,item_name) ;

		int l = item_name.length() ;
		for(int i=0 ;i<l ;i++)
		{
			//CHECKS IF NAME CONTAINS ONLY ALPHABETS AND SPACES
			if(isalpha(item_name[i]) || isspace(item_name[i]))
			{
				flag = 0 ;
			}
			else
			{
				flag = 1 ;
				cout<<"\n\tINVALID NAME.\n\tNUMERIC AND SPECIAL CHARACTERS ARE NOT ALLOWED IN NAME.\n\tPLEASE RE-ENTER CORRECT NAME. " ;
				break ;
			}
		}

	}while(flag==1) ;

	//VALIDATION FOR PRICE OF ITEM
	do
	{
		cout<<"\n\tENTER PRICE OF ITEM :" ;
		cin>>price ;

		if(price<=0)
		{
			flag = 1 ;
			cout<<"\n\tINVALID ITEM PRICE.\n\tPRICE CAN'T BE NEGATIVE OR ZERO.\n\tPLEASE RE-ENTER CORRECT PRICE." ;
		}
		else
		{
			flag = 0 ;
		}

	}while(flag==1) ;

	//VALIDATION FOR QUANTITY OF ITEM
	do
	{
		cout<<"\n\tENTER AVAILABLE QUANTITY OF ITEM :" ;
		cin>>available_qty ;

		if(available_qty<0)
		{
			flag = 1 ;
			cout<<"\n\tINVALID QUANTITY.\n\tQUANTITY CAN'T BE NEGATIVE.\n\tPLEASE RE-ENTER CORRECT QUANTITY." ;
		}
		else
		{
			flag = 0 ;
		}

	}while(flag==1) ;

	cout<<"\n\t________________________________________________________________________________________________________________________________" ;
}

//METHOD TO DISPLAY ITEM DETAILS
void item_node :: display_item()
{
	cout<<"\n\n\t||****ITEM DETAILS*****||" ;
	cout<<"\n\n\tITEM NUMBER      : "<<item_num ;
	cout<<"\n\tITEM NAME          : "<<item_name ;
	cout<<"\n\tPRICE              : RS."<<price<<" /-" ;
	cout<<"\n\tAVAILABLE QUANTITY : "<<available_qty<<endl<<endl ;

}

//METHOD TO DISPLAY MENU LIST FOR ADMIN
void item_list ::display_admin()
{
	//LOCAL VARIABLES
	int g = 1 ;
	int flag = 0 ;
	cout<<"\n\n" ;

	item_node *ptr = new item_node() ;
	ptr = head ;

	cout<<"\n"<<setw(60)<<"****SNACKS****" ;
	cout<<"\n\t_______________________________________________________________________________________________________________________________________________" ;
	cout<<"\n\n\t"<<setw(10)<<"ITEM NO."<<setw(30)<<"ITEM NAME"<<setw(10)<<"PRICE"<<setw(10)<<"QUANTITY" ;
	cout<<"\n\t_______________________________________________________________________________________________________________________________________________" ;

	cout<<"\n\n" ;

	while(ptr!=NULL)
	{
		g++ ;
		cout<<"\t"<<setw(10)<<ptr->item_num<<setw(30)<<ptr->item_name<<setw(10)<<ptr->price<<setw(10)<<ptr->available_qty<<endl ;
		ptr = ptr->next ;

		if(g > ns && flag ==0)
		{
			flag = 1 ;
			cout<<"\n\n"<<setw(60)<<"****DRINKS & BEVERAGES****" ;
			cout<<"\n\n\t_______________________________________________________________________________________________________________________________________" ;
			cout<<"\n\n\t"<<setw(10)<<"ITEM NO."<<setw(30)<<"ITEM NAME"<<setw(10)<<"PRICE"<<setw(10)<<"QUANTITY" ;
			cout<<"\n\t_______________________________________________________________________________________________________________________________________" ;
			cout<<"\n\n" ;

		}
	}

}

//CONSTRUCTOR DEFINITION
item_list :: item_list()
{
	head = NULL ;
	ns = 0 ;
	nd = 0 ;
}

//METHODE TO CREATE MENU
void item_list :: create_menu()
{
	int count = 0 ;
	int t = 0 ;
	int i = 0 ;

	//VALIDATION FOR NUMBER OF SNACKS
	do
	{
		cout<<"\n\tHOW MANY NUMBER OF SNACKS ?\n\t" ;
		cin>>ns ;

		if(ns < 0)
		{
			cout<<"\n\tINVALID NUMBER OF SNACKS." ;
			cout<<"\n\tNUMBER OF SNACKS CAN'T BE NEGATIVE" ;
			cout<<"\n\tPLEASE REENTER CORRECT NUMBER OF SNACKS.";
		}

		if(ns > 150)
		{
			cout<<"\n\tINVALID NUMBER OF SNACKS.";
			cout<<"\n\tMAXIMUM NUMBER OF SNACKS CAN'T BE MORE THAN 150" ;
			cout<<"\n\tPLEASE REENTER CORRECT NUMBER OF SNACKS " ;
		}

	}while((ns<0) || (ns>150)) ;


	//VALIDATION FOR NUMBER OF DRINKS AND BEVERAGES
	do
	{
		cout<<"\n\tHOW MANY NUMBER OF DRINKS ?\n\t" ;
		cin>>nd ;

		if(nd < 0)
		{
			cout<<"\n\tINVALID NUMBER OF DRINKS." ;
			cout<<"\n\tNUMBER OF DRINKS CAN'T BE NEGATIVE" ;
			cout<<"\n\tPLEASE REENTER CORRECT NUMBER OF DRINKS.";
		}

		if(nd > 150)
		{
			cout<<"\n\tINVALID NUMBER OF DRINKS.";
			cout<<"\n\tMAXIMUM NUMBER OF DRINKS CAN'T BE MORE THAN 150" ;
			cout<<"\n\tPLEASE REENTER CORRECT NUMBER OF DRINKS " ;
		}


	}while((nd < 0) || (nd > 150)) ;

	for(count = 1 ; count<=2 ; count++ )
	{
		if(count == 1)
		{
			t = ns ;
			cout<<"\n\n\t\t\t-----ENTER SNACKS DETAILS------ " ;
		}
		else
		{
			t = nd ;
			cout<<"\n\n\t\t\t-----ENTER DRINKS AND BEVERAGES DETAILS------ " ;
		}

		for(i = 1 ; i<=t ; i++)
		{
			item_node *temp = new item_node() ;
			temp->accept_item(head) ;

			if(head == NULL)
			{
				head = temp ;
			}
			else
			{
				item_node *ptr = new item_node() ;
				ptr = head ;

				while(ptr->next != NULL)
				{
					ptr = ptr->next ;
				}
				temp->prev = ptr ;
				ptr->next = temp ;
			}
		}
	}
}

//METHODE TO DISPLAY MENU CARD TO CUSTOMER
void item_list :: display_menu()
{
	//INSTANCE VARIABLES
	int g = 1 ;//TEMPORARY VARIABLE
	int flag = 0 ;

	cout<<"\n\t....................................................................................................................................." ;
	cout<<"\n"<<setw(60)<<"||******HALDIRAM'S FOOD PLANET******||"<<endl ;
	cout<<"\n\n" ;

	item_node *ptr = new item_node() ;
	ptr = head ;
	cout<<"\n"<<setw(60)<<"****SNACKS****" ;
	cout<<"\n\n\t_______________________________________________________________________________________________________________________________________" ;
	cout<<"\n\n\t"<<setw(10)<<"ITEM NO."<<setw(30)<<"ITEM NAME"<<setw(10)<<"PRICE" ;
	cout<<"\n\t_______________________________________________________________________________________________________________________________________" ;
	cout<<"\n\n" ;

	while(ptr!=NULL)
	{
		cout<<"\t"<<setw(10)<<ptr->item_num<<setw(30)<<ptr->item_name<<setw(10)<<ptr->price<<endl ;
		ptr = ptr->next ;
		g++ ;

		if((g) > ns && flag == 0)
		{
			flag = 1 ;
			cout<<"\n\n"<<setw(60)<<"****DRINKS & BEVERAGES****" ;
			cout<<"\n\n\t_______________________________________________________________________________________________________________________________________" ;
			cout<<"\n\n\t"<<setw(10)<<"ITEM NO."<<setw(30)<<"ITEM NAME"<<setw(10)<<"PRICE" ;
			cout<<"\n\t_______________________________________________________________________________________________________________________________________" ;
			cout<<"\n\n" ;

		}
	}

	cout<<"\n\t........................................................................................................................................." ;

}

//METHODE TO INSERT SNACKS AT 1ST POS
void item_list :: insert_snacks()
{
	item_node *temp = new item_node() ;
	temp->accept_item(head) ;

	if(head == NULL)
	{
		head = temp ;
		ns++ ;
		cout<<"\n\tINSERTED SUCCESFULLY." ;

	}
	else
	{
		temp->next = head ;
		head->prev = temp ;
		head = temp ;
		ns++ ;
		cout<<"\n\tINSERTED SUCCESFULLY." ;

	}
}

//METHODE TO INSERT DRINKS AT LAST POS
void item_list :: insert_drinks()
{
	item_node *temp = new item_node() ;
	temp->accept_item(head) ;

	item_node *ptr = NULL ;

	if(head == NULL)
	{
		head = temp ;
		nd++ ;
		cout<<"\n\tINSERTED SUCCESFULLY." ;

	}
	else
	{
		ptr = head ;
		while(ptr->next != NULL)
		{
			ptr = ptr->next ;
		}
		ptr->next = temp ;
		temp->prev = ptr ;
		nd++ ;
		cout<<"\n\tINSERTED SUCCESFULLY." ;

	}

}

//METHODE TO INSERT SNACKS AT ANY POS
void item_list :: pos_snacks()
{

	int pos = 0 ;

	cout<<"\n\tENTER POSITION AT WHICH YOU HAVE TO INSERT SNACK :" ;
	cin>>pos ;

	//VALIDATION FOR POSITION
	if((pos >(ns+1)) || (pos <= 0))
	{
		cout<<"\n\tPLEASE TRY AGAIN LATER" ;

		if(pos <= 0)
		{
			cout<<"\n\tPOSITION CAN'T BE ZERO OR NEGATIVE" ;
		}

		if(pos >(ns+1))
		{
			cout<<"\n\tPOSITION CAN BE BETWEEN 1 TO "<<(ns + 1) ;
		}
	}

	else
	{
		if(pos == 1)
		{
			insert_snacks() ;
		}

		else
		{
			item_node *temp = new item_node() ;
			temp->accept_item(head) ;

			item_node *ptr = new item_node() ;

			ptr = head ;
			int i = 1 ;

			while(i<pos-1)
			{
				ptr = ptr->next ;
				i++ ;
			}

			temp->next = ptr->next ;
			temp->prev = ptr ;
			(temp->next )->prev = temp ;
			ptr->next = temp ;
			ns++ ;

			cout<<"\n\tGIVEN SNACK INSERTED SUCCESSFULLY" ;

		}
	}
}

//METHODE TO INSERT DRINKS AT ANY POS
void item_list :: pos_drinks()
{

	int pos= 0;

	cout<<"\n\tENTER POSITION AT WHICH YOU HAVE TO INSERT DRINK :" ;
	cin>>pos ;

	//VALIDATION FOR POSITION
	if((pos >(nd +1)) || (pos<=0))
	{
		cout<<"\n\tPLEASE TRY AGAIN LATER" ;

		if(pos <= 0)
		{
			cout<<"\n\tPOSITION CAN'T BE ZERO OR NEGATIVE" ;
		}

		if(pos >(nd+1))
		{
			cout<<"\n\tPOSITION CAN BE BETWEEN 1 TO "<<(nd + 1) ;
		}

	}

	else
	{
		pos = pos + ns ;
		if(pos == (ns + nd +1))
		{
			insert_drinks() ;
		}

		else
		{
			item_node *temp = new item_node() ;
			item_node *ptr = new item_node() ;

			temp->accept_item(head) ;

			ptr = head ;
			int i =1 ;

			while(i<pos-1)
			{
				ptr = ptr->next ;
				i++;
			}

			temp->next = ptr->next ;
			temp->prev = ptr ;
			(temp->next )->prev = temp ;
			ptr->next = temp ;
			nd++ ;

			cout<<"\n\tGIVEN DRINK INSERTED SUCCESSFULLY" ;


		}
	}
}

//METHODE TO DELETE
void item_list :: delete_item()
{
	int d_item_num = 0 ;
	int count = 0 ;
	item_node *ptr = NULL ;
	item_node *res = new item_node() ;

	//VALIDATION FOR ITEM NUMBER
	do
	{
		cout<<"\n\tENTER ITEM NUMBER TO BE DELETED. " ;
		cin>>d_item_num ;

		if(d_item_num <= 0)
		{
			cout<<"\n\tINVALID ITEM NUMBER ." ;
			cout<<"\n\tITEM NUMBER CAN'T BE NEGATIVE OR ZERO" ;
			cout<<"\\n\tPLEASE REENTER CORRECT ITEM NUMBER .";
		}

	}while(d_item_num < 0) ;

	res = search(d_item_num) ;

	if(res == NULL)
	{
		cout<<"\n\tPLEASE TRY AGAIN LATER" ;
	}

	else
	{
		//First Node
		if(head == res)
		{
			head = head ->next ;
			head -> prev = NULL ;
			delete res ;
			cout<<"\n\tITEM DETAILS DELETED SUCCESSFULLY" ;

			if(ns > 1)
			{
				ns-- ;
			}

			else
			{
				nd-- ;
			}

		}
		else
		{
			ptr = head ;

			while((ptr->next != NULL) && (ptr != res))
			{
				count++ ;
				ptr = ptr->next ;
			}

			//last node
			if(res->next == NULL)
			{
				if((count+1) <= ns)
				{
					ns-- ;
				}

				else if(((count+1) > ns) && (nd != 0))
				{
					nd-- ;
				}

				(res->prev)->next = NULL ;
				delete res ;
				cout<<"\n\tITEM DETAILS DELETED SUCCESSFULLY" ;
			}

			//any other node
			else
			{
				if(count <= ns)
				{
					ns-- ;
				}

				else if((count > ns) && (nd != 0))
				{
					nd-- ;
				}

				(res->prev)->next = (res->next) ;
				(res->next)->prev = (res->prev) ;
				delete res ;
				cout<<"\n\tITEM DETAILS DELETED SUCCESSFULLY" ;
			}

		}


	}

}

//METHODE TO SEARCH

item_node* item_list :: search(int fitem_num)
{
	int flag = 0 ;
	item_node *ptr = new item_node() ;

	if(head==NULL)
	{
		cout<<"\n\tLIST IS EMPTY." ;
		return NULL ;
	}

	else
	{
		ptr = head ;
		while(ptr->next!=NULL)
		{
			if(ptr->item_num == fitem_num)
			{
				flag = 1 ;
				cout<<"\n\tITEM DETAILS FOUND. " ;
				ptr->display_item() ;
				return ptr ;
			}

			else
			{
				ptr = ptr->next ;
			}
		}
	}

	if(ptr->item_num==fitem_num)
	{
		flag = 1 ;
		cout<<"\n\tITEM DETAILS FOUND. " ;
		ptr->display_item() ;
		return ptr ;
	}

	if(flag == 0)
	{
		cout<<"\n\tINCORRECT ITEM NUMBER. " ;
		return NULL ;
	}

	return NULL ;


}

//METHODE TO UPDATE PRICE & QUANTITY
void item_list :: update()
{
	int flag =0;
	int up;
	int ch =0;
	item_node *ptr = new item_node();

	//VALIDATION FOR ITEM NUMBER
	do
	{
		cout<<"\n\tENTER ITEM NUMBER TO BE UPDATED: ";
		cin>>up;

		if(up <= 0)
		{
			cout<<"\n\tINVALID ITEM NUMBER ." ;
			cout<<"\n\tITEM NUMBER CAN'T BE NEGATIVE OR ZERO" ;
			cout<<"\\n\tPLEASE REENTER CORRECT ITEM NUMBER .";
		}

	}while(up <= 0) ;

	ptr = search(up);

	if(ptr != NULL )
	{
		flag=1;
		cout<<"\n\t1. UPDATE QUANTITY " ;
		cout<<"\n\t2. UPDATE PRICE " ;

		cout<<"\n\tENTER YOUR CHOICE : " ;
		cin>>ch;

		if(ch==1)
		{
			cout<<"\n\tENTER NEW QUANTITY : " ;
			cin>>ptr->available_qty;
		}

		else if(ch==2)
		{
			cout<<"\n\tENTER NEW PRICE : RS." ;
			cin>>ptr->price;
		}

		else
		{
			cout<<"\n\tINVALID INPUT. "<<endl;
		}

		ptr->display_item();
	}

	if(flag==0)
	{
		cout<<"\n\tTRY AGAIN LATER."<<endl;
	}
}

//CLASS NODE : PURCHASE
class p_node
{
	friend class p_list ;
	friend class item_list ;
	friend class item_node ;

	//INSTANCE VARIABLES
	int no ;
	float quant ;
	string name ;
	double rate ;
	p_node *next1 ;
	p_node *prev1 ;

	public :
		//CONSTRUCTOR
		p_node() ;

};

//CONSTRUCTOR DEFINITION
p_node ::p_node()
{

	no = 0 ;
	quant = 0.0f ;
	name = "" ;
	rate = 0.0 ;
	next1 = NULL ;
	prev1 = NULL ;


}

//CLASS LIST : PURCHASE
class p_list
{

	friend class p_node ;
	friend class item_list ;
	friend class item_node ;

	//INSTANCE VARIABLES
	double amount ;
	int discount ;
	p_node *head1 ;

public:
	double total ;

	//CONSTRUCTOR
	p_list() ;

	//MEMBER FUNCTIONS
	void add(int item_no, item_list l) ;
	void bill() ;
	void highest_sold_item() ;
	void add_offer() ;
	double offer(double ftotal) ;
};

//CONSTRUCTOR DEFINITION
p_list ::p_list()
{
	total =0.0 ;
	head1 = NULL ;
	amount = 0.0 ;
	discount = 0 ;
}

//METHODE TO ADD OFFER
void p_list :: add_offer()
{
	//VALIDATION FOR AMOUNT
	do
	{
		cout<<"\n\t ENTER THE AMOUNT ON WHICH YOU WANT TO GIVE DISCOUNT ";
		cin>>amount;

		if(amount < 0)
		{
			cout<<"\n\tINVALID AMOUNT ." ;
			cout<<"\n\tAMOUNT CAN'T BE NEGATIVE " ;
			cout<<"\n\tPLEASE REENTER CORRECT AMOUNT.";
		}


	}while(amount < 0) ;

	//VALIDATION FOR DISCOUNT
	do
	{
		cout<<"\n\t ENTER THE DISCOUNT TO BE GIVEN ";
		cin>>discount;

		if(discount < 0)
		{
			cout<<"\n\tINVALID DISCOUNT ." ;
			cout<<"\n\tDISCOUNT CAN'T BE NEGATIVE " ;
			cout<<"\n\tPLEASE REENTER CORRECT DISCOUNT.";
		}

		if(discount > 20)
		{
			cout<<"\n\tINVALID DISCOUNT ." ;
			cout<<"\n\tMAXIMUM LIMIT ON DISCOUNT IS 20 % " ;
			cout<<"\n\tPLEASE REENTER CORRECT DISCOUNT.";
		}

	}while((discount < 0) ||(discount > 20) ) ;

}

//METHODE TO CALCULATE DISCOUNTED TOTAL
double p_list :: offer(double ftotal)
{
	if(ftotal >= amount && (amount>0))
	{
		cout<<"\n\tCONGRATULATION !!!!!! YOU GOT A DISCOUNT OF "<<discount<< "%" ;
		double temp1 ;
		temp1 = (discount *ftotal)/100 ;

		ftotal = ftotal - temp1 ;

		cout<<"\n"<<setw(80)<<"TOTAL = Rs. "<<ftotal;
	}

	return ftotal ;
}

//METHODE TO GENERATE & DISPLAY BILL
void p_list ::bill()
{
	p_node *ptr = new p_node() ;
	double ftotal = 0.0 ;
	ptr = head1 ;
	int sr = 1;



	cout<<"\n\n\t********************************************************************************************************************";
	cout<<"\n\n"<<setw(60)<<"||******HALDIRAM'S FOOD PLANET******||"<<endl ;
	cout<<"\n\n\t"<<setw(7)<<"SR. NO"<<setw(10)<<"ITEM NO."<<setw(30)<<"ITEM NAME"<<setw(10)<<"QUANTITY"<<setw(10)<<"PRICE"<<endl ;
	cout<<"\n\t----------------------------------------------------------------------------------------------------------------------" ;

	while(ptr != NULL)
	{
		cout<<"\n\t"<<setw(7)<<sr<<setw(10)<<ptr->no<<setw(30)<<ptr->name<<setw(10)<<ptr->quant<<setw(10)<<ptr->rate<<endl ;
		ftotal = ftotal+ (ptr->rate *ptr->quant) ;
		sr++ ;
		ptr = ptr->next1 ;

	}

	cout<<"\n\t----------------------------------------------------------------------------------------------------------------------" ;

	cout<<"\n"<<setw(80)<<"TOTAL = Rs."<<ftotal<<endl ;

	ftotal = offer(ftotal ) ;
	total = total + ftotal ;

	cout<<"\n\n\tTHANKS FOR VISITING. THANKS FOR VISITING. THANKS FOR VISITING. THANKS FOR VISITING ." ;
	cout<<"\n\n\t********************************************************************************************************************";

	head1 = NULL ;

}

//METHODE TO PLACE ORDER
void p_list::add(int item_no,item_list l)
{

	item_node *res = new item_node() ;

	res = l.search(item_no) ;

	if(res == NULL)
	{
		cout<<"\n\tTRY AGAIN LATER" ;
	}

	else
	{
		p_node *temp= new p_node() ;
		cout<<"\n\tENTER QUANTITY YOU WANT TO ORDER :" ;
		cin>>temp->quant ;

		if(temp->quant > res->available_qty)
		{
			cout<<"\n\tNOT AVAILABLE" ;
		}

		else if(temp->quant < 0)
		{
			cout<<"\n\tINVALID INPUT " ;

		}

		else if(res->available_qty == 0)
		{
			cout<<"\n\tITEM NOT AVAILABLE .SORRY FOR INCONVINENCE" ;
		}

		else
		{
			temp->rate = res->price ;
			temp->name = res ->item_name ;
			temp->no = res->item_num ;
			res->sold_qty = res->sold_qty + temp->quant ;
			res->available_qty = res->available_qty - temp->quant ;

			if(head1 == NULL)
			{
				head1 = temp ;
			}

			else
			{
				p_node *ptr = new p_node() ;
				ptr = head1 ;

				while(ptr->next1 != NULL)
				{
					ptr = ptr-> next1 ;
				}

				ptr->next1 = temp ;
			}

 		}
	}
}

//DRIVER CODE
int main()
{
	//LOCAL VARIABLES
	int ch = 0 ;
	int ch1 = 0 ;
	int ch2 = 0 ;
	int ch3 = 0;
	int item_no = 0;

	//OBJECTS
	item_list l ;
	p_list p ;

	l.create_menu() ; //CALLING create_menu()

	do
	{
		//DISPLAY MENU
		cout<<"\n\tMENU :" ;
		cout<<"\n\t\t1.SWITCH TO ADMINISTRATOR" ;
		cout<<"\n\t\t2.DISPLAY MENU CARD" ;
		cout<<"\n\t\t3.EXIT" ;
		cout<<"\n\n\tENTER YOUR CHOICE :" ;
		cin>>ch ;

		switch(ch)
		{
		case 1 :
				do
				{
					//DISPLAY MENU FOR ADMIN
					cout<<"\n\t\tMENU :" ;
					cout<<"\n\t\t\t1.INSERT SNACKS" ;
					cout<<"\n\t\t\t2.INSERT DRINKS " ;
					cout<<"\n\t\t\t3.DELETE" ;
					cout<<"\n\t\t\t4.UPDATE" ;
					cout<<"\n\t\t\t5.DISPLAY LIST OF ITEMS" ;
					cout<<"\n\t\t\t6.TOTAL EARNINGS" ;
					cout<<"\n\t\t\t7.ADD OFFER" ;
					cout<<"\n\t\t\t8.EXIT" ;

					cout<<"\n\t\tENTER YOUR CHOICE :" ;
					cin>>ch1 ;

					switch(ch1)
					{
					case 1 :l.pos_snacks() ;//CALLING pos_snacks()
							break ;

					case 2 :l.pos_drinks() ;//CALLING pos_drinks()
							break ;

					case 3 :l.delete_item() ;//CALLING delete_item()
							break ;

					case 4 :l.update() ;//CALLING update()
							break ;

					case 5 :l.display_admin() ;//CALLING display_admin()
							break ;

					case 6 :cout<<"\n\t\tTOTAL EARNINGS : RS."<<p.total<<"/-" ;
							break ;

					case 7 :p.add_offer() ;//CALLING add_offer()
							break ;

					case 8: cout<<"\n\t\tTHANK YOU" ;
							break ;

					default :cout<<"\n\t\tINVALID INPUT" ;
							break ;
					}
				}while(ch1 != 8) ;
				break ;

		case 2 :
				do
				{
					//DISPLAY MENU FOR CUSTOMER
					cout<<"\n\t\tMENU :" ;
					cout<<"\n\t\t\t1.DISPLAY MENU " ;
					cout<<"\n\t\t\t2.ORDER PLACE" ;
					cout<<"\n\t\t\t3.EXIT" ;
					cout<<"\n\t\tENTER YOUR CHOICE :" ;
					cin>>ch2 ;

					switch(ch2)
					{
					case 1 :
							l.display_menu() ;//CALLING display_menu()
							break;

					case 2 :
							do
							{
								l.display_menu() ;//CALLING display_menu()
								cout<<"\n\t\tENTER ITEM NO THAT YOU WANT TO PURCHASE :" ;
								cin>>item_no ;
								p.add(item_no, l) ;//CALLING add(item_no, l)

								cout<<"\n\n\t\tDO YOU WANT TO CONTINUE ?" ;
								cout<<"\n\t\t\t1.YES ";
								cout<<"\n\t\t\t2.NO" ;

								cout<<"\n\n\t\tENTER YOUR CHOICE :" ;
								cin>>ch3 ;

							}while(ch3 == 1) ;

							p.bill() ;//CALLING  bill()
							break ;


					case 3 :cout<<"\n\t\tTHANK YOU " ;
							break ;

					default : cout<<"\n\t\tINVALID INPUT" ;
							break ;

					}
				}while(ch2 != 3) ;
				break ;

		case 3 :cout<<"\n\tTHANK YOU" ;
				break ;

		default :cout<<"\n\tINVALID INPUT " ;
				break ;

		}
	}while(ch != 3) ;


	return 0; //INDICATES SUCCESS
}

/*

 OUTPUT :-


	HOW MANY NUMBER OF SNACKS ?
	-1

	INVALID NUMBER OF SNACKS.
	NUMBER OF SNACKS CAN'T BE NEGATIVE
	PLEASE REENTER CORRECT NUMBER OF SNACKS.
	HOW MANY NUMBER OF SNACKS ?
	200

	INVALID NUMBER OF SNACKS.
	MAXIMUM NUMBER OF SNACKS CAN'T BE MORE THAN 150
	PLEASE REENTER CORRECT NUMBER OF SNACKS
	HOW MANY NUMBER OF SNACKS ?
	6

	HOW MANY NUMBER OF DRINKS ?
	4


			-----ENTER SNACKS DETAILS------
	ENTER ITEM NUMBER : -11

	INVALID ITEM NUMBER.
	ITEM NUMBER CAN'T BE NEGATIVE OR ZERO.
	PLEASE RE-ENTER CORRECT ITEM NUMBER.
	ENTER ITEM NUMBER : 44444

	INVALID ITEM NUMBER.
	MAXIMUM NUMBER OF DIGITS IN ITEM NUMBER CAN'T BE MORE THAN 4.
	PLEASE RE-ENTER CORRECT ITEM NUMBER.
	ENTER ITEM NUMBER : 1111

	ENTER NAME OF ITEM : M@SALA DOSA

	INVALID NAME.
	NUMERIC AND SPECIAL CHARACTERS ARE NOT ALLOWED IN NAME.
	PLEASE RE-ENTER CORRECT NAME.
	ENTER NAME OF ITEM : 123

	INVALID NAME.
	NUMERIC AND SPECIAL CHARACTERS ARE NOT ALLOWED IN NAME.
	PLEASE RE-ENTER CORRECT NAME.
	ENTER NAME OF ITEM : MASALA DOSA

	ENTER PRICE OF ITEM :-20

	INVALID ITEM PRICE.
	PRICE CAN'T BE NEGATIVE OR ZERO.
	PLEASE RE-ENTER CORRECT PRICE.
	ENTER PRICE OF ITEM :0

	INVALID ITEM PRICE.
	PRICE CAN'T BE NEGATIVE OR ZERO.
	PLEASE RE-ENTER CORRECT PRICE.
	ENTER PRICE OF ITEM :150

	ENTER AVAILABLE QUANTITY OF ITEM :-5

	INVALID QUANTITY.
	QUANTITY CAN'T BE NEGATIVE.
	PLEASE RE-ENTER CORRECT QUANTITY.
	ENTER AVAILABLE QUANTITY OF ITEM :50

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 1111

	ITEM NUMBER ALREADY EXIST.
	PLEASE RE-ENTER UNIQUE ITEM NUMBER.

	ENTER ITEM NUMBER : 2342

	ENTER NAME OF ITEM : CHEESE GRILLED VEG SANDWICH

	ENTER PRICE OF ITEM :200

	ENTER AVAILABLE QUANTITY OF ITEM :100

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 6013

	ENTER NAME OF ITEM : WHITE PASTA

	ENTER PRICE OF ITEM :220

	ENTER AVAILABLE QUANTITY OF ITEM :100

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 5044

	ENTER NAME OF ITEM : PAV BHAJI

	ENTER PRICE OF ITEM :150

	ENTER AVAILABLE QUANTITY OF ITEM :150

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 6785

	ENTER NAME OF ITEM : HAKKA NOODLES

	ENTER PRICE OF ITEM :200

	ENTER AVAILABLE QUANTITY OF ITEM :100

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 1236

	ENTER NAME OF ITEM : FRENCH FRIES 120

	INVALID NAME.
	NUMERIC AND SPECIAL CHARACTERS ARE NOT ALLOWED IN NAME.
	PLEASE RE-ENTER CORRECT NAME.
	ENTER NAME OF ITEM : FRENCH FRIES

	ENTER PRICE OF ITEM :120

	ENTER AVAILABLE QUANTITY OF ITEM :125

	________________________________________________________________________________________________________________________________

			-----ENTER DRINKS AND BEVERAGES DETAILS------
	ENTER ITEM NUMBER : 2111

	ENTER NAME OF ITEM : WHITE CUKA

	ENTER PRICE OF ITEM :120

	ENTER AVAILABLE QUANTITY OF ITEM :60

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 3342

	ENTER NAME OF ITEM : PAPAYA JUICE

	ENTER PRICE OF ITEM :100

	ENTER AVAILABLE QUANTITY OF ITEM :30

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 6123

	ENTER NAME OF ITEM : CHOCOLATE FUDGE

	ENTER PRICE OF ITEM :220

	ENTER AVAILABLE QUANTITY OF ITEM :90

	________________________________________________________________________________________________________________________________
	ENTER ITEM NUMBER : 7144

	ENTER NAME OF ITEM : COLD COFFEE

	ENTER PRICE OF ITEM :199

	ENTER AVAILABLE QUANTITY OF ITEM :60

	________________________________________________________________________________________________________________________________
	MENU :
		1.SWITCH TO ADMINISTRATOR
		2.DISPLAY MENU CARD
		3.EXIT

	ENTER YOUR CHOICE :1

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :1

	ENTER POSITION AT WHICH YOU HAVE TO INSERT SNACK :-2

	PLEASE TRY AGAIN LATER
	POSITION CAN'T BE ZERO OR NEGATIVE
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :1

	ENTER POSITION AT WHICH YOU HAVE TO INSERT SNACK :9

	PLEASE TRY AGAIN LATER
	POSITION CAN BE BETWEEN 1 TO 7
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :1

	ENTER POSITION AT WHICH YOU HAVE TO INSERT SNACK :1

	ENTER ITEM NUMBER : 3001

	ENTER NAME OF ITEM : MANCHURIAN

	ENTER PRICE OF ITEM :250

	ENTER AVAILABLE QUANTITY OF ITEM :50

	________________________________________________________________________________________________________________________________
	INSERTED SUCCESFULLY.
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :1

	ENTER POSITION AT WHICH YOU HAVE TO INSERT SNACK :5

	ENTER ITEM NUMBER : 3002

	ENTER NAME OF ITEM : MIX VEG PIZZA

	ENTER PRICE OF ITEM :450

	ENTER AVAILABLE QUANTITY OF ITEM :100

	________________________________________________________________________________________________________________________________
	GIVEN SNACK INSERTED SUCCESSFULLY
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :1

	ENTER POSITION AT WHICH YOU HAVE TO INSERT SNACK :9

	ENTER ITEM NUMBER : 3003

	ENTER NAME OF ITEM : GARLIC BREAD

	ENTER PRICE OF ITEM :180

	ENTER AVAILABLE QUANTITY OF ITEM :150

	________________________________________________________________________________________________________________________________
	GIVEN SNACK INSERTED SUCCESSFULLY
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :5



                                              ****SNACKS****
	_______________________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250        50
	      1111                   MASALA DOSA       150        50
	      2342   CHEESE GRILLED VEG SANDWICH       200       100
	      6013                   WHITE PASTA       220       100
	      3002                 MIX VEG PIZZA       450       100
	      5044                     PAV BHAJI       150       150
	      6785                 HAKKA NOODLES       200       100
	      1236                  FRENCH FRIES       120       125
	      3003                  GARLIC BREAD       180       150


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________

	      2111                    WHITE CUKA       120        60
	      3342                  PAPAYA JUICE       100        30
	      6123               CHOCOLATE FUDGE       220        90
	      7144                   COLD COFFEE       199        60

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :2

	ENTER POSITION AT WHICH YOU HAVE TO INSERT DRINK :1

	ENTER ITEM NUMBER : 9001

	ENTER NAME OF ITEM : HOT COFFEE

	ENTER PRICE OF ITEM :230

	ENTER AVAILABLE QUANTITY OF ITEM :150

	________________________________________________________________________________________________________________________________
	GIVEN DRINK INSERTED SUCCESSFULLY
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :2

	ENTER POSITION AT WHICH YOU HAVE TO INSERT DRINK :2

	ENTER ITEM NUMBER : 9003

	ENTER NAME OF ITEM : KITKAT SHAKE

	ENTER PRICE OF ITEM :199

	ENTER AVAILABLE QUANTITY OF ITEM :80

	________________________________________________________________________________________________________________________________
	GIVEN DRINK INSERTED SUCCESSFULLY
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :2

	ENTER POSITION AT WHICH YOU HAVE TO INSERT DRINK :7

	ENTER ITEM NUMBER : 9005

	ENTER NAME OF ITEM : BADAM SHAKE

	ENTER PRICE OF ITEM :300

	ENTER AVAILABLE QUANTITY OF ITEM :40

	________________________________________________________________________________________________________________________________
	INSERTED SUCCESFULLY.
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :5



                                              ****SNACKS****
	_______________________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250        50
	      1111                   MASALA DOSA       150        50
	      2342   CHEESE GRILLED VEG SANDWICH       200       100
	      6013                   WHITE PASTA       220       100
	      3002                 MIX VEG PIZZA       450       100
	      5044                     PAV BHAJI       150       150
	      6785                 HAKKA NOODLES       200       100
	      1236                  FRENCH FRIES       120       125
	      3003                  GARLIC BREAD       180       150


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230       150
	      9003                  KITKAT SHAKE       199        80
	      2111                    WHITE CUKA       120        60
	      3342                  PAPAYA JUICE       100        30
	      6123               CHOCOLATE FUDGE       220        90
	      7144                   COLD COFFEE       199        60
	      9005                   BADAM SHAKE       300        40

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :3

	ENTER ITEM NUMBER TO BE DELETED. 2222

	INCORRECT ITEM NUMBER.
	PLEASE TRY AGAIN LATER
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :3

	ENTER ITEM NUMBER TO BE DELETED. 1236

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 1236
	ITEM NAME          : FRENCH FRIES
	PRICE              : RS.120 /-
	AVAILABLE QUANTITY : 125


	ITEM DETAILS DELETED SUCCESSFULLY
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :5



                                              ****SNACKS****
	_______________________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250        50
	      1111                   MASALA DOSA       150        50
	      2342   CHEESE GRILLED VEG SANDWICH       200       100
	      6013                   WHITE PASTA       220       100
	      3002                 MIX VEG PIZZA       450       100
	      5044                     PAV BHAJI       150       150
	      6785                 HAKKA NOODLES       200       100
	      3003                  GARLIC BREAD       180       150


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230       150
	      9003                  KITKAT SHAKE       199        80
	      2111                    WHITE CUKA       120        60
	      3342                  PAPAYA JUICE       100        30
	      6123               CHOCOLATE FUDGE       220        90
	      7144                   COLD COFFEE       199        60
	      9005                   BADAM SHAKE       300        40

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :4

	ENTER ITEM NUMBER TO BE UPDATED: 3345

	INCORRECT ITEM NUMBER.
	TRY AGAIN LATER.

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :4

	ENTER ITEM NUMBER TO BE UPDATED: 3342

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 3342
	ITEM NAME          : PAPAYA JUICE
	PRICE              : RS.100 /-
	AVAILABLE QUANTITY : 30


	1. UPDATE QUANTITY
	2. UPDATE PRICE
	ENTER YOUR CHOICE : 2

	ENTER NEW PRICE : RS.150


	||****ITEM DETAILS*****||

	ITEM NUMBER      : 3342
	ITEM NAME          : PAPAYA JUICE
	PRICE              : RS.150 /-
	AVAILABLE QUANTITY : 30


		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :4

	ENTER ITEM NUMBER TO BE UPDATED: 2342

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 2342
	ITEM NAME          : CHEESE GRILLED VEG SANDWICH
	PRICE              : RS.200 /-
	AVAILABLE QUANTITY : 100


	1. UPDATE QUANTITY
	2. UPDATE PRICE
	ENTER YOUR CHOICE : 1

	ENTER NEW QUANTITY : 50


	||****ITEM DETAILS*****||

	ITEM NUMBER      : 2342
	ITEM NAME          : CHEESE GRILLED VEG SANDWICH
	PRICE              : RS.200 /-
	AVAILABLE QUANTITY : 50


		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :5



                                              ****SNACKS****
	_______________________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250        50
	      1111                   MASALA DOSA       150        50
	      2342   CHEESE GRILLED VEG SANDWICH       200        50
	      6013                   WHITE PASTA       220       100
	      3002                 MIX VEG PIZZA       450       100
	      5044                     PAV BHAJI       150       150
	      6785                 HAKKA NOODLES       200       100
	      3003                  GARLIC BREAD       180       150


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE  QUANTITY
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230       150
	      9003                  KITKAT SHAKE       199        80
	      2111                    WHITE CUKA       120        60
	      3342                  PAPAYA JUICE       150        30
	      6123               CHOCOLATE FUDGE       220        90
	      7144                   COLD COFFEE       199        60
	      9005                   BADAM SHAKE       300        40

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :6

		TOTAL EARNINGS : RS.0/-
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :7

	 ENTER THE AMOUNT ON WHICH YOU WANT TO GIVE DISCOUNT -5

	INVALID AMOUNT .
	AMOUNT CAN'T BE NEGATIVE
	PLEASE REENTER CORRECT AMOUNT.
	 ENTER THE AMOUNT ON WHICH YOU WANT TO GIVE DISCOUNT 1000

	 ENTER THE DISCOUNT TO BE GIVEN 25

	INVALID DISCOUNT .
	MAXIMUM LIMIT ON DISCOUNT IS 20 %
	PLEASE REENTER CORRECT DISCOUNT.
	 ENTER THE DISCOUNT TO BE GIVEN 5

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :8

		THANK YOU
	MENU :
		1.SWITCH TO ADMINISTRATOR
		2.DISPLAY MENU CARD
		3.EXIT

	ENTER YOUR CHOICE :2

		MENU :
			1.DISPLAY MENU
			2.ORDER PLACE
			3.EXIT
		ENTER YOUR CHOICE :1

	.....................................................................................................................................
                      ||******HALDIRAM'S FOOD PLANET******||



                                              ****SNACKS****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250
	      1111                   MASALA DOSA       150
	      2342   CHEESE GRILLED VEG SANDWICH       200
	      6013                   WHITE PASTA       220
	      3002                 MIX VEG PIZZA       450
	      5044                     PAV BHAJI       150
	      6785                 HAKKA NOODLES       200
	      3003                  GARLIC BREAD       180


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230
	      9003                  KITKAT SHAKE       199
	      2111                    WHITE CUKA       120
	      3342                  PAPAYA JUICE       150
	      6123               CHOCOLATE FUDGE       220
	      7144                   COLD COFFEE       199
	      9005                   BADAM SHAKE       300

	.........................................................................................................................................
		MENU :
			1.DISPLAY MENU
			2.ORDER PLACE
			3.EXIT
		ENTER YOUR CHOICE :2

	.....................................................................................................................................
                      ||******HALDIRAM'S FOOD PLANET******||



                                              ****SNACKS****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250
	      1111                   MASALA DOSA       150
	      2342   CHEESE GRILLED VEG SANDWICH       200
	      6013                   WHITE PASTA       220
	      3002                 MIX VEG PIZZA       450
	      5044                     PAV BHAJI       150
	      6785                 HAKKA NOODLES       200
	      3003                  GARLIC BREAD       180


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230
	      9003                  KITKAT SHAKE       199
	      2111                    WHITE CUKA       120
	      3342                  PAPAYA JUICE       150
	      6123               CHOCOLATE FUDGE       220
	      7144                   COLD COFFEE       199
	      9005                   BADAM SHAKE       300

	.........................................................................................................................................
		ENTER ITEM NO THAT YOU WANT TO PURCHASE :3002

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 3002
	ITEM NAME          : MIX VEG PIZZA
	PRICE              : RS.450 /-
	AVAILABLE QUANTITY : 100


	ENTER QUANTITY YOU WANT TO ORDER :150

	NOT AVAILABLE

		DO YOU WANT TO CONTINUE ?
			1.YES
			2.NO

		ENTER YOUR CHOICE :1

	.....................................................................................................................................
                      ||******HALDIRAM'S FOOD PLANET******||



                                              ****SNACKS****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250
	      1111                   MASALA DOSA       150
	      2342   CHEESE GRILLED VEG SANDWICH       200
	      6013                   WHITE PASTA       220
	      3002                 MIX VEG PIZZA       450
	      5044                     PAV BHAJI       150
	      6785                 HAKKA NOODLES       200
	      3003                  GARLIC BREAD       180


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230
	      9003                  KITKAT SHAKE       199
	      2111                    WHITE CUKA       120
	      3342                  PAPAYA JUICE       150
	      6123               CHOCOLATE FUDGE       220
	      7144                   COLD COFFEE       199
	      9005                   BADAM SHAKE       300

	.........................................................................................................................................
		ENTER ITEM NO THAT YOU WANT TO PURCHASE :3002

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 3002
	ITEM NAME          : MIX VEG PIZZA
	PRICE              : RS.450 /-
	AVAILABLE QUANTITY : 100


	ENTER QUANTITY YOU WANT TO ORDER :2


		DO YOU WANT TO CONTINUE ?
			1.YES
			2.NO

		ENTER YOUR CHOICE :1

	.....................................................................................................................................
                      ||******HALDIRAM'S FOOD PLANET******||



                                              ****SNACKS****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250
	      1111                   MASALA DOSA       150
	      2342   CHEESE GRILLED VEG SANDWICH       200
	      6013                   WHITE PASTA       220
	      3002                 MIX VEG PIZZA       450
	      5044                     PAV BHAJI       150
	      6785                 HAKKA NOODLES       200
	      3003                  GARLIC BREAD       180


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230
	      9003                  KITKAT SHAKE       199
	      2111                    WHITE CUKA       120
	      3342                  PAPAYA JUICE       150
	      6123               CHOCOLATE FUDGE       220
	      7144                   COLD COFFEE       199
	      9005                   BADAM SHAKE       300

	.........................................................................................................................................
		ENTER ITEM NO THAT YOU WANT TO PURCHASE :9005

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 9005
	ITEM NAME          : BADAM SHAKE
	PRICE              : RS.300 /-
	AVAILABLE QUANTITY : 40


	ENTER QUANTITY YOU WANT TO ORDER :2


		DO YOU WANT TO CONTINUE ?
			1.YES
			2.NO

		ENTER YOUR CHOICE :2


	********************************************************************************************************************

                      ||******HALDIRAM'S FOOD PLANET******||


	 SR. NO  ITEM NO.                     ITEM NAME  QUANTITY     PRICE

	----------------------------------------------------------------------------------------------------------------------
	      1      3002                 MIX VEG PIZZA         2       450

	      2      9005                   BADAM SHAKE         2       300

	----------------------------------------------------------------------------------------------------------------------
                                                                     TOTAL = Rs.1500

	CONGRATULATION !!!!!! YOU GOT A DISCOUNT OF 5%
                                                                    TOTAL = Rs. 1425

	THANKS FOR VISITING. THANKS FOR VISITING. THANKS FOR VISITING. THANKS FOR VISITING .

	********************************************************************************************************************
		MENU :
			1.DISPLAY MENU
			2.ORDER PLACE
			3.EXIT
		ENTER YOUR CHOICE :2

	.....................................................................................................................................
                      ||******HALDIRAM'S FOOD PLANET******||



                                              ****SNACKS****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250
	      1111                   MASALA DOSA       150
	      2342   CHEESE GRILLED VEG SANDWICH       200
	      6013                   WHITE PASTA       220
	      3002                 MIX VEG PIZZA       450
	      5044                     PAV BHAJI       150
	      6785                 HAKKA NOODLES       200
	      3003                  GARLIC BREAD       180


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230
	      9003                  KITKAT SHAKE       199
	      2111                    WHITE CUKA       120
	      3342                  PAPAYA JUICE       150
	      6123               CHOCOLATE FUDGE       220
	      7144                   COLD COFFEE       199
	      9005                   BADAM SHAKE       300

	.........................................................................................................................................
		ENTER ITEM NO THAT YOU WANT TO PURCHASE :6785

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 6785
	ITEM NAME          : HAKKA NOODLES
	PRICE              : RS.200 /-
	AVAILABLE QUANTITY : 100


	ENTER QUANTITY YOU WANT TO ORDER :1


		DO YOU WANT TO CONTINUE ?
			1.YES
			2.NO

		ENTER YOUR CHOICE :1

	.....................................................................................................................................
                      ||******HALDIRAM'S FOOD PLANET******||



                                              ****SNACKS****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      3001                    MANCHURIAN       250
	      1111                   MASALA DOSA       150
	      2342   CHEESE GRILLED VEG SANDWICH       200
	      6013                   WHITE PASTA       220
	      3002                 MIX VEG PIZZA       450
	      5044                     PAV BHAJI       150
	      6785                 HAKKA NOODLES       200
	      3003                  GARLIC BREAD       180


                                  ****DRINKS & BEVERAGES****

	_______________________________________________________________________________________________________________________________________

	  ITEM NO.                     ITEM NAME     PRICE
	_______________________________________________________________________________________________________________________________________

	      9001                    HOT COFFEE       230
	      9003                  KITKAT SHAKE       199
	      2111                    WHITE CUKA       120
	      3342                  PAPAYA JUICE       150
	      6123               CHOCOLATE FUDGE       220
	      7144                   COLD COFFEE       199
	      9005                   BADAM SHAKE       300

	.........................................................................................................................................
		ENTER ITEM NO THAT YOU WANT TO PURCHASE :9003

	ITEM DETAILS FOUND.

	||****ITEM DETAILS*****||

	ITEM NUMBER      : 9003
	ITEM NAME          : KITKAT SHAKE
	PRICE              : RS.199 /-
	AVAILABLE QUANTITY : 80


	ENTER QUANTITY YOU WANT TO ORDER :1


		DO YOU WANT TO CONTINUE ?
			1.YES
			2.NO

		ENTER YOUR CHOICE :2


	********************************************************************************************************************

                      ||******HALDIRAM'S FOOD PLANET******||


	 SR. NO  ITEM NO.                     ITEM NAME  QUANTITY     PRICE

	----------------------------------------------------------------------------------------------------------------------
	      1      6785                 HAKKA NOODLES         1       200

	      2      9003                  KITKAT SHAKE         1       199

	----------------------------------------------------------------------------------------------------------------------
                                                                     TOTAL = Rs.399


	THANKS FOR VISITING. THANKS FOR VISITING. THANKS FOR VISITING. THANKS FOR VISITING .

	********************************************************************************************************************
		MENU :
			1.DISPLAY MENU
			2.ORDER PLACE
			3.EXIT
		ENTER YOUR CHOICE :3

		THANK YOU
	MENU :
		1.SWITCH TO ADMINISTRATOR
		2.DISPLAY MENU CARD
		3.EXIT

	ENTER YOUR CHOICE :1

		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :6

		TOTAL EARNINGS : RS.1824/-
		MENU :
			1.INSERT SNACKS
			2.INSERT DRINKS
			3.DELETE
			4.UPDATE
			5.DISPLAY LIST OF ITEMS
			6.TOTAL EARNINGS
			7.ADD OFFER
			8.EXIT
		ENTER YOUR CHOICE :8

		THANK YOU
	MENU :
		1.SWITCH TO ADMINISTRATOR
		2.DISPLAY MENU CARD
		3.EXIT

	ENTER YOUR CHOICE :4

	INVALID INPUT
	MENU :
		1.SWITCH TO ADMINISTRATOR
		2.DISPLAY MENU CARD
		3.EXIT

	ENTER YOUR CHOICE :3

	THANK YOU
 */
