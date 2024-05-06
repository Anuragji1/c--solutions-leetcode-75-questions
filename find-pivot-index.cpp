Problem Statement 18) Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:

There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000

------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;  // Calculate the total sum of all elements
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - nums[i] - leftSum) {
                return i;  // Found the pivot index
            }
            leftSum += nums[i];  // Accumulate the left sum
        }

        return -1;  // No pivot index found
    }
};

----Explanation:- 
Finding the Pivot Index for Equal Sums:

Calculating Total Sum:

The function takes a vector of integers nums as input.
It initializes an integer variable totalSum (set to 0).
It iterates through the nums vector using a for loop, adding each element (num) to the totalSum. This loop calculates the sum of all elements in the vector.
Initializing Left Sum:

It initializes another integer variable leftSum (set to 0) to store the cumulative sum of elements on the left side of the potential pivot index.
Iterating Through Elements:

It uses another for loop that iterates through each index i in the nums vector.
Checking for Pivot Index:

Inside the loop, it checks if the current leftSum is equal to the difference between the totalSum and the current element (nums[i]) minus the leftSum itself. This can be simplified as leftSum == totalSum - nums[i] - leftSum.
If this condition is true, it means the element at index i acts as a pivot because the sum of elements to its left (leftSum) is equal to the sum of elements to its right (totalSum - nums[i] - leftSum).
If the condition is true, the function returns the current index i as the pivot index.
Accumulating Left Sum:

If the condition for the pivot index is not met, the loop continues iterating. Inside the loop, it adds the current element (nums[i]) to the leftSum to prepare for the calculation of the next left sum for the next iteration.
Not Found Case:

If the loop completes iterating through all elements without finding a pivot index (no condition for leftSum equality is met), the function returns -1 to indicate that no such pivot index exists in the nums vector.
