def divide(o, L, R):
    if L==R :
        ans[o] = a[L-1]
        d[o] = b[L-1]
        return
    M = (L + R) // 2
    divide(o * 2, L, M)
    divide(o * 2 + 1, M + 1, R)
    d[o] = d[o*2] * d[o*2+1]
    ans[o] = ans[o*2] + d[o*2] * ans[o*2+1]

inputfile = open('b.in','r')

n = int(inputfile.readline())

b = [int(n) for n in inputfile.readline().split()]
a = [int(n) for n in inputfile.readline().split()]

ans = [0] * (4 * n + 1)
d = [0] * (4 * n + 1)

divide(1, 1, n)

inputfile.close()

outputfile = open('std.out','w')
outputfile.write(str(ans[1])+'\n')
outputfile.close()
