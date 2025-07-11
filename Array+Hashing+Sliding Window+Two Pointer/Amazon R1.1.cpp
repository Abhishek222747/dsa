Design a data structure to optimize storage for array of Booleans, I used bits of an Integer 
to store Booleans efficiently.


class BitBooleanArray {
private:
    vector<int> bits;
    int n;

public:
    BitBooleanArray(int size) {
        n = size;
        bits.resize((n + 31) / 32, 0);  // ceil(n / 32)
    }

    void set(int index, bool value) {
        int bucket = index / 32;
        int bitPos = index % 32;

        if (value)
            bits[bucket] |= (1 << bitPos);
        else
            bits[bucket] &= ~(1 << bitPos);
    }

    bool get(int index) {
        int bucket = index / 32;
        int bitPos = index % 32;
        return (bits[bucket] >> bitPos) & 1;
    }
};
