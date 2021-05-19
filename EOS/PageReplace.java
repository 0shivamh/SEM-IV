import java.util.*;

import javax.swing.plaf.synth.SynthStyle;
class PageReplace
{

	//create a object to get the user input
		

	static int check(int frame[],int frame_size,int page)
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
	
	static void display(int frame[],int frame_size,int page_faults)
	{
		int i;
		Scanner in=new Scanner(System.in);
		System.out.println("\nMain Memory Status:");
		for(i=0;i<frame_size;i++)
		{
			frame[i]=in.nextInt();

		}
		System.out.println("\tFaults: ");
		for(i=1;i<=page_faults;i++)
		System.out.println("F ");
	}
	
	static int no_space(int frame[],int frame_size)
	{
		int i,flag;
		for(i=0;i<frame_size && flag!=0;i++)
		{
			if(frame[i]==0)
				flag=0;
		}
		return flag=1;
	}
	static void page_fifo()
	
	{
		Scanner in=new Scanner(System.in);
		int i,page_faults,page;
		int frame[] =new int[5];
		int frame_size,frame_index;
		int ch;
	
		frame_index=-1;
		page_faults=0;
	
		System.out.println("\nEnter Working set Size ");
		frame_size=in.nextInt();
	
		for(i=0;i<frame_size;i++)
			frame[i]=0;
		i=0;
		do
		{
			System.out.println("\nEnter Page : ");
			page=in.nextInt();
			if (check(frame,frame_size,page) == -1)
			{
				frame_index=(frame_index+1)%frame_size;
				frame[frame_index]=page;
				page_faults++;
			}
			
			display(frame,frame_size,page_faults);
	
			System.out.println("\nDo you want more Pages(1/0): ");
			ch=in.nextInt();
			i++;
		}while(ch != 0);
		
		System.out.println("No of Page Faults are: "+page_faults);
	}
	
	
	static void page_lru()
	{
		Scanner in=new Scanner(System.in);
		int i,j,page_faults,page;
		int frame[]=new int[5];
		int frame_size,frame_index;
		int ch;
	
		frame_index=-1;
		page_faults=0;
	
		System.out.println("\nEnter Working set Size ");
		frame_size=in.nextInt();
	
		for(i=0;i<frame_size;i++)
			frame[i]=0;
	
		do
		{
			
			System.out.println("\nEnter Page : ");
			page=in.nextInt();
	
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
	
			System.out.println("\nDo you want more Pages(1/0): ");
			ch=in.nextInt();
			i++;
		}while(ch != 0);
		
		System.out.println("\nNo of Page Faults are: %d\n"+page_faults);
	}
	
	
	
	static void page_opt()
	{
		Scanner in=new Scanner(System.in);
		int i,j,page_faults;
		int page[]= new int[20];
		int frame[]=new int[5];
		int frame_check[]=new int[5];
		int frame_size,frame_index,page_index,no_page,cnt;
		
	
		frame_index=-1;
		page_faults=0;
		
		System.out.println("\nEnter Total Number of Pages: ");
		no_page=in.nextInt();
		
		for(i=0;i<no_page;i++)
		{
			System.out.println("Enter Page %d: "+i+1);
			page[i]=in.nextInt();
		}
	
		page_index=0;
		System.out.println("\nEnter Working set Size: ");
		frame_size=in.nextInt();
	
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
			System.out.println("\n\n\tInsert Page %d in Main Memory."+page[page_index]);
			display(frame,frame_size,page_faults);
			page_index++;
	
		}
		
	System.out.println("\n\nNo of Page Faults are: %d\n"+page_faults);
	}
	
        public static void main(String args[]) 
        {
                
			int ch;
	do
 	{
		Scanner in=new Scanner(System.in);
		System.out.println("\n\n--------------MENU--------------");
		System.out.println("\n  1.Page Replacement using FIFO.");
		System.out.println("\n  2.Page Replacement using LRU.");
		System.out.println("\n  3.Page Replacement using Optimal.");
		System.out.println("\n  4.Exit.");
		System.out.println("\nEnter your Choice: ");
		ch=in.nextInt();

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
				System.out.println("\nInvalid Choice! ");
		}
	}while(ch!=4);
               
                
        }
}