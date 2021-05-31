n = int(input())

count_s = 0 
count_t = 0 

for i in range(0, n):
    s = input()
    count_s += s.count('s') + s.count('S')
    count_t += s.count('t') + s.count('T')

if count_t > count_s:
    print('English')
else:
    print('French')