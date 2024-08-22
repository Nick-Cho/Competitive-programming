def main():
    t = int(input())
    tests = []
    for i in range(t):
        tests.append(list(map(int, input().split())))
    for test in tests:
        if (2*test[0] - test[1])%3 != 0 or 2*test[0] - test[1] < 0 or 2*test[1] - test[0] < 0 or (2*test[1] - test[0])%3 < 0:
           print("NO")
        else:
            print("YES")
            
if __name__ == "__main__":
    main()