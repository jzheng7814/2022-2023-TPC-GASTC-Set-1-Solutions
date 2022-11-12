N = int(input())

for expression in range(N):
    ans = True

    s = []
    exp = input()

    for i in exp:
        if i in ['(', '{', '[']:
            s.append(i)
        else:
            if i == ')':
                if not (len(s) > 0 and s[-1] == '('):
                    ans = False
                    break
                else:
                    s.pop()

            elif i == '}':
                if not (len(s) > 0 and s[-1] == '{'):
                    ans = False
                    break
                else:
                    s.pop()

            else:
                if not (len(s) > 0 and s[-1] == '['):
                    ans = False
                    break
                else:
                    s.pop()

    
    print(ans and len(s) == 0)
