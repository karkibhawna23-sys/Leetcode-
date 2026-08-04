class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_set<int> st;

        for (int candy : candyType) {
            st.insert(candy);
        }

        int unique = st.size();
        int canEat = candyType.size() / 2;

        return min(unique, canEat);
    }
};