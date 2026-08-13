class MinStack {
    vector<int> arr;
    vector<int> minIdx;

public:
    MinStack() {}
    
    void push(int val) {
        arr.push_back(val);

        if (minIdx.empty() || val < arr[minIdx.back()]) {
            int currIdx = arr.size() - 1;
            minIdx.push_back(currIdx);
        }
    }
    
    void pop() {
        if (minIdx.back() == arr.size() - 1) {
            minIdx.pop_back();
        }
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return arr[minIdx.back()];
    }
};
