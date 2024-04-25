**Move Zeroes**

Problem Statement 9) Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

----------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;

        for (int num : nums) {
            if (num != 0) {
                nums[writeIndex++] = num;  // Write non-zero elements to the beginning
            }
        }

        // Fill the remaining elements with 0
        fill(nums.begin() + writeIndex, nums.end(), 0);
    }
};

----Explanation :- 
  Moving Zeros to the End:

Write Index Initialization:

The function takes a vector of integers nums as input.
It initializes an integer variable writeIndex to 0. This variable will track the position where the next non-zero element should be written in the nums vector.
Iterating Through Numbers:

It uses a for loop that iterates through each element (num) in the nums vector using a range-based for loop.
Moving Non-Zero Elements:

Inside the loop, it checks if the current element (num) is not equal to 0.
If the element is non-zero:
It writes the current element (num) to the nums vector at the index pointed to by writeIndex.
It increments writeIndex to point to the next available position for the next non-zero element.
Filling with Zeros:

After the loop iterates through all elements, the non-zero elements will be written to the beginning of the nums vector up to the index writeIndex.
To move zeros to the end, the function utilizes the fill function from the <algorithm> header.
It calls fill(nums.begin() + writeIndex, nums.end(), 0). This fills the remaining elements in the nums vector starting from the position after writeIndex (where non-zero elements end) up to the end (nums.end()) with the value 0.
In-Place Modification:

It's important to note that this code modifies the original nums vector in-place. The non-zero elements are shifted to the beginning, and the remaining spaces are filled with zeros.
