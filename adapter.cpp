/*
 * adapter.cpp
 * http://www.techscore.com/tech/DesignPattern/Adapter/Adapter2.html/
 * AdapterパターンのC++による実装
 * 2016/06/02 Y.Tanaka
 */

#include <iostream>
#include <memory>

using namespace std;

// Taro
class Taro {
 public:
  void enjoyWithAllClassmate(){
    cout << "Taro: ";
    cout << "みんなで楽しむ" << endl;
  }
};

// Chairperson
class Chairperson {
 public:
  virtual ~Chairperson(){}
  virtual void organizeClass() = 0;
};

// NewTaro
class NewTaro: private Taro, public Chairperson {
 public:
  void organizeClass() {
    (*this).enjoyWithAllClassmate();
  }
};

// Hanako
class Hanako: public Chairperson {
 private:
  unique_ptr<Taro> taro;
 public:
  Hanako():taro(new Taro()){}
  void organizeClass();
};


void Hanako::organizeClass() {
    cout << "Hanako:";
    (*taro).enjoyWithAllClassmate();
  }

// main
int main(int, char const*[])
{
  /* 継承を利用したAdapterパターン */
  unique_ptr<Chairperson> chairperson_inherited;
  chairperson_inherited = make_unique<NewTaro>();
  chairperson_inherited->organizeClass();

  /* 移譲を利用したAdapterパターン */
  unique_ptr<Chairperson> chairperson_transfered;
  chairperson_transfered = make_unique<Hanako>();
  chairperson_transfered->organizeClass();

  return 0;
}
