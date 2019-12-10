from sympy import Symbol
from sympy import *
import sympy
import numpy as np
import math as m

def funcion_factorial(numero):
    if(numero == 0):
        return 1
    
    if(numero == 1):
        return numero
    else:
        return funcion_factorial(numero-1)*numero

def derivada_funcion(cantidad,f,x):
    if(cantidad == 0):
        return f
    else:
        return derivada_funcion(int(cantidad)-1,f.diff(x),x)

n = 3
m = 3
y = sympify("sin(x)")
N = n + m
x = Symbol('x')
simbolos = []

a = [] 
q = []
p = []
resultado = []
ecu = []
""" variables  """
for i in range(0,n+1):
    simbolos.append(Symbol('p'+str(i)))
for i in range(0,m+1):
    simbolos.append(Symbol('q'+str(i)))
"""  sacando Maclaurin """
for i in range(0,N+1):
    factorial = funcion_factorial(i)
    x_derivada = (derivada_funcion(i,y,x))
    sol = x_derivada.evalf(subs ={x:0})
    a.append(sol/factorial*x**i)
"""  Valores de P """
for i in range(0,n+1):
    p.append(simbolos[i]*x**i)
    
"""  Valores de Q """
for i in range(n+1,N+2):
    q.append(simbolos[i]*x**(i-(n+1)))
    
"""  Multiplicando serie*Q """
for i in range(0,len(q)):
    for j in range(0,len(a)):
        q[i] = q[i].evalf(subs ={Symbol('q0'):1})
        resultado.append(a[j]*q[i])  
""" separando los valores de x**k"""
"""para k=0"""
ecuacionN = 0
for j in range(0,len(resultado)):
    """los resultados que no tienen x"""
    if(resultado[j].count(x)==0):
        if(ecuacionN == 0):
            ecuacionN = resultado[j].evalf(subs ={Symbol('q0'):1})
        else:
            ecuacionN = ecuacionN + resultado[j].evalf(subs ={Symbol('q0'):1})
ecu.append(ecuacionN)
"""para k = 1"""
ecuacionN1 = []
ecuacionN = 0
""" se agregan todos con los datos k>=1  a un arreglo """
for j in range(0,len(resultado)):
    if(resultado[j].count(x)!=0):
        ecuacionN1.append(resultado[j])
"""se van eliminando los datos en donde k>1"""
for r in range(0,len(ecuacionN1)):
    for i in range(2,N*10):
        for j in range(0,len(ecuacionN1)):
            if(ecuacionN1[j].count(x**i)!=0):
                ecuacionN1.pop(j)
                break
"""se guarda el resultado en una variable"""
for i in range(0,len(ecuacionN1)):
    if(ecuacionN == 0):
        ecuacionN = ecuacionN1[i].evalf(subs ={x:1})
    else:
        ecuacionN = ecuacionN1[i].replace(x,1) + ecuacionN
ecu.append(ecuacionN)
"""siendo k>1"""
for i in range(2,N+1):
    ecuacionN = 0
    for j in range(0,len(resultado)):
        if(resultado[j].count(x**i)!= 0):
            if(ecuacionN == 0):
                ecuacionN = resultado[j].evalf(subs ={x:1})
            else:
                ecuacionN = ecuacionN + resultado[j].replace(x,1)
    ecu.append(ecuacionN)

padeAprox=[]
""" se resta el resultado de la multiplicacion con P(x)"""
for i in range(0,len(ecu)):
    if(i<len(p)):
        padeAprox.append(ecu[i]- p[i].replace(x,1))
    else:
        padeAprox.append(ecu[i])
""" se remueven los simbolos que ya tienen valor """
simbolos.remove(Symbol('q0'))
simbolos.remove(Symbol('p0'))
"""p0 se iguala a a0(0)"""
p_0 = padeAprox[0].replace(Symbol('p0'),0)
#print('p0: '+ str(p_0))
"""se elimina la ecuacion de p0 = a0(0) del arreglo"""
padeAprox.pop(0)
#print(solve(padeAprox,simbolos))
"""Haciendo la ecuacion"""
a = solve(padeAprox,simbolos)
qfunction = 0
pfunction = 0
cantidadq = n
countq = 1
countp = 1
for key in a:
    if(cantidadq > 0):
        qfunction = qfunction+(a[key]*x**(countq))
        countq = countq + 1
        cantidadq = cantidadq -1
    else:
        pfunction = pfunction+(a[key]*x**countp)
        countp = countp +1
funcion = (p_0 + qfunction)/(pfunction + 1)
funcion1=p_0 + qfunction
funcion2 = pfunction+1
print(funcion1)
print(funcion2)
