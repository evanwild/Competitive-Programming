from math import sqrt

T = int(input())

for test in range(T):
  N, B = [int(i) for i in input().split()]
  S = [int(i) for i in input().split()]

  S.sort(reverse=True)

  M = 0

  for num in S:
    if num > B:
      M += 1
    else:
      break

  ans = sqrt(N - M) * 100
  print('Bob wins $' + ('%.2f' % ans) + ' at IOI!')