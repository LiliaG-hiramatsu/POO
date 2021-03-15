from time import time, localtime, strftime
from Articulacion import Articulacion
from EfectorFinal import EfectorFinal
from Reporte import Reporte

class PanelControlS(EfectorFinal, Articulacion):
    EstadoR = 0
    Conexion = 0
    tiempo = 0.0
    t0 = time()

    def Cambiar_Conexion(self, est):
        fecha = strftime(" %a, %d %b %Y %H:%M:%S ", localtime())
        if est == 1:
            self.Conexion = 1
            l = fecha + "\nServidor CONECTADO \n"
        elif est == 0:
            self.Conexion = 0
            l = fecha + "\nServidor DESCONECTADO \n"
        print(l)
        return l

    def Cambiar_Estado(self, est):
        fecha = strftime(" %a, %d %b %Y %H:%M:%S ", localtime())
        if est == 1:
            self.EstadoR = 1
            self.tiempo = time() - self.t0
            tt = self.tiempo
            l = fecha + "\nRobot ENCENDIDO\n"
        elif est == 0:
            self.EstadoR = 0
            self.tiempo = 0.0
            l = fecha + "Robot APAGADO\n"
        print(l)
        return l

    def Automatico(self, arch):
        archivo = open(arch)
        valores=[]
        for linea in archivo.readlines():
          if linea.find('M') != (-1):
            self.orden(linea)
            aux=linea[2:len(linea)]
            while len(aux) > 1:
              if aux.find(':') !=-1:
                valores.append(int(aux[0:aux.find(':')]))
                aux=aux[aux.find(':')+1:len(aux)]
              else:
                valores.append(int(aux[0:len(aux)-1]))
                aux=''
            self.Mover(valores[0], valores[1], valores[2], valores[3])
            self.Cambiar_w(valores[0], valores[4])
            self.CambiarSentido(valores[5])
            valores=[]
          if linea.find('P') != (-1):
            self.orden(linea)
            aux=linea[2:len(linea)]
            while len(aux) >1:
              if aux.find(':') !=-1:
                valores.append(int(aux[0:aux.find(':')]))
                aux=aux[aux.find(':')+1:len(aux)]
              else:
                valores.append(int(aux[0:len(aux)-1]))
                aux=''
            self.CambiarEstadoEF(valores[0])
            self.ElegirColor(valores[0], valores[1])
            self.CambiarVel(valores[2])
            valores = []
          if linea.find('H') != (-1):
            self.orden(linea)
            self.Homing()
        archivo.close

    def mostrar_help(self):
        return '\nElija la función (1 a 6) para obtener más información:\n\t1: Mover\n\t2: ActivarEF\n\t3: Homing\n\t4: Automatico\n\t5: Reporte\n\t6: Backup\n'

    def help(self, opcion):
        if opcion == 1:
            return 'Mover: Función que controla el movimiento de las articulaciones\nRecibe formato:\nM:ARTICULACIÓN (1 a 3)\n:COORDENADA GEOMETRICA FINAL (X,Y,Z) (mm)\n:VELOCIDAD ANGULAR (radianes/segundo)\n:SENTIDO (0: sentido de las agujas del reloj, 1: sentido contrario de las agujas del reloj)\nEjemplo: M:2:30:30:90:30:0\n'
        elif opcion == 2:
            return 'ActivarEF: Funcion para activar la pistola de pintura:\nRecibe formato:\nP:ESTADO (1:encendido, 0:apagado)\n:COLOR (1.Azul 2.Amarillo 3.Rojo)\n:VELOCIDAD ANGULAR (radianes/segundo).\nEjemplo: P:1:2:45\n'
        elif opcion == 3:
            return 'Homing: Función que restaura el robot a su posición inicial\nRecibe formato:\nH\n'
        elif opcion == 4:
            return 'automatico: Modo automático: Lee comandos precargados en un archivo .txt\n'
        elif opcion == 5:
            return 'reporte: Muestra el reporte de la actividad del robot desde que se activó\n'
        elif opcion == 6:
            return 'backup: Crea un archivo .txt para guardar las próximas órdenes\n'
        else:
            return "Función no encontrada"
