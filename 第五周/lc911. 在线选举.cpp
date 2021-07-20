class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int, int> voteCount;
        datas.resize(persons.size(), 0);
        indexs.resize(persons.size(), 0);
        int cur = 0, curval = 0;
        for (int i = 0; i < persons.size(); ++i) {
            indexs[i] = times[i];
            voteCount[persons[i]]++;
            if (voteCount[persons[i]] >= cur) {
                cur = voteCount[persons[i]];
                datas[i] = persons[i];
                curval = persons[i];
            }else {
                datas[i] = curval;
            }
        }
    }

    int q(int t) {
        int left = 0, right = indexs.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (indexs[mid] > t) right = mid;
            else left = mid + 1;
        }
        return datas[left - 1];
    }

private:
    vector<int> datas;
    vector<int> indexs;
};