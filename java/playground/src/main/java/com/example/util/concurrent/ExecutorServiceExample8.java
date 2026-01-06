package com.example.util.concurrent;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

class ExecutorServiceExample8 {

    public static class HelloCallable implements Callable<String> {

        @Override
        public String call() throws Exception {
            long t = 500;
            Thread.sleep(t);
            String message = "Hello from " + Thread.currentThread().getName() + " after sleeping " + t
                    + " milliseconds.";
            System.out.println(message);
            return message;
        }
    }

    public static void main(String[] args) {
        int corePoolSize = 5;
        int maximumPoolSize = 20;
        BlockingQueue<Runnable> workqueue = new ArrayBlockingQueue<>(100);
        ExecutorService executor = new ThreadPoolExecutor(corePoolSize, maximumPoolSize, 200, TimeUnit.MILLISECONDS, workqueue);

        try {
            long begin = System.currentTimeMillis();

            int n = 10;
            List<Future<String>> futures = new ArrayList<>(n);
            List<String> results = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                Future<String> future = executor.submit(new HelloCallable());
                futures.add(future);
            }
            for (Future<String> future : futures) {
                String result = future.get();
                results.add(result);
            }

            long end = System.currentTimeMillis();
            System.out.printf("%d milliseconds have elapsed.\n", end - begin);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }

        // Say hello from the main thread.
        System.out.println("Hello from " + Thread.currentThread().getName());
    }
}
