class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        
       
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;


        for (auto& pair : map) {
            int num = pair.first;
            int count = pair.second;
            minHeap.push({count, num});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
       return result;
    }
};