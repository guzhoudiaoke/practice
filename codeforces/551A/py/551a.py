import sys

n = int(input())
an = list(map(int, sys.stdin.readline().split()))

result = []
for i in range(n):
    rank = 1
    for j in range(n):
        if i != j and an[j] > an[i]:
            rank += 1
    result.append(rank)

print(" ".join(map(str, result)))
