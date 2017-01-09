width, height = 10000000, int(raw_input())
matr = [[-1]*height for i in range(width)]

for y in range(0, height):
    r = raw_input().split(' ')
    a, b = int(r[0]), int(r[1])
    for x in xrange(a, b):
        matr[x][y] = y + 1

for r in xrange(0, int(raw_input())):
    x = int(raw_input())
    answer = -1
    for y in xrange(0, height):
        if (matr[x][y] > 0):
            answer = matr[x][y]
    print(answer)