#!/usr/bin/python
import sys
import math

def A(m,n):
	return math.factorial(n) / math.factorial(n-m)

def solution(n):
	return sum([A(i, n) for i in xrange(2, n + 1)])

n = int(raw_input())
print solution(n)