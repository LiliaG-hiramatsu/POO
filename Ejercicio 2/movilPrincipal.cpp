#include "movilPrincipal.h"

Movil::Movil(int x, int y, int x0, int y0, int W, int H, int hacia){
  this->x = x;
  this->y = y;
  this->x0 = x0;
  this->y0 = y0;
  this->W = W;
  this->H = H;
  this->hacia = hacia;
}

void Movil::mostrarNombre(){
  cout << "MOVIL_MANUAL" << endl;
}

int Movil::getXactual(int W){
  srand(time(NULL));
  x0 = 1 + rand() % W - 1;
  return this -> x0;
}

int Movil::getYactual(int H){
  srand(time(NULL));
  y0 = 1 + rand() % H - 1;
  return this -> y0;
}

void Movil::moverse(int x0, int y0, int hacia){
  switch (hacia) {
    case 0:
      cout << "Ha salido del programa." << endl;
      break;
    case 1:
      y = y0 + 1;
      break;
    case 2:
      x = x0 + 1;
      break;
    case 3:
      y = y0 - 1;
      break;
    case 4:
      x = x0 - 1;
      break;
    default:
      break;
  }
}

int Movil::getPosicionX(){
  return this -> x;
}

int Movil::getPosicionY(){
  return this -> y;
}
