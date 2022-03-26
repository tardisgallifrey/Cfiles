#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dave.h"

#define MAX_INDEX 4

char messages[MAX_INDEX][100];

int add_msg(char *message, int index);

int main(){
    
    char *msg;
    msg = (char *)malloc(100);
    int index = 0;
    
    while(1){

        printf("Enter a chosen message:   ");
        fgets(msg, 100, stdin);

    index = add_msg(msg, index);
    
    for(int i = 0; i < index; i++){
        if(strlen(messages[i]) > 0){
            printf("%d   %s", i, messages[i]);
        }
        sleep(1);
    }
    
    free(msg);
    printf("End of routine.\n");
    sleep(1);
    }

    free(messages);
    return 0;
}

int add_msg(char *message, int index){
    switch(index){
        case MAX_INDEX:
                for(int i = MAX_INDEX; i > 0; i--){
                    strcpy(messages[i - 1], messages[i - 2]);
                }
                index = 0;
                strcpy(messages[index], message);
                break;
        default:
            strcpy(messages[index], message);
            index++;
            break;
    }

    return index;
}