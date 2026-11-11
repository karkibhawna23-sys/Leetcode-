
class Solution {
public:

    vector<int> ans;
    vector<pair<int, int>> temp;

    void mergeSort(vector<pair<int, int>>& arr, int low, int high) {

        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {

            if (arr[i].first <= arr[j].first) {

                ans[arr[i].second] += j - (mid + 1);

                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {

            ans[arr[i].second] += j - (mid + 1);

            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int x = low; x <= high; x++) {
            arr[x] = temp[x];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.assign(n, 0);
        temp.resize(n);

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        if (n > 0) {
            mergeSort(arr, 0, n - 1);
        }

        return ans;
    }
};
