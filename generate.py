from random import randint
from os import system

FOLDERNAME = "Blue 4- Toothpicks and Marshmallows, Part I"
PROGRAMNAME = "toothpick1.py"

for i in range(1, 6):
    testcase_success = False

    while not testcase_success:
        inp = ''

        N = randint(1000, 10000)
        M = randint(int(N / 2), 2 * N)
        inp += f'{N} {M}\n'

        edges = set()

        for j in range(M):
            a = randint(1, N - 1)
            b = randint(a + 1, N)

            while (a, b) in edges:
                a = randint(1, N - 1)
                b = randint(a + 1, N)
            
            edges.add((a, b))

            inp += f'{a} {b}\n'
        
        with open("in.txt", "w") as tmpout:
            tmpout.write(inp)
    
        if system(f'python3 "{FOLDERNAME}/{PROGRAMNAME}" < in.txt > out.txt') == 0:
            testcase_success = True
            
            with open(f'{FOLDERNAME}/{i}.txt', "w") as outfile:
                outfile.write(inp)
                outfile.write('\n')
                with open('out.txt', 'r') as tmpin:
                    outfile.write(tmpin.read())
                outfile.write('\n\n')
