package example

import org.apache.spark.sql.SparkSession
import org.apache.spark.sql.Row
import org.apache.spark.sql.types.{
  StructType,
  StructField,
  StringType,
  IntegerType
}

object RDDToDataFrameExample2 {

  def main(args: Array[String]): Unit = {
    val spark = SparkSession
      .builder()
      .appName("RDDToDataFrameExample")
      .master("local[1]")
      .getOrCreate()

    val rdd = spark.sparkContext
      .parallelize(
        Seq(
          Row("Alice", 18, "Beijing"),
          Row("Bob", 25, "Shanghai"),
          Row("Charlie", 30, "Nanjing")
        )
      )

    val schema = StructType(
      Seq(
        StructField("name", StringType, nullable = false),
        StructField("age", IntegerType, nullable = false),
        StructField("city", StringType, nullable = false)
      )
    )

    val df = spark.createDataFrame(rdd, schema)

    df.show()

    spark.stop()
  }
}
