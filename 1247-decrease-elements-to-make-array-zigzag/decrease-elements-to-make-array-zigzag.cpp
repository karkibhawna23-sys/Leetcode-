class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();

        int evenCost = 0;
        int oddCost = 0;

        for (int i = 0; i < n; i++) {

            int left = (i == 0) ? INT_MAX : nums[i - 1];
            int right = (i == n - 1) ? INT_MAX : nums[i + 1];

            int decrease = max(0, nums[i] - min(left, right) + 1);

            if (i % 2 == 0)
                evenCost += decrease;
            else
                oddCost += decrease;
        }

        return min(evenCost, oddCost);
    }
};