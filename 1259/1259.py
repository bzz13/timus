#!/usr/bin/python
import sys

def f(n):
	return 1 + 2**n + 3**n + 4**n

c = f(int(raw_input()))
answer = 0;
while (c % 10 == 0):
	answer += 1
	c /= 10

print answer