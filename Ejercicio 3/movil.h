#ifndef MOVIL_H
#define MOVIL_H
#include<cstdlib>
#include<string>
#include<sstream>
#include<ctime>
#include<iostream>
using namespace std;
#include<list>

class Movil{
protected:
  int x, y, x0, y0, W, H, hacia;
  string ord;
public:
  Movil(int x, int y, int x0, int y0, int W, int H, int hacia, string ord);
  virtual int getX() const;
  virtual int getY() const;
  virtual void mover(int x0, int y0, int hacia);
  virtual string getOrden() const;
  virtual string toString() const;
};


#endif
