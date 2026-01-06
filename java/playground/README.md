# Java

## Initialize a new Java project with maven

Make sure maven is installed:

```bash
$ mvn -version
Apache Maven 3.9.9 (8e8579a9e76f7d015ee5ec7bfcdc97d260186937)
...
```

Initialize a new Java project with Maven archetype plugin:

```bash
mvn archetype:generate \
    -DarchetypeGroupId=org.apache.maven.archetypes \
    -DarchetypeArtifactId=maven-archetype-quickstart \
    -DgroupId=com.example \
    -DartifactId=playground \
    -Dversion=1.0.0
```

## Run Java main class

1. Use `mvn exec:java` to run the main class:

    ```bash
    mvn exec:java -Dexec.mainClass="com.example.HelloWorld"
    ```

2. Use `java` to run the main class:

    ```bash
    mvn clean compile
    java -cp target/classes com.example.HelloWorld
    ```
