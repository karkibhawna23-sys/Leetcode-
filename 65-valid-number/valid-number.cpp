class Solution {
public:
    bool isNumber(string s) {

        bool num = false;
        bool dot = false;
        bool exp = false;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if(isdigit(ch)) {
                num = true;
            }

            else if(ch == '.') {

                // dot ek hi baar
                // e ke baad dot nahi
                if(dot || exp) {
                    return false;
                }

                dot = true;
            }

            else if(ch == 'e' || ch == 'E') {

                // e ek hi baar
                // e se pehle number hona chahiye
                if(exp || !num) {
                    return false;
                }

                exp = true;
                num = false;
            }

            else if(ch == '+' || ch == '-') {

                // sign start me ya e ke baad
                if(i != 0 && s[i-1] != 'e' && s[i-1] != 'E') {
                    return false;
                }
            }

            else {
                return false;
            }
        }

        return num;
    }
};
