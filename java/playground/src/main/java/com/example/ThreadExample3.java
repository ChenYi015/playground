package com.example;

public class ThreadExample3 {

    public static void main(String[] args) throws InterruptedException {
        // Create a new thread with Java 8 lambda expression.
        Thread thread = new Thread(() -> {
            // Say hello from the thread.
            System.out.println("Hello from " + Thread.currentThread().getName());
        });
        thread.start();
        thread.join();

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
