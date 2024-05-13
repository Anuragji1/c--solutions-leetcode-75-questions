**Removing Stars From a String**

Problem Statement 23) You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s.

------------------------------------------------------------------------------------------
SOLUTION :- 
class Solution {
public:
    string removeStars(string s) {
        string c="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                c.pop_back();
            }else{
                c+=s[i];
            }
            
        }
        return c;
    }
};

----Explanation:- 
Removing Stars from String:

Iterating Through Characters:

The function takes a string s as input, containing characters and potentially stars.
It initializes an empty string c which will hold the result without stars.
It uses a for loop to iterate over each character (s[i]) in the input string s.
Handling Stars and Other Characters:

Inside the loop, it checks if the current character is a star (s[i] == '*).
If it's a star, it assumes the previous character in the result string (c) was added due to a non-star character encountered earlier. Since stars remove the previous character, it removes the last character from c using c.pop_back(). This effectively simulates the behavior of a stack, where stars pop the previous character from the result string.
If the current character is not a star (else case), it means it's a valid character to keep. In this case, it appends the current character (s[i]) to the result string c using the += operator.
Returning the Result:

After iterating through all characters in the input string, the c string will contain only the characters that were not removed by stars.
The function returns the c string as the result, representing the input string with stars removed.
