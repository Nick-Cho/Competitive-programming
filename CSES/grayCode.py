def main():
    n = int(input())
    def rec(n):
        if n == 1:
            return ["0", "1"]
        
        prevGrayCode = rec(n-1)
        reversedPrevGrayCode = prevGrayCode[::-1]
        
        prevSize = len(prevGrayCode)
        index = 0
        # print("Reversed: " , reversedPrevGrayCode)
        while index < prevSize:
            # print(prevGrayCode)
            appendedZero = "0" + prevGrayCode[index]
            
            prevGrayCode[index] = "1" + reversedPrevGrayCode[index]
            
            prevGrayCode.append(appendedZero)
            
            # print(prevGrayCode)
            
            index += 1
            
        return prevGrayCode
    arr = rec(n)
    for num in arr:
        print(num)
    
if __name__ == "__main__": 
    main()  