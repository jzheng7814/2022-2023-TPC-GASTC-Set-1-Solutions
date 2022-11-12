ans = 0

for i in range(int(input())):
    xll, yll, xur, yur = [int(j) for j in input().split()]

    ans  += (xur - xll) * (yur - yll)

print(ans)