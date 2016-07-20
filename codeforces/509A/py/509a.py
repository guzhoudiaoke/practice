n = int(input())
mat = [[0] * n] * n

for i in range(n):
    mat[0][i] = 1
    mat[i][0] = 1

for i in range(1, n):
    for j in range(1, n):
        mat[i][j] = mat[i-1][j] + mat[i][j-1]

print(mat[n-1][n-1])
