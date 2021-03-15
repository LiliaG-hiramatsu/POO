#include "movil.h"

class MovilAutonomo : public Movil{
protected:
  int cargaInicial, indicador, dist;
public:
  MovilAutonomo(int, int, int, int, int, int, int, string, int, int, int);
  int getCarga_inicial();
  virtual void mover(int x0, int y0, int hacia);
  virtual string getOrden() const;
  virtual string toString() const;
  virtual int getX() const;
  virtual int getY() const;
  int consumo(int dist);
};
