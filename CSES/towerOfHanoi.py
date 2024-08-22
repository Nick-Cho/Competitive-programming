def main():
  n = int(input())
  moves = []
  sourceStk, destStk, auxStk = 1, 3, 2
  def moveDisk(numDisks, moves, src, dest, aux):
    if numDisks == 1:
      moves.append([src, dest])
      return

    moveDisk(numDisks-1, moves, src, aux, dest)
    moves.append([src, dest])
    moveDisk(numDisks-1, moves, aux, dest, src)


  moveDisk(n, moves, sourceStk, destStk, auxStk)
  print(len(moves))
  for m in moves:
    print(m[0], m[1])

if __name__ == "__main__":
  main()