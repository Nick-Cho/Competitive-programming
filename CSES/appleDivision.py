def main():
    n = int(input())
    apples = []
    apples = list(map(int, input().split(" ")))
    # print(apples)
    res = rec(0, 0, 0, 0)
    def rec(i, sum1, sum2, diff):
        if i == n:
            return diff
        
    
    
if __name__ == "__main__":
    main()