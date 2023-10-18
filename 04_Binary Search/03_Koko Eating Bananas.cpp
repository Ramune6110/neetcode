class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (int i = 0; i < piles.size(); i++) {
            r = max(r, piles[i]);
        }

        int result = r;

        while (l <= r) {
            int k = l + (r - l) / 2;
            long int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += ceil((double)piles[i] / k);
            }

            if (hours <= h) {
                result = min(result, k);
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        
        return result;
    }
};