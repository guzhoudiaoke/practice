import sys

n, m = map(int, sys.stdin.readline().split())
is_succ = [False] * n
scores = [""] * n

for i in range(n):
    scores[i] = input()

for i in range(m):
    max_score = 0
    for j in range(n):
        if max_score < int(scores[j][i]):
            max_score = int(scores[j][i])
    for j in range(n):
        if max_score == int(scores[j][i]):
            is_succ[j] = True

ans = 0
for i in range(n):
    if is_succ[i]:
        ans += 1

print(ans)
