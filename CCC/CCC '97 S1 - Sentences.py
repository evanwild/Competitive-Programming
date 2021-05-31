n = int(input())

for i in range(n):
    sub = int(input())
    ver = int(input())
    obj = int(input())

    subs = []
    vers = []
    objs = []

    for i in range(sub):
        subs.append(input())
    for i in range(ver):
        vers.append(input())
    for i in range(obj):
        objs.append(input())

    for s in subs:
        for v in vers:
            for o in objs:
                print(f'{s} {v} {o}.')