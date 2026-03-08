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
        default:
            return false;
            break;
    }
}

int evaluate(int ans,char operator,char* input){
    /*
    printf("ans: %d, operator: %c, input: ",ans,operator);
    int k = 0;
    while (input[k] != 0)
        printf("%c", input[k++]);
    */
    int i = 0;
    int operand = 0;
    if (input[0] == '\n')
        return ans;

    while (!isOperation(input[i]) && input[i] != '\n'){
        if (operator == 0){
            if (i == 0){
                ans = 0;
                ans += input[i] - 48;
            }
            else{
            ans *= 10;
            ans += input[i] - 48;
            }
        }
        else{
            operand *= 10;
            operand += input[i] - 48;
        }
        i++;
    }
    if (operator != 0 && input[0] == '\n')
        return ans;
    else {
        switch (operator){
            case '+':
                ans += operand;
                break;
            case '-':
                ans -= operand;
                break;
            case '*':
                ans *= operand;
                break;
            case '/':
                ans /= operand;
                break;
            case '%':
                ans %= operand;
                break;
            default:
                break;
        }
        if (isOperation(input[i])){
            operator = input[i];
            i += 1;
        }
        int s = 0;
        while (input[s] != 0)
            s++;
        memmove(input, input + i, s*sizeof(char)-i);
        evaluate(ans,operator,input);
    }
}

bool quit(char* input){
    return (input[0] == 'q' || input[0] == 'Q');
}

bool parse(int ans){
    char input[32];
    int i = 0;
    int c;
    printf("input: ");
    while ((c = getchar()) != '\n' && i < 31) {
        if ((char)c == ' ')
            continue;
        else
        input[i++] = (char)c;
    }
    if (quit(input))
        return false;
    input[i] = '\n';
    ans = evaluate(ans, 0, input);
    printf("ans: %d\n", ans);
    parse(ans);
}

int main(){

    parse(0);

    return 1;
}
