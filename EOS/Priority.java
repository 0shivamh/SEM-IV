import java.util.*;
public class Priority
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);//create a object to get the user input
		
		System.out.println("Enter the number of process: ");//how many process you have to enter
		int num=in.nextInt();
		
		//assign one array to get the burst time for the each process
		
		
		int B[]=new int[num];
		
		
		for(int i=0;i<num;i++)
		{
			System.out.println("Enter the Burst time for "+(i+1)+": ");
			B[i]=in.nextInt();
		}
		
		//assign another array to get the priority for the each process
		
		int P[]=new int[num];
		
		for(int i=0;i<num;i++)
		{
			System.out.println("Enter the Priority value time for "+(i+1)+": ");
			P[i]=in.nextInt();
		}
		
		//here we considered as lower priority value as higher priority process
		
		//assign one array to save the priority values again.
		//because here we have to sorting (ascending) the first priority array to findout 
		//the process order to finish their tasks..
		
		//after we will check the each sorting process to the original array to identify the 
		//process numer;;
		
		int P1[]=new int[num];
		
		//define the priority values there
		
		for(int i=0;i<num;i++)
		{
			P1[i]=P[i];
		}
		
		//now sort the P array to order the process based on their priority value
		
		//use bubble sorting
		
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num-1;j++)
			{
				if(P[j]>P[j+1])
				{
					int tem=P[j];
					P[j]=P[j+1];
					P[j+1]=tem;
				}
			}
		}
		
		//now check the sorting array and original array
		
		//before assign some variables
		
		//this is for adding the waiting in every step;
		
		int wait=0;//initial value is 0;
		
		//this is for store the waiting for each process
		
		int wait_time[]=new int[num];
		
		//this is for get the total waiting time for all processess
		
		float total=0;
		
		int k=0;
		
		System.out.println("Process\t\tBurst time\twaiting time");
		
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
			{
				if(P[i]==P1[j])
				{
					System.out.println("p"+(j+1)+"\t\t"+B[j]+"\t\t\t"+wait);
					wait_time[k]=wait;
					total+=wait;
					wait+=B[j];
				}
			}
		}
		
		System.out.println("The average waiting time is: "+(total/num));
	}
}