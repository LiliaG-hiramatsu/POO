#include "pantalla.h"

Pantalla::Pantalla(int _x, int _y, int _w, int _h, int _r){
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  r = _r;
}

void Pantalla::mostrar(){
  int Rx = (w-1)/2;
  int Ry = (h-1)/2;
  int contador = 0;
  srand(time(NULL));
  int k = 1;
  do {
    x = 1 + rand() % w - 1;
    y = 1 + rand() % h - 1;
    //cout << "Punto[" << k << "]: (" << x << "," << y << ")\n";
    if (x < Rx+r && x > Rx-r && y < Ry+r && y > Ry-r) {
      contador++;
    }
    k++;
  } while(k <= 1000);
  float porcentaje = (float(contador)/1000)*100;
  cout << "Hay un " << porcentaje << " por ciento de puntos dentro de la circunferencia." << endl;
}
