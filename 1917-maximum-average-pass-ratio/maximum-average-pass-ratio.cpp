
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for max heap
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        
        // Max heap: {gain, passes, total}
        priority_queue<tuple<double,int,int>> pq;
        
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), p, t});
        }
        
        while (extraStudents--) {
            auto [g, p, t] = pq.top();
            pq.pop();
            p++, t++; // assign one extra student
            pq.push({gain(p, t), p, t});
        }
        
        double sum = 0;
        while (!pq.empty()) {
            auto [g, p, t] = pq.top();
            pq.pop();
            sum += (double)p / t;
        }
        
        return sum / classes.size();
    }
};
