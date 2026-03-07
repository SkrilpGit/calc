#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*
 * Make an iterative calculator that recognises numbers and splits them by operations
 * we want:
 * number and operator recognising
 * iterative processing that is resistant to non typical inputs
 * support for ()
 * quitting on "q" "quit" "exit" "kill" and any other thingys
 * support + - * / % ^ log
 * more to come!
 */

bool isOperation(char c){
    switch (c){
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '*':
            return true;
            break;
        case '/':
            return true;
            break;
        case '%':
            return true;
            break;
        case '^':
            return true;
            break;
        default:
            return false;
            break;
    }
}

int main(){
    int ans = 0;
    int size = 8;
    char item[size];
    bool operation = false;
    int c;
    c = getchar();
    while(c != '\n'){
        int i = 0;
        while(c != isOperation(c) && c != '\n'){
            if (i > size){
               memmove(item, item, size + 4);
               size += 4;
            }
            if (c == ' ')
                continue;
            item[i] = c - 48;
            i++;
            c = getchar();
        }
        if (c == isOperation(c))
            operation = true;
       for (int k = 0; k <= i; k++){
           if (item[k] < 0 || item[k] > 9){
               printf("Invalid character, not an int or operation: %c", c + 48);
               return 0;
           }
           ans *= k;
           ans += item[k];
       }
    }
    printf("Hello Calc\n");
    return 1;
}
