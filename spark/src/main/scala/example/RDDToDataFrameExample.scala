package example

import org.apache.spark.sql.SparkSession

object RDDToDataFrameExample {

  case class Person(name: String, age: Int, city: String)

  def main(args: Array[String]): Unit = {
    val spark = SparkSession
      .builder()
      .appName("RDDToDataFrameExample")
      .master("local[1]")
      .getOrCreate()

    import spark.implicits._

    spark.sparkContext
      .parallelize(
        Seq(
          Person("Alice", 18, "Beijing"),
          Person("Bob", 25, "Shanghai"),
          Person("Charlie", 30, "Nanjing")
        )
      )
      .toDF()
      .show()
  }
}
