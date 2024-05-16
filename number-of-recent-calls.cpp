**Number of Recent Calls**

Problem Statement 26) You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

 

Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
 

Constraints:

1 <= t <= 109
Each test case will call ping with strictly increasing values of t.
At most 104 calls will be made to ping.

---------------------------------------------------------------------------------------------------------------
SOLUTION = class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

----Explanation:-
Tracking Recent Pings:

Queue for Timestamps:

The class defines a member variable q as a queue of integers. This queue will store the timestamps of received pings.
ping(t) Method:

The ping(t) method takes an integer t as input, representing the timestamp of a new ping received.
Adding Ping Timestamp:

It pushes the current timestamp t onto the back of the queue (q.push(t)) to record the ping.
Maintaining Recent Window (3000 milliseconds):

It uses a while loop to maintain a window of the last 3000 milliseconds of pings in the queue.
Inside the loop, it checks the condition q.front() < t - 3000. This checks if the timestamp at the front of the queue (q.front()) is older than 3000 milliseconds compared to the current timestamp t.
If the condition is true, it means the front element in the queue is outside the recent window (older than 3 seconds). In this case, it removes the outdated element from the queue using q.pop().
This loop ensures that the queue only contains timestamps of pings received within the last 3 seconds.
Returning Count of Recent Pings:

After potentially removing outdated pings from the queue, the size of the queue (q.size()) represents the number of pings received within the last 3000 milliseconds. This value is returned by the ping method.
