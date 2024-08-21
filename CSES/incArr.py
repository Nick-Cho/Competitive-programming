def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    res = 0
    prev = arr[0]
    for num in arr:
        if prev > num:
            res += prev - num
        else:
            prev = num
    print(res)

if __name__ == "__main__":
    main()