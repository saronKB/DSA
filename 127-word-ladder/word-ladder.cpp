class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> st;
        for (auto str : wordList)
            st.insert(str);
        q.push({beginWord, 1});
        st.erase(beginWord);
        while (!q.empty()) {
            auto frontNode = q.front();
            string frontStr = frontNode.first;
            int dist = frontNode.second;
            q.pop();
            if (frontStr == endWord)
                return dist;
            else {
                for (int i = 0; i < frontStr.size(); i++) {
                    char currChar = frontStr[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        frontStr[i] = ch;
                        if (st.find(frontStr) != st.end()) {
                            st.erase(frontStr);
                            q.push({frontStr, dist + 1});
                        }
                    }
                    frontStr[i] = currChar;
                }
            }
        }
        return 0;
    }
};
