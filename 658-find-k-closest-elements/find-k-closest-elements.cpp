class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int left = 0;
        int right = arr.size() - k;

        while (left < right) {

            if (x - arr[left] > arr[left + k] - x) {
                left++;
            }
            else {
                right--;
            }
        }

        return vector<int>(arr.begin() + left,
                           arr.begin() + left + k);
    }
};