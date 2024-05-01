**Max Consecutive Ones III**

Problem Statement 15) Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

------------------------------------------------------------------------------------------
SOLUTION :- 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeros = 0, maxLength = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {  // Count zeros within the window
                zeros++;
            }

            while (zeros > k) {  // Shrink the window if zeros exceed k
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);  // Update the maximum length
            right++;
        }

        return maxLength;
    }
};

----Explanation:-
Initialization:

The function takes a vector of integers nums and an integer k (maximum allowed zeros) as input.
It initializes four integer variables:
left (set to 0) to keep track of the starting index of the current window.
right (set to 0) to keep track of the ending index of the current window (initially pointing to the first element).
zeros (set to 0) to count the number of zeros within the current window.
maxLength (set to 0) to store the maximum length of a subarray with at most k zeros found so far.
Sliding Window Loop:

It uses a while loop that continues as long as right is less than the size of the nums vector (right < nums.size()). This ensures the window stays within the vector's bounds as it slides.
Counting Zeros:

Inside the loop, it checks if the current element (nums[right]) is equal to 0.
If it's a zero, it increments the zeros counter to track the number of zeros within the current window.
Shrinking Window (if necessary):

It enters another while loop that continues as long as zeros is greater than k. This loop handles the case where the current window has more zeros than allowed (k).
Inside this inner loop, it shrinks the window from the left side until the number of zeros becomes at most k.
It checks if the element at the left index is equal to 0.
If the element at left is a zero, it decrements the zeros counter to reflect the removal of a zero from the window.
It increments left to move the window one position to the right, effectively shrinking it.
Updating Maximum Length:

After potentially shrinking the window or adding a new element to the right, it checks if the current window length (right - left + 1) is greater than the maxLength.
If the current window length is larger, it updates the maxLength to store the new maximum length of a subarray with at most k zeros found so far.
Sliding the Window:

After checking for maximum length, it increments right by 1 to move the window one position to the right for the next iteration of the outer loop. This expands the window.
Returning Maximum Length:

After the outer loop completes, iterating through all possible windows, the maxLength variable will hold the maximum length of a subarray with at most k zeros in the nums vector.
The function returns the maxLength value as the result.
