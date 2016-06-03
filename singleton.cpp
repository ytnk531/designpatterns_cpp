#include <iostream>

class RegisterNote{
 private:
  int num;
  static RegisterNote* registerNote;
  RegisterNote():num(3){ }
 public:
  static RegisterNote* getInstance(){
    return registerNote;
  }
  void write(){
    std::cout<<"num:" << num++ <<std::endl;
  }
};

RegisterNote* RegisterNote::registerNote = new RegisterNote();

int main(void) {
  RegisterNote* rn = RegisterNote::getInstance();
  rn->write();
  RegisterNote* new_rn = rn->getInstance();
  new_rn->write();
  return 0;
}
