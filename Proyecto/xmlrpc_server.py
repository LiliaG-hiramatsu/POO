from xmlrpc.server import SimpleXMLRPCServer
from PanelControlS import PanelControlS
from Articulacion import Articulacion
from EfectorFinal import EfectorFinal
from Reporte import Reporte
from threading import Thread
import socket
import logging

RPC_PORT = 8080

class Server(object):

    server = None

    def __init__(self, consola, port = RPC_PORT):
        self.consola = consola
        self.server = SimpleXMLRPCServer(("localhost", port), logRequests = True)
        print("Listening on port 8080...")

        self.server.register_instance(consola)
        self.server.register_function(self.link, 'link')
        self.server.register_function(self.estado_conexion, 'estado_conexion')
        self.server.register_function(self.estado_robot, 'estado_robot')
        self.server.register_function(self.mostrar_ayuda, 'mostrar_ayuda')
        self.server.register_function(self.get_ayuda, 'get_ayuda')
        self.server.register_function(self.ModoAutomatico, 'ModoAutomatico')
        self.server.register_function(self.mover, 'mover')
        self.server.register_function(self.VelAngular, 'VelAngular')
        self.server.register_function(self.Sentido, 'Sentido')
        self.server.register_function(self.Posicion_inicial, 'Posicion_inicial')
        self.server.register_function(self.EstadoEfectorFinal, 'EstadoEfectorFinal')
        self.server.register_function(self.ColorPintura, 'ColorPintura')
        self.server.register_function(self.VelEF, 'VelEF')
        self.server.register_function(self.backup, 'backup')
        self.server.register_function(self.Orden, 'Orden')


        #aca creamos un hilo que lanza al servidor
        self.thread = Thread(target = self.run_server)
        self.thread.start()
        print("Servidor RPC iniciado en el puerto [%s]" % str(self.server.server_address))

    def run_server(self):
        self.server.serve_forever()

    def shutdown(self):
        self.server.shutdown()
        self.thread.join()

    #esta funcion le indica al cliente si se establecio el enlace
    def link(self):
        return 1

    def estado_conexion(self, estado):
        aux = PanelControlS()
        return aux.Cambiar_Conexion(estado)

    def estado_robot(self, estado):
        aux = PanelControlS()
        return aux.Cambiar_Estado(estado)

    def mostrar_ayuda(self):
        aux = PanelControlS()
        return aux.mostrar_help()

    def get_ayuda(self, opcion):
        aux = PanelControlS()
        return aux.help(opcion)

    def ModoAutomatico(self, arch):
        aux = PanelControlS()
        return aux.Automatico(arch)

    def mover(self, articulacion, i, j, k):
        aux = Articulacion()
        return aux.Mover(articulacion, i, j, k)

    def VelAngular(self, articulacion, velocidad):
        aux = Articulacion()
        return aux.Cambiar_w(articulacion, velocidad)

    def Sentido(self, sentido):
        aux = Articulacion()
        return aux.CambiarSentido(sentido)

    def Posicion_inicial(self):
        aux = Articulacion()
        return aux.Homing()

    def EstadoEfectorFinal(self, estado):
        aux = EfectorFinal()
        return aux.CambiarEstadoEF(estado)

    def ColorPintura(self, estado, color):
        aux = EfectorFinal()
        return aux.ElegirColor(estado, color)

    def VelEF(self, v):
        aux = EfectorFinal()
        return aux.CambiarVel(v)

    def backup(self):
        aux = Reporte()
        return aux.Backup()

    def Orden(self, l):
        aux = Reporte()
        return aux.orden(l)
