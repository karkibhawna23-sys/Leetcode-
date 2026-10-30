class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;
    int snap_id = 0;

    SnapshotArray(int length) {
        arr.resize(length);

        for (int i = 0; i < length; i++) {
            arr[i].push_back({0, 0});
        }
    }

    void set(int index, int val) {
        arr[index].push_back({snap_id, val});
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto &v = arr[index];

        int low = 0;
        int high = v.size() - 1;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid].first <= snap_id) {
                ans = v[mid].second;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */