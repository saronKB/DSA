class Solution {
public:
    double search(unordered_map<string, unordered_map<string, double>>& net, string first, string last, unordered_set<string>& seen) {
        if (first == last) return 1.0;
        seen.insert(first);
        for (auto& pair : net[first]) {
            string nextNode = pair.first;
            double val = pair.second;
            if (seen.count(nextNode) == 0) {
                double ans = search(net, nextNode, last, seen);
                if (ans != -1.0) return val * ans;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& qs) {
        unordered_map<string, unordered_map<string, double>> net;
        for (int i = 0; i < eqs.size(); i++) {
            string x = eqs[i][0];
            string y = eqs[i][1];
            double num = vals[i];
            net[x][y] = num;
            net[y][x] = 1.0 / num;
        }
        
        vector<double> results;
        for (auto& q : qs) {
            string begin = q[0];
            string finish = q[1];
            unordered_set<string> seen;
            if (net.count(begin) == 0 || net.count(finish) == 0) {
                results.push_back(-1.0);
            } else {
                results.push_back(search(net, begin, finish, seen));
            }
        }
        return results;
    }
};