#include "movilAutonomo2.h"

MovilAutonomo2::MovilAutonomo2(int x, int y, int x0, int y0, int W, int H, int hacia, int cargaInicial, int indicador, int dist) : Movil(x, y, x0, y0, W, H, hacia) {
  this->cargaInicial = cargaInicial;
  this->indicador = indicador;
  this->dist = dist;
}

int MovilAutonomo2::getXactual(int W){
  srand(time(NULL));
  x0 = 1 + rand() % W - 1;
  return this -> x0;
}

int MovilAutonomo2::getYactual(int H){
  srand(time(NULL));
  y0 = 1 + rand() % H - 1;
  return this -> y0;
}

int MovilAutonomo2::getcarga_inicial(){
  srand(time(NULL));
  cargaInicial = rand() % 101 + 200;
  return this -> cargaInicial;
}

void MovilAutonomo2::moverse(int x0, int y0, int hacia){
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

int MovilAutonomo2::getPosicionX(){
  return this -> x;
}

int MovilAutonomo2::getPosicionY(){
  return this -> y;
}

int MovilAutonomo2::consumo(int dist){
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
