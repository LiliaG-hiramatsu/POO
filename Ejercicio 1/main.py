#Dada una circunferencia de radio R ubicada en el centro de una pantalla de
#W x H, se desea calcular el porcentaje de 1000 puntos generados aleatoriamente
#que caen dentro de ella.
#R, W y H son valores dados por el operador, cumpliéndose las siguiente restricciones:
#50<R<600 pixels
#Máximo W es 1024 pixels
#Máximo H es 768 pixels

from Puntos import Puntos

a = True
while (a == True):
    R = int(input("R = "))
    if (50 >= R >= 600):
        print('Error')
        a = False
    else:
        W = int(input("W = "))
        if (W > 1024):
            print('Error')
            a = False
        else:
            H = int(input("H = "))
            if (H > 768):
                print('Error')
                a = False
            else:
                p = Puntos(W, H, R)
                a = False
