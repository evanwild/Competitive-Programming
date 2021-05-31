import sys
sys.setrecursionlimit(10**9) 

N = int(input())
words = set()
word = ""
dp = []

def solve(i):
  if i == len(word):
    return 0
  if dp[i] != -1:
    return dp[i]
  ans = 10**9
  substr = ''
  for j in range(len(word) - i):
    substr += word[i + j]
    if substr in words:
      ans = min(ans, 1 + solve(i + j + 1))
  dp[i] = ans
  return ans

for i in range(N):
  words.add(input())

for i in range(10):
  word = input()
  dp = [-1] * 2005
  print(solve(0) - 1)