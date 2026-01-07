package com.example.io;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;

public class FileInputStreamExample {

    private static String FILE = "output/result.txt";

    public static void main(String[] args) throws FileNotFoundException, IOException {
        writeString();
        readByByte();
        readByBytes();
    }

    private static void writeString() throws IOException {
        Path path = Path.of(FILE);
        Files.createDirectories(path.getParent());
        Files.writeString(path, "Hello, World!\n", StandardCharsets.UTF_8);
    }

    private static void readByByte() throws FileNotFoundException, IOException {
        try (FileInputStream in = new FileInputStream(FILE)) {
            int ch;
            while ((ch = in.read()) != -1) {
                System.out.print((char) ch);
            }
        }
    }

    private static void readByBytes() throws FileNotFoundException, IOException {
        try (FileInputStream in = new FileInputStream(FILE)) {
            byte[] buf = new byte[8];
            int len;
            while ((len = in.read(buf)) != -1) {
                System.out.print(new String(buf, 0, len, StandardCharsets.UTF_8));
            }
        }
    }
}
