def str_to_list(s):
    return list(map(int, s.strip().split(" ")))

cases = []

with open("out.txt", "r") as f:
    lines = f.readlines()

i = 0
while i < len(lines):
    try:
        case = []
        case.append(str_to_list(lines[i]))
        case.append(str_to_list(lines[i+1]))
        case.append(str_to_list(lines[i+2]))
        cases.append(case)
        i += 4
    
    except:
        break

def check_inc(ls):
    return  all(ls[i] <= ls[i+1] for i in range(len(ls) - 1))

for case in cases:
    assert check_inc(case[2])
 
