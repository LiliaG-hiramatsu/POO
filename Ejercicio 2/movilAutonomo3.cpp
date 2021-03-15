#include "movilAutonomo3.h"

MovilAutonomo3::MovilAutonomo3(int x, int y, int x0, int y0, int W, int H, int hacia, int cargaInicial, int indicador, int dist) : Movil(x, y, x0, y0, W, H, hacia) {
  this->cargaInicial = cargaInicial;
  this->indicador = indicador;
  this->dist = dist;
}

int MovilAutonomo3::getXactual(int W){
  srand(time(NULL));
  x0 = 1 + rand() % W - 1;
  return this -> x0;
}

int MovilAutonomo3::getYactual(int H){
  srand(time(NULL));
  y0 = 1 + rand() % H - 1;
  return this -> y0;
}

int MovilAutonomo3::getcarga_inicial(){
  srand(time(NULL));
  cargaInicial = rand() % 101 + 200;
  return this -> cargaInicial;
}

void MovilAutonomo3::moverse(int x0, int y0, int hacia){
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

int MovilAutonomo3::getPosicionX(){
  return this -> x;
}

int MovilAutonomo3::getPosicionY(){
  return this -> y;
}

int MovilAutonomo3::consumo(int dist){
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
