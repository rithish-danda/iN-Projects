// Project -1
// Number Swap Game

// Header Files
#include<stdio.h>
#include<string.h>
/*#include<conio.h>*/
#include<ctype.h>

//Global declaration of some essential variables
int n=4, m=4, chances=6;

// Function to Swap the elements passed
void swap(char* a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array in required format
void printarray( char* array[n][m] ){
    printf("\n\t\t\t-----------------------------\n");
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            if ( j==0 ){
                if( strlen(array[i][j]) >1 )
                     printf( "\t\t\t|  %s  |", array[i][j] );
                else
                     printf( "\t\t\t|   %s  |", array[i][j] );
            }
            else{
                if( strlen( array[i][j] )>1 )
                     printf( "  %s  |", array[i][j] );
                else
                     printf( "   %s  |", array[i][j] );

            }
        }
        printf("\n");
    }
    printf("\t\t\t-----------------------------\n");
}


// Function to be executed when left command is selected
void left(char* array[n][m]){
    int p,q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(array[i][j]==" "){
                p=i;q=j;
                break;
            }
        }
    }
    if(q==3)
        printf("Invalid Move !");
    else
        swap(&array[p][q],&array[p][q+1]);
    printarray(array);
}

// Function to be executed when right command is selected

void right(char* array[n][m]){
    int p,q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(array[i][j]==" "){
                p=i;q=j;
                break;
            }
        }
    }
    if(q==0)
        printf("Invalid Move !");
    else
        swap(&array[p][q],&array[p][q-1]);
    printarray(array);
}


// Function to be executed when up command is selected

void up(char* array[n][m]){
    int p,q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(array[i][j]==" "){
                p=i;q=j;
                break;
            }
        }
    }
    if(p==3)
        printf("Invalid Move !");
    else
        swap(&array[p][q],&array[p+1][q]);
    printarray(array);
}


// Function to be executed when down command is selected

void down(char* array[n][m]){
    int p,q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(array[i][j]==" "){
                p=i;q=j;
                break;
            }
        }
    }
    if(p==0)
        printf("Invalid Move !");
    else
        swap(&array[p][q],&array[p-1][q]);
    printarray(array);
}

// Function to compare two passed arrays

int compare(char* array[n][m]){
    char *win[4][4] = {{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15"," "}};
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if (array[i][j] != win[i][j])
                return 0;
        }
    }
    return 1;
}

// Function which contains the switch case for the movements of the numbers in array
void game(char* name){
    char input;
    char* array[4][4] = { {"1","2","3","4"}, {"5"," ","6","7"}, {"9","10","11","8"}, {"13","14","15","12",} };
    printarray(array);
    for(int i=1 ; i<=chances ; chances--){
        printf("\n\n\t\t  Hello, %s. There are %d chances remaining.\n",name,chances);
        input = _getch();
        if ( input=='w' || input=='W' )
            up(array);
        else if( input=='a' || input=='A' )
            left(array);
        else if( input=='s' || input=='S' )
            down(array);
        else if( input=='d' || input=='D' )
            right(array);
        else if( input=='e' || input=='E' ){
            printf("\n\n\t\t----- GAME TERMINATED ON REQUEST -----\n\n");
            return;
        }
        else{
            printf("\n\n\t\t---Invalid Input--- \n\n");
        }

    // comparing arrays and checking for the game status inside the game function
    if (compare(array)==0 && chances==0){
        printf("\n\n\t\t\t\t-----YOU LOSE-----\n\n");
        break;
    }
    else if(compare(array)==1){
        printf("\n\n\t\t\t\t-----YOU WIN-----\n\n");
        break;
    }
}
}

// Function to print the Rules of the Game
void printrules(char* name){
    printf("\nHello, %s\n\n", name);
    printf("\n\n----- RULES OF THIS GAME------\n\n");
    printf("\n1. You can move only one step at a time.\n");
    printf("\tMove Up: Use Up-arrow key\n");
    printf("\tMove Down: Use Down-arrow key\n");
    printf("\tMove Right: Use right-arrow Key\n");
    printf("\tMove Left: Use left-arrow Key\n");
    printf("\n2. You can move the number to an empty position only.\n");
    printf("\n3. For each valid move,your total number of moves will decrease by 1.\n");
    printf("\n4. Winning Situation: Numbers in the 4*4 matrix should be ascending from 1 to 15 and last cell as empty.\n");

    char *array[4][4] = { {"1","2","3","4"}, {"5","6","7","8"}, {"9","10","11","12"}, {"13","14","15"," "} };
    printarray(array);

    printf("\n5. Press 'e' or 'E' to exit anytime halfway.\n");
    printf("\nSo try to finish the game in minimum number of chances.\n");
    printf("\n\tGood Luck ! Happy Gaming\t\t\n");
    printf("\nPress any key to continue...\n");
    _getch();
    game(name);
}

// Driver Code a.k.a The main() function
int main(){
    char name[30];
    printf("Enter your name: ");
    scanf("%[^\n]s",name);
    printrules(name);
    return 0;
}
