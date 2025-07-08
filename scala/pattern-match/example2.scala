object PatternMatchExample2 extends App {
  def matchTest(x: Int): String = x match {
    case 0 => "zero"
    case 1 => "one"
    case 2 => "two"
    case _ => "other"
  }

  for (i <- 0 until 4) {
    println(matchTest(i))
  }
}
