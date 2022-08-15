#include<stdio.h>
#include<string.h>
#include<math.h>

void swap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void printArray(char a[],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c  ",a[i][j]);
        }
        printf("\n");
    }
}

void game(char name[])
{
    int chances=10;
    
}

void displayRules()
{
    printf("\e[1mGAME RULES\e[m\n");
    printf("\n1. You can move only one step at a time.\n");
    printf("\tMove Up: Use Up-arroow key\n");
    printf("\tMove Down: Use Down-arrow key\n");
    printf("\tMove Right or left: Use roght-arrow or left-arrow keys\n");
    printf("\n2. You can move the number to an empty position only.\n");
    printf("\n3. For each valid move,your total number of moves will decrease by 1.\n");
    printf("\n4. Winning Situation: Numbers in the 4*4 matrix should be ascending from 1 to 15 and last cell as empty.\n")
    char a[4][4];
    a = {{'1','2','3','4'},{'5','6','7','8'},{'9',"10","11","12"},{"13","14","15",32}}
    printArray(a,4,4);
    return;
}
int main()
{
    char name[30];
    printf("Enter your name: ");
    scanf("%[^\n]s",name);
    game(name);
    return 0;
}
