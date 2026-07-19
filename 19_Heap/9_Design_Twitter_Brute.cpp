#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
  int count;
  priority_queue<vector<int>> timelineMaxHeap;
  unordered_map<int, unordered_set<int>> followMap;

public:
  Twitter() { count = 0; }

  void postTweet(int userId, int tweetId) {
    // T = total tweets
    //  TC O(log T)
    timelineMaxHeap.push({count, tweetId, userId});
    count += 1;
  }

  vector<int> getNewsFeed(int userId) {
    // TC O(T log T)
    vector<int> ans;
    priority_queue<vector<int>> userTimeline = timelineMaxHeap;

    // const int TIME = 0;
    const int TWEET = 1;
    const int USER = 2;
    while (!userTimeline.empty() && ans.size() < 10) {
      auto topTweet = userTimeline.top();
      userTimeline.pop();
      if (topTweet[USER] == userId || followMap[userId].count(topTweet[USER])) {
        ans.push_back(topTweet[TWEET]);
      }
    }
    return ans;
  }

  void follow(int followerId, int followeeId) {
    // TC O(1)
    followMap[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    // TC O(1)
    followMap[followerId].erase(followeeId);
  }
};

int main() {
  cout << "9 Design Twitter BRUTE" << endl;
  //   Design a simplified version of Twitter where users can post tweets,
  //   follow/unfollow another user, and is able to see the 10 most recent
  //   tweets in the user's news feed.

  // Implement the Twitter class:

  // Twitter() Initializes your twitter object.
  // void postTweet(int userId, int tweetId) Composes a new tweet with ID
  // tweetId by the user userId. Each call to this function will be made with a
  // unique tweetId. List<Integer> getNewsFeed(int userId) Retrieves the 10 most
  // recent tweet IDs in the user's news feed. Each item in the news feed must
  // be posted by users who the user followed or by the user themself. Tweets
  // must be ordered from most recent to least recent. void follow(int
  // followerId, int followeeId) The user with ID followerId started following
  // the user with ID followeeId. void unfollow(int followerId, int followeeId)
  // The user with ID followerId started unfollowing the user with ID
  // followeeId.

  //   Input
  // ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
  // "getNewsFeed", "unfollow", "getNewsFeed"]
  // [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
  // Output
  // [null, null, [5], null, null, [6, 5], null, [5]]

  // Explanation
  // Twitter twitter = new Twitter();
  // twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
  // twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
  // tweet id -> [5]. return [5] twitter.follow(1, 2);    // User 1 follows
  // user 2. twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
  // twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2
  // tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is
  // posted after tweet id 5. twitter.unfollow(1, 2);  // User 1 unfollows
  // user 2. twitter.getNewsFeed(1);  // User 1's news feed should return a list
  // with 1 tweet id -> [5], since user 1 is no longer following user 2.

  Twitter twitter;

  cout << "Design Twitter Test" << endl;

  // User 1 posts tweet 5
  twitter.postTweet(1, 5);

  vector<int> feed1 = twitter.getNewsFeed(1);
  cout << "Feed of User 1: ";
  for (int x : feed1) {
    cout << x << " ";
  }
  cout << endl;

  // User 1 follows User 2
  twitter.follow(1, 2);

  // User 2 posts tweet 6
  twitter.postTweet(2, 6);

  vector<int> feed2 = twitter.getNewsFeed(1);
  cout << "Feed of User 1 after following User 2: ";
  for (int x : feed2) {
    cout << x << " ";
  }
  cout << endl;

  // User 1 unfollows User 2
  twitter.unfollow(1, 2);

  vector<int> feed3 = twitter.getNewsFeed(1);
  cout << "Feed of User 1 after unfollowing User 2: ";
  for (int x : feed3) {
    cout << x << " ";
  }
  cout << endl;

  // Additional Test
  Twitter twitter2;

  twitter2.postTweet(1, 10);
  twitter2.postTweet(1, 11);
  twitter2.postTweet(1, 12);

  twitter2.follow(2, 1);

  vector<int> feed4 = twitter2.getNewsFeed(2);

  cout << "Feed of User 2 following User 1: ";
  for (int x : feed4) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}

// | Function    | Time           | Space |
// | ----------- | -------------- | ----- |
// | Constructor | O(1)           | O(1)  |
// | postTweet   | O(log T)       | O(1)  |
// | getNewsFeed | O(T log T)     | O(T)  |
// | follow      | O(1) avg       | O(1)  |
// | unfollow    | O(1) avg       | O(1)  |
