package com.example.util.concurrent;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

class ExecutorServiceExample4 {

    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();

        try {
            // Submit an anonymous callable object to the executor service.
            Future<String> future = executor.submit(new Callable<String>() {
                @Override
                public String call() throws Exception {
                    return "Hello from " + Thread.currentThread().getName();
                }
            });
            String result = future.get();
            System.out.println("Future result: " + result);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
