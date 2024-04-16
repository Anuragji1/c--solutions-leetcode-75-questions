**Greatest Common Divisor of Strings**

Problem Statement 2) For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

---------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if concatenated strings are equal or not, if not return ""
        if(str1 + str2 != str2 + str1)
            return "";
        // If strings are equal than return the substring from 0 to gcd of size(str1), size(str2)
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};

-----Explanation :- 
GCD Function (Implicit):

The code assumes a function gcd(a, b) exists to calculate the greatest common divisor of two integers a and b. This function is likely implemented elsewhere and not shown here.
Concatenation Check:

The function first checks if the concatenation of str1 and str2 is equal to the concatenation of str2 and str1 (str1 + str2 != str2 + str1). This check ensures a specific relationship between the strings for a valid GCD to exist in this context.
If the concatenation is not equal in both orders, it implies the strings cannot be formed by repeating a smaller common substring. In this case, the function returns an empty string ("").
GCD-Based Substring (Valid Case):

If the concatenation check passes, it indicates that str1 and str2 can be formed by repeating a smaller substring.
The function then calculates the GCD of the lengths of str1 and str2 using the gcd function. This GCD represents the length of the repeating substring that forms both strings.
It uses the substr(0, gcd) function to extract a substring from str1 starting from index 0 and having a length equal to the calculated GCD.
The rationale behind using str1 is that both strings share the common substring, and str1 can be used as a reference here.
Returning the GCD Substring:

If the concatenation check passes, the function returns the substring extracted from str1 using substr, which represents the GCD of the two strings under the given constraint.
Key Points:

This code defines the GCD of strings in a specific way where the concatenation order matters (str1 + str2 must equal str2 + str1).
It leverages the GCD of lengths to determine the length of the repeating substring.
The GCD substring is extracted from str1 assuming it shares the common substring with str2.
