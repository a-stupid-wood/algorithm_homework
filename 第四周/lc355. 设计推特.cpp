struct User {
    unordered_set<int> followeeSet;
    deque<pair<int, int>> tweets;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        maxSize = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        User &user = id2User[userId];
        if (user.tweets.size() >= maxSize) {
            user.tweets.pop_back();
        }
        user.tweets.emplace_front(++time, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.first > b.first;
        };
        // 小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        vector<int> res;
        //先插入自己
        User &user = id2User[userId];
        for (pair<int, int> tweet : user.tweets) {
            cout << tweet.first << " " << tweet.second << " " << user.tweets.size() << endl;
            q.push(tweet);
        }
        //接着插入所有followee 的 tweettweet
        for (int followeeId : user.followeeSet) {
            for (pair<int, int> tweet : id2User[followeeId].tweets) {
                cout << "other " << tweet.first << " " << tweet.second << " " << id2User[followeeId].tweets.size() << endl;
                if (q.size() >= maxSize) {
                    if (tweet.first > q.top().first) {
                        q.pop();
                        q.push(tweet);
                    }
                }else {
                    q.push(tweet);
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        User &followerUser = id2User[followerId];
        followerUser.followeeSet.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        User &followerUser = id2User[followerId];
        followerUser.followeeSet.erase(followeeId);
    }

private:
    unordered_map<int, User> id2User;
    int time;
    int maxSize;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
