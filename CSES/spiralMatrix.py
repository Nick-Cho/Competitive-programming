
def main():
    n = int(input())
    reqs = []
    for i in range(n):
        reqs.append(list(map(int, input().split())))
    # print(reqs)
    
    for req in reqs:
        x, y = req[0], req[1]
        # Determine the spiral
        spiral = max(x, y) # Matrix is 1 indexed so don't need +1
        start = (spiral - 1) ** 2 + 1
        end = spiral ** 2
        if spiral % 2 == 0:
            if y>=x:
                print(start + x - 1)
            else:
                print(end - y + 1)
        
        else:
            if x>=y:
                print(start + y - 1)
            else:
                print(end - x + 1)            
    
if __name__ == "__main__":
    main()