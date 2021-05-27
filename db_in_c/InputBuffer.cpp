#include "InputBuffer.h"
#include <iostream>

const std::string& InputBuffer::getBuffer(){
  if(this ->buffer_ == ""){
    throw "input buffer is not initialized";
  }
  return this ->buffer_;
}

void InputBuffer::readUserInput(){
  std::cin >> this->buffer_;
}
