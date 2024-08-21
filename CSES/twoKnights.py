def main():
    n = int(input())
    print(0)
    for i in range(2, n+1):
        print(((i**2 * (i**2 - 1)) // 2) - (4 * (i-1) * (i-2)))
        
if __name__ == "__main__":
    main()