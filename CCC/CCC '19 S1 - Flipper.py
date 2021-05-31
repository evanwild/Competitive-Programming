a, b, c, d = 1, 2, 3, 4
instructions = input()
for char in instructions:
    if char == 'H':
        a, b, c, d = c, d, a, b
    else:
        a, b, c, d = b, a, d, c
print(f'{a} {b}\n{c} {d}')