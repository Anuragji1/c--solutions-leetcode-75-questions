**Maximum Average Subarray 1**

Problem Statement 13) You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

-------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return static_cast<double>(nums[0]);
        }
        
        int start = 0;
        int end = k;
        double average = 0.0;
        
        // Calculate the average of the first window
        for (int i = 0; i < k; i++) {
            average += static_cast<double>(nums[i]) / k;
        }
        
        // Initialize the maximum average
        double max_average = average;
        
        // Slide the window and update the maximum average
        while (end < nums.size()) {
            average = average - static_cast<double>(nums[start]) / k;
            average = average + static_cast<double>(nums[end]) / k;
            max_average = max(max_average, average);
            start++;
            end++;
        }
        
        return max_average;
    }
};
----Explanation :- 
Finding Maximum Subarray Average:

Handling Edge Case:

The function first checks for an edge case where the size of the input vector nums is 1. In this case, the entire vector itself is the only possible subarray, so it simply returns the first element (cast to double) as the average.
Initialization:

It initializes two integer variables:
start (set to 0) to keep track of the starting index of the current window.
end (set to k) to keep track of the ending index of the current window (considering the window size is k).
It initializes a double variable average (set to 0.0) to store the current window's average.
It calculates the initial average for the first window of size k. It iterates from index 0 to k-1 (exclusive) and adds each element to the average variable. Then it divides the total by k to get the average and stores it in the average variable.
Maximum Average Initialization:

It initializes another double variable max_average (set to average) to store the maximum average found so far. This variable will be updated if a larger average is encountered during the window sliding process.
Sliding Window Loop:

It uses a while loop that continues as long as end is less than the size of the nums vector (end < nums.size()). This ensures the window stays within the vector's bounds as it slides.
Updating Window Average:

Inside the loop, it performs two key operations to update the average as the window slides:
It subtracts the element at the start index (which is about to move out of the window) from the average. This is because this element will no longer be part of the average calculation in the next iteration. It divides by k to account for the change in window size relative to the average.
It adds the element at the end index (which is about to be included in the window) to the average. This is because this element will now be part of the average calculation in the next iteration. It again divides by k to incorporate the new element into the average.
Updating Maximum Average:

After updating the window average, it compares the current average with the max_average. If the current average is larger, it updates max_average to store the new maximum average found so far.
Sliding the Window:

After updating the averages, it increments both start and end by 1. This effectively slides the window one position to the right for the next iteration of the loop.
Returning Maximum Average:

After the loop completes, iterating through all possible windows of size k, the max_average variable will hold the maximum average of any subarray with length k in the nums vector.
The function returns the max_average as the result.
