object GenericClassExample1 extends App {
  class Stack[T] {
    private var elements: List[T] = Nil

    def push(elem: T): Unit = {
      elements = elem :: elements
    }

    def peek: T = elements.head

    def pop(): T = {
      val top = elements.head
      elements = elements.tail
      top
    }
  }

  {
    val numbers = new Stack[Int]
    numbers.push(1)
    numbers.push(2)

    println(numbers.peek) // Output: 2
    println(numbers.pop()) // Output: 2
    println(numbers.peek) // Output: 1
    println(numbers.pop()) // Output: 1
  }

  sealed trait Fruit
  case class Apple(weight: Int) extends Fruit
  case class Banana(weight: Int) extends Fruit

  {
    val fruits = new Stack[Fruit]
    fruits.push(Apple(100))
    fruits.push(Banana(200))

    println(fruits.peek) // Output: Banana(200)
    println(fruits.pop()) // Output: Banana(200)
    println(fruits.peek) // Output: Apple(100)
    println(fruits.pop()) // Output: Apple(100)
  }
}
