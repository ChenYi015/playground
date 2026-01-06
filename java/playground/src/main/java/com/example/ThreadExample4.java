package com.example;

public class ThreadExample4 {
    public static void main(String[] args) throws InterruptedException {
        // Create a new thread with anonymous class which implements Runnable interface.
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                // Say hello from the thread.
                System.out.println("Hello from " + Thread.currentThread().getName());
            }
        });
        thread.start();
        thread.join();

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
