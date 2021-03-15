#include "movilPrincipal.h"

class MovilAutonomo3 : public Movil{
protected:
  int cargaInicial, indicador, dist;
public:
  MovilAutonomo3(int, int, int, int, int, int, int, int, int, int);
  virtual int getXactual(int W);
  virtual int getYactual(int H);
  int getcarga_inicial();
  virtual void moverse(int x0, int y0, int hacia);
  virtual int getPosicionX();
  virtual int getPosicionY();
  int consumo(int dist);
};
