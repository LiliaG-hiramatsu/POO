# El programa debe crear 1 móvil (manual) dentro de una grilla plana.
# El móvil posee un nombre único y conoce su posición actual, la
# secuencia de órdenes recibidas y la distancia total recorrida.
# Las dimensiones del plano y las órdenes de movimiento son dadas
# por el operador (para moverse puede usar el código estructurado
# en las diapositivas 20-21 de la presentación C vs C++).
# Crear también 3 objetos móviles autónomos (obtenidos a partir del
# anterior). Cada móvil está alimentado por una batería de carga inicial
# variable al azar entre 200-300 mAh y cuenta con un indicador de
# carga de la misma. Por cada unidad de distancia recorrida se
# consumen entre 20 a 40 mAh (constante al azar para el móvil).
# El reporte debe mostrar, en cada ciclo, la posición, la cadena de
# órdenes recibidas, las distancia y el tiempo que el móvil estuvo en
# movimiento desde su creación hasta que el operador eligió
# TERMINAR. Además del nivel de carga y consumo si corresponden.

from movilPrincipal import Movil
from movilAutonomo1 import MovilAutonomo1
from movilAutonomo2 import MovilAutonomo2
from movilAutonomo3 import MovilAutonomo3
from random import randint
from time import time

print('Ingresar dimensiones de la grilla:')
w = int(input('w = '))
h = int(input('h = '))
print('Elija la dirección de movimiento con:')
print('1. ADELANTE')
print('2. DERECHA')
print('3. ATRAS')
print('4. IZQUIERDA')
print('5. TERMINAR')
print('0. SALIR')
distancia = 0
distancia1 = 0
distancia2 = 0
distancia3 = 0
orden = []
b = True
flat = 1
while (flat == 1):
    b = True
    print('Elegir el movil (0, 1, 2, 3)')
    movil = int(input())

    if (movil == 0):
        #MOVIL MANUAL
        movil0 = Movil('MOVIL_MANUAL')
        print(movil0.nombre)
        i0 = randint(0, w)
        j0 = randint(0, h)
        print('La posicion actual es: (',i0,',',j0,')')
        i = i0
        j = j0
        print('Insertar secuencia de operaciones:')
        while (b == True):
            op_mover = int(input())
            if (op_mover == 1):
                distancia = distancia + 1
                orden += ['ADELANTE']
                j = movil0.getY(j0, op_mover)
                j0 = j
            if (op_mover == 2):
                distancia = distancia + 1
                orden += ['DERECHA']
                i = movil0.getX(i0, op_mover)
                i0 = i
            if (op_mover == 3):
                distancia = distancia + 1
                orden += ['ATRAS']
                j = movil0.getY(j0, op_mover)
                j0 = j
            if (op_mover == 4):
                distancia = distancia + 1
                orden += ['IZQUIERDA']
                i = movil0.getX(i0, op_mover)
                i0 = i
            if (op_mover == 5):
                orden += ['TERMINAR']
                b = False
            if (op_mover == 0):
                orden += ['SALIR']
                b = False
            if (i > w or i < 0 or j > h or j < 0):
                print('Se sale de la grilla.')
                b = False
        print('Nueva posición: (',i,',',j,')')
        print('Secuencia de órdenes:')
        print(orden)
        print('Distancia recorrida:', distancia, '[m]')
        orden[:] = []

    if (movil == 1):
        #MOVIL AUTONOMO 1
        movil1 = MovilAutonomo1('MOVIL_AUTONOMO_1')
        t0 = time()
        print(movil1.nombre)
        i01 = randint(0, w)
        j01 = randint(0, h)
        print('La posición actual es: (',i01,',',j01,')')
        i1 = i01
        j1 = j01
        carga = randint(200, 300)
        print('Carga inicial:',carga,'[mAh]')
        indicador = carga
        b = True
        print('Insertar secuencia de operaciones:')
        while (b == True):
            op_mover = int(input())
            if (op_mover == 1):
                distancia1 = distancia1 + 1
                orden += ['ADELANTE']
                j1 = movil1.getY(j01, op_mover)
                j01 = j1
            if (op_mover == 2):
                distancia1 = distancia1 + 1
                orden += ['DERECHA']
                i1 = movil1.getX(i01, op_mover)
                i01 = i1
            if (op_mover == 3):
                distancia1 = distancia1 + 1
                orden += ['ATRAS']
                j1 = movil1.getY(j01, op_mover)
                j01 = j1
            if (op_mover == 4):
                distancia1 = distancia1 + 1
                orden += ['IZQUIERDA']
                i1 = movil1.getX(i01, op_mover)
                i01 = i1
            if (op_mover == 5):
                orden += ['TERMINAR']
                tf = time()
                b = False
            if (op_mover == 0):
                orden += ['SALIR']
                tf = time()
                b = False
            if (i1 > w or i1 < 0 or j1 > h or j1 < 0):
                print('Se sale de la grilla.')
                tf = time()
                b = False
        tiempo = tf - t0
        print('Nueva posición: (',i1,',',j1,')')
        print('Secuencia de órdenes:')
        print(orden)
        print('Distancia recorrida:', distancia1, '[m]')
        indicador = movil1.consumo(distancia1, carga)
        c = carga - indicador
        print('Consumió:',c,'[mAh]')
        print('Carga restante:',indicador,'[mAh]')
        print('Tiempo del movimiento:',tiempo,'[s]')
        orden[:] = []

    if (movil == 2):
        #MOVIL AUTONOMO 2
        movil2 = MovilAutonomo2('MOVIL_AUTONOMO_2')
        t0 = time()
        print(movil2.nombre)
        i02 = randint(0, w)
        j02 = randint(0, h)
        print('La posición actual es: (',i02,',',j02,')')
        i2 = i02
        j2 = j02
        carga = randint(200, 300)
        print('Carga inicial:',carga,'[mAh]')
        indicador = carga
        b = True
        print('Insertar secuencia de operaciones:')
        while (b == True):
            op_mover = int(input())
            if (op_mover == 1):
                distancia2 = distancia2 + 1
                orden += ['ADELANTE']
                j2 = movil2.getY(j02, op_mover)
                j02 = j2
            if (op_mover == 2):
                distancia2 = distancia2 + 1
                orden += ['DERECHA']
                i2 = movil2.getX(i02, op_mover)
                i02 = i2
            if (op_mover == 3):
                distancia2 = distancia2 + 1
                orden += ['ATRAS']
                j2 = movil2.getY(j02, op_mover)
                j02 = j2
            if (op_mover == 4):
                distancia2 = distancia2 + 1
                orden += ['IZQUIERDA']
                i2 = movil2.getX(i02, op_mover)
                i02 = i2
            if (op_mover == 5):
                orden += ['TERMINAR']
                tf = time()
                b = False
            if (op_mover == 0):
                orden += ['SALIR']
                tf = time()
                b = False
            if (i2 > w or i2 < 0 or j2 > h or j2 < 0):
                print('Se sale de la grilla.')
                tf = time()
                b = False
        tiempo = tf - t0
        print('Nueva posición: (',i2,',',j2,')')
        print('Secuencia de órdenes:')
        print(orden)
        print('Distancia recorrida:', distancia2, '[m]')
        indicador = movil2.consumo(distancia2, carga)
        c = carga - indicador
        print('Consumió:',c,'[mAh]')
        print('Carga restante:',indicador,'[mAh]')
        print('Tiempo del movimiento:',tiempo,'[s]')
        orden[:] = []

    if (movil == 3):
        #MOVIL AUTONOMO 3
        movil3 = MovilAutonomo3('MOVIL_AUTONOMO_3')
        t0 = time()
        print(movil3.nombre)
        i03 = randint(0, w)
        j03 = randint(0, h)
        print('La posición actual es: (',i03,',',j03,')')
        i3 = i03
        j3 = j03
        carga = randint(200, 300)
        print('Carga inicial:',carga,'[mAh]')
        indicador = carga
        b = True
        print('Insertar secuencia de operaciones:')
        while (b == True):
            op_mover = int(input())
            if (op_mover == 1):
                distancia3 = distancia3 + 1
                orden += ['ADELANTE']
                j3 = movil3.getY(j03, op_mover)
                j03 = j3
            if (op_mover == 2):
                distancia3 = distancia3 + 1
                orden += ['DERECHA']
                i3 = movil3.getX(i03, op_mover)
                i03 = i3
            if (op_mover == 3):
                distancia3 = distancia3 + 1
                orden += ['ATRAS']
                j3 = movil3.getY(j03, op_mover)
                j03 = j3
            if (op_mover == 4):
                distancia3 = distancia3 + 1
                orden += ['IZQUIERDA']
                i3 = movil3.getX(i03, op_mover)
                i03 = i3
            if (op_mover == 5):
                orden += ['TERMINAR']
                tf = time()
                b = False
            if (op_mover == 0):
                orden += ['SALIR']
                tf = time()
                b = False
            if (i3 > w or i3 < 0 or j3 > h or j3 < 0):
                print('Se sale de la grilla.')
                tf = time()
                b = False
        tiempo = tf - t0
        print('Nueva posición: (',i3,',',j3,')')
        print('Secuencia de órdenes:')
        print(orden)
        print('Distancia recorrida:', distancia3, '[m]')
        indicador = movil3.consumo(distancia3, carga)
        c = carga - indicador
        print('Consumió:',c,'[mAh]')
        print('Carga restante:',indicador,'[mAh]')
        print('Tiempo del movimiento:',tiempo,'[s]')
        orden[:] = []

    print('¿Continuar? sí(1) / no(0)')
    fin = int(input())
    if fin == 0:
        flat = 0
