for i in range(int(input())):
    xll, yll, xur, yur = [int(j) for j in input().split()]

    print((xur - xll) * (yur - yll))