class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;

        for (string word : words)
            wordMap[word]++;

        for (int i = 0; i < wordLen; i++) {

            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {

                string word = s.substr(j, wordLen);

                if (wordMap.count(word)) {

                    seen[word]++;
                    count++;

                    while (seen[word] > wordMap[word]) {

                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } else {

                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};