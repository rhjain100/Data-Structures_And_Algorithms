#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb 27 15:42:26 2019

@author: rishabhjain
"""
def f1(n):
    if n<=2:
        return 1
    else:
        return (f1(n-1)+f1(n-2))
nums=[]
fil1 = open("input1.txt","r")
fil2 = open("output1.txt","w")
for i in fil1:
    x=""
    for j in range(len(i)):
        if i[j]=="\n":
            break
        x+=i[j]
    a=str(f1(int(x)))
    a=a+"\n"
    fil2.write(a)
fil1.close()
fil2.close()