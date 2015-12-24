#!/usr/bin/python
from __future__ import print_function
import sys

n = int(raw_input())
k = int(raw_input())

f = { -2 : 0, -1: 0, 0: 1, 1: k-1}

for i in xrange(2, n + 1):
	f[i] = f[i-1]*k - f[i-3]*(k-1)

answer = f[n]

print(answer, end='')