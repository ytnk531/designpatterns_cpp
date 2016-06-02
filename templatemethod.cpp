#include <iostream>

using namespace std;

class Cuttable {
 public:
  virtual ~Cuttable(){}
};
class Wood: public Cuttable { };

class WoodCutPrint {
 public:
  virtual ~WoodCutPrint(){}
  virtual void draw(Cuttable hanzai) = 0;
  virtual void cut(Cuttable hanzai) = 0;
  virtual void print(Cuttable hanzai) = 0;
  void createWoodCutPrint(){
    Wood *hanzai = new Wood();
    draw(*hanzai);
    cut(*hanzai);
    print(*hanzai);
    delete hanzai;
  }
};

class TanakaWoodCutPrint :public WoodCutPrint{
 public:
  void draw(Cuttable){
    cout
      << "hanzai にマジックを使って大好きな女の子の絵を描く"
      << endl;
  }
  void cut(Cuttable){
    cout
      << "彫刻刀を使って細部まで丁寧に hanzai を彫る"
      << endl;
  }
  void print(Cuttable){
    cout
      << "版画インクと馬簾を使って豪快にプリントする"
      << endl;
  }
};

int main(int const, char const*[])
{
  WoodCutPrint* tanaka = new TanakaWoodCutPrint();
  tanaka->createWoodCutPrint();
  return 0;
}
