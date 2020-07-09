import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Supplier;

public class ThreadSolution {
    AtomicInteger fi;
    AtomicInteger gi;
    AtomicInteger hi;

    class myThread extends Thread {
        int id;
        Supplier<?> job;
        AtomicInteger value;
        AtomicInteger post;
        int threshold;

        public myThread(int id, Supplier<?> job, AtomicInteger value, AtomicInteger post, int threshold) {
            this.id = id;
            this.job = job;
            this.value = value;
            this.post = post;
            this.threshold = threshold;
        }

        @Override
        public void run() {
            while (true) {
                if (value.get() == threshold) {
                    break;
                }
            }
            job.get();
            if (post != null) {
                post.incrementAndGet();
            }
        }

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public void solve(Functions param) throws Exception {
        fi = new AtomicInteger(0);
        gi = new AtomicInteger(0);
        hi = new AtomicInteger(0);

        for (int i = 0; i < param.hs.size(); ++i) {
            new myThread(i + 1, param.hs.get(i), hi, null, param.gs.size()).start();
        }
        for (int i = 0; i < param.gs.size(); ++i) {
            new myThread(i + 1, param.gs.get(i), gi, hi, param.fs.size()).start();
        }
        for (int i = 0; i < param.fs.size(); ++i) {
            new myThread(i + 1, param.fs.get(i), fi, gi, 0).start();
        }
    }

}
