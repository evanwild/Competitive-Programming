max_contestant_num = 0
max_contestant_score = -1
for i in range(1, 6):
    score = [int(s) for s in input().split()]
    if sum(score) > max_contestant_score:
        max_contestant_score = sum(score)
        max_contestant_num = i
print(f'{max_contestant_num} {max_contestant_score}')