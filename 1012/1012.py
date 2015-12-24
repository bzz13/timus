#!/usr/bin/python
from __future__ import print_function
import sys

def base10toN(num, n):
	convertString = "0123456789abcdefghijklmnopqrstuvwxyz"
	if num < n:
		return convertString[num]
	else:
		return base10toN(num//n,n) + convertString[num%n]

def isCorrect(num, n):
	if (len(num) != n):
		return False
	return num.find("00") == -1

n = int(raw_input())
k = int(raw_input())

rangeMin = k**(n-1)
rangeMax = k**n
answer = 0

for x in xrange(rangeMin, rangeMax):
	b = base10toN(x, k)
	t = isCorrect(b, n)
	# print('{0} --> {1}'.format(b, t), end='\n')
	if (t):
		answer += 1

print(answer, end='')