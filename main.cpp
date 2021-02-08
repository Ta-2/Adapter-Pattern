#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Adaptor.hpp"
using namespace std;

class Weapon {
public:
  virtual ~Weapon(){};
};

class Sword : public Weapon {
public:
  void Sword_Attribute () { cout << "属性: 斬撃" << endl; }
};

class Adapted_Sword : public Adapter <Sword> {
public:
  void Adapt_function(){
    Adapt_class->Sword_Attribute();
  }
};

class Spear : public Weapon {
public:
  void Spear_Attribute () { cout << "属性: 刺突" << endl; }
};

class Adapted_Spear : public Adapter <Spear> {
public:
  void Adapt_function(){
    Adapt_class->Spear_Attribute();
  }
};

class Hammer : public Weapon{
public:
  void Hammer_Attribute () { cout << "属性: 打撃" << endl; }
};

class Adapted_Hammer : public Adapter <Hammer> {
public:
  void Adapt_function(){
    Adapt_class->Hammer_Attribute();
  }
};

int main(){
  vector<Weapon *> list;
  Weapon *sword = new Adapted_Sword();
  Weapon *spear = new Adapted_Spear();
  Weapon *hammer = new Adapted_Hammer();
  list.emplace_back(sword);
  list.emplace_back(spear);
  list.emplace_back(hammer);

  for( auto *it: list){
    if(dynamic_cast<Adapted_Sword *>(it) != NULL)dynamic_cast<Adapted_Sword *>(it)->Adapt_function();
    if(dynamic_cast<Adapted_Spear *>(it) != NULL)dynamic_cast<Adapted_Spear *>(it)->Adapt_function();
    if(dynamic_cast<Adapted_Hammer *>(it) != NULL)dynamic_cast<Adapted_Hammer *>(it)->Adapt_function();
  }

  return 0;
}
