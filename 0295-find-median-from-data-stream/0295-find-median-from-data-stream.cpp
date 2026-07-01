class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianFinder() {
    }
    void addNum(int num) {
        minH.push(num);

        maxH.push(minH.top());
        minH.pop();

        if (maxH.size() - minH.size() > 1) {
            minH.push(maxH.top());
            maxH.pop();
        }
    }

    double findMedian() {
        if (minH.size() == maxH.size()) {
            return (minH.top() + maxH.top()) / 2.0;
        }
        return maxH.top() / 1.0;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */