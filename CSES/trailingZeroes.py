def main():
    n, curr = 5
    res = 0
    n = int(input())
    while (curr <= n):
        res += n // curr
        curr *= 5
    print(res)
    
if __name__ == "__main__":
    main()