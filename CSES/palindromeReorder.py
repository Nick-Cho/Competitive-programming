def main():
    s = str(input())
    m = {}
    stk = []
    for c in s:
        m[c] = m.get(c, 0) + 1
    odd = False
    oddChar = ''
    res = ""
    for key, value in m.items():
        if value % 2 == 1:
            if odd:
                print("NO SOLUTION")
                return
            odd = True
            oddChar = key            
        stk.append(key*(value//2))
        res += key*(value//2)
    res += oddChar
    while stk:
        res += stk.pop()
    print(res)
if __name__ == "__main__":
    main()