#!/usr/bin/python
import sys
from collections import defaultdict

n = int(raw_input())
mod = 1000000009

primes3 = set([101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997])
prefs = set(x%100 for x in primes3)
deduction = defaultdict(set)
for pref in prefs:
	for d in xrange(0,10):
		m = pref*10 + d
		if m in primes3:
			deduction[pref].add(d)

dp = [[0 for x in xrange(100)] for x in xrange(n+1)] # n x 100
for x in primes3:
	dp[3][x%100] += 1

for i in xrange(4,n+1):
	for pref in prefs:
		for d in deduction[pref]:
			m = pref*10 + d
			dp[i][m%100] += dp[i-1][pref]
			dp[i][m%100] %= mod

# for j in xrange(3, n+1):
# 	ans = 0
# 	for i in xrange(1, 100):
# 		ans += dp[j][i]
# 		ans %= mod
# 	print j, " --> ", ans

ans = 0
for i in xrange(1, 100):
	ans += dp[n][i]
	ans %= mod
print ans