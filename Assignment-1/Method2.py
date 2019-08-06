#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb 27 15:52:14 2019

@author: rishabhjain
"""
def f2(n):
    if n<=2:
        return 1
    else:
        p=1
        q=1
        for i in range(3,n+1):
            r=p+q
            p=q
            q=r
        return r
nums=[]
fil1 = open("input2.txt","r")
fil2 = open("output2.txt","w")
for i in fil1:
    x=""
    for j in range(len(i)):
        if i[j]=="\n":
            break
        x+=i[j]
    a=str(f2(int(x)))
    a=a+"\n"
    fil2.write(a)
fil1.close()
fil2.close()