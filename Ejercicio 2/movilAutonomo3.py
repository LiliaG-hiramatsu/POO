from movilPrincipal import Movil
from random import randint

class MovilAutonomo3(Movil):
    def consumo(self, dist, cargaInicial):
        f = 0
        _consumo = randint(20,40)
        ind = cargaInicial
        while (f < dist):
            f = f + 1
            if (f == dist):
                ind = cargaInicial - f*_consumo
        return ind
