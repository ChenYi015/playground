import scala.util.Random

object PatternMatchExample1 extends App {
  val x: Int = Random.nextInt(4)

  val s: String = x match {
    case 0 => "zero"
    case 1 => "one"
    case 2 => "two"
    case _ => "other"
  }

  println(s)
}
