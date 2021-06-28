class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> domains;
        for (auto& str: cpdomains) {
            int index = str.find(' ');
            int count = stoi(str.substr(0, index));
            string domain = str.substr(index + 1);

            while (index > 0) {
                domains[domain] += count;
                index = domain.find('.');
                domain = domain.substr(index + 1);
            }
        }

        for (auto& domain : domains) ans.push_back(to_string(domain.second) + " " + domain.first);
        return ans;
    }
};
