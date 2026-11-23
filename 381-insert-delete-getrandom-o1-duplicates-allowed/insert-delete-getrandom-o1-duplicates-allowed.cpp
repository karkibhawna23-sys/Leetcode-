
class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {
        
    }

    bool insert(int val) {
        bool result = mp[val].empty();

        mp[val].insert(nums.size());
        nums.push_back(val);

        return result;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int idx = *mp[val].begin();
        int last = nums.back();
        int lastIdx = nums.size() - 1;

        nums[idx] = last;

        mp[val].erase(idx);
        mp[last].erase(lastIdx);

        if (idx != lastIdx) {
            mp[last].insert(idx);
        }

        nums.pop_back();

        if (mp[val].empty()) {
            mp.erase(val);
        }

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */