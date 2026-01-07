package com.example.io;

import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class PrintWriterExample {

    public static void main(String[] args) throws IOException {
        try (PrintWriter writer = new PrintWriter(System.out, true)) {
            boolean b = true;
            writer.println(b);

            char ch = 'x';
            writer.println(ch);

            char[] chs = new char[] { 'a', 'b', 'c' };
            writer.println(chs);

            int i = 42;
            writer.println(i);

            double d = 3.14;
            writer.println(d);

            String s = "Hello, World!";
            writer.println(s);

            writer.printf("Now is %s.\n", LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
        }
    }
}
