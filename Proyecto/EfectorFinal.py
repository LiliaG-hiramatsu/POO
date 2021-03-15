from time import time, localtime, strftime
from Reporte import Reporte

class EfectorFinal(Reporte):

    def CambiarEstadoEF(self, EstadoEfector):
        fecha = strftime(" %a, %d %b %Y %H:%M:%S ", localtime())
        if EstadoEfector == 1:
            self.EstadoEF = 1
            l = "\n " + fecha + "\nPistola de pintura activada"
        elif EstadoEfector == 0:
            self.EstadoEF = 0
            l = "\n " + fecha + "\nPistola de pintura desactivada"
        print(l)
        self.reportar(l)
        return l

    def ElegirColor(self, EstadoEfector, Color):
        if EstadoEfector == 1:
            if Color == 1:
                self.Color = 1
                l = "Pintando de color azul"
            elif Color == 2:
                self.Color = 2
                l = "Pintando de color amarillo"
            elif Color == 3:
                self.Color = 3
                l = "Pintando de color rojo"
        else:
            l = "La pistola de pintura se encuentra desactivada\n"
            if Color == 1:
                self.Color = 1
                l += "Cambio de color a azul"
            elif Color == 2:
                self.Color = 2
                l += "Cambio de color a amarillo"
            elif Color == 3:
                self.Color = 3
                l += "Cambio de color a rojo"
        print(l)
        self.reportar(l)
        return l

    def CambiarVel(self, vel):
        self.Vel_ef = vel
        vel = str(vel)
        l = "La velocidad del efector final es "+vel+" rad/s\n"
        print(l)
        self.reportar(l)
        return l

    def __init__(self):
        self.EstadoEF = 0 #APAGADO
        self.Vel_ef = None
        self.Color = None
        Reporte.__init__(self)
