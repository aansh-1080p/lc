class Twitter {
public:
    int time = 0;

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;
        vector<int> feed;

        vector<int> itlist;
        itlist.push_back(userId);

        for(const auto& fid : followers[userId]) {
            itlist.push_back(fid);
        }

        for(int i = 0; i < itlist.size(); i++) {

            auto it = tweets.find(itlist[i]);

            if(it != tweets.end()) {

                const auto& ttweets = it->second;

                int count = 0;

                for(int j = ttweets.size() - 1;
                    j >= 0 && count < 10;
                    j--) {

                    pq.push(ttweets[j]);
                    count++;
                }
            }
        }

        int i = 0;
        int s = pq.size();

        while(i < 10 && i < s) {
            feed.push_back(pq.top().second);
            pq.pop();
            i++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */