class KthLargest {
    vector<int> nums;
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums): k(k), nums(nums) {
        for (int & n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
