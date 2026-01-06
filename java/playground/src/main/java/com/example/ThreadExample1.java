package com.example;

import java.util.ArrayList;
import java.util.List;

public class ThreadExample1 {

    public static class HelloRunnable implements Runnable {

        @Override
        public void run() {
            // Say hello from the thread.
            System.out.printf("Hello from ", Thread.currentThread().getName());
        }

    }

    public static void main(String[] args) throws InterruptedException {
        // Create a new thread by implementing Runnable interface.
        Runnable runnable = new HelloRunnable();
        Thread thread = new Thread(runnable);
        thread.start();
        thread.join();

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
