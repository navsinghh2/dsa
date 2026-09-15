class Solution {
public:
    int maxPalindromes(string s, int k) {

        int count = 0;
        int prevEnd = -1;

        for(int i = 0; i + k <= s.length(); i++) {
            string sub = s.substr(i, k);
            string rev = sub;
            reverse(rev.begin(), rev.end());
            if(sub == rev && i > prevEnd) {
                count++;
                prevEnd = i + k - 1;
            }
            if(i + k + 1 <= s.length()) {
                string sub2 = s.substr(i, k + 1);
                string rev2 = sub2;
                reverse(rev2.begin(), rev2.end());
                if(sub2 == rev2 && i > prevEnd) {
                    count++;
                    prevEnd = i + k;
                }
            }
        }

        return count;
    }
};