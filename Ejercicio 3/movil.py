from random import randint

class Movil:
    def __init__(self, nombre):
        self.nombre = nombre

    def __str__(self):
        return 'Movil: {}'.format(self.nombre)

    def getX(self, x0, hacia):
        if (hacia == 2):
            return x0 + 1
        if (hacia == 4):
            return x0 - 1

    def getY(self, y0, hacia):
        if (hacia == 1):
            return y0 + 1
        if (hacia == 3):
            return y0 - 1
