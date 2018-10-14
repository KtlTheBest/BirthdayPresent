#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int code[] = {9, 44, 14, 14, 47, 72, 45, 78, 142, 13, 140, 44, 47};

char answer[20];

void flush(){
    while(getchar() != '\n');
}

void decode(){
    int i;
    int n = sizeof(code) / sizeof(code[0]);
    for(i = 0; i < n; ++ i){
        answer[i] = ((code[i] >> 5) | (code[i] << 3)) & 255;
    }
    answer[n] = 0;
}

void printGuess(int size){
    static int n = sizeof(code) / sizeof(code[0]);
    int i = 0;
    for(; i < n; ++ i){
        putchar(' ');
        if(i >= size){
            putchar('_');
        } else {
            putchar(answer[i]);
        }
        putchar(' ');
    }
    putchar('\n');
}

void finishGame(char c[]){
    printf("Correct! The answer is:\n");
    int i;
    for(i = 0; i < 13; ++ i){
        putchar(answer[i]);
        if(i == 4) putchar(' ');
    }
    printf(", %s", c);
    printf("!\n");
}

void playGame(){
    int count = 0;
    printf("Please enter your name: ");
    char c[100];
    scanf("%s", c);
    flush();
    printf("Hello %s. I suspect that today's your birthday)\nWould you like to solve a quiz?\n", c);
    int n = sizeof(code) / sizeof(code[0]);
    while(count != n){
        printGuess(count);
        printf("Choose a letter ");
        int pos = rand() % 4;
        char arr[4];
        arr[pos] = answer[count];
        int i = 0;
        for(; i < 4; ++ i){
            if(i != pos){
                arr[i] = (rand() % 26) + 'a';
            }
        }

        putchar('(');
        for(i = 0; i < 4; ++ i){
            if(i){
                printf(", ");
            }
            printf("%c", arr[i]);
        }

        printf("): ");
        char guess;
        scanf("%c", &guess);
        flush();
        if(guess == arr[pos] || guess == tolower(arr[pos])){
            count ++;
        }
    }
    finishGame(c);
}

int main(){
    srand(time(0));
    decode();
    playGame();
    return 0;
}
