#include "movilAutonomo.h"

MovilAutonomo::MovilAutonomo(int x, int y, int x0, int y0, int W, int H, int hacia, string ord, int cargaInicial, int indicador, int dist) : Movil(x, y, x0, y0, W, H, hacia, ord) {
  this->cargaInicial = cargaInicial;
  this->indicador = indicador;
  this->dist = dist;
}

int MovilAutonomo::getCarga_inicial(){
  srand(time(NULL));
  cargaInicial = rand() % 101 + 200;
  return this -> cargaInicial;
}

void MovilAutonomo::mover(int x0, int y0, int hacia){
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

string MovilAutonomo::getOrden() const{
  return this -> ord;
}

string MovilAutonomo::toString() const {
  stringstream ss;
  ss << this -> ord;
  return ss.str();
}

int MovilAutonomo::getX() const{
  return this -> x;
}

int MovilAutonomo::getY() const{
  return this -> y;
}

int MovilAutonomo::consumo(int dist){
  int _consumo, f = 0;
  indicador = cargaInicial;
  srand(time(NULL));
  _consumo = rand() % 21 + 20; //mAh
  while (f < dist){
    f++;
    if (f == dist){
      indicador = cargaInicial - f*_consumo;
    }
  }
  return this -> indicador;
}
