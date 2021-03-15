from time import time, localtime, strftime
from Reporte import Reporte

class Articulacion(Reporte):


    def Cambiar_w(self, art, velocidad):
        if art == 1:
          self.w1 = velocidad
        elif art == 2:
          self.w2 = velocidad
        elif art == 3:
          self.w3 = velocidad
        art = str(art)
        velocidad = str(velocidad)
        l = "La velocidad de la articulación "+art+" es "+velocidad+" rad/s"
        print(l)
        self.reportar(l)
        return l

    def CambiarSentido(self, Sentido):
        if Sentido == 0:
          self.sentido = 0
          l = "Sentido de giro horario"
        elif Sentido == 1:
          self.sentido = 1
          l = "Sentido de giro antihorario"
        self.reportar(l)
        print(l)
        return l

    def Mover(self, articulacion, i, j, k):
        fecha = strftime(" %a, %d %b %Y %H:%M:%S ", localtime())
        articulacion = str(articulacion)
        i = str(i)
        j = str(j)
        k = str(k)
        l = "\n " + fecha + "\nLa articulacion "+articulacion+" se movió con éxito a la posición ("+i+","+j+","+k+")"
        print(l)
        w = 0
        self.reportar(l)

        return l

    def Homing(self):
        fecha = strftime(" %a, %d %b %Y %H:%M:%S ", localtime())
        self.q1 = 0
        self.q2 = 0
        self.q3 = 0
        l = fecha + "\nEl robot seteó sus variables articulares en cero"
        print(l)
        self.reportar(l)
        return l

    def __init__(self):
        #posiciones angulares de cada articulacion
        self.q1 = 0
        self.q2 = 0
        self.q3 = 0
        self.sentido = 0
        self.w1 = 0
        self.w2 = 0
        self.w3 = 0
        Reporte.__init__(self)
