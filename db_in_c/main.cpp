#include <iostream>
#include "InputBuffer.h"

const int EXIST_SUCCESS = 0 ;

void print_prompt() {
  std::cout << "sql> ";
}

int main(int argc, char* argv[]){
  InputBuffer inputBuffer;
  while(true){
    print_prompt();
    inputBuffer.readUserInput();
    if(inputBuffer.getBuffer() == ".exit"){
      exit(EXIST_SUCCESS);
    }else{
      std::cout << "unrecognized command: " << inputBuffer.getBuffer() << "\n";
    }
  }
}
