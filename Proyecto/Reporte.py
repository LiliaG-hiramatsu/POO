from datetime import datetime
from time import time,localtime,strftime
import os

class Reporte():

    def reportar(self, linea):
        archivo = open('Reporte'+strftime(" %d %b %Y")+'.txt','a')
        archivo.write(linea+'\n')
        pass

    def mostrar(self):
        archivo = open('Reporte'+strftime(" %d %b %Y")+'.txt')
        for linea in archivo.readlines():
            print(linea)
        archivo.close()
        pass

    def orden(self, linea):
        if self.on == True:
            archivo=open('Ordenes'+self.fecha+'.txt','a')
            archivo.write(linea+"\n")
            archivo.close()
        pass

    def Backup(self):
        if self.on == True:
            self.on = False
            l = "Backup finalizado"
        else:
            self.on = True
            l = "Se inició back up"
            self.fecha = strftime(" %d %b %Y %H:%M:%S", localtime())
            archivo = open("Ordenes" + self.fecha + ".txt","w")
            archivo.close

        print(l)
        return l

    def __init__(self):
        self.on = False
        self.fecha = None
