package ir.javacup.elev;

public class Elevator {
    private boolean _open = true;
    private State state = State.SECURE;
    private int flor = 0;

    public State getState() {
        return state;
    }

    public void open() {
        _open = true;
    }

    public void move(int a) {
        if (state == State.INSECURE) {
            throw new RuntimeException("Elevator is insecure");
        }
        if (a < -2 || a > 10) {
            throw new RuntimeException("Floor number should be between -2 and 10");
        }

        if (flor == a) {
            _open = true;
        } else {
            flor = a;
            _open = false;
        }
    }
    public int getFloorNumber() {
        return flor;
    }
    public boolean isOpen() {
        return _open;
    }
    public boolean isUnderMaintenance() {
        return state == State.INSECURE;
    }
    public boolean finishMaintenance() {
        return state == State.SECURE;
    }
    public void startMaintenance() {
        state = State.INSECURE;
    }
    public void close() {
        _open = false;
    }
}
