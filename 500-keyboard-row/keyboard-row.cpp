class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for(string word : words) {

            int count1 = 0, count2 = 0, count3 = 0;

            for(char ch : word) {

                ch = tolower(ch);

                if(row1.find(ch) != string::npos)
                    count1++;

                else if(row2.find(ch) != string::npos)
                    count2++;

                else
                    count3++;
            }

            if(count1 == word.size() ||
               count2 == word.size() ||
               count3 == word.size()) {

                ans.push_back(word);
            }
        }

        return ans;
    }
};