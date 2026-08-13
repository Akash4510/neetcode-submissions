class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int& n : stones) {
            maxHeap.push(n);
        }

        while (!maxHeap.empty()) {
            if (maxHeap.size() == 1) {
                return maxHeap.top();
            }

            int x = maxHeap.top();
            maxHeap.pop();

            int y = maxHeap.top();
            maxHeap.pop();

            int rem = abs(x - y);
            if (rem) maxHeap.push(rem);
        }

        return 0;
    }
};
