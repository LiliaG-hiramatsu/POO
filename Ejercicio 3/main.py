from movil import Movil
from movilAutonomo import MovilAutonomo
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
orden = []
movil = []
print('Ingresar la cantidad de moviles autónomos:')
N = int(input('N = '))

#MOVIL MANUAL
movil0 = Movil('MOVIL_MANUAL')
print(movil0.nombre)
i0 = randint(0, w)
j0 = randint(0, h)
print('La posición actual es: (',i0,',',j0,')')
i = i0
j = j0
print('Insertar secuencia de operaciones:')
b = True
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
#MOVILES AUTÓNOMOS
movil1 = MovilAutonomo('MOVIL_AUTONOMO')
print(movil1.nombre)
k = 1
while (k <= N):
    start_time = time()
    movil += [k]
    i01 = randint(0, w)
    j01 = randint(0, h)
    print('La posición actual es: (',i01,',',j01,')')
    i1 = i01
    j1 = j01
    carga = randint(200, 300)
    print('Carga inicial:', carga,'[mAh]')
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
            end_time = time()
            b = False
        if (op_mover == 0):
            orden += ['SALIR']
            end_time = time()
            b = False
        if (i1 > w or i1 < 0 or j1 > h or j1 < 0):
            print('Se sale de la grilla.')
            end_time = time()
            b = False
    tiempo = end_time - start_time
    print('Nueva posición: (',i1,',',j1,')')
    print('Secuencia de órdenes:')
    print(orden)
    print('Distancia recorrida:',distancia1,'[m]')
    indicador = movil1.consumo(distancia1, carga)
    c = carga - indicador
    print('Consumió:',c,'[mAh]')
    print('Carga restante:',indicador,'[mAh]')
    print('Tiempo del movimiento:',tiempo,'[s]')
    i01 = 0
    j01 = 0
    start_time = 0
    distancia1 = 0
    orden[:] = []
    k = k + 1
print('Lista de móviles autónomos:')
print(movil)
