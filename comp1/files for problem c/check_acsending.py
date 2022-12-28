s = None
with open('c_files/out_arr.txt', 'r') as f:
    s = f.read()

def is_sorted(a):
    return a == sorted(a)

l = [is_sorted([int(i) for i in x.strip().split(' ')]) for x in s.split('\n')]
print(l)
for i in l:
    if not i:
        print(i)