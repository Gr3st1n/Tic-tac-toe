#include <stdio.h>
#include <stdlib.h>
#define BOXES 10

#ifdef _WIN32
    #define TERM_CLEAR "cls"
#else
    #define TERM_CLEAR "clear"
#endif

char grid[BOXES] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void initializeGrid(){
    grid[1] = '1';
    grid[2] = '2';
    grid[3] = '3';
    grid[4] = '4';
    grid[5] = '5';
    grid[6] = '6';
    grid[7] = '7';
    grid[8] = '8';
    grid[9] = '9';
}

int choiceMenu(){
    system(TERM_CLEAR);
    int choice = 0;
    printf("----------------------------\n");
    printf("|  WELCOME TO TIC-TAC-TOE  |\n");
    printf("----------------------------\n");
    printf("- Decide what to do: \n");
    printf("[1] PvP \n[2] Exit\n");
    printf("Enter: ");
    scanf("%d", &choice);
    while(choice < 1 || choice > 2){
        printf("Invalid value, please try again: \n");
        printf("Enter: ");
        scanf("%d", &choice);
    }
    return choice;
}

int restartChoice(){
    int choice = 0;
    printf("- Congratulation! Decide what to do: \n");
    printf("[1] Restart the command\n [2] Return to menu\n");
    printf("Enter: ");
    scanf("%d", &choice);
    while(choice < 1 || choice > 2){
        printf("Invalid value, please try again: \n");
        printf("Enter: ");
        scanf("%d", &choice);
    }
    return choice;
}

void printGrid(){
    system(TERM_CLEAR);
    printf("-------\n");
    printf("| PVP |\n");
    printf("-------\n");
    printf("Player [1] => X\n");
    printf("Player [2] => O\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[1], grid[2], grid[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[4], grid[5], grid[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[7], grid[8], grid[9]);
    printf("     |     |     \n\n");
}

int winnerPick(){
    if(grid[1] == grid[2] && grid[2] == grid[3]){
        return 1;
    }else if(grid[1] == grid[4] && grid[4] == grid[7]){
        return 1;
    }else if(grid[1] == grid[5] && grid[5] == grid[9]){
        return 1;
    }else if(grid[2] == grid[5] && grid[5] == grid[8]){
        return 1;
    }else if(grid[3] == grid[6] && grid[6] == grid[9]){
        return 1;
    }else if(grid[3] == grid[5] && grid[5] == grid[7]){
        return 1;
    }else if(grid[4] == grid[5] && grid[5] == grid[6]){
        return 1;
    }else if(grid[7] == grid[8] && grid[8] == grid[9]){
        return 1;
    }else if(grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
        grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7] 
        != '7' && grid[8] != '8' && grid[9] != '9'){
        return 0;
    }else{
        return -1;
    }
}

void PVP(){
    int player = 1;
    int matchOutcome = 0;
    int playerChoice;
    char sign;
    do{
        printGrid();
        player = (player % 2) ? 1 : 2;
        printf("It's player %d turn, enter the number corresponding to the number of the box: \n", player);
        printf("Enter: ");
        scanf("%d", &playerChoice);
        sign = (player == 1) ? 'X' : 'O';
        if(playerChoice == 1 && grid[1] == '1'){
            grid[1] = sign;
        }else if(playerChoice == 2 && grid[2] == '2'){
            grid[2] = sign;
        }else if(playerChoice == 3 && grid[3] == '3'){
            grid[3] = sign;
        }else if(playerChoice == 4 && grid[4] == '4'){
            grid[4] = sign;
        }else if(playerChoice == 5 && grid[5] == '5'){
            grid[5] = sign;
        }else if(playerChoice == 6 && grid[6] == '6'){
            grid[6] = sign;
        }else if(playerChoice == 7 && grid[7] == '7'){
            grid[7] = sign;
        }else if(playerChoice == 8 && grid[8] == '8'){
            grid[8] = sign;
        }else if(playerChoice == 9 && grid[9] == '9'){
            grid[9] = sign;
        }else{
            printf("--Invalid Move--");
            player--;
        }
        matchOutcome = winnerPick();
        player ++;
    } while (matchOutcome == -1);
    printGrid();
    if(matchOutcome == 1){
        player--;
        printf("Congratulations player %d, you won!", player);
    }else if(matchOutcome == 0){
        printf("The match ended in a draw");
    }
    initializeGrid();
}

int main(){
    int choice;
    int secondChoice;
    do{
        choice = choiceMenu();
        switch(choice){
            case 1:
            do{
                PVP ();
                secondChoice = restartChoice();
            }while(secondChoice == 1);
            break;
            case 2:
                system(TERM_CLEAR);
                printf("Thanks for playing :)");
                printf("GitHub: Gr3st1n");
            break;
        }
    } while (choice != 2);
}