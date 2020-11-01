package ir.javacup.exam;

public enum Medium {
    VACUUM(1),
    WATER(1.33),
    GLASS(1.5),
    DIAMOND(2.4);


    private final double n;

    private Medium(double n) {
        this.n = n;
    }

    public double n() {
        return this.n;
    }

    public double criticalAngle(Medium other) {
        if (this.n <= other.n) {
            throw new NoCriticalAngleException();
        } else {
            return (Math.sinh(other.n / this.n) * 180) / Math.PI;
        }
    }

    public double criticalAngle() {
        if (n == 1) {
            throw new NoCriticalAngleException();
        } else {
            return (Math.sinh(1 / this.n) * 180) / Math.PI;
        }
    }
}


