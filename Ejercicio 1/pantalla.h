#include <iostream>

using namespace std;
#include <cstdlib>
#include <ctime>

class Pantalla {
  public:
    Pantalla(int, int, int, int, int); //constructor
    void mostrar();

  private:
    int x, y, r, w, h; //Atributos
};
