#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
int IP1, IP2, IP3, IP4, CIDR, subnet, mask;
char class;
//Request User input
printf("Please enter IP address in the form of \"0.0.0.0\": \n");
scanf("%i.%i.%i.%i", &IP1, &IP2, &IP3, &IP4);
//Check if IP is valide
do
{
    if((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 ==
    255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0))
    {
    printf("Warning!! IP address invalid, please enter a valid IP address: \n");
    scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
    }
}while((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1== 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0));
//If IP valid ask for CIDR
printf(" Enter any number from 1 to 15 as CIDR number: \n");
scanf("%d", &CIDR);
do{
    //CHeck if CIDR is valid
    if(CIDR > 32 || CIDR == 0)
    {
    printf("| Invalid CIDR, please enter a valid CIDR: |\n");
    scanf("%d", &CIDR);
    }
}while(CIDR > 32);
//Let's determine IP class
if(IP1 <=170) {
    class = 'A';
}else if(IP1 <=190) {
    class = 'B';
}else {
    class = 'C';
}
subnet=pow(2,16-CIDR);
mask=pow(2,32-CIDR)-2;
printf("Here is your Result:\n");
printf("your IP %i.%i.%i.%i/%i is of class %c\n", IP1,IP2,IP3,IP4,CIDR,class);
printf("Subnet:\t%d \n", subnet);
printf("host:\t%d \n", mask);
return (0);
}