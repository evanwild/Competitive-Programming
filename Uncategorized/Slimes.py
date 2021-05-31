import sys
sys.setrecursionlimit(10**9)

N = int(input())
a = []
prefix_sum = []
dp = [[-1 for i in range(405)] for j in range(405)]

def a_sum(l, r):
  if l == 0:
    return prefix_sum[r]
  return prefix_sum[r] - prefix_sum[l - 1]

def solve(l, r):
  if l == r:
    return 0
  if dp[l][r] != -1:
    return dp[l][r]
  
  ans = 100000000000000000000
  for i in range(l, r):
    ans = min(ans, solve(l, i) + solve(i + 1, r) + a_sum(l, r))

  dp[l][r] = ans
  return ans
  
a = [int(i) for i in input().split()]

prefix_sum.append(a[0])
for i in range(1, N):
  prefix_sum.append(prefix_sum[i - 1] + a[i])

print(solve(0, N - 1))