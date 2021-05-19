#include<stdio.h>
#define maxm 100
#define minm 0

struct memory
{
	int blk_sz,pro,flag;
}M[10];

int no_pro,no_blk,pro_sz[10];

void first_fit();
void best_fit();
void next_fit();
void show();

int main()
{

int i;

printf("\n Enter the no of memory blocks");
scanf("%d",&no_blk);

for(i=0;i<no_blk;i++)	
{
	printf("\n Enter the size of memory blocks");
	scanf("%d",&M[i].blk_sz);
}

printf("\n Enter the no of process");
scanf("%d",&no_pro);

for(i=0;i<no_pro;i++)
{
	printf("\n Enter the size of process");
	scanf("%d",&pro_sz[i]);
}

	printf("\n 1.FF");
	first_fit();

	printf("\n 2.BF");
	best_fit();

	printf("\n 3.NF");
	next_fit();

	return(0);
}


void first_fit()
{
	int i,j;
	for(i=0;i<no_blk;i++)
	M[i].flag=0;

	for(i=0;i<no_pro;i++)
	for(j=0;j<no_blk;j++)
	{	
		if(M[j].flag!=1 && pro_sz[i]<=M[j].blk_sz)
		{
			M[j].pro=i+1;
			M[j].flag=1;
			break;
		}
	}
	show();
}


void show()
{
	int i;	
	printf("\n\n Memory Block\t Block-size \t process \t process size");
	for(i=0;i<no_blk;i++)
	{
	 printf("\n %d\t\t%d",i+1,M[i].blk_sz);
         if(M[i].flag==1)
              printf("\t\t%d\t\t%d",M[i].pro,pro_sz[M[i].pro-1]);
        }
}


void best_fit()
{

int i,j,k,min;
for(i=0;i<no_blk;i++)
{
	M[i].pro=0;
	M[i].flag=0;
}

for(i=0;i<no_pro;i++)
{
	min=maxm;
	for(j=0;j<no_blk;j++)
	if(M[j].flag!=1 && pro_sz[i]<=M[j].blk_sz)
	if(min>(M[j].blk_sz-pro_sz[i]))
	{
		min=M[j].blk_sz-pro_sz[i];
		k=j;
	}
	if(min!=maxm)
	{
		M[k].pro=i+1;
		M[k].flag=1;
	}
}
show();
}	


void next_fit()
{
	int i,j,k;
	for(i=0;i<no_blk;i++)
	{
		M[i].pro=0;
		M[i].flag=0;
	}
	k=0;
	for(i=0;i<no_pro;i++)
	for(j=k;j<no_blk;j++)
	if(M[j].flag!=1 && pro_sz[i]<=M[j].blk_sz)
	{
		M[j].flag=1;
		M[j].pro=i+1;
		k=(j+1)%no_blk;
		break;
	}
show();

}	