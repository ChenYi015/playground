object ListComprehensionExample1 extends App {
  case class Person(name: String, age: Int)

  val people = Seq(
    Person("Alice", 16),
    Person("Bob", 17),
    Person("Charlie", 25),
    Person("David", 22)
  )

  val adults = for (person <- people if person.age >= 18) yield person

  adults.foreach(println)
}
