from itertools import permutations

def main():
    s = input()

    def solve(S):
       
        s_sorted = sorted(S)
        
        unique_strings = set()
        
        for perm in permutations(s_sorted):
            unique_strings.add(''.join(perm))
            
        return unique_strings
    
    res = solve(s)
    print(len(res))
    for s in res:
        print(s)
        
if __name__ == "__main__":
    main()