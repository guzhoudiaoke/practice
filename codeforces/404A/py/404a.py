n = int(input())
square = [""] * n

for i in range(n):
    square[i] = input()

diagonals = square[0][0]
undiagonals = square[0][1]
ans = True
if diagonals == undiagonals:
    ans = False
else:
    for i in range(n):
        for j in range(n):
            if i == j or i + j == n-1:
                if square[i][j] != diagonals:
                    ans = False
            else:
                if square[i][j] != undiagonals:
                    ans = False

if ans:
    print("YES")
else:
    print("NO")
