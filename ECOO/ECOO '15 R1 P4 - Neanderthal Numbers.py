word = ''
dp = []
valid = {'ook','ookook','oog','ooga','ug','mook','mookmook','oogam','oogum','ugug'}

def solve(i):
  if i == len(word):
    return 1
  if dp[i] != -1:
    return dp[i]
  ans = 0
  substr = ''
  for j in range(len(word) - i):
    substr += word[i + j]
    if substr in valid:
      ans += solve(i + j + 1)
  dp[i] = ans
  return ans

for i in range(10):
  word = input()
  dp = [-1] * 2005
  print(solve(0))