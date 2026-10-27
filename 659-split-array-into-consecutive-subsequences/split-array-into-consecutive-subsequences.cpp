
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;

        for (int x : nums) {
            freq[x]++;
        }

        for (int x : nums) {
            if (freq[x] == 0) {
                continue;
            }

            // Try to add x to an existing subsequence
            if (need[x] > 0) {
                need[x]--;
                need[x + 1]++;
            }
            // Otherwise, start a new subsequence x, x+1, x+2
            else if (freq[x + 1] > 0 && freq[x + 2] > 0) {
                freq[x + 1]--;
                freq[x + 2]--;
                need[x + 3]++;
            }
            else {
                return false;
            }

            freq[x]--;
        }

        return true;
    }
};
