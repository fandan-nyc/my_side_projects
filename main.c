#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InputBuffer_t {
    char* buff;
    size_t buff_len;
    ssize_t input_len; // the number of chars;
};

typedef struct InputBuffer_t InputBuffer;

InputBuffer* new_input_buffer(){
    InputBuffer* res = malloc(sizeof(InputBuffer));
    res -> buff = NULL;
    res -> buff_len = 0 ;
    res -> input_len = 0;
    return res;
}

void print_prompt(){
    printf("db > ");
}

void read_input(InputBuffer* ib){
    ssize_t bytes_read = getline(&(ib->buff), &(ib->buff_len), stdin);
    if (bytes_read <= 0){
        printf("error reading input\n");
        exit(EXIT_FAILURE);
    }
    ib->input_len = bytes_read -1 ; 
    ib->buff[bytes_read-1] = 0;
}

int main(int argc, char* argv[]){
    InputBuffer* ib = new_input_buffer();
    while(true){
        print_prompt();
        read_input(ib);
        if( strcmp(ib->buff, ".exit") == 0 ){
            exit(EXIT_SUCCESS);
        }else {
            printf("command: %s not recognized.\n", ib->buff);
        }
    }
}
