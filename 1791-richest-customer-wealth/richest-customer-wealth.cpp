class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int big=0;
        for(auto &row:accounts){
            int total =0;
            for(int x:row){
                total+=x;
            }
            if(total>big) big=total;
        }
        return big;
    }
    //return big;
};