def main():
    n = int(input())
    
    arr = []
    for i in range(1, n+1):
        arr.append(i)
    totalSum = sum(arr)
    if totalSum % 2 == 0:
        print("YES")
        set1 = []
        set2 = []
        vis = [0]*(n+1)
        setOneSum = 0
        maxElement = arr[-1]
        while setOneSum < totalSum//2:
            remainingSum = totalSum//2 - setOneSum
            if remainingSum > maxElement:
                set1.append(maxElement)
                setOneSum += maxElement
                vis[maxElement] = 1
                maxElement -= 1
            else:
                set1.append(remainingSum)
                setOneSum += remainingSum
                vis[remainingSum] = 1
        for i in range(1, n+1):
            if vis[i] == 0:
                set2.append(i)
        print(len(set1))
        print(" ".join(map(str, set1)))
        print(len(set2))
        print(" ".join(map(str, set2)))
    else:
        print("NO")
if __name__ == "__main__":
    main()