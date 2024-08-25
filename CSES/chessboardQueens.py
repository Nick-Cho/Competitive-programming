def main():
    col = [0]*8
    diag = [0]*15
    diag2 = [0]*15
    board = []
    for i in range(8):
        board.append(str(input()))
    # print(board)
    
    def rec(row, col, diag, diag2, res):
        if row == 8:
            res[0]+=1
            return
        for i in range(8):
            if board[row][i] == "*" or col[i]==1 or diag[row-i+7]==1 or diag2[row+i-1]==1:
                continue
            col[i] = 1
            diag[row-i+7] = 1
            diag2[row+i-1] = 1
            rec(row+1, col, diag, diag2, res)
            col[i] = diag[row-i+7] = diag2[row+i-1] = 0
        return res
    res=[0]
    rec(0, col, diag, diag2, res)
    print(res[0])
    
if __name__ == "__main__":
    main()