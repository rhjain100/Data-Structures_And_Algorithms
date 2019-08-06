#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb 27 20:41:25 2019

@author: rishabhjain
"""
def PowerofG(n):
    G=[[0,1],[1,1]]
    if n==1:
        return G
    else:
        if n%2==0:
            H=PowerofG(n/2)
            return matmult(H,H)
        else:
            H=PowerofG((n-1)/2)
            return matmult(matmult(H,H),G)
    
def matmult(X,Y):
    result = [[0,0],
              [0,0]]
    for i in range(len(X)):
        for j in range(len(Y[0])):
            for k in range(len(Y)):
               result[i][j] += X[i][k] * Y[k][j]
    return result

def f3(n):
    temp = PowerofG(n)
    return (temp[1][0])

nums=[]
fil1 = open("input3.txt","r")
fil2 = open("output3.txt","w")
for i in fil1:
    x=""
    for j in range(len(i)):
        if i[j]=="\n":
            break
        x+=i[j]
    a=str(f3(int(x)))
    a=a+"\n"
    fil2.write(a)
fil1.close()
fil2.close()