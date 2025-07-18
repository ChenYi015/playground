object ListComprehensionExample2 extends App {
  def pairs(m: Int, n: Int) = for (
    i <- 1 to m;
    j <- 1 to n if j <= i
  ) yield (i, j)

  pairs(9, 9).foreach {
    case (i, j) if i != j => print(s"${i} x ${j} = ${i * j}    ")
    case (i, j) if i == j => println(s"${i} x ${j} = ${i * j}")
  }
  // Output:
  // 1 x 1 = 1
  // 2 x 1 = 2    2 x 2 = 4
  // 3 x 1 = 3    3 x 2 = 6    3 x 3 = 9
  // 4 x 1 = 4    4 x 2 = 8    4 x 3 = 12    4 x 4 = 16
  // 5 x 1 = 5    5 x 2 = 10    5 x 3 = 15    5 x 4 = 20    5 x 5 = 25
  // 6 x 1 = 6    6 x 2 = 12    6 x 3 = 18    6 x 4 = 24    6 x 5 = 30    6 x 6 = 36
  // 7 x 1 = 7    7 x 2 = 14    7 x 3 = 21    7 x 4 = 28    7 x 5 = 35    7 x 6 = 42    7 x 7 = 49
  // 8 x 1 = 8    8 x 2 = 16    8 x 3 = 24    8 x 4 = 32    8 x 5 = 40    8 x 6 = 48    8 x 7 = 56    8 x 8 = 64
  // 9 x 1 = 9    9 x 2 = 18    9 x 3 = 27    9 x 4 = 36    9 x 5 = 45    9 x 6 = 54    9 x 7 = 63    9 x 8 = 72    9 x 9 = 81
}
