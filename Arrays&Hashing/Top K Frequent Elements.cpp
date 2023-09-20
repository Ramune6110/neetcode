class Solution {
public:
    /* bucket sort */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            buckets[it->second].push_back(it->first);
        }

        vector<int> result;
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }

            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }

        return result;
    }

    /* heap */
    /*vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }*/
};