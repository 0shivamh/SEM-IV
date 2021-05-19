#include<stdio.h>
#define MAX 25
int banker(int [MAX][MAX],int [MAX][MAX],int [MAX][MAX],int,int); 
int main()
{
 int allocated[MAX][MAX],maxneeded[MAX][MAX],need[MAX][MAX];
 int i,j,num_pro,num_res;
 printf("\nenter the number of process to execute ");
 scanf("%d",&num_pro);
 printf("\nenter the number of resources to allocate ");
 scanf("%d",&num_res);
 for(i=0;i<num_pro;i++)
 {
  printf("\nenter the information regarding p%d process ",i+1); 
  for(j=0;j<num_res;j++)
   {
     printf("\nenter the number of '%c' resource to allocate :",j+65);
     scanf("%d",&allocated[i][j]);
     printf("\nenter the max need of '%c' resource",j+65);
     scanf("%d",&maxneeded[i][j]);
     need[i][j]=maxneeded[i][j]-allocated[i][j];
   }
 }
 banker(allocated,maxneeded,need,num_res,num_pro);
 
return 0; 
}
int banker(int allocated[MAX][MAX],int maxneeded[MAX][MAX],int need[MAX][MAX],int num_res,int num_pro)
{
  int avail[MAX],i,count=0,flag[MAX];
  printf("\nenter the reserved resources :");
  for(i=0;i<num_res;i++)
   {
     printf("enter the '%c' resource availability",i+65);
     scanf("%d",&avail[i]);
    flag[i]=0;
   } 
  printf("\nsafe sequence number is:");
  while(count<num_pro)
  {
    for(i=0;i<num_pro;i++)
     {
       if(need[i][0]<=avail[0]&&need[i][1]<=avail[1]&&need[i][2]<=avail[2]&&!flag[i])
          {
            printf(" p%d  ",i);
            avail[0]=avail[0]+allocated[i][0];
            avail[1]=avail[1]+allocated[i][1];
            avail[2]=avail[2]+allocated[i][2];
            flag[i]=1;
            count++;
          }
       }
   }
} 
  
/*

**************OUTPUT***************

ot@dhcppc36 TEIT8554]# ./ban.out

enter the number of process to execute 5

enter the number of resources to allocate 3

enter the information regarding p1 process 
enter the number of 'A' resource to allocate :0

enter the max need of 'A' resource7

enter the number of 'B' resource to allocate :1

enter the max need of 'B' resource5

enter the number of 'C' resource to allocate :0

enter the max need of 'C' resource3

enter the information regarding p2 process 
enter the number of 'A' resource to allocate :2

enter the max need of 'A' resource3

enter the number of 'B' resource to allocate :0

enter the max need of 'B' resource2

enter the number of 'C' resource to allocate :0

enter the max need of 'C' resource2

enter the information regarding p3 process 
enter the number of 'A' resource to allocate :3

enter the max need of 'A' resource9

enter the number of 'B' resource to allocate :0

enter the max need of 'B' resource0

enter the number of 'C' resource to allocate :2

enter the max need of 'C' resource2

enter the information regarding p4 process 
enter the number of 'A' resource to allocate :2

enter the max need of 'A' resource2

enter the number of 'B' resource to allocate :1

enter the max need of 'B' resource2

enter the number of 'C' resource to allocate :1

enter the max need of 'C' resource2

enter the information regarding p5 process 
enter the number of 'A' resource to allocate :0

enter the max need of 'A' resource4

enter the number of 'B' resource to allocate :0

enter the max need of 'B' resource3

enter the number of 'C' resource to allocate :2

enter the max need of 'C' resource3

enter the reserved resources :enter the 'A' resource availability3
enter the 'B' resource availability3
enter the 'C' resource availability3
safe sequence number is: p1   p3   p4   p0   p2  
*/