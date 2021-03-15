#include <iostream>
using namespace std;
#include "XmlRpc.h"
using namespace XmlRpc;
#include "Reporte.h"
#include <sstream>
#include <string>
#include <cstring>

int main() {

  Reporte report; //objeto report de tipo Reporte

  string IP;
  int port;

  cout << "Hola!\n";
  cout << "Ingrese la IP: ";
  cin >> IP;
  cout << endl;
  cout << "Ingrese el Nº de puerto: ";
  cin >> port;
  cout << endl;

  const char *ip = IP.c_str();
  //c_str() convierte un string en un puntero const char*

  XmlRpcClient c(ip, port);
  int data = 0;
  XmlRpcValue noArgsConf, result;
  if (c.execute("link", noArgsConf, result)) {
    cout << "Conexión exitosa\n";
    data = result;  //data = 1
  }
  else {
    data = 0;
    cout << "Conexión fallida\n" << endl;
  }

  report.setInicio();

  bool conexion = true;
  char orden;
  string estado_serial;
  string estado_robot;
  bool est_serial = false;
  bool est_robot = false;

  while (data) {
    while (conexion) {
      if (est_serial == true) {
        estado_serial = "Conectado";
      }
      else {
        estado_serial = "Desconectado";
      }
      if (est_robot == true) {
        estado_robot = "Activado";
      }
      else {
        estado_robot = "Desactivado";
      }
      cout << "Estado conexión serie: " << estado_serial << "\n"
      << "Estado Robot: " << estado_robot << "\n";

      cout << "¿Desea conectar/desconectar el puerto serie?[c/d]\n";
      cin >> orden;
      cout << "\n";
      if (orden == 'c') {
        XmlRpcValue ArgConect, result;
        ArgConect = 1;
        if (c.execute("estado_conexion", ArgConect, result)) {
          est_serial = true;
          cout << result << '\n';
          report.setConexion("conectado");
        }
        report.addOperation("Conexion establecida");
      }
      else if (orden == 'd') {
        XmlRpcValue ArgDisconect, result;
        ArgDisconect = 0;
        if (c.execute("estado_conexion", ArgDisconect, result)) {
          est_serial = false;
          cout << result << '\n';
          report.setConexion("Desconectado");
        }
        report.addOperation("Desconexion");
      }
      else {
        cout << "comando no reconocido";
      }

      cout << "¿Desea activar/desactivar el robot?[a/d]\n";
      cin >> orden;
      cout << "\n";
      if (orden == 'a') {
        XmlRpcValue Arg, result;
        Arg = 1;
        if (c.execute("estado_robot", Arg, result)) {
          cout << result << '\n';
          est_robot = true;
          report.setEstado("Activado");
        }
        report.addOperation("Activado");
      }
      else if (orden == 'd') {
        XmlRpcValue Arg, result;
        Arg = 0;
        if (c.execute("estado_robot", Arg, result)) {
          cout << result << '\n';
          est_robot = false;
          report.setEstado("Desactivado");
        }
        report.addOperation("Desactivado");
      }
      else {
        cout << "Comando no reconocido\n";
      }

      if (est_serial == true && est_robot == true) {
        conexion = false;
      }
    }

    cout << "\nComandos posibles:" << endl
    << "> Mover Robot (CodigoG comando M:ARTICULACIÓN (1 a 3):COORDENADA GEOMETRICA FINAL (X,Y,Z) (mm):VELOCIDAD ANGULAR (radianes/segundo):SENTIDO (0: sentido de las agujas del reloj, 1: sentido contrario de las agujas del reloj))" << endl
    << "> Activar/Desactivar pistola de pintura (CodigoG comando P:ESTADO (1:encendido, 0:apagado):COLOR (1.Azul 2.Amarillo 3.Rojo):VELOCIDAD ANGULAR (radianes/segundo))" << endl
    << "> Reset posicion robot (CodigoG comando H)" << endl
    << "> Modo automatico: automatico" << endl
    << "> Si necesita ayuda ingrese: help" << endl
    << "> Mostrar reporte: reporte" << endl
    << "> Inicializar/finalizar backup de secuencia de órdenes: backup" << endl
    << "> Salir: salir\n\n";
    string comando;
    cin >> comando;

    if (comando == "help") {
      XmlRpcValue noArg, result;
      if (c.execute("mostrar_ayuda", noArg, result)) {
        cout << result << endl;
      }
      int opc;
      cin >> opc;
      cout << "\n";
      XmlRpcValue op;
      op = opc;
      if (c.execute("get_ayuda", op, result)) {
        cout << result << endl;
      }
      report.addOperation("Ayuda");
    }
    bool on;
    if (comando == "backup") {
      XmlRpcValue NoArg, result;
      if (c.execute("backup", NoArg, result));
      cout << result << endl;
    }

    if (comando == "reporte") {
      cout << report.sendReport() << endl;
    }

    if (comando == "salir") {
      XmlRpcValue Arg, result;
      Arg = 0;
      if (c.execute("estado_robot", Arg, result));
      if (c.execute("estado_conexion", Arg, result));
      cout << "Desconectando\nHasta pronto\n" << '\n';
      data = 0;
    }

    //MODO AUTOMÁTICO
    if (comando == "automatico") {
      string arch;
      cout << "Ingrese el nombre del archivo a ejecutar: " << '\n';
      cin >> arch;
      XmlRpcValue Arg, result;
      Arg = arch;
      if (c.execute("ModoAutomatico", Arg, result)) {
        cout << "Leyendo archivo con órdenes preestablecidas" << '\n';
        cout << "El modo automático se realizó con éxito" << '\n';
      }
      report.addOperation("El modo automático se realizó con éxito");
    }

    else {
      XmlRpcValue ArgO, result;
      ArgO = comando;
      if (c.execute("Orden", ArgO, result));

      string codigo[7];
      istringstream iss(comando); //toma la cadena de entrada (comando) y la guarda en un buffer de string (iss)
      string aux;
      int i = 0;
      //interprete de codigo G
      while (getline(iss, aux ,':')) {  //separa los caracteres de iss entre : y los guarda en aux
        codigo[i] = aux;
        i++;
      }

      //MOVER ARTICULACIÓN
      if (codigo[0] == "M") {
        XmlRpcValue Args, result;
        Args[0] = codigo[1];  //nro de articulacion (1, 2 o 3)
        Args[1] = codigo[2];  //coordenada x
        Args[2] = codigo[3];  //coordenada y
        Args[3] = codigo[4];  //coordenada z
        if(c.execute("mover", Args, result));
        cout << result << endl;
        int a = stoi(codigo[1]);
        float x, y, z;
        x = stof(codigo[2]);
        y = stof(codigo[3]);
        z = stof(codigo[4]);
        report.setX(a, x);
        report.setY(a, y);
        report.setZ(a, z);

        XmlRpcValue Argss, result1;
        Argss[0] = codigo[1];  //articulacion
        Argss[4] = codigo[5];  //velocidad angular
        if(c.execute("VelAngular", Argss, result1));
        cout << result1 << endl;

        XmlRpcValue ArgS, result2;
        ArgS[5] = stoi(codigo[6]);  //sentido (0 o 1)
        if(c.execute("Sentido", ArgS, result2));
        cout << result2 << endl;

        report.addOperation("Grado de libertad movido");
      }

      //EFECTOR FINAL
      if (codigo[0] == "P") { //pistola de pintura
        XmlRpcValue Arg1, result1;
        Arg1[0] = stoi(codigo[1]);
        if (codigo[1] == "1") {
          Arg1[0] = 1;  //estado activado
        }
        else {
          Arg1[0] = 0;  //estado desactivado
        }
        if (c.execute("EstadoEfectorFinal", Arg1, result1));
        cout << result1 << endl;
        XmlRpcValue Arg2, result2;
        if (codigo[1] == "1") {
          Arg2[0] = stoi(codigo[1]);
          Arg2[1] = stoi(codigo[2]);  //color
        }
        if (c.execute("ColorPintura", Arg2, result2));
        cout << result2 << endl;
        string color1 = result2;
        report.pintar(color1);

        XmlRpcValue Arg3, result3;
        if (codigo[1] == "1") {
          Arg3[0] = codigo[3];  //velocidad
        }
        if (c.execute("VelEF", Arg3, result3));
        cout << result3 << endl;
        report.addOperation("Operación del efector final realizada con éxito");
        float v = stof(codigo[3]);
        report.setVel(v);
      }

      //HOMING
      if (codigo[0] == "H") {
        XmlRpcValue ArgH, result;
        if (c.execute("Posicion_inicial", ArgH, result)) {
          cout << result << endl;
        }
        report.addOperation("Se realizó un homing");
      }
    }
  }
  return 0;
}

//COMANDOS PARA COMPILAR Y EJECUTAR EN LA TERMINAL DE UBUNTU

//g++ -c XmlRpcClient.cpp -o XmlRpcClient
//g++ -c XmlRpcDispatch.cpp -o XmlRpcDispatch
//g++ -c XmlRpcServer.cpp -o XmlRpcServer
//g++ -c XmlRpcServerConnection.cpp -o XmlRpcServerConnection
//g++ -c XmlRpcServerMethod.cpp -o XmlRpcServerMethod
//g++ -c XmlRpcSocket.cpp -o XmlRpcSocket
//g++ -c XmlRpcSource.cpp -o XmlRpcSource
//g++ -c XmlRpcUtil.cpp -o XmlRpcUtil
//g++ -c XmlRpcValue.cpp -o XmlRpcValue
//g++ -c Reporte.cpp -o Reporte
//g++ -o test main.cpp XmlRpcClient.cpp XmlRpcDispatch.cpp XmlRpcServer.cpp XmlRpcServerConnection.cpp XmlRpcServerMethod.cpp XmlRpcSocket.cpp XmlRpcSource.cpp XmlRpcUtil.cpp XmlRpcValue.cpp Reporte.cpp
//./test
