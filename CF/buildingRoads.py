
def union(u, v, parents, rank):
    pu = find(u, parents, rank)
    pv = find(v, parents, rank)
    
    if pu == pv:
        # already in same tree
        return

    if rank[pu] >= rank[pv]:
        parents[pv] = pu
        rank[pu] += rank[pv]
        
    elif rank[pu] < rank[pv]:
        parents[pu] = pv
        rank[pv] += rank[pu]
        
        
def find(a, parents, rank):
    if a != parents[a]:
        parents[a] = find(parents[a], parents, rank)
    return parents[a]

def main():
    n, m = map(int, input().split())
    parents = [i for i in range(n+1)]
    rank = [1 for i in range(n+1)]
    for i in range(m):
        u, v = map(int, input().split())
        union(u, v, parents, rank)
    ref = find(1, parents, rank)
    res = []
    num_roads = 0
    # print("\n")
    # print(parents[4])
    # print(rank[4])
    for i in range(1, n+1):
        cmp = find(i, parents, rank)
        if cmp != ref:
            num_roads += 1
            res.append((i, ref))
            union(i, ref, parents, rank)
            ref = find(1, parents, rank)
    print(num_roads)
    for r in res:
        print(r[0], r[1])

if __name__ == "__main__":
    main()