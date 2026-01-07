package com.example;

import java.util.ArrayList;
import java.util.List;

public class SynchronizedExample {

    public static class Counter {

        private int count = 0;

        public synchronized void inc() {
            count++;
        }

        public int get() {
            return count;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        int m = 100;
        int n = 1000000;
        List<Thread> threads = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            Thread thread = new Thread(() -> {
                for (int j = 0; j < n; j++) {
                    counter.inc();
                }
            });
            threads.add(thread);
        }

        long begin = System.currentTimeMillis();

        for (Thread thread : threads) {
            thread.start();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        long end = System.currentTimeMillis();

        System.out.println("Counter: " + counter.get());
        System.out.printf("%d milliseconds have elapsed.\n", end - begin);
    }
}