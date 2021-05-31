n = int(input())
for i in range(n):
    print(' '.join(['****' if len(word) == 4 else word for word in input().split(' ')]))