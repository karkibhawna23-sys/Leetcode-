class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word) {

            if (i >= pattern.size())
                return false;

            if (mp1.count(pattern[i]) && mp1[pattern[i]] != word)
                return false;

            if (mp2.count(word) && mp2[word] != pattern[i])
                return false;

            mp1[pattern[i]] = word;
            mp2[word] = pattern[i];

            i++;
        }

        return i == pattern.size();
    }
};