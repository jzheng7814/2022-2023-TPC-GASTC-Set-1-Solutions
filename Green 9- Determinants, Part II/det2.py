N = int(input())

for i in range(N):
    for j in range(N - 1):
        if (i + j) % 2 == 0:
            print(1, end=' ')
        else:
            print(-1, end=' ')
    
    if (i + N - 1) % 2 == 0:
        print(1)
    else:
        print(-1)