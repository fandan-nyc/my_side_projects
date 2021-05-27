#include <string>

class InputBuffer {
public:
  const std::string & getBuffer();
  void readUserInput();
private:
  std::string buffer_;
};
