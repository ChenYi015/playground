package example

import org.apache.spark.{SparkConf, SparkContext}

object MapPartitionsWithIndexExample {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setAppName("MapPartitionsWithIndexExample")
      .setMaster("local[1]")

    val sc = new SparkContext(conf)

    sc
      .parallelize(1 to 100, 4)
      .mapPartitionsWithIndex((index, iter) => {
        Iterator.single((index, iter.size))
      })
      .foreach {
        case (index, size) => {
          println(s"Partition $index has $size elements.")
        }
      }

    sc.stop()
  }
}
