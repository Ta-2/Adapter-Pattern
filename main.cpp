#include <iostream>
#include <string>
#include "Adaptor.hpp"
using namespace std;

class Adaptor_interface {
public:
  virtual void Item_str(void) = 0;
  virtual ~Adaptor_interface(){}
};

class Item {
private:
  string name_;
public:
  explicit Item (const string& name): name_(name){}
  ~Item (){}
  void Item_str (void){
    cout << name_ << endl;
  }
};

class Adaptor: public Item, public Adaptor_interface{
public:
    explicit Adaptor(const string& name) : Item(name){}
    ~Adaptor(){}
    void Item_str(void){
      Item_str();
    }
};

int main(){
  Adaptor *a1 = new Adaptor("Taro");
  a1->Item_str();

  return 0;
}
