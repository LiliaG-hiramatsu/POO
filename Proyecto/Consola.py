from cmd import Cmd
from xmlrpc_server import Server
from PanelControlS import PanelControlS
from Articulacion import Articulacion
from EfectorFinal import EfectorFinal
from Reporte import Reporte

class Consola(Cmd):
    Serv = None

    def do_Conectar(self, args):
        """Establece la conexión"""
        if panel.Conexion == 0:
            panel.Cambiar_Conexion(1)
            self.Serv = Server(self)
        else:
            print("Ya se encuentra conectado\n")

    def do_Desconectar(self, args):
        """Cierra la conexión"""
        if panel.Conexion == 1:
            panel.Cambiar_Conexion(0)
            self.Serv.shutdown()
            self.Serv = None
        else:
            print("Ya se encuentra desconectado\n")

    def do_Activar(self, args):
        """Activa el robot"""
        if panel.EstadoR == 0:
            panel.Cambiar_Estado(1)
        else:
            print("Ya se encuentra encendido\n")

    def do_Desactivar(self, args):
        """Desactiva el robot"""
        if panel.EstadoR == 1:
            panel.Cambiar_Estado(0)
        else:
            print("Ya se encuentra apagado\n")

    def do_mover(self, args):
        """Función que controla el movimiento de las articulaciones\nRecibe formato:\nM:ARTICULACIÓN (1 a 3)\n:COORDENADA GEOMETRICA FINAL (X,Y,Z) (mm)\n:VELOCIDAD ANGULAR (radianes/segundo)\n:SENTIDO (0: sentido de las agujas del reloj, 1: sentido contrario de las agujas del reloj)\nEjemplo: M:2:30:30:90:30:0\n"""
        cadena = str(input("Ingresar orden: ")) #M:1:23:23:23:45:1
        rep.orden(cadena)
        valores = []
        aux=cadena[2:len(cadena)]
        while len(aux) > 0:
          if aux.find(':') !=-1:
            valores.append(aux[0:aux.find(':')])
            aux=aux[aux.find(':')+1:len(aux)]
          else:
            valores.append(aux[0:len(aux)])
            aux = ""
        nro_art = int(valores[0])
        i = float(valores[1])
        j = float(valores[2])
        k = float(valores[3])
        vel = float(valores[4])
        sentido = int(valores[5])
        art.Mover(nro_art, i, j, k)
        art.Cambiar_w(nro_art, vel)
        art.CambiarSentido(sentido)

    def do_activarEF(self, args):
        """Funcion para activar la pistola de pintura:\nRecibe formato:\nP:ESTADO (1:encendido, 0:apagado)\n:COLOR (1.Azul 2.Amarillo 3.Rojo)\n:VELOCIDAD ANGULAR (radianes/segundo).\nEjemplo: P:1:2:45\n"""
        cadena = str(input("Ingresar orden: ")) #P:1:2:45
        rep.orden(cadena)
        valores = []
        aux=cadena[2:len(cadena)]
        while len(aux) > 0:
          if aux.find(':') !=-1:
            valores.append(int(aux[0:aux.find(':')]))
            aux=aux[aux.find(':')+1:len(aux)]
          else:
            valores.append(int(aux[0:len(aux)]))
            aux = ""
        estadoEF = int(valores[0])
        color = int(valores[1])
        velEF = float(valores[2])
        if estadoEF == 1:
            l1 = efector.CambiarEstadoEF(estadoEF)
            l2 = efector.ElegirColor(estadoEF, color)
            l3 = efector.CambiarVel(velEF)
        if estadoEF == 0:
            l1 = efector.CambiarEstadoEF(estadoEF)
            l2 = efector.ElegirColor(estadoEF, color)
            l3 = efector.CambiarVel(velEF)

    def do_homing(self, args):
        """Función que restaura el robot a su posición inicial\nRecibe formato:\nH\n"""
        cadena = str(input("Ingresar orden: ")) #H
        rep.orden(cadena)
        art.Homing()

    def do_automatico(self, args):
        """Modo automático: Lee comandos precargados en un archivo .txt\n"""
        arch=input("Ingrese el nombre del archivo a ejecutar: ")
        panel.Automatico(arch)

    def do_reporte(self, args):
        """Devuelve un reporte de la actividad del robot desde que se activó"""
        rep.mostrar()

    def do_backup(self, args):
        """Crea un archivo .txt para guardar las próximas órdenes"""
        rep.Backup()

    def default(self, args):
        print("Comando inexistente")

    def do_salir(self, args):
        """Salir del intérprete"""
        print("Nos vemos")
        return(True)

if __name__ == '__main__':
    efector = EfectorFinal()
    panel = PanelControlS()
    art = Articulacion()
    rep = Reporte()
    print("HOLA")
    print("Ingrese 'help' para más información\n")
    uncli = Consola()
    uncli.prompt = '>> '
    uncli.cmdloop('Iniciando entrada de comandos')
