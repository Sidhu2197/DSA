#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
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

        if (maxidx != i) {
            swap(vec[i], vec[maxidx]);
            heapify(maxidx);
        }
    }

    void pop() {
        if (vec.empty()) return;
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(0);
    }

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

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator<(const Student& obj) const {
        return this->marks < obj.marks;
    }
};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("tony", 85));
    pq.push(Student("meow", 90));
    pq.push(Student("optimus", 98));
    
    while (!pq.empty()) {
        cout << "top = "<<pq.top().name<<" , "<<pq.top().marks<< endl;
        pq.pop();
    }
    
    return 0;
}