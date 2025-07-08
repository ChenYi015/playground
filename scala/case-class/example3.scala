object CaseClassExample3 extends App {
  case class Message(sender: String, recipient: String, body: String)
  val message1 = Message("Alice", "Bob", "Hello, Bob!")
  val message2 = Message("Alice", "Bob", "Hello, Bob!")
  println(message1 == message2) // true
}
