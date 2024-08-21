from typing import List

def main():
    n = int(input())
    sett = set()
    arr = (input().split())

    for num in arr:
        sett.add(int(num))
    for i in range(1,int(n)+1):
        if i not in sett:
            print(i)
            return

if __name__ == "__main__":
    main()