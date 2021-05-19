/*	Implementing Page Replacement Strategies
	(a) FIFO
	(b) LRU
	(c) OPTIMAL

*/

#include<stdio.h>
#define max 20


int check(int frame[],int frame_size,int page)
{
	int i;
	for(i=0;i<frame_size;i++)
	{
		if(frame[i]==page)
		{
			return i;
		}
	}
	return -1;
}

void display(int frame[],int frame_size,int page_faults)
{
	int i;
	printf("\nMain Memory Status:");
	for(i=0;i<frame_size;i++)
	{
		printf("\t%d",frame[i]);
	}
	printf("\tFaults: ");
	for(i=1;i<=page_faults;i++)
	printf("F ");
}

int no_space(int frame[],int frame_size)
{
	int i,flag=1;
	for(i=0;i<frame_size && flag!=0;i++)
	{
		if(frame[i]==0)
			flag=0;
	}
	return flag;
}
void page_fifo()
{
	int i,page_faults,page,frame[5];
	int frame_size,frame_index;
	int ch;

	frame_index=-1;
	page_faults=0;

	printf("\nEnter Working set Size ");
	scanf("%d",&frame_size);

	for(i=0;i<frame_size;i++)
		frame[i]=0;
	i=0;
	do
	{
		printf("\nEnter Page : ");
		scanf("%d",&page);
		if (check(frame,frame_size,page) == -1)
		{
			frame_index=(frame_index+1)%frame_size;
			frame[frame_index]=page;
			page_faults++;
		}
		
		display(frame,frame_size,page_faults);

		printf("\nDo you want more Pages(1/0): ");
		scanf("%d",&ch);
		i++;
	}while(ch != 0);
	
	printf("\nNo of Page Faults are: %d\n",page_faults);
}


void page_lru()
{
	int i,j,page_faults,page,frame[5];
	int frame_size,frame_index;
	int ch;

	frame_index=-1;
	page_faults=0;

	printf("\nEnter Working set Size ");
	scanf("%d",&frame_size);

	for(i=0;i<frame_size;i++)
		frame[i]=0;

	do
	{
		
		printf("\nEnter Page : ");
		scanf("%d",&page);

		i=check(frame,frame_size,page);		
		
		if (i== -1)
		{
			page_faults++;
			i=frame_size-1;
		}
		for(j=i;j>0;j--)
		{
			frame[j]=frame[(j-1)];
		}		

		frame[0]=page;
		
		display(frame,frame_size,page_faults);

		printf("\nDo you want more Pages(1/0): ");
		scanf("%d",&ch);
		i++;
	}while(ch != 0);
	
	printf("\nNo of Page Faults are: %d\n",page_faults);
}



void page_opt()
{
	int i,j,page_faults,page[max],frame[5],frame_check[5];
	int frame_size,frame_index,page_index,no_page,cnt;
	

	frame_index=-1;
	page_faults=0;
	
	printf("\nEnter Total Number of Pages: ");
	scanf("%d",&no_page);
	
	for(i=0;i<no_page;i++)
	{
		printf("Enter Page %d: ",i+1);
		scanf("%d",&page[i]);
	}

	page_index=0;
	printf("\nEnter Working set Size: ");
	scanf("%d",&frame_size);

	for(i=0;i<frame_size;i++)
	{
		frame[i]=0;
	}

	while(page_index < no_page)
	{
		i=check(frame,frame_size,page[page_index]);		
		
		if (i == -1)
		{
		    if(no_space(frame,frame_size))
		    {	
			cnt=0;
			for(j=page_index+1;j<no_page && cnt<2;j++)
			{
				for(i=0;i<frame_size;i++)
				{
					if(page[j] == frame[i] && frame_check[i]==0)
					{
						frame_check[i]=1;
						cnt++;
						break;
					}
				}	
			}	
			for(i=0;i<frame_size;i++)
			{
				if(frame_check[i]==0)
				break;
			}
			
			for(j=0;j<frame_size;j++)
			{
				frame_check[j]=0;
			}
		
 		    }
		    else
		    {
			for(i=0;i<frame_size;i++)
			{
				if(frame[i]==0)
				break;
			}
		    }
		frame[i]=page[page_index];			
		page_faults++;
	
		}
		printf("\n\n\tInsert Page %d in Main Memory.",page[page_index]);
		display(frame,frame_size,page_faults);
		page_index++;

	}
	
printf("\n\nNo of Page Faults are: %d\n",page_faults);
}


int main()
{
	int ch;
	do
 	{
		printf("\n\n--------------MENU--------------");
		printf("\n  1.Page Replacement using FIFO.");
		printf("\n  2.Page Replacement using LRU.");
		printf("\n  3.Page Replacement using Optimal.");
		printf("\n  4.Exit.");
		printf("\nEnter your Choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: page_fifo();
				break;

			case 2: page_lru();
				break;

			case 3: page_opt();
				break;

			case 4:
				break;
			default: 
				printf("\nInvalid Choice! ");
		}
	}while(ch!=4);
}


/*==================================OUTPUT===============================================

--------------MENU--------------
  1.Page Replacement using FIFO.
  2.Page Replacement using LRU.
  3.Page Replacement using Optimal.
  4.Exit.
Enter your Choice: 1

Enter Resident Size: 3

Enter Page : 2

Main Memory Status:	2	0	0	Faults: F 
Do you want more Pages(1/0): 1

Enter Page : 3

Main Memory Status:	2	3	0	Faults: F F 
Do you want more Pages(1/0): 1

Enter Page : 2

Main Memory Status:	2	3	0	Faults: F F 
Do you want more Pages(1/0): 1

Enter Page : 1

Main Memory Status:	2	3	1	Faults: F F F 
Do you want more Pages(1/0): 0

No of Page Faults are: 3


--------------MENU--------------
  1.Page Replacement using FIFO.
  2.Page Replacement using LRU.
  3.Page Replacement using Optimal.
  4.Exit.
Enter your Choice: 2

Enter Resident Size: 3

Enter Page : 2

Main Memory Status:	2	0	0	Faults: F 
Do you want more Pages(1/0): 1

Enter Page : 3

Main Memory Status:	3	2	0	Faults: F F 
Do you want more Pages(1/0): 1

Enter Page : 2

Main Memory Status:	2	3	0	Faults: F F 
Do you want more Pages(1/0): 1

Enter Page : 1

Main Memory Status:	1	2	3	Faults: F F F 
Do you want more Pages(1/0): 0

No of Page Faults are: 3


--------------MENU--------------
  1.Page Replacement using FIFO.
  2.Page Replacement using LRU.
  3.Page Replacement using Optimal.
  4.Exit.
Enter your Choice: 3

Enter Total Number of Pages: 12
Enter Page 1: 2
Enter Page 2: 3
Enter Page 3: 2
Enter Page 4: 1
Enter Page 5: 5
Enter Page 6: 2
Enter Page 7: 4
Enter Page 8: 5
Enter Page 9: 3
Enter Page 10: 2
Enter Page 11: 5
Enter Page 12: 2

Enter Working set Size: 3


	Insert Page 2 in Main Memory.
Main Memory Status:	2	0	0	Faults: F 

	Insert Page 3 in Main Memory.
Main Memory Status:	2	3	0	Faults: F F 

	Insert Page 2 in Main Memory.
Main Memory Status:	2	3	0	Faults: F F 

	Insert Page 1 in Main Memory.
Main Memory Status:	2	3	1	Faults: F F F 

	Insert Page 5 in Main Memory.
Main Memory Status:	2	3	1	Faults: F F F F 

	Insert Page 2 in Main Memory.
Main Memory Status:	2	3	1	Faults: F F F F 

	Insert Page 4 in Main Memory.
Main Memory Status:	2	3	4	Faults: F F F F F 

	Insert Page 5 in Main Memory.
Main Memory Status:	2	3	5	Faults: F F F F F F 

	Insert Page 3 in Main Memory.
Main Memory Status:	2	3	5	Faults: F F F F F F 

	Insert Page 2 in Main Memory.
Main Memory Status:	2	3	5	Faults: F F F F F F 

	Insert Page 5 in Main Memory.
Main Memory Status:	2	3	5	Faults: F F F F F F 

	Insert Page 2 in Main Memory.
Main Memory Status:	2	3	5	Faults: F F F F F F 

No of Page Faults are: 6


--------------MENU--------------
  1.Page Replacement using FIFO.
  2.Page Replacement using LRU.
  3.Page Replacement using Optimal.
  4.Exit.
Enter your Choice: 4

*/


