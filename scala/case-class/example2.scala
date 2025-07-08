object CaseClassExample2 extends App {
  case class Message(sender: String, recipient: String, body: String)
  val message = Message("Alice", "Bob", "Hello, Bob!")
  println(
    s"Message from ${message.sender} to ${message.recipient}: ${message.body}"
  )
  // Message from Alice to Bob: Hello, Bob!
}
