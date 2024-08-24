def main():
    n = int(input())
    apples = []
    apples = list(map(int, input().split(" ")))
    # print(apples)

    def rec(i, sum1, sum2):
        if i == n:
            return abs(sum1-sum2)
        
        take = rec(i+1, sum1+apples[i], sum2)
        not_take = rec(i+1, sum1, sum2+apples[i])
        return min(take, not_take)
    
    res = rec(0, 0, 0)
    print(res)
    
if __name__ == "__main__":
    main()