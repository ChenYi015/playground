package com.example

class Person(name: String, age: Int) {
  println("Constructing Person")

  override def toString(): String = s"Person($name, $age)"
}

object Person {
  def main(args: Array[String]): Unit = {
    val p = new Person("John", 42)
    println(p)
  }
}
