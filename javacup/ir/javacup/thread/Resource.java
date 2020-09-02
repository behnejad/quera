package ir.javacup.thread;


public class Resource {
	private volatile int content = -1;

	public int get() {
		synchronized (this) {
			if (content == -1) {
				try {
					this.wait();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			int a = content;
			content = -1;
			return a;
		}
	}
	
	public void set(int value) {
		synchronized (this) {
			content = value;
			this.notify();
		}
	}
}
