package com.example.util.concurrent;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.RejectedExecutionException;

class ExecutorServiceExample3 {

    public static class HelloCallable implements Callable<String> {

        private String name;

        public HelloCallable(String name) {
            this.name = name;
        }

        @Override
        public String call() throws Exception {
            String message = "Hello, " + name + "!";
            System.out.println(message);
            return message;
        }
    }

    public static void main(String[] args) {
        // Create a new single thread executor.
        ExecutorService executor = Executors.newSingleThreadExecutor();

        try {
            // Submit a callable to the executor service.
            Callable<String> callable = new HelloCallable("World");
            Future<String> future = executor.submit(callable);
            String result = future.get();
            System.out.println("Future result: " + result);
        } catch (RejectedExecutionException | InterruptedException | ExecutionException e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());

    }
}
