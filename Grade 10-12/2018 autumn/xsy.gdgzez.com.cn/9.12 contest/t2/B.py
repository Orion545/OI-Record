inputfile = open('b.in','r')

n = int(inputfile.readline())

b = [int(n) for n in inputfile.readline().split()]
a = [int(n) for n in inputfile.readline().split()]

ans = 0
cur = 1
for i in range(0, n):
    res = a[i]
    ans += res * cur
    cur *= b[i]

inputfile.close()

outputfile = open('std.out','w')
outputfile.write(str(ans)+"\n")
outputfile.close()
