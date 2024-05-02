**Longest Subarray of 1`s After Deleting One Element**

Problem Statement 16) Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

-----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, prevMax = 0, currMax = 0, zeroCount = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;  // Count zeros
            }

            while (zeroCount > 1) {  // Shrink the window if there are more than one zero
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            currMax = right - left + 1;  // Update current maximum length
            prevMax = max(prevMax, currMax - 1);  // Consider deleting either the leftmost or rightmost 1
            right++;
        }

        return prevMax;  // Return the maximum length considering deletion
    }
};

----Explanation :-
Finding Subarray with Maximum Ones (At Most One Zero):

Initialization:

The function takes a vector of integers nums as input.
It initializes five integer variables:
left (set to 0) to keep track of the starting index of the current window.
right (set to 0) to keep track of the ending index of the current window (initially pointing to the first element).
prevMax (set to 0) to store the previous maximum length found (considering deletion of either the leftmost or rightmost 1).
currMax (set to 0) to store the current maximum length of the window.
zeroCount (set to 0) to count the number of zeros within the current window.
Sliding Window Loop:

It uses a while loop that continues as long as right is less than the size of the nums vector (right < nums.size()). This ensures the window stays within the vector's bounds as it slides.
Counting Zeros:

Inside the loop, it checks if the current element (nums[right]) is equal to 0.
If it's a zero, it increments the zeroCount to track the number of zeros within the current window.
Shrinking Window (if necessary):

It enters another while loop that continues as long as zeroCount is greater than 1. This loop handles the case where the current window has more than one zero, which violates the constraint.
Inside this inner loop, it shrinks the window from the left side until the number of zeros becomes at most 1.
It checks if the element at the left index is equal to 0.
If the element at left is a zero, it decrements the zeroCount counter to reflect the removal of a zero from the window.
It increments left to move the window one position to the right, effectively shrinking it.
Updating Maximum Lengths:

After potentially shrinking the window or adding a new element to the right, it calculates the current window length (right - left + 1) and stores it in currMax.
It updates the prevMax by comparing it with the current maximum length minus 1 (currMax - 1). This -1 accounts for the possibility that either the leftmost or rightmost element in the current window might be a 1 that needs to be deleted to achieve a subarray with at most one zero. The max function ensures prevMax always holds the larger of the two values (considering deletion).
Sliding the Window:

After checking for maximum lengths, it increments right by 1 to move the window one position to the right for the next iteration of the outer loop. This expands the window.
Returning Maximum Length (Considering Deletion):

After the outer loop completes, iterating through all possible windows, the prevMax variable will hold the maximum length of a subarray with at most one zero in the nums vector, considering the potential deletion of either the leftmost or rightmost 1 in the subarray. This addresses the constraint of having at most one zero.
The function returns the prevMax value as the result.
