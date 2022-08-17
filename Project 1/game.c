// Project-1
// Number Shifting game

#include<stdio.h>
#include<math.h>          // Header Files
#include<string.h>

int n=4,m=4;

// Function to Swap Elements
void swap( char* a, char* b ){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the Array
void printarray( char* array[n][m] ){
    printf("-----------------------------\n");
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
void left( char* array[n][m] ){
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<m ; j++ ){
            if ( array[i][j]==0 && j==3 )
                printf("Invalid move !");
            else if ( array[i][j]==" " )
                swap( &array[i][j], &array[i][j+1] );
        }
    }
    printarray(array);
}

// Function to be executed when right command is selected
void right( char* array[n][m]){
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<m ; j++ ){
            if ( array[i][j]==0 && j==0 )
                printf("Invalid move !");
            else if ( array[i][j]==" " )
                swap( &array[i][j], &array[i][j-1] );
        }
    }
    printarray(array);
}

// Function to be executed when down command is selected
void down( char* array[n][m]){
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<m ; j++ ){
            if ( array[i][j]==0 && i==0 )
                printf("Invalid move !");
            else if ( array[i][j]==" " )
                swap( &array[i][j], &array[i-1][j] );
        }
    }
    printarray(array);
}

// Function to be executed when up command is selected
void up( char* array[n][m]){
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<m ; j++ ){
            if ( array[i][j]==0 && i==3 )
                printf("Invalid move !");
            else if ( array[i][j]==" " )
                swap( &array[i][j], &array[i+1][j] );
        }
    }
    printarray(array);
}

// Function to display the rules of the game
void displayRules( char name[] ){
    printf("Hello, %s\n", name);
    printf("\e[1m ---GAME RULES--- \e[m\n");
    printf("\n1. You can move only one step at a time.\n");
    printf("\tMove Up: Use Up-arroow key\n");
    printf("\tMove Down: Use Down-arrow key\n");
    printf("\tMove Right or left: Use right-arrow or left-arrow keys\n");
    printf("\n2. You can move the number to an empty position only.\n");
    printf("\n3. For each valid move,your total number of moves will decrease by 1.\n");
    printf("\n4. Winning Situation: Numbers in the 4*4 matrix should be ascending from 1 to 15 and last cell as empty.\n");

    char* array[4][4] = { {"1","2","3","4"}, {"5","6","7","8"}, {"9","10","11","12"}, {"13","14","15"," "} };
    printArray(array);
    printf("\n");
    return;
}

// Function to compare two arrays
void compare(char* array[n][m], char* wintable[n][m]){
    for ( int i=0 ; i<n ; i++ )
        for(int j=0 ; j<m ; j++){
            if ( array[i][j] != wintable[i][j] )
                return 0;
        }
        return 1;
}

// Function to execute the game
void game(char name){
    
    char* array[n][m] = { {"1","2","3","4"}, {"6","8"," ","7"}, {"10","13","15","14"}, {"11","12","5","9"} };
    int chances = 10;
    for( int i=0 ; i<chances ; i++){
        printf("\n...Hello %s, %d moves remaining...",name,chances);
        char input[];
        scanf("%s",input);
        
        // switch case to implement respective input
        switch(input){
            case 'w':
                up(array); break;
            case 'a':
                left(array); break;
            case 's':
                down(array); break;
            case 'd':
                right(array); break;
            default:
                printf("---Wrong Input---"); break;
        }
        
        // comparing and printing the game status
        char* wintable[n][m] = {{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15"," "}};
        
        if ( compare(array,wintable)==0 && chances==10 )
             printf("---YOU LOSE---");
        else if ( compare(array,wintable)==1 )
             printf("---YOU WIN---");
    }
}

// Driver code a.k.a main() function
int main()
{
    char name[30];
    printf("Enter your name: ");
    scanf("%[^\n]s",name);
    displayRules(name);
    game(name);
    return 0;
}
