from random import randint

class Puntos:
    def __init__(self, w, h, r):
        i = 1
        j = 0
        while (i<=1000):
            self.x = randint(0, w-1)
            self.y = randint(0, h-1)
            x = self.x
            y = self.y
            #print('punto[',i,'] = (',x,',',y,')')
            rx = (w-1)/2
            ry = (h-1)/2
            if (x < rx+r and x > rx-r and y < ry+r and y > ry-r):
                j = j+1
            i = i+1
        #print('Hay', j, 'puntos dentro de la circunferencia de radio', r)
        porcentaje = float((j/1000)*100)
        print('Hay un', porcentaje, 'por ciento de puntos en la circunferencia de radio', r)
