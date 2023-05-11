#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef enum{
    Rock,
    Paper,
    Scissors,
    Lizard,
    Spock,
} LRS_Choice;

enum result {
    loss,
    draw,
    win,
};

void getUserChoice(LRS_Choice *choice);
void getComputerChoice(LRS_Choice *choice);
void printWinner(enum result graph[5][5], LRS_Choice comp, LRS_Choice user);
char* decodeNumber(int num);

int main (void) {
    // Graph that saves the result
    enum result result_graph[][5] =
            {
                {draw, loss, win, win, loss},
                {win, draw, loss, loss, win},
                {loss, win, draw, win, loss},
                {loss, win, loss, draw, win},
                {win, loss, win, loss, draw}
            };
    LRS_Choice Computer;
    LRS_Choice User;
    printf("Rock Lizard Spock!\n_______________________\n");
    while(1){
        getUserChoice(&User);
        getComputerChoice(&Computer);
        printWinner(result_graph, Computer, User);
    }
}

void getUserChoice(LRS_Choice *choice) {
    int temp;
    printf("0 - Exit\n1 - Rock\n2 - Paper\n 3 - Scissors\n4 - Lizard\n5 - Spock\n\nYour choice:");
    scanf("%d", &temp);
    if (!temp)
    {
        printf("Spiel wird beendet...\n");
        exit(0);
    } else {
        *choice = temp - 1;
        printf("\nYou chose %s\n", decodeNumber(*choice));
    }
}

void getComputerChoice(LRS_Choice *choice) {
    time_t t;
    srand((unsigned) time(&t));
    *choice = (int) floor(rand() / (double) RAND_MAX * Spock);
    printf("The computer chose %s\n", decodeNumber(*choice));
}

void printWinner(enum result graph[5][5], LRS_Choice comp, LRS_Choice user) {
    if(graph[comp][user] == draw) {
        printf("It's a draw\n\n");
    } else if (graph[user][comp] == win){
        printf("You won!\n\n");
    } else {
        printf("You lost!\n\n");
    }
}

char* decodeNumber(int num)
{
    switch (num) {
        case Rock: return "Rock";
        case Paper: return "Paper";
        case Scissors: return "Scissors";
        case Lizard: return "Lizard";
        case Spock: return "Spock";
    }
}