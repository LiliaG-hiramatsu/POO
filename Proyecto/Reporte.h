#ifndef REPORTE_H
#define REPORTE_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <time.h>
using namespace std;

class Reporte {
public:
    Reporte();
    Reporte(const Reporte& orig);
    void setConexion(string con);
    void setEstado(string estado);
    void setX(int art, float valor1);
    void setY(int art, float valor2);
    void setZ(int art, float valor3);
    void pintar(string c);
    void setVel(float valor);
    void setInicio();
    void addOperation(string operacion);
    string sendReport();

private:
    string conexion;
    string status;
    float qx[3] = {0, 0, 0};
    float qy[3] = {0, 0, 0};
    float qz[3] = {0, 0, 0};
    string color;
    float velEF;
    time_t inicio;
    string operation = "";
};

#endif /* REPORTE_H */
