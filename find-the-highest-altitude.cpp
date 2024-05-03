**Find the Highest Altitude**

Problem Statement 17) There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
 

Constraints:

n == gain.length
1 <= n <= 100
-100 <= gain[i] <= 100

----------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0, highestAltitude = 0;

        for (int altitudeChange : gain) {
            currentAltitude += altitudeChange;  // Update current altitude
            highestAltitude = max(highestAltitude, currentAltitude);  // Track highest altitude
        }

        return highestAltitude;
    }
};

----Explanation :-
Finding Maximum Altitude:

Initialization:

The function takes a vector of integers gain as input, where each element represents the change in altitude for a specific point.
It initializes two integer variables:
currentAltitude (set to 0) to store the current altitude at any point in the iteration.
highestAltitude (set to 0) to keep track of the maximum altitude reached so far.
Iterating Through Altitude Changes:

It uses a for loop that iterates through each element (altitudeChange) in the gain vector. This element represents the change in altitude for a specific point in the climb.
Updating Current Altitude:

Inside the loop, it adds the current altitudeChange to the currentAltitude. This effectively calculates the new altitude reached after the change at the current point.
Tracking Highest Altitude:

After updating the current altitude, it compares the current altitude (currentAltitude) with the highestAltitude using the max function.
If the current altitude is greater than the highestAltitude, it updates the highestAltitude to store the new maximum altitude reached so far. This ensures highestAltitude always holds the largest value encountered during the iteration.
Returning Maximum Altitude:

After iterating through all altitude changes in the gain vector, the highestAltitude variable will hold the maximum altitude reached during the entire climb.
The function returns the highestAltitude as the result.
