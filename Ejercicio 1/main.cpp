//Dada una circunferencia de radio R ubicada en el centro de una pantalla de
//W x H, se desea calcular el porcentaje de 1000 puntos generados aleatoriamente
//que caen dentro de ella.
//R, W y H son valores dados por el operador, cumpliéndose las siguiente restricciones:
//50<R<600 pixels
//Máximo W es 1024 pixels
//Máximo H es 768 pixels

#include "pantalla.h"

int main(){
  int R, W, H;
  int i, j;
  cout << "R = ";
  cin >> R;
  if (R <= 50 || R >= 600) {
    cout << "Valor de R incorrecto" << '\n';
  }
  else {
    cout << "W = ";
    cin >> W;
    if (W > 1024) {
      cout << "Valor de W incorrecto" << '\n';
    }
    else {
      cout << "H = ";
      cin >> H;
      if (H > 768) {
        cout << "Valor de H incorrecto" << '\n';
      }
      else {
        Pantalla *p;
        p = new Pantalla(i, j, W, H, R);
        p -> mostrar();
        delete p;
      }
    }
  }
  return 0;
}
