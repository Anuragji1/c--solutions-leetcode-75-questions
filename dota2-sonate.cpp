**Dota2 Senate**

Problem Statement 27) In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

 

Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
 

Constraints:

n == senate.length
1 <= n <= 104
senate[i] is either 'R' or 'D'.

---------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();
            if (r < d) {
                radiant.push(r + senate.size());
            } else {
                dire.push(d + senate.size());
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};

-------Explanation :-
Simulating Battle and Predicting Winner:

Senators and Queues:

The function takes a string senate as input, where each character represents a senator ('R' for Radiant, 'D' for Dire).
It initializes two queues:
radiant: A queue to store indices of Radiant senators.
dire: A queue to store indices of Dire senators.
It iterates through the senate string using a for loop.
Inside the loop, it checks if the current character is 'R' (Radiant senator).
If it's 'R', it pushes the current index (i) into the radiant queue. This stores the position of the Radiant senator.
If the current character is 'D' (Dire senator), it pushes the current index (i) into the dire queue.
Simulated Battle:

It uses a while loop that continues as long as both radiant and dire queues are not empty (both parties have senators left).
Inside the loop, it simulates a battle round:
It retrieves the index of the first senator from each queue:
r = radiant.front(): Index of the first Radiant senator (popped from the queue).
d = dire.front(): Index of the first Dire senator (popped from the queue).
It compares the indices (r and d) to determine the winner of the round.
If r < d (Radiant senator's index is smaller), it means the Radiant senator eliminates the Dire senator first. In this case, the Radiant senator survives and is added back to the radiant queue, but its index is incremented by the length of the senate string (r + senate.size()). This simulates the Radiant senator moving to the back of the line (since the string is circular) and potentially facing another senator later.
If d < r (Dire senator's index is smaller), it means the Dire senator eliminates the Radiant senator first. Similar to the previous case, the Dire senator survives and is added back to the dire queue with an incremented index (d + senate.size()).
Determining Winner:

The while loop continues until one of the queues becomes empty (all senators of that party are eliminated).
After the loop exits, it checks if the radiant queue is empty.
If radiant is empty, it means all Radiant senators were eliminated, so the function returns "Dire" as the winner.
If radiant is not empty, it means the Radiant party still has senators remaining, so the function returns "Radiant" as the winner.
