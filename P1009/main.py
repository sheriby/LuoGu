n = int(input())
sum, cur = 0, 1

for i in range(1, n+1):
    cur = cur * i
    sum = sum + cur

print(sum)