**Kids With the Greatest Number of Candies**

Problem Statement 3) There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 

Constraints:

n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50

----------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>answer;
        int max_value = 0;
        for (int i = 0; i < candies.size(); i++){
            if (max_value <= candies.at(i)){max_value = candies.at(i);}
        }

        for (int i = 0; i < candies.size(); i++){
            if (candies.at(i) + extraCandies >= max_value){answer.push_back(true);}
            else {answer.push_back(false);}
        }
        return answer;
    }
};

----Explanation :-
Initialization:

The function takes a vector of integers candies representing the initial number of candies each child has and an integer extraCandies representing the extra candies to be distributed.
It creates an empty vector of booleans named answer to store the results (True if a child has enough candies after distribution, False otherwise).
It initializes a variable max_value to 0 to keep track of the maximum number of candies any child has initially.
Finding Maximum Candies:

It uses a for loop to iterate through the candies vector.
Inside the loop:
It checks if the current candy count (candies.at(i)) is greater than or equal to the current max_value.
If it is, it updates max_value to the current candy count, ensuring it holds the maximum value encountered so far.
Checking with Extra Candies:

After finding the maximum initial candy count, it uses another for loop to iterate through the candies vector again.
Inside the loop:
It checks if the sum of the current child's candies (candies.at(i)) and the extra candies (extraCandies) is greater than or equal to the max_value found previously.
If the sum is greater than or equal to max_value, it means the child will have enough candies to be considered as having the most even after distribution. The corresponding element in the answer vector is set to True using push_back(true).
If the sum is less than max_value, the child won't have enough candies to be considered as having the most. The corresponding element in the answer vector is set to False using push_back(false).
Returning Results:

After iterating through all children, the answer vector will contain boolean values for each child, indicating whether they have enough candies to be considered as having the most after the extra candies are distributed.
The function returns the answer vector.
