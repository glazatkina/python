# task from stepic course (3.7.5)

summ = {}
count = {}

with open('test.in','r') as inf:
    for line in inf:
        line = line.strip()
        lst = line.split()
        if int(lst[0]) in summ.keys():
            summ[int(lst[0])] += float(lst[2])
            count[int(lst[0])] += 1
        else:
            summ[int(lst[0])] = float(lst[2])
            count[int(lst[0])] = 1
    
    for i in range(11):
        if i+1 in summ.keys():
            print(i + 1, summ[i + 1] / count[i + 1])
        else:
            print(i + 1, '-')