// Project -1
// Number Swap Game

// Header Files
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

//Global declaration of some essential variables
int n=4, m=4, chances=3;

// Function to Swap the elements passed
void swap(char* a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array in required format
void printarray( char* array[n][m] ){
    printf("\n-----------------------------\n");
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            if ( j==0 ){
                if( strlen(array[i][j]) >1 )
                     printf( "|  %s  |", array[i][j] );
                else
                     printf( "|   %s  |", array[i][j] );
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
    printf("-----------------------------\n");
}


// Function to be executed when left command is selected
void left(char* array[n][m]){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if (array[i][j]==" " && j!=3){
                swap( &array[i][j], &array[i][j+1]);
                break;
            }
            else if (array[i][j]==" " && j==3)
                printf("Invalid Move !");
        }
    }
    printarray(array);
}

// Function to be executed when right command is selected
void right(char* array[n][m]){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if (array[i][j]==" " && j!=0){
                swap( &array[i][j], &array[i][j-1]);
                break;
            }
            else if (array[i][j]==" " && j==0)
                printf("Invalid Move !");
        }
    }
    printarray(array);
}

// Function to be executed when up command is selected
void up(char* array[n][m]){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if (array[i][j]==" " && i!=3){
                swap( &array[i][j], &array[i+1][j]);
                break;
            }
            else if (array[i][j]==" " && i==3)
                printf("Invalid Move !");
        }
    }
    printarray(array);
}

// Function to be executed when down command is selected
void down(char* array[n][m]){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if (array[i][j]==" " && i!=0){
                swap( &array[i][j], &array[i-1][j]);
                break;
            }
            else if (array[i][j]==" " && i==0)
                printf("Invalid Move !");
        }
    }
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
    char* array[4][4] = { {"1","2","3","4"}, {"5","6","7","8"}, {"9","10","11","12"}, {" ","13","14","15",} };
    printarray(array);
    for(int i=1 ; i<=chances ; chances--){
        printf("\nHello, %s. There are %d chances remaining.",name,chances);
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
            printf("\n\n----- GAME TERMINATED ON REQUEST -----\n\n");
            return;
        }
        else{
            printf("\n\n---Invalid Input--- \n\n");
        }
    }
    // comparing arrays and checking for the game status inside the game function
    if (compare(array)==0 && chances==0){
        printf("\n\n-----YOU LOSE-----\n\n");
    }
    else if(compare(array)==1){
        printf("\n\n-----YOU WIN-----\n\n");
    }
}

// Function to print the Rules of the Game
void printrules(char* name){
    printf("\n\n----- GAME RULES ------\n\n");
    printf("\nHello, %s\n\n", name);
    printf("\n1. You can move only one step at a time.\n");
    printf("\tMove Up: Use Up-arrow key\n");
    printf("\tMove Down: Use Down-arrow key\n");
    printf("\tMove Right or left: Use right-arrow or left-arrow keys\n");
    printf("\n2. You can move the number to an empty position only.\n");
    printf("\n3. For each valid move,your total number of moves will decrease by 1.\n");
    printf("\n4. Winning Situation: Numbers in the 4*4 matrix should be ascending from 1 to 15 and last cell as empty.\n");

    char *array[4][4] = { {"1","2","3","4"}, {"5","6","7","8"}, {"9","10","11","12"}, {"13","14","15"," "} };
    printarray(array);

    printf("\n5. Press 'e' or 'E' to exit anytime halfway.\n");
    printf("\n........Good Luck ! Happy Gaming.......\n.");
    printf("\n\tPress any key to continue...\n");
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
