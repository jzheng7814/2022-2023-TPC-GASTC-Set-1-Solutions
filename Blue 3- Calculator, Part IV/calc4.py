s = []
exp = input().split()[::-1]

for i in exp:
    if i in ['+', '-', '*', '/', '^']:
        if len(s) < 2:
            print(False)
        else:
            a = s.pop()
            b = s.pop()

            if i == '+':
                s.append(b + a)
            elif i == '-':
                s.append(b - a)
            elif i == '*':
                s.append(b * a)
            elif i == '/':
                s.append(b / a)
            else:
                s.append(b ** a)
    else:
        s.append(int(i))

if len(s) > 1:
    print(False)
else:
    print(s[0])