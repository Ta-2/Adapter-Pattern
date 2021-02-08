#ifndef ADA_HPP
#define ADA_HPP

using namespace std;

template <typename T>
class Adapter : public T {
public:
  virtual void Adapt_function () = 0;
  virtual ~Adapter(){};
  T *Adapt_class = new T();
};

#endif
