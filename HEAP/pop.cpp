#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class heap {
    vector<int> vec;
public:

    void heapify(int i) {
        if (i >= vec.size()) {
            return;
        }
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxidx = i;
        if (l < vec.size() && vec[l] > vec[maxidx]) {
            maxidx = l;
        }

        if (r < vec.size() && vec[r] > vec[maxidx]) {
            maxidx = r;
        }

        if (maxidx != i) { // only swap if needed
            swap(vec[i], vec[maxidx]); // FIXED: arr → vec
            heapify(maxidx);
        }
    }

    void pop() {
        if (vec.empty()) return;
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(0);
    }

    // Added because main() calls them
    void push(int val) {
        vec.push_back(val);
        int i = vec.size() - 1;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (vec[parent] < vec[i]) {
                swap(vec[parent], vec[i]);
                i = parent;
            } else break;
        }
    }

    int top() {
        if (vec.empty()) return -1;
        return vec[0];
    }

    bool empty() {
        return vec.empty();
    }
};

int main() {
    heap h; // FIXED: Heap → heap
    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);

    while (!h.empty()) {
        cout << "top = " << h.top() << endl;
        h.pop();
    }
    return 0;
}
