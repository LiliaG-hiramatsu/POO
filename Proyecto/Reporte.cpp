#include "Reporte.h"
using namespace std;

Reporte::Reporte() {
}

Reporte::Reporte(const Reporte& orig) {
}

void Reporte::setConexion(string con) {
  this -> conexion = con;
}

void Reporte::setEstado(string estado) {
  this -> status = estado;
}

void Reporte::setX(int art, float valor1) {
  this -> qx[art-1] = valor1;
}

void Reporte::setY(int art, float valor2) {
  this -> qy[art-1] = valor2;
}

void Reporte::setZ(int art, float valor3) {
  this -> qz[art-1] = valor3;
}

void Reporte::pintar(string c) {
  this -> color = c;
}

void Reporte::setVel(float valor) {
  this -> velEF = valor;
}

void Reporte::setInicio() {
  time(&this -> inicio);  //esta funcion devuelve el tiempo actual
}

void Reporte::addOperation(string operacion) {
  time_t now;
  string msj, aux;
  time(&now); //registra el tiempo actual
  aux = ctime(&now); //guarda en aux el tiempo como una cadena: Fri Nov 13 13:42:20 2020
  aux.erase(0,11); //corta los primeros 11 caracteres, queda 13:42:20 2020
  aux.erase(8,13); //corta desde el caracter 8 hasta el caracter 13, queda 13:42:20
  msj = "[" + aux + "] " + operacion + "\n";
  this -> operation.append(msj);
}

string Reporte::sendReport() {
  string msj1, msj2, msj3, msj4, msj5, msj6, msj7, msj8, send;
  msj1 = "- El puerto serie se encuentra " + this -> conexion;
  msj2 = "- El estado del robot es: " + this -> status;
  time_t now;
  time(&now);
  double exe = difftime(now, this -> inicio);  //hace la diferencia entre esos dos tiempos

  ostringstream aux, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8, aux9, aux10, aux11;
  //crea variables de tipo ostringstream. Esto es, se almacenan en el buffer como una secuencia de caracteres y se puede acceder a estos como si fuesen todos de tipo string con str()

  aux << exe; //le asigna a aux el valor de exe
  msj3 = "- Tiempo desde inicio de la comunicacion con el servidor: " + aux.str() + " segundos";
  aux1 << this -> qx[0];
  aux2 << this -> qy[0];
  aux3 << this -> qz[0];
  msj4 = "- Posicion de la articulacion 1: ";
  msj4.append("(" + aux1.str() + "," + aux2.str() + "," + aux3.str() + ") milimetros");
  aux4 << this -> qx[1];
  aux5 << this -> qy[1];
  aux6 << this -> qz[1];
  msj5 = "- Posicion de la articulacion 2: ";
  msj5.append("(" + aux4.str() + "," + aux5.str() + "," + aux6.str() + ") milimetros");
  aux7 << this -> qx[2];
  aux8 << this -> qy[2];
  aux9 << this -> qz[2];
  msj6 = "- Posicion de la articulacion 3: ";
  msj6.append("(" + aux7.str() + "," + aux8.str() + "," + aux9.str() + ") milimetros");
  aux10 << this -> color;
  string c = aux10.str();
  msj7 = "- Pintó de color: ";
  msj7.append(c.erase(0,18));
  aux11 << this -> velEF;
  msj8 = "- La velocidad del efector final es: ";
  msj8.append(aux11.str());
  msj8.append(" rad/s");
  send = msj1 + "\n" + msj2 + "\n" + msj3 + "\n" + msj4 + "\n" + msj5 + "\n" + msj6 + "\n" + msj7 + "\n" + msj8 + "\n" + "- Registro de ordenes:\n" + this -> operation;
  return send;
}
