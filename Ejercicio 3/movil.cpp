#include "movil.h"

Movil::Movil(int x, int y, int x0, int y0, int W, int H, int hacia, string ord){
  this->x = x;
  this->y = y;
  this->x0 = x0;
  this->y0 = y0;
  this->W = W;
  this->H = H;
  this->hacia = hacia;
  this->ord = ord;
}

void Movil::mover(int x0, int y0, int hacia){
  switch (hacia) {
    case 0:
      ord = "SALIR";
      cout << "Ha salido del programa." << endl;
      break;
    case 1:
      ord = "ADELANTE";
      y = y0 + 1;
      break;
    case 2:
      ord = "DERECHA";
      x = x0 + 1;
      break;
    case 3:
      ord = "ATRAS";
      y = y0 - 1;
      break;
    case 4:
      ord = "IZQUIERDA";
      x = x0 - 1;
      break;
    case 5:
      ord = "TERMINAR";
      break;
    default:
      break;
  }
}

string Movil::getOrden() const{
  return this -> ord;
}

string Movil::toString() const {
  stringstream ss;
  ss << "orden " << this -> ord;
  return ss.str();
}

int Movil::getX() const{
  return this -> x;
}

int Movil::getY() const{
  return this -> y;
}
