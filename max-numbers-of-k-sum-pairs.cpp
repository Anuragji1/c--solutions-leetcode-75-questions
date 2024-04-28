**Max Number of K-Sun Pairs**

Problem Statement 12) You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

----------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // Store frequency of each number
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;  // Find the complement to make a pair with sum k
            if (freq[complement] > 0) {  // If the complement exists, create a pair
                operations++;
                freq[complement]--;
            } else {
                freq[num]++;  // Otherwise, store the current number for potential future pairs
            }
        }

        return operations;
    }
};

----Explanation :- 
  Finding Maximum Pairs with Target Sum:

Frequency Map and Initialization:

The function takes a vector of integers nums and an integer target k as input.
It creates an unordered_map named freq to store the frequency of each number encountered in the nums vector. This map will help efficiently track how many times each number appears.
It initializes an integer variable operations (set to 0) to count the number of pairs formed so far.
Iterating Through Numbers:

It uses a for loop that iterates through each element (num) in the nums vector.
Finding Complement:

Inside the loop, it calculates the complement for the current number (num). The complement is the value needed to add up to the target k when paired with the current number (complement = k - num).
Checking for Complement:

It checks if the complement exists in the freq map and its frequency is greater than 0 (meaning there's at least one occurrence of the complement seen before).
If the complement exists with a positive frequency:
This indicates a potential pair can be formed using the current num and the complement.
It increments operations to count this pair.
It decrements the frequency of the complement in the freq map by 1 since one occurrence is used for this pair.
Storing Current Number:

If the complement is not found or its frequency is 0:
This means no pair can be formed with the current num yet.
The code stores the current num in the freq map by incrementing its frequency. This stores the num for potential future pairs if its complement is encountered later in the loop iterations.
Returning Maximum Pairs:

After iterating through all numbers in nums, the operations variable will hold the maximum number of pairs that can be formed where each pair adds up to the target k.
The function returns the operations value.
