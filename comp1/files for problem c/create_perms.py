from itertools import permutations

n = 7
n_fact = 720

with open('inp.txt', 'w') as f:
    s = list(permutations(list(range(1,n+1))))
    
    # [1,2,3]
    f.write(f'{n_fact}\n')
    lst = [' '.join([str(i) for i in l]) for l in s]
    for i in lst:
        f.write(f'{n}\n')
        f.write(f'{i}\n')
    # f.write('\n'.join())