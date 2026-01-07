package com.example.util.concurrent.locks;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.ReentrantLock;

public class ReentrantLockExample {

    public static class Counter {

        private int count = 0;

        private ReentrantLock lock = new ReentrantLock();

        public synchronized void inc() {
            lock.lock();
            try {
                count++;
            } finally {
                lock.unlock();
            }
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
