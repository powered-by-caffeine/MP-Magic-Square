#include <stdio.h>
#include <windows.h>

#define A 3

#define TRUE 1
#define FALSE 0

void displayDivider()
{
    int i;

    printf("\n"); 

    for (i = 0; i < 50; i++)
    {
        printf("─");//prints a divider
    }

    printf("\n\n");
}

void displayError()
{
    printf("\a"); //plays a sound
    printf("\nInvalid Input. Please try again.\n");
}

void displayStart()
{
    displayDivider();
    printf("Programmed by: \n");
    printf("Robee Feliciano, Derrick Valdellon, and Sean Grande\n\n");

    printf("Instructions: \n");
    printf("- Each player takes turns selecting from a group of\n pegs that contain a value from 1-9\n (a peg cannot be used again!)\n\n");
    

    printf("- The players then get to select a location on the\n board to place their peg.\n\n The board layout looks like this: \n");
    printf("\t\t┌───┬───┬───┐\n");
    printf("\t\t│ 1 │ 2 │ 3 │\n");
    printf("\t\t├───┼───┼───┤\n");
    printf("\t\t│ 4 │ 5 │ 6 │\n");
    printf("\t\t├───┼───┼───┤\n");
    printf("\t\t│ 7 │ 8 │ 9 │\n");
    printf("\t\t└───┴───┴───┘\n\n");

    printf("- The first to complete a row / column that is\n equal to 15 wins!\n");
    printf("- Alternatively, the first to complete a row /\n column that is less than 15 loses.\n\n");

    printf("Enjoy! :)\n");
}

void displayBoard(int board[A][A])
{
    int i, j; // row and column

    printf("\t\t┌───┬───┬───┐\n");

    for (i = 0; i < A; i++) 
    {
        printf("\t\t");
        for (j = 0; j < A; j++) 
        {
            if(board[i][j] == 0)
            {
                printf("│   ");
            } 
            else 
            {
                printf("│ %d ", board[i][j]);
            }
            
        }
        printf("│\n");

        if (i < A - 1) 
        {
            printf("\t\t├───┼───┼───┤\n");
        }
    }

    printf("\t\t└───┴───┴───┘\n");
    printf("\n");

    /*
    EXPECTED OUTPUT

        0   1   2                [i][j]
    ┌───┬───┬───┐
    │ 1 │ 2 │ 3 │ 0  [0][0] | [0][1] | [0][2]
    ├───┼───┼───┤
    │ 4 │ 5 │ 6 │ 1  [1][0] | [1][1] | [1][2]
    ├───┼───┼───┤
    │ 7 │ 8 │ 9 │ 2  [2][0] | [2][1] | [2][2]
    └───┴───┴───┘
    */
}

int isOver(int board[A][A]) //returns the sum of a row/col that is not empty
{
    int i;
    int sum = 0;

    // check rows
    for (i = 0; i < A; i++) 
    {
        if ((board[i][0] + board[i][1] + board[i][2]) == 15) 
        {
            sum = 15;
        } 
        else if ((board[i][0] + board[i][1] + board[i][2]) < 15) 
        {
            if ((board[i][0] != 0) && (board[i][1] != 0) && (board[i][2] != 0)) 
            {
                sum = board[i][0] + board[i][1] + board[i][2];
            }
        }
    }

    // check columns
    for (i = 0; i < A; i++) 
    {
        if ((board[0][i] + board[1][i] + board[2][i]) == 15) 
        {
            sum = 15;
        } 
        else if ((board[0][i] + board[1][i] + board[2][i]) < 15) 
        {
            if ((board[0][i] != 0) && (board[1][i] != 0) && (board[2][i] != 0)) 
            {
                sum = board[0][i] + board[1][i] + board[2][i];
            }
        }
    }


    return sum;
}

void playerMove(int board[A][A], int turn, int PEGS[]) 
{
    int playerPeg;
    int V = FALSE;
    int P;
    int i;

    printf("\nAvailable pegs: ");
        
    for (i = 0; i < 9; i++)
    {
        if (PEGS[i] != 0)
        {
            printf("%d ", PEGS[i]);
        }
    }

    printf("\n");


    /*ASK FOR PEG*/
    do 
    {
        if (turn == TRUE) 
        {
            printf("\nPlayer A Enter Peg: ");
            scanf("%d", &playerPeg);
        } 
        else if (turn == FALSE) 
        {
            printf("\nPlayer B Enter Peg: ");
            scanf("%d", &playerPeg);
        }

        if (playerPeg != 0) //this needs to be checked first because a used peg will be represented as a 0 in the array
        {
            for (i = 0; i < 9; i++) 
            {
                if (playerPeg == PEGS[i]) 
                {
                    PEGS[i] = 0; //converts the peg number from the array of pegs so the player can't select it again
                    V = TRUE;
                }
            }
        }
        

        if (V == FALSE) 
        {
            displayError();
        }

    } while (V == FALSE);

    /*ASK FOR LOCATION*/
    V = FALSE;

    while (V == FALSE) 
    {
        printf("\nEnter Position on board: ");
        scanf("%d", &P);

        switch (P) 
        {
            case 1: //T-L
                if (board[0][0] == 0) 
                {
                    board[0][0] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 2: //T-C
                if (board[0][1] == 0) 
                {
                    board[0][1] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 3: //T-R
                if (board[0][2] == 0) 
                {
                    board[0][2] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 4: //M-L
                if (board[1][0] == 0) 
                {
                    board[1][0] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 5: //M-C
                if (board[1][1] == 0) 
                {
                    board[1][1] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 6: //M-R
                if (board[1][2] == 0) 
                {
                    board[1][2] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 7: //B-L
                if (board[2][0] == 0) 
                {
                    board[2][0] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 8: //B-C
                if (board[2][1] == 0) 
                {
                    board[2][1] = playerPeg;
                    V = TRUE;
                } 

                break;

            case 9: //B-R
                if (board[2][2] == 0) 
                {
                    board[2][2] = playerPeg;
                    V = TRUE;
                } 

                break;

            default:
                break; 
        }

        if (V == FALSE)
        {
            displayError();
        }
    }
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8); //function in windows.h> that translates UTF8 characters to be printed properly in the console
    int turn = TRUE;
    int over = FALSE;
    int sum = 0;

    char reset = 'Y';


    displayStart();

    while (reset == 'Y' || reset == 'y')
    {
        turn = TRUE;
        over = FALSE;
        sum = 0;

        reset = 'Y';
            
        int board[A][A] =  {{0, 0, 0}, 
                            {0, 0, 0}, 
                            {0, 0, 0}};

        int Peg[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  


       

        while (over == FALSE) 
        {
            displayDivider();

            displayBoard(board);

            if (turn == TRUE) 
            {
                printf("\t       Player A's turn\n\n");
            } 
            else if (turn == FALSE) 
            {
                printf("\t       Player B's turn\n\n");
            }

            playerMove(board, turn, Peg);

            sum = isOver(board);

            if (sum > 0)
            {
                over = TRUE;
            }
            else
            {
                turn = !turn; //switches turns
            }
        }

        displayDivider();

        displayBoard(board);

        if ((turn && over == TRUE) && sum == 15) // turn A over and sum of row/col = 15
        {
            printf("\t\tPlayer A wins!\n");
        } 
        else if ((!turn && over == TRUE) && sum == 15) // turn B over and sum of row/col == 15
        {
            printf("\t\tPlayer B wins!\n");
        } 
        else if ((turn && over == TRUE) && sum < 15) // turn A over and sum of row/col < 15
        {
            printf("\t\tPlayer B wins!\n");
        } 
        else if ((!turn && over == TRUE) && sum < 15) // turn B over and sum of row/col < 15
        {
            printf("\t\tPlayer A wins!\n");
        }

        printf("\n");

        displayDivider();
        printf("Play again? (Y/N)\n\n");

        printf("Input: ");
        scanf(" %c", &reset);

    }
    
    

    return 0;
}