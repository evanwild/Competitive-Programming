def z(l):
    ans = l.count('A')*4 + l.count('K')*3 + l.count('Q')*2 + l.count('J')
    ans += max(0, 3 - len(l))
    return ans 

x = input()

C = x[1:x.find('D')]
D = x[x.find('D')+1:x.find('H')]
H = x[x.find('H')+1:x.find('S')]
S = x[x.find('S')+1:]

print("Cards Dealt              Points")
print(f"Clubs {' '.join(C)} {z(C)}")
print(f"Diamonds {' '.join(D)} {z(D)}")
print(f"Hearts {' '.join(H)} {z(H)}")
print(f"Spades {' '.join(S)} {z(S)}")
print(f"Total {z(C)+z(D)+z(H)+z(S)}")