package example

import org.apache.spark.{SparkConf, SparkContext, TaskContext}

object MapPartitionsExample {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setAppName("MapPartitionsExample")
      .setMaster("local[1]")

    val sc = new SparkContext(conf)

    sc.parallelize(0 until 1000, 4)
      .mapPartitions(iter =>
        Iterator.single(TaskContext.getPartitionId, iter.size)
      )

    sc.stop()
  }
}
