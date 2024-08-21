n = int(input())
if n == 1:
    print("1")
elif n <= 3:
    print("NO SOLUTION")
else:
    seq_start = 2
    seq_start2 = 1
    while seq_start<=n:
        print(seq_start, end=" ")
        seq_start += 2
    while seq_start2<=n:
        print(seq_start2, end=" ")
        seq_start2 += 2