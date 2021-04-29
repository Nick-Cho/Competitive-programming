import sys

ipt = str(input())
S,R = ipt.split(' ')
S = int(S)
R= int(R)
#print(S,R)

if (S**2) > (3.14*R**2):
  print ("SQUARE")
else:
  print ("CIRCLE")
