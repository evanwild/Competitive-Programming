from datetime import datetime, timedelta

start = [int(i) for i in input().split()]
end = [int(i) for i in input().split()]

time0 = datetime.strptime(input(), '%Y:%m:%d:%H:%M:%S')
time0 += timedelta(seconds=abs(start[0] - end[0]) + abs(start[1] - end[1]))

print(time0.strftime('%Y:%m:%d:%H:%M:%S'))