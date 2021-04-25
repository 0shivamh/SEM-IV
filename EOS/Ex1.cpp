/*
Write a program to implement an address book with options given below:
a) Create address book. b) View address book. c) Insert a record. d) Delete a record. e)
Modify a record. f) Exit
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class AddressBook
{
 int Sr_No;
 char name[20];
 char addr[20];
 long phno;
 public:
 	int Insert(AddressBook *p,int n)
	{
	 cout<<"Enter Sr No: ";
	cin>>p[n].Sr_No;
	cout<<"Enter Name: ";
	cin>>p[n].name;
	cout<< "Enter Address: ";
	cin>>p[n].addr;
	cout<<"Enter Contact: ";
	cin>>p[n].phno;
	cout<<"\nRECORD INSERTED...\n";
	n++;
	return n;
	}

	int Display(){
	cout<<Sr_No<<"\t"<<name<<"\t"<<addr<<"\t"<<phno<<"\n";
    return 0;
	}

	int Del(AddressBook *p,int n,int roll)
	{
		int j=0,k,flag=0;
		for(j=0;j<n;j++)
		{
			if(p[j].Sr_No==roll)
            {
                flag=1;
                break;
            }
		}
        if(flag==1)
        {
            for(k=j;k<n;k++)
            {
            p[k]=p[k+1];
            }
            cout<<"\nRECORD DELETED.\n";
            return n-1;
        }
			else
			{
				cout<<"\nRecord Not Found\n";
				return n;
			}
	}
	int Update(AddressBook *p,int roll,int n)
	{
		int i,ch1;
		for(i=0;i<n;i++)
		{
		if(p[i].Sr_No==roll)
    		{
    			while(1){
    			cout<<"\n*****Modify Options****\n";
    			cout<<"\n 1. Update Address";
    			cout<<"\n 2. Update Conatct";
   				cout<<"\n 3. Update Both";
   				cout<<"\n 4. Return to main Menu";
   				cout<<"\n\n Enter Your Choice:";
   				cin>>ch1;    				
				switch(ch1){
    				case 1: cout<<"Address:";
    						cin>>p[i].addr;
    						cout<<"Record Updated...\n";
    						break;
   					case 2: cout<<"Contact:\t";
   							cin>>p[i].phno;
   							cout<<"Record Updated...\n";
   							break; 					
					case 3: cout<<"Address:";
							cin>>p[i].addr;
							cout<<"Contact:\t";
							cin>>p[i].phno;
							cout<<"Record Updated...\n";
							break;
					case 4: return n;
					default: cout<<"!! Wrong Key !!";
							break;
					}
				}
			break;
    		}
            
		}
    		if(p[i].Sr_No!=roll)
		{
    		cout<<"\nRecord Not Found\n\n";
		}
        return 0;
	}
    
};
int main()
{
 AddressBook o[10];
 int i=0,ch,j,roll;
 while(1)
  {
   cout<<"\n*****Address Book*****";
   cout<<"\n";
   cout<< "\n 1.Insert";
   cout<< "\n 2.Display";
   cout<< "\n 3.Delete";
   cout<< "\n 4.Modify";
   cout<< "\n 5.Exit";
   cout<< "\n\n ENTER YOUR CHOICE:";
   cin>> ch;
   switch(ch){
     case 1: i=o[0].Insert(o,i);
               break;
     case 2: cout<<"Sr.No\tNAME\tAddress\tContact\n==============================================\n";
		for(j=0;j<i;j++){
		o[j].Display();
		}
		break;
	 case 3:
		cout<<"Enter the Sr No to Delete:";
		cin>> roll;
		i=o[0].Del(o,i,roll);
		break;
	 case 4:
	 	cout<<"Enter the Sr No For Data Update:";
		cin>> roll;
		i=o[0].Update(o,roll,i);
		break;
     case 5: exit(0);   
	 default: cout<<"Wrong Key!!";
	 		break;
     
    }
  }

 }