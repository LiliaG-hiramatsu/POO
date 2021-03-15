// El programa debe crear 1 móvil (manual) dentro de una grilla plana.
// El móvil posee un nombre único y conoce su posición actual, la
// secuencia de órdenes recibidas y la distancia total recorrida.
// Las dimensiones del plano y las órdenes de movimiento son dadas
// por el operador (para moverse puede usar el código estructurado
// en las diapositivas 20-21 de la presentación C vs C++).
// Crear también 3 objetos móviles autónomos (obtenidos a partir del
// anterior). Cada móvil está alimentado por una batería de carga inicial
// variable al azar entre 200-300 mAh y cuenta con un indicador de
// carga de la misma. Por cada unidad de distancia recorrida se
// consumen entre 20 a 40 mAh (constante al azar para el móvil).
// El reporte debe mostrar, en cada ciclo, la posición, la cadena de
// órdenes recibidas, las distancia y el tiempo que el móvil estuvo en
// movimiento desde su creación hasta que el operador eligió
// TERMINAR. Además del nivel de carga y consumo si corresponden.

#include "movilPrincipal.h"
#include "movilAutonomo1.h"
#include "movilAutonomo2.h"
#include "movilAutonomo3.h"

int main(){
  int w, h, i = 0, j = 0, i0 = 0, j0 = 0, distancia = 0, distancia1 = 0, distancia2 = 0, distancia3 = 0;
  int i1 = 0, i2 = 0, i3 = 0, j1 = 0, j2 = 0, j3 = 0,  i01 = 0, i02 = 0, i03 = 0, j01 = 0, j02 = 0, j03 = 0;
  double t0, tf;
  cout << "Ingresar dimensiones de la grilla" << endl;
  cout << "w = ";
  cin >> w;
  cout << "h = ";
  cin >> h;
  cout << "Elija la dirección de movimiento con:" << endl
        << "1. ADELANTE" << endl
        << "2. DERECHA" << endl
        << "3. ATRAS" << endl
        << "4. IZQUIERDA" << endl
        << "5. TERMINAR" << endl
        << "0. SALIR" << endl;
  bool b = true;
  int n = 1, n1 = 1, n2 = 1, n3 = 1, carga;
  int op_mover; //orden
  int ind; //indicador
  Movil *m;
  MovilAutonomo1 *m1;
  MovilAutonomo2 *m2;
  MovilAutonomo3 *m3;
  m = new Movil(i, j, i0, j0, w, h, op_mover); //MANUAL
  m1 = new MovilAutonomo1(i1, j1, i01, j01, w, h, op_mover, carga, ind, distancia1);
  m2 = new MovilAutonomo2(i2, j2, i02, j02, w, h, op_mover, carga, ind, distancia2);
  m3 = new MovilAutonomo3(i3, j3, i03, j03, w, h, op_mover, carga, ind, distancia3);
  int flat = 1;
  while (flat == 1) {
    b = true;
    int movil;
    cout << "Elegir el movil (0, 1, 2, 3)" << endl;
    cin >> movil;
    if (movil == 0) {
      //MOVIL MANUAL
      cout << "Nombre del móvil: " << endl;
      m -> mostrarNombre();
      cout << "La posición actual es: (";
      i0 = m -> getXactual(w);
      j0 = m -> getYactual(h);
      cout << i0 << "," << j0 << ")" << endl;
      i = i0;
      j = j0;
      cout << "Insertar secuencia de operaciones: " << endl;
      const char *cadenaOrden0[20];
      while (b == true){
        cin >> op_mover;
        m -> moverse(i0, j0, op_mover);
        if (op_mover == 1) {
          cadenaOrden0[n] = "ADELANTE";
          distancia++;
          j = m -> getPosicionY();
          j0 = j;
        }
        if (op_mover == 2) {
          cadenaOrden0[n] = "DERECHA";
          distancia++;
          i = m -> getPosicionX();
          i0 = i;
        }
        if (op_mover == 3) {
          cadenaOrden0[n] = "ATRAS";
          distancia++;
          j = m -> getPosicionY();
          j0 = j;
        }
        if (op_mover == 4) {
          cadenaOrden0[n] = "IZQUIERDA";
          distancia++;
          i = m -> getPosicionX();
          i0 = i;
        }
        if (op_mover == 5) {
          cadenaOrden0[n] = "TERMINAR";
          b = false;
        }
        if (op_mover == 0) {
          cadenaOrden0[n] = "SALIR";
          b = false;
        }
        if (i > w || i < 0 || j > h || j < 0) {
          cout << "Se sale de la grilla." << endl;
          b = false;
        }
        n++;
      }
      cout << "Nueva posición: (" << i << "," << j << ")" << endl;
      cout << "Secuencia de órdenes: " << endl;
      int k;
      for (k = 1; k < n; k++){
        cout << k << ") " << cadenaOrden0[k] << endl;
      }
      cout << "Distancia recorrida: " << distancia << " [m]" << endl;
    }

    if (movil == 1) {
      //MOVIL AUTONOMO 1
      t0 = clock();
      cout << "La posición actual es: (";
      i01 = m1 -> getXactual(w);
      j01 = m1 -> getYactual(h);
      cout << i01 << "," << j01 << ")" << endl;
      i1 = i01;
      j1 = j01;
      cout << "Carga inicial: ";
      carga = m1 -> getcarga_inicial();
      cout << carga << "[mAh]" << endl;
      ind = carga;
      cout << "Insertar secuencia de operaciones: " << endl;
      const char *cadenaOrden1[20];
      while (b == true){
        cin >> op_mover;
        m1 -> moverse(i01, j01, op_mover);
        if (op_mover == 1) {
          cadenaOrden1[n1] = "ADELANTE";
          distancia1++;
          j1 = m1 -> getPosicionY();
          j01 = j1;
        }
        if (op_mover == 2) {
          cadenaOrden1[n1] = "DERECHA";
          distancia1++;
          i1 = m1 -> getPosicionX();
          i01 = i1;
        }
        if (op_mover == 3) {
          cadenaOrden1[n1] = "ATRAS";
          distancia1++;
          j1 = m1 -> getPosicionY();
          j01 = j1;
        }
        if (op_mover == 4) {
          cadenaOrden1[n1] = "IZQUIERDA";
          distancia1++;
          i1 = m1 -> getPosicionX();
          i01 = i1;
        }
        if (op_mover == 5) {
          cadenaOrden1[n1] = "TERMINAR";
          tf = clock();
          b = false;
        }
        if (op_mover == 0) {
          cadenaOrden1[n1] = "SALIR";
          tf = clock();
          b = false;
        }
        if (i1 > w || i1 < 0 || j1 > h || j1 < 0) {
          cout << "Se sale de la grilla." << endl;
          tf = clock();
          b = false;
        }
        n1++;
      }
      double tiempo = (double(tf-t0)/CLOCKS_PER_SEC);
      cout << "Nueva posición: (" << i1 << "," << j1 << ")" << endl;
      cout << "Secuencia de órdenes: " << endl;
      int k;
      for (k = 1; k < n1; k++){
        cout << k << ") " << cadenaOrden1[k] << endl;
      }
      cout << "Distancia recorrida: " << distancia1 << " [m]" << endl;
      ind = m1 -> consumo(distancia1);
      int c = carga - ind;
      cout << "Consumió: " << c << " [mAh]" << endl;
      cout << "Carga restante: " << ind << " [mAh]" << endl;
      cout << "Tiempo del movimiento: " << tiempo << "[s]" << endl;
    }

    if (movil == 2) {
      //MOVIL AUTONOMO 2
      t0 = clock();
      cout << "La posición actual es: (";
      i02 = m2 -> getXactual(w);
      j02 = m2 -> getYactual(h);
      cout << i02 << "," << j02 << ")" << endl;
      i2 = i02;
      j2 = j02;
      cout << "Carga inicial: ";
      carga = m2 -> getcarga_inicial();
      cout << carga << "[mAh]" << endl;
      ind = carga;
      cout << "Insertar secuencia de operaciones: " << endl;
      const char *cadenaOrden2[20];
      while (b == true){
        cin >> op_mover;
        m2 -> moverse(i02, j02, op_mover);
        if (op_mover == 1) {
          cadenaOrden2[n2] = "ADELANTE";
          distancia2++;
          j2 = m2 -> getPosicionY();
          j02 = j2;
        }
        if (op_mover == 2) {
          cadenaOrden2[n2] = "DERECHA";
          distancia2++;
          i2 = m2 -> getPosicionX();
          i02 = i2;
        }
        if (op_mover == 3) {
          cadenaOrden2[n2] = "ATRAS";
          distancia2++;
          j2 = m2 -> getPosicionY();
          j02 = j2;
        }
        if (op_mover == 4) {
          cadenaOrden2[n2] = "IZQUIERDA";
          distancia2++;
          i2 = m2 -> getPosicionX();
          i02 = i2;
        }
        if (op_mover == 5) {
          cadenaOrden2[n2] = "TERMINAR";
          tf = clock();
          b = false;
        }
        if (op_mover == 0) {
          cadenaOrden2[n2] = "SALIR";
          tf = clock();
          b = false;
        }
        if (i > w || i < 0 || j > h || j < 0) {
          cout << "Se sale de la grilla." << endl;
          tf = clock();
          b = false;
        }
        n2++;
      }
      double tiempo = (double(tf-t0)/CLOCKS_PER_SEC);
      cout << "Nueva posición: (" << i2 << "," << j2 << ")" << endl;
      cout << "Secuencia de órdenes: " << endl;
      int k;
      for (k = 1; k < n2; k++){
        cout << k << ") " << cadenaOrden2[k] << endl;
      }
      cout << "Distancia recorrida: " << distancia2 << " [m]" << endl;
      ind = m2 -> consumo(distancia2);
      int c = carga - ind;
      cout << "Consumió: " << c << " [mAh]" << endl;
      cout << "Carga restante: " << ind << " [mAh]" << endl;
      cout << "Tiempo del movimiento: " << tiempo << "[s]" << endl;
    }

    if (movil == 3) {
      //MOVIL AUTONOMO 3
      t0 = clock();
      cout << "La posición actual es: (";
      i03 = m3 -> getXactual(w);
      j03 = m3 -> getYactual(h);
      cout << i03 << "," << j03 << ")" << endl;
      i3 = i03;
      j3 = j03;
      cout << "Carga inicial: ";
      carga = m3 -> getcarga_inicial();
      cout << carga << "[mAh]" << endl;
      ind = carga;
      cout << "Insertar secuencia de operaciones: " << endl;
      const char *cadenaOrden3[20];
      while (b == true){
        cin >> op_mover;
        m3 -> moverse(i03, j03, op_mover);
        if (op_mover == 1) {
          cadenaOrden3[n3] = "ADELANTE";
          distancia3++;
          j3 = m3 -> getPosicionY();
          j03 = j3;
        }
        if (op_mover == 2) {
          cadenaOrden3[n3] = "DERECHA";
          distancia3++;
          i3 = m3 -> getPosicionX();
          i03 = i3;
        }
        if (op_mover == 3) {
          cadenaOrden3[n3] = "ATRAS";
          distancia3++;
          j3 = m3 -> getPosicionY();
          j03 = j3;
        }
        if (op_mover == 4) {
          cadenaOrden3[n3] = "IZQUIERDA";
          distancia3++;
          i3 = m3 -> getPosicionX();
          i03 = i3;
        }
        if (op_mover == 5) {
          cadenaOrden3[n3] = "TERMINAR";
          tf = clock();
          b = false;
        }
        if (op_mover == 0) {
          cadenaOrden3[n3] = "SALIR";
          tf = clock();
          b = false;
        }
        if (i > w || i < 0 || j > h || j < 0) {
          cout << "Se sale de la grilla." << endl;
          tf = clock();
          b = false;
        }
        n3++;
      }
      double tiempo = (double(tf-t0)/CLOCKS_PER_SEC);
      cout << "Nueva posición: (" << i3 << "," << j3 << ")" << endl;
      cout << "Secuencia de órdenes: " << endl;
      int k;
      for (k = 1; k < n3; k++){
        cout << k << ") " << cadenaOrden3[k] << endl;
      }
      cout << "Distancia recorrida: " << distancia3 << " [m]" << endl;
      ind = m3 -> consumo(distancia3);
      int c = carga - ind;
      cout << "Consumió: " << c << " [mAh]" << endl;
      cout << "Carga restante: " << ind << " [mAh]" << endl;
      cout << "Tiempo del movimiento: " << tiempo << "[s]" << endl;
    }
    int fin;
    cout << "¿Continuar? sí(1) / no(0)" << endl;
    cin >> fin;
    if (fin == 0) flat = 0;
  }

  return 0;
}
