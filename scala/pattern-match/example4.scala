object PatternMatchExample4 extends App {
  val input = "Alice is 25 years old"

  val s = input match {
    case s"$name is $age years old" => s"$name's age is $age"
    case _                          => "No match"
  }
  println(s) // Alice's age is 25
}
