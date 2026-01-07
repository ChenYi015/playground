package com.example;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class BufferedWriterExample2 {

    public static void main(String[] args) throws IOException {
        Path path = Paths.get("output/result.txt");

        Files.createDirectories(path.getParent());

        try (BufferedWriter writer = Files.newBufferedWriter(path, StandardCharsets.UTF_8, StandardOpenOption.CREATE,
                StandardOpenOption.TRUNCATE_EXISTING)) {
            writer.write("This is the first line.\n");
            writer.write("This is the second line.\n");
            writer.write("This is the third line.\n");
        }
    }
}
