**Can Place Flowers**

Problem Statement 4) You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length


------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;  // Dummy value to handle the first plot

        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0 && (prev == -1 || prev == 0) && (i == m - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                count++;
                if (count >= n) {
                    return true;
                }
            }
            prev = flowerbed[i];
        }

        return count >= n;
    }
};

-----Explanation :-
Planting Flowers with Constraints:

Initialization:

The function takes a vector flowerbed where 0 represents an empty plot and 1 represents a flower and an integer n representing the number of flowers to plant.
It initializes a variable count to 0 to keep track of the number of flowers planted so far.
It gets the size of the flowerbed (m) from the size of the flowerbed vector.
It initializes a variable prev to -1, which acts as a dummy value to handle the first plot check in the loop (as there's no previous plot before the first element).
Iterating Through Flowerbed:

It uses a for loop to iterate through each plot (i) in the flowerbed vector.
Planting Conditions:

Inside the loop, it checks if a flower can be planted at the current plot using multiple conditions:

The current plot (flowerbed[i]) must be empty (equal to 0).
The previous plot (prev) must either be empty (0) or non-existent (-1 for the first plot). This ensures flowers are not planted next to each other.
The next plot (flowerbed[i + 1]) must either be the end of the flowerbed (i == m - 1) or empty (0) to avoid planting next to existing flowers.
If all these conditions are met, it indicates a valid location to plant a flower.

Planting and Counting:

If the planting conditions are satisfied:
The current plot is marked as occupied with a flower by setting flowerbed[i] to 1.
The count of planted flowers is incremented.
If the count becomes greater than or equal to n (all required flowers are planted), the function returns true indicating success.
Updating Previous Plot:

After checking for planting at the current plot, the prev variable is updated to the current plot value (flowerbed[i]) to be used for checking the next plot in the loop iteration.
Final Check:

After iterating through the entire flowerbed, the function checks if the final count of planted flowers (count >= n). If it is, it means all required flowers were planted, and the function returns true.
If the loop completes without planting enough flowers (count < n), the function returns false, indicating planting n flowers is not possible in the given flowerbed layout.
