package by.bntu.ossp.lab04;

import java.util.concurrent.locks.ReentrantLock;

public class Task01 {

    private static final int THREADS_COUNT = 2;

    public static void main(String[] args) {
        CommonResource commonResource = new CommonResource();
        ReentrantLock locker = new ReentrantLock(); // создаем заглушку
        for (int i = 0; i < THREADS_COUNT; i++) {
            Thread t = new Thread(new CountThread(commonResource, locker));
            t.setName("Thread " + (i + 1));
            t.start();
        }
    }
}

class CommonResource {
    int x = 0;
}

class CountThread implements Runnable {

    private CommonResource res;
    private ReentrantLock locker;

    CountThread(CommonResource res, ReentrantLock lock) {
        this.res = res;
        locker = lock;
    }

    public void run() {
        locker.lock(); // устанавливаем блокировку
        try {
            res.x = 1;
            for (int i = 0; i < 5; i++) {
                System.out.printf("%s X: %d \n", Thread.currentThread().getName(), res.x);
                res.x++;
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        } finally {
            locker.unlock(); // снимаем блокировку
        }
    }
}
