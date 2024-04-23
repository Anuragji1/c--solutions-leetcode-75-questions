**Product of Array Except Self**

Problem Statement 7) Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

-----------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
   vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int> left(n), right(n), answer(n);

       // Left prefix products
       left[0] = 1;
       for (int i = 1; i < n; i++) {
           left[i] = left[i - 1] * nums[i - 1];
       }

       // Right suffix products
       right[n - 1] = 1;
       for (int i = n - 2; i >= 0; i--) {
           right[i] = right[i + 1] * nums[i + 1];
       }

       // Combine left and right products
       for (int i = 0; i < n; i++) {
           answer[i] = left[i] * right[i];
       }

       return answer;
   }
};

----Explanation :- 
Product of All Elements Except Self:

Initialization:

The function takes a vector of integers nums as input.
It gets the size of the vector (n) for loop iterations.
It creates three vectors of integers:
left (size n) to store the product of all elements to the left of each index (excluding the element itself).
right (size n) to store the product of all elements to the right of each index (excluding the element itself).
answer (size n) to store the final result, which will be the product of left and right elements for each index.
Left Prefix Products:

It initializes left[0] to 1 because there's no element to the left of the first element, so its product is simply 1.
It uses a for loop iterating from the second element (i = 1) to the last element (i < n).
Inside the loop, for each index i, it calculates the product of the previous element (nums[i - 1]) and the corresponding value in left from the previous iteration (left[i - 1]). This represents the cumulative product of elements to the left of the current index.
The calculated product is stored in left[i].
Right Suffix Products:

It initializes right[n - 1] to 1 because there's no element to the right of the last element, so its product is simply 1.
It uses a for loop iterating from the second last element (i = n - 2) to the first element (i >= 0). Notice it iterates backward compared to the left product calculation.
Inside the loop, for each index i, it calculates the product of the next element (nums[i + 1]) and the corresponding value in right from the previous iteration (right[i + 1]). This represents the cumulative product of elements to the right of the current index.
The calculated product is stored in right[i].
Combining Left and Right Products:

After calculating both left and right products, it uses another for loop iterating through all elements (i = 0 to i < n).
Inside the loop, for each index i, it multiplies the corresponding elements from left and right (left[i] * right[i]) and stores the result in answer[i]. This product represents all elements except the current element at index i.
Returning Result:

After iterating through all elements, the answer vector will contain the product of all elements except the element at each index in the original nums vector.
The function returns the answer vector.
