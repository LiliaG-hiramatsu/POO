// Modificar el programa que permite gestionar los móviles anterior de modo
// tal que:
// Se puedan crear N móviles autónomos (en lugar de sólo 3)
// Los móviles se almacenan en una lista de objetos
// La secuencia de órdenes recibidas se almacene en otra lista adecuada

#include "movil.h"
#include "movilAutonomo.h"
#include "lista.h"
#include <list>

int main(){
  int w, h;
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
  int carga, op_mover, ind, N, distancia = 0, i0 = 0, j0 = 0, i = 0, j = 0;
  string orden;
  int q, i01 = 0, j01 = 0, i1 = 0, j1 = 0, distancia1 = 0;

  Movil *m;
  m = new Movil(i, j, i0, j0, w, h, op_mover, orden); //MOVIL MANUAL
  list <MovilAutonomo> m_a; //LISTA DE MOVILES AUTONOMOS
  list <MovilAutonomo>::iterator it;  //ITERADOR DE MOVILES AUTONOMOS
  list <MovilAutonomo> ordenes; //LISTA DE ÓRDENES
  list <MovilAutonomo>::iterator it_orden;  //ITERADOR DE ÓRDENES

  cout << "Ingresar la cantidad de moviles autónomos:" << endl;
  cout << "N = ";
  cin >> N;

  for (q = 0; q < N; q++) {
    m_a.insert(m_a.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
  }

  //MOVIL MANUAL
  cout << "MOVIL_MANUAL" << endl;
  cout << "La posición actual es: (";
  srand(time(NULL));
  i0 = 1 + rand() % w - 1;
  j0 = 1 + rand() % h - 1;
  cout << i0 << "," << j0 << ")" << endl;
  i = i0;
  j = j0;
  cout << "Insertar secuencia de operaciones: " << endl;
  while (b == true){
    cin >> op_mover;
    m -> mover(i0, j0, op_mover);
    orden = m -> getOrden();
    if (op_mover == 1) {
      distancia++;
      ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
      j = m -> getY();
      j0 = j;
    }
    if (op_mover == 2) {
      distancia++;
      ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
      i = m -> getX();
      i0 = i;
    }
    if (op_mover == 3) {
      distancia++;
      ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
      j = m -> getY();
      j0 = j;
    }
    if (op_mover == 4) {
      distancia++;
      ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
      i = m -> getX();
      i0 = i;
    }
    if (op_mover == 5) {
      ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
      b = false;
    }
    if (op_mover == 0) {
      ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
      b = false;
    }
    if (i > w || i < 0 || j > h || j < 0) {
      cout << "Se sale de la grilla." << endl;
      b = false;
    }
  }
  cout << "Nueva posición: (" << i << "," << j << ")" << endl;
  cout << "Secuencia de órdenes: " << endl;
  for (it_orden = ordenes.begin(); it_orden != ordenes.end(); it_orden++){
    cout << it_orden -> toString() << endl;
  }
  cout << "Distancia recorrida: " << distancia << " [m]" << endl;
  //BORRAR LOS OBJETOS DE LA LISTA ORDENES
  ordenes.clear();

  //MOVILES AUTONOMOS
  int n = 1;
  t0 = clock();
  for (it = m_a.begin(); it != m_a.end(); it++) {
    cout << "MOVIL_AUTONOMO Nro. " << n << endl;
    srand(time(NULL));
    i01 = 1 + rand() % w - 1;
    j01 = 1 + rand() % h - 1;
    cout << "La posición actual es: (";
    cout << i01 << "," << j01 << ")" << endl;
    i1 = i01;
    j1 = j01;
    cout << "Carga inicial: ";
    carga = it -> getCarga_inicial();
    cout << carga << "[mAh]" << endl;
    ind = carga;
    b = true;
    cout << "Insertar secuencia de operaciones:" << endl;
    while (b == true) {
      cin >> op_mover;
      it -> mover(i01, j01, op_mover);
      orden = it -> getOrden();
      if (op_mover == 1) {
        distancia1++;
        ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
        j1 = it -> getY();
        j01 = j1;
      }
      if (op_mover == 2) {
        distancia1++;
        ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
        i1 = it -> getX();
        i01 = i1;
      }
      if (op_mover == 3) {
        distancia1++;
        ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
        j1 = it -> getY();
        j01 = j1;
      }
      if (op_mover == 4) {
        distancia1++;
        ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
        i1 = it -> getX();
        i01 = i1;
      }
      if (op_mover == 5) {
        tf = clock();
        ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
        b = false;
      }
      if (op_mover == 0) {
        tf = clock();
        ordenes.insert(ordenes.end(), MovilAutonomo(i1, j1, i01, j01, w, h, op_mover, orden, carga, ind, distancia1));
        b = false;
      }
      if (i1 > w || i1 < 0 || j1 > h || j1 < 0) {
        cout << "Se sale de la grilla." << endl;
        tf = clock();
        b = false;
      }
    }
    double tiempo = (double(tf-t0)/CLOCKS_PER_SEC);
    cout << "Nueva posición: (" << i1 << "," << j1 << ")" << endl;
    cout << "Secuencia de órdenes: " << endl;
    for (it_orden = ordenes.begin(); it_orden != ordenes.end(); it_orden++){
      cout << it_orden -> toString() << endl;
    }
    cout << "Distancia recorrida: " << distancia1 << " [m]" << endl;
    ind = it -> consumo(distancia1);
    int c = carga - ind;
    cout << "Consumió: " << c << " [mAh]" << endl;
    cout << "Carga restante: " << ind << " [mAh]" << endl;
    cout << "Tiempo del movimiento: " << tiempo << "[s]" << endl;
    i01 = 0;
    j01 = 0;
    t0 = 0;
    distancia1 = 0;
    ordenes.clear();
    n++;
  }

  return 0;
}
