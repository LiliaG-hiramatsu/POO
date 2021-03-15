#ifndef MOVILPRINCIPAL_H
#define MOVILPRINCIPAL_H
#include<cstdlib>
#include<string>
#include<ctime>
#include<iostream>
using namespace std;

class Movil{
protected:
  int x, y, x0, y0, W, H, hacia;
public:
  Movil(int, int, int, int, int, int, int);
  void mostrarNombre();
  virtual int getXactual(int W);
  virtual int getYactual(int H);
  virtual void moverse(int x0, int y0, int hacia);
  virtual int getPosicionX();
  virtual int getPosicionY();
};

#endif
