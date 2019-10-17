package by.bntu.ossp.lab04;
import java.util.concurrent.Semaphore;

public class Task02 {

    private static final int THREADS_COUNT = 3;

    public static void main(String[] args) {
        Semaphore sem = new Semaphore(1); // 1 разрешение
        Resource res = new Resource();
        for (int i = 0; i < THREADS_COUNT; i++) {
            new Thread(new ThreadsCount(res, sem, "Thread " + (i + 1))).start();
        }
    }
}
class Resource{
    int x=0;
}

class ThreadsCount implements Runnable{

    private Resource res;
    private Semaphore sem;
    private String name;

    ThreadsCount(Resource res, Semaphore sem, String name){
        this.res=res;
        this.sem=sem;
        this.name=name;
    }

    public void run(){
        try{
            System.out.println(name + " ожидает разрешение");
            sem.acquire();
            res.x=1;
            for (int i = 0; i < 5; i++){
                System.out.println(this.name + ": " + res.x);
                res.x++;
                Thread.sleep(100);
            }
        }
        catch(InterruptedException e){System.out.println(e.getMessage());}
        System.out.println(name + " освобождает разрешение");
        sem.release();
    }
}
