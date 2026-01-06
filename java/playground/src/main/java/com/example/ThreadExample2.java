package com.example;

public class ThreadExample2 {

    public static class HelloThread extends Thread {

        @Override
        public void run() {
            // Say hello from the thread.
            System.out.println("Hello from " + Thread.currentThread().getName());
        }
    }

    public static void main(String[] args) throws InterruptedException {
        // Create a new thread by extending Thread class.
        Thread thread = new HelloThread();
        thread.start();
        thread.join();

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
