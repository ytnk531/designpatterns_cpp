#include <iostream>

using namespace std;


class Cuttable{
 public:
  virtual ~Cuttable(){}
};

class Potato: public Cuttable{};

class Wood: public Cuttable{};

class CutPrint {
 protected:
  virtual void draw(Cuttable) = 0;
  virtual void cut(Cuttable) = 0;
  virtual void print(Cuttable) = 0;
  Cuttable* createCuttable(){
    return new Wood();
  }

 public:
  virtual ~CutPrint(){}
  void createCutPrint(){
    Cuttable* hanzai = createCuttable();
    draw(*hanzai);
    cut(*hanzai);
    print(*hanzai);
  }
};

class ImagawaCutPrint : public CutPrint{
 protected:
  void draw(Cuttable){
    cout << "マンガの絵を描く" 
         << endl;
  }

  void cut(Cuttable){
    cout << "彫刻刀を利用して器用に掘る" 
         << endl;
  }

  void print(Cuttable){
    cout << "インクとして、自分の血を使いプリントする" 
         << endl;
  }
  Cuttable* createCuttable(){
    return new Potato();
  }
};

int main(int, char const*[])
{
  CutPrint* imagawa = new ImagawaCutPrint();
  imagawa->createCutPrint();
  return 0;
}
