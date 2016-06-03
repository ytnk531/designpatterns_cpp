#include <iostream>
#include <array>

using namespace std;

class Cloneable{
 public:
  virtual ~Cloneable(){}
  virtual Cloneable* createClone() = 0;
};

class Paper : public Cloneable {
 private:
  string name;
 public:
  Paper(){}
  Paper(string n){ name = n; }
  Cloneable* createClone(){
    Paper* newPaper = new Paper();
    newPaper->name = name;
    cout << "createClone()" << endl;
    return newPaper;
  }
};

class Teacher{
 public:
  array<Paper,100> createManyCrystals();

 private:
  void drawCrystal(Paper){
    cout<<"時間がかかる"<<endl;
  }
  void cutAccordanceWithLine(Paper){
    cout<<"時間がかかる"<<endl;
  }
};

array<Paper,100> Teacher::createManyCrystals() {
  Paper *prototype = new Paper("雪の結晶");
  drawCrystal(*prototype);
  cutAccordanceWithLine(*prototype);

  array<Paper, 100> papers;

  for (int n = 0; n < (int)papers.size(); n++) {
    papers[n] = *(Paper*)(prototype->createClone());
  }
  return papers;
}


int main(void) {
  Teacher *you = new Teacher;
  array<Paper,100> crystals;
  crystals = you->createManyCrystals();
  return 0;
}
