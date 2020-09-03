
public class DynamicArray {
    private String[] data;

    public String[] getData() {
        return data;
    }

    public DynamicArray(int initialSize) {
        this.data = new String[initialSize];
    }

    public void add(String data) {
        for (int i = 0; i < this.data.length; ++i) {
            if (this.data[i] == null) {
                this.data[i] = data;
                return;
            }
        }
        String[] n = new String[this.data.length * 2];
        for (int i = 0; i < this.data.length; ++i) {
            n[i] = this.data[i];
        }
        n[this.data.length] = data;
        this.data = n;
    }

    public int delete(int index) {
        if (index >= data.length || index < 0 || data[index] == null) {
            return -1;
        }

        data[index] = null;
        for (int i = index; i < data.length - 1; ++i) {
            data[i] = data[i + 1];
        }
        data[data.length - 1] = null;

        int c = 0;
        for (String datum : data) {
            if (datum != null) {
                ++c;
            }
        }

        if (c <= (data.length / 4)) {
            String[] n = new String[data.length / 2];
            for (int i = 0; i < n.length; ++i) {
                n[i] = data[i];
            }
            data = n;
        }

        return 1;
    }
}
