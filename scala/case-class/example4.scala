object CaseClassExample4 extends App {
  case class Message(sender: String, recipient: String, body: String)
  val message1 = Message("Alice", "Bob", "Hello, Bob!")
  val message2 = message1.copy(body = "Goodbye, Bob!")
  println(message1) // Message(Alice,Bob,Hello, Bob!)
  println(message2) // Message(Alice,Bob,Goodbye, Bob!)
}
