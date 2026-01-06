package com.example.util.concurrent;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.RejectedExecutionException;

class ExecutorServiceExample1 {

    public static class HelloRunnable implements Runnable {

        @Override
        public void run() {
            // Say hello from the thread.
            System.out.println("Hello from " + Thread.currentThread().getName());
        }
    }

    public static void main(String[] args) {
        // Create a new single thread executor.
        ExecutorService executor = Executors.newSingleThreadExecutor();

        try {
            // Submit a runnable to the executor.
            Runnable runnable = new HelloRunnable();
            Future<?> future = executor.submit(runnable);
            future.get();
        } catch (RejectedExecutionException | InterruptedException | ExecutionException e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }

        // Say hello from main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
