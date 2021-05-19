#include<stdio.h>
main()
{
 int i,a[10],b[10],n,j,w=0,c[10],d[10],s,p[10];
 float awt,att,temp=0,temp1=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 printf("Enter process id & burst time & priority of process\n");
 for(i=0;i<n;i++)
  {
   scanf("%d%d%d",&b[i],&a[i],&p[i] );
  }
 printf("***********************\n");
 // Input Display
 printf("INPUT\n");
 printf("process\tBT\tPriority\n");
 for(i=0;i<n;i++)  
  {
   printf("p%d\t%d\t%d\n",b[i],a[i],p[i]);
  } 
  printf("***********************\n");
// Sorting according to priority
  for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
      {
        if(p[i]>p[j])
         {
           s=p[i];
           p[i]=p[j];
           p[j]=s;
           s=b[i];
           b[i]=b[j];
           b[j]=s;
           s=a[i];
           a[i]=a[j];
           a[j]=s;

         }
       }
   } 
// Sorted list
 printf("Sorted list according to burst time\n");
 printf("process\tBT\tPriority\n");
 for(i=0;i<n;i++)
  {
   printf("p%d\t%d\t%d\n",b[i],a[i],p[i]);
  } 
printf("***********************\n");
// Calculate waiting time & Turnaround time
 for(i=0;i<n;i++)
  {
   c[i]=w;
   temp=temp+c[i];
   d[i]=c[i]+a[i];
   temp1=temp1+d[i];
   w=w+a[i];
  } 
// Calculate average WT & TT
  awt=temp/n;
  att=temp1/n;
   
//Output
  printf("OUTPUT\n");
  printf("Process\tBT\tPriority\tWT\tTT\n");
  for(i=0;i<n;i++)
   {
    printf("p%d\t%d\t%d\t\t%d\t%d\n",b[i],a[i],p[i],c[i],d[i]);
   } 
   printf("Average Waiting time=%f\n",awt);
   printf("average turnaround time=%f\n",att);
}
 
/* OUTPUT
[raisoni@localhost te]$ vi priority.c 
[raisoni@localhost te]$ cc priority.c 
[raisoni@localhost te]$ ./a.out
Enter no of processes:3
Enter process id & burst time & priority of process
1 2 3
2 3 4
3 4 2
***********************
INPUT
process	BT	Priority
p1	2	3
p2	3	4
p3	4	2
***********************
Sorted list according to burst time
process	BT	Priority
p3	4	2
p1	2	3
p2	3	4
***********************
OUTPUT
Process	BT	Priority	WT	TT
p3	4	2		0	4
p1	2	3		4	6
p2	3	4		6	9
Average Waiting time=3.333333
average turnaround time=6.333333
*/