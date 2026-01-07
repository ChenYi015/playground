package com.example;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterExample1 {

    public static void main(String[] args) throws IOException {
        String file = "output/result.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file, false))) {
            writer.write("This is the first line.\n");
            writer.write("This is the second line.\n");
        }
    }

}
