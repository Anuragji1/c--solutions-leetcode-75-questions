**Asteroid Collision**

Problem Statement 24) We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

----------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int asteroid : asteroids) {
            // Keep adding right-moving asteroids to the result
            if (asteroid > 0) {
                result.push_back(asteroid);
            } else {
                // Left-moving asteroid, handle collisions
                while (!result.empty() && result.back() > 0 && result.back() < -asteroid) {
                    result.pop_back();  // Right-moving asteroid destroyed
                }

                if (!result.empty() && result.back() == -asteroid) {
                    result.pop_back();  // Both asteroids destroyed
                } else if (result.empty() || result.back() < 0) {
                    result.push_back(asteroid);  // Left-moving asteroid survives
                }
            }
        }
        return result;
    }
};

----Explanation:-
Simulating Asteroid Collisions:

Resulting Asteroids:

The function takes a vector of integers asteroids as input, where each element represents an asteroid's mass (positive for right-moving, negative for left-moving).
It initializes an empty vector result to store the asteroids that survive collisions.
Iterating Through Asteroids:

It uses a for loop to iterate through each asteroid (asteroid) in the input vector.
Right-Moving Asteroids:

If the current asteroid's mass is positive (asteroid > 0), it means it's moving right. In this case, it's assumed to survive any previous collisions and is directly added to the result vector using push_back.
Left-Moving Asteroids and Collisions:

If the current asteroid's mass is negative (else case), it means it's moving left. This triggers collision handling:
It uses a while loop that continues as long as three conditions are met:
!result.empty(): The result vector is not empty (ensures there are asteroids to compare with).
result.back() > 0: The last asteroid in result is moving right (potential collision).
result.back() < -asteroid: The right-moving asteroid's mass (absolute value) is smaller than the left-moving asteroid's mass (absolute value). This condition ensures a collision where the left-moving asteroid destroys the right-moving one.
Inside the while loop, it removes the last asteroid from result using pop_back. This simulates the right-moving asteroid being destroyed in the collision.
Further Left-Moving Asteroid Handling:

After the while loop (collision handling), there are three additional cases to consider for the left-moving asteroid:
!result.empty() && result.back() == -asteroid: If result is not empty and the last asteroid has the same mass (absolute value) as the current left-moving asteroid, it means they both get destroyed in a head-on collision. In this case, both are removed from result using pop_back.
result.empty() || result.back() < 0: If result is empty or the last asteroid in result is also moving left (result.back() < 0), it means the left-moving asteroid survives the collisions encountered so far. In this case, it's added to result using push_back.
Returning the Result:

After iterating through all asteroids, the result vector will contain the asteroids that survived collisions based on their mass and direction.
The function returns the result vector as the final outcome of the asteroid collisions.
