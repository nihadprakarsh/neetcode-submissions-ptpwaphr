class MedianFinder {
public:
    priority_queue<double,vector<double>,greater<double>> minHeap;
    priority_queue<double> maxHeap;
    int count = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        count++;
    }
    
    double findMedian() {
        if(count%2){
            return maxHeap.top();
        }
        else{
            return (minHeap.top()+maxHeap.top())/2.0;
        }
    }
};
