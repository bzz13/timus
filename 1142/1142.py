#!/usr/bin/python
import sys
import math

def P(n):
	return math.factorial(n)

def A(n):
	return 2**n

def solution(n):
	return P(n) * A(n - 1) + 1

n = 1
while (n > 0):
	n = int(raw_input())
	if (n == -1):
		exit()
	print P(n), A(n-1), solution(n)