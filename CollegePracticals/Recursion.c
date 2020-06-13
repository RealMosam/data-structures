
#include<stdio.h>
void towers(int num, char BEG[], char AUX[], char END[])
{
    if (num==1)
    {
        printf("\nMove disk 1 from peg %s to peg %s\n",BEG,END);
        return;
    }
    towers(num-1,BEG,END,AUX);
    printf("\nMove disk %d from peg %s to peg %s\n",num,BEG,END);
    towers(num-1,AUX,BEG,END);
}
int main()
{
    int num=0;
    char BEG[20];
    char END[20];
    char AUX[20];
    printf("Enter the number of disks:\n");
    scanf("%d",&num);
    printf("\nEnter the name of tower\n");
    scanf("%s%s%s", BEG,AUX,END);
    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    towers(num,BEG,AUX,END);
    return 0;
}

