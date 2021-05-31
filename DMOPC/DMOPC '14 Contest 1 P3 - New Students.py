import sys
input = sys.stdin.readline

I = int(input())
avg = 0

for x in range(I):
    avg += int(input())

S = int(input())

for x in range(S):
    avg += int(input())
    I += 1
    print(avg / I)