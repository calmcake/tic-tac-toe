#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define X 88
#define O 79
#define SPACE 32

int game_field[] = {
    SPACE, SPACE, SPACE,
    SPACE, SPACE, SPACE,
    SPACE, SPACE, SPACE };

int user_char;
int bot_char;

void select_char(){
    printf("Выберите символ (X или O) - ");
    scanf("%c", &user_char);

    if (user_char == X){
        bot_char = O;
    }else{
        bot_char = X;
    }
    
}

void user_step(){
    int user_step;

    do{
        printf("Ведите номер ячейки (от 1 до 9) - ");
        scanf("%d", &user_step);
    } while (game_field[user_step - 1] == X || game_field[user_step - 1] == O);
    

    game_field[user_step - 1] = user_char;
}

void bot_step(){
    int bot_step;

    do{
        bot_step = rand() % 10;
    } while (game_field[bot_step] == X || game_field[bot_step] == O);

    game_field[bot_step] = bot_char;
    
}

int check_if_win(){
    int stop_game = 1;

    if (game_field[0] == X && game_field[1] == X && game_field[2] == X || 
        game_field[3] == X && game_field[4] == X && game_field[5] == X ||
        game_field[6] == X && game_field[7] == X && game_field[8] == X ||
        game_field[0] == X && game_field[4] == X && game_field[8] == X ||
        game_field[2] == X && game_field[4] == X && game_field[6] == X || 
        game_field[1] == X && game_field[4] == X && game_field[7] == X ||
        game_field[2] == X && game_field[5] == X && game_field[8] == X ||
        game_field[3] == X && game_field[6] == X && game_field[9] == X ){
        printf("THE WINNER IS X\n");

        stop_game = 0;
    }

    if (game_field[0] == O && game_field[1] == O && game_field[2] == O || 
        game_field[3] == O && game_field[4] == O && game_field[5] == O ||
        game_field[6] == O && game_field[7] == O && game_field[8] == O ||
        game_field[0] == O && game_field[4] == O && game_field[8] == O ||
        game_field[2] == O && game_field[4] == O && game_field[6] == O || 
        game_field[1] == O && game_field[4] == O && game_field[7] == O ||
        game_field[2] == O && game_field[5] == O && game_field[8] == O ||
        game_field[3] == O && game_field[6] == O && game_field[9] == O ){
        printf("THE WINNER IS O\n");

        stop_game = 0;
    }
    
    return stop_game;
}

void display_field(){
    printf("+---+---+---+\n");

    for (int index = 0; index < 9; index++){
        if (index % 3 == 0 && index != 0){
            printf("|");
            printf("\n+---+---+---+\n");
        }
        printf("| %c ", game_field[index]);
    }
    
    printf("|");
    printf("\n+---+---+---+\n");
}

int main(){
    srand(time(NULL));
    select_char();

    while (check_if_win()){
        display_field();
        user_step();
        bot_step();
    }
    display_field();
}