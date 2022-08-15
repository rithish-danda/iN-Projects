#include<stdio.h>
#include<string.h>
#include<math.h>

int n=4,m=4;

void swap(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void printArray(int a[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return;
}


void left(int a[n][m])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0 && j==3)
                printf("Invalid move !\n");
            else if (a[i][j]==0)
                swap(a[i][j],a[i][j+1]);
        }
    printArray(a);
    return;
}

void right(int a[n][m])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0 && j==0)
                printf("Invalid move !\n");
            else if (a[i][j]==0)
                swap(a[i][j],a[i][j-1]);
        }
    printArray(a);
    return;
}

void up(int a[n][m])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0 && i==3)
                printf("Invalid move !\n");
            else if (a[i][j]==0)
                swap(a[i][j],a[i+1][j]);
        }
    printArray(a);
    return;
}

void down(int a[n][m])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0 && i==0)
                printf("Invalid move !\n");
            else if (a[i][j]==0)
                swap(a[i][j],a[i-1][j]);
        }
    printArray(a);
    return;
}

void game(char name[])
{
    int a[4][4] = {{1,6,3,2},{5,0,4,11},{15,8,12,7},{9,10,14,13}};
    int chances=10;
    while(chances!=0)
    {
        char c;
        printf("Hello %s, moves remaining: %d\n",name,chances);
        scanf("%c",&c);
        
        if(c=='w'||c=='W')
            up(a);
        else if(c=='a'||c=='A')
            left(a);
        else if(c=='s'||c=='S')
            down(a);
        else if(c=='d'||c=='D')
            right(a);
        else
            printf("Invalid Operation !\n");
        
        chances-=1;
    }
    int b[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==b[i][j])
                count+=1;
        }
    if(count==16)
        printf("YOU WIN !");
    else
        printf("YOU LOSE !");
}

void displayRules(char name[])
{
    printf("Hello %s\n",name);
    printf("\e[1m GAME RULES \e[m\n");
    printf("\n1. You can move only one step at a time.\n");
    printf("\tMove Up: Use Up-arroow key\n");
    printf("\tMove Down: Use Down-arrow key\n");
    printf("\tMove Right or left: Use right-arrow or left-arrow keys\n");
    printf("\n2. You can move the number to an empty position only.\n");
    printf("\n3. For each valid move,your total number of moves will decrease by 1.\n");
    printf("\n4. Winning Situation: Numbers in the 4*4 matrix should be ascending from 1 to 15 and last cell as empty.\n");
    int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    printArray(a);
    printf("\n");
    game(name);
    return;
}

int main()
{
    char name[30];
    printf("Enter your name: ");
    scanf("%[^\n]s",name);
    displayRules(name);
    return 0;
}