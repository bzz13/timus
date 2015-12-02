#!/usr/bin/python
import sys

n = int(raw_input())
DP=[i for i in xrange(0, n + 1)];
for i in xrange(5, n + 1):
	if (i % 3 == 0):
		DP[i] = DP[i-3] * 3
	elif (i % 3 == 1):
		DP[i] = DP[i-4] * 4
	else:
		DP[i] = DP[i-2] * 2
print DP[n]