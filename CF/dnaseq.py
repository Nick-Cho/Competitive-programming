dna = str(input())
res = 0
curr_max = 0
prev = dna[0]
for c in dna:
    if c==prev:
        curr_max+=1
    else:
        res = max(res, curr_max)
        curr_max = 1
        prev = c
        
print(max(res, curr_max))
    