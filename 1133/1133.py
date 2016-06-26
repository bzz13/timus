#!/usr/bin/python
import sys

data = [int(x) for x in raw_input().split()]
i, Di, j, Dj, n = data[0], data[1], data[2], data[3], data[4]

if (i == n):
	print Di
	sys.exit(0)

if (j == n):
	print Dj
	sys.exit(0)

Fib = [0, 1]
for l in xrange(2, 2001):
	Fib.append(Fib[l-2] + Fib[l-1])

if (i > j):
	t = Di
	Di = Dj
	Dj = t
	t = i
	i = j
	j = t

Di1 = (Dj - Fib[j-i-1] * Di) / Fib[j-i]
if (i+1 == n):
	print Di1
	sys.exit(0)


if (n > i):
	i1 = i+1
	while i1 != n:
		i1 += 1
		Dn = Di + Di1
		Di = Di1
		Di1 = Dn
	print Dn
else:
	i1 = i
	while i1 != n:
		i1 -= 1
		Dn = Di1 - Di
		Di1 = Di
		Di = Dn
	print Dn
sys.exit(0)