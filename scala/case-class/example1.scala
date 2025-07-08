object CaseClassExample1 extends App {
  case class Book(isbn: String)
  val book = Book("978-0486282114")
  println(book) // Book(978-0486282114)
}
