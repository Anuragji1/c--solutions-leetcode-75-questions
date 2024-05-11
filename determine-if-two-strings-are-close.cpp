**Determine if Two Strings Are Close**

Problem Statement 21) Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.

------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool closeStrings(string word1, string word2)
    { 
        map<char,int> m1;
        map<char,int> m2;
        if(word1.size()!=word2.size()) return false;

        for(int i=0;i<word1.size();i++)
        {
            m1[word1[i]]++;
        }
        
        for(int i=0;i<word2.size();i++)
        {
            m2[word2[i]]++;
        }
        for(int i=0;i<word1.size();i++)
        {
            if(m2[word1[i]]==0)
            {
                return false;
            }
        }
        for(int i=0;i<word2.size();i++)
        {
            if(m1[word2[i]]==0)
            {
                return false;
            }
        }

        vector<int> v1;
        vector<int> v2;
        
        for(auto i : m1)
        {
            v1.push_back(i.second);
        }
      
        
        for(auto i : m2)
        {
            v2.push_back(i.second);
        }
        sort(v1.begin(),v1.end());
        
        sort(v2.begin(),v2.end());

        if(v1==v2) return true;
        else return false;

    }
};

----Explanation :-
Two strings are considered close if they have the following properties:

Same Length: The strings must have the same length.
Same Character Set: Both strings must contain the same set of characters (unique characters can appear with different frequencies).
Matching Frequencies: The frequency of each character (number of times it appears) should be the same in both strings.
Here's a breakdown of how the code works:

Checking for Closeness:

Length Check:

The function takes two strings word1 and word2 as input.
It first checks if the lengths of word1 and word2 are equal (word1.size() != word2.size()).
If the lengths are not equal, the strings cannot be close and the function returns false.
Character Count Maps:

It creates two map objects: m1 for word1 and m2 for word2. These maps will store the character (key) and its frequency (count) in each string.
It iterates through word1 and word2 using separate loops.
Inside each loop, for each character encountered (word1[i] or word2[i]), it increments the corresponding count in the respective map (m1 or m2). This builds a frequency map for each string, where the key is the character and the value is the number of times it appears.
Character Existence Check:

It iterates through word1 again using a loop.
Inside the loop, it checks if the character from word1 exists in the m2 map (m2[word1[i]] == 0).
If a character from word1 does not exist in word2 (count in m2 is zero), the strings cannot be close and the function returns false. This ensures both strings share the same set of characters.
It performs a similar check by iterating through word2 and verifying if each character exists in word1.
Frequency Comparison (Preparation):

It creates two empty vectors: v1 and v2. These vectors will be used to store the frequencies (counts) of characters from m1 and m2, respectively.
It iterates through both m1 and m2 maps using range-based for loops.
Inside each loop, it pushes the frequency (count) value (i.second) from the current map entry (i) into the corresponding vector (v1 for m1 and v2 for m2). This effectively extracts the frequencies from the maps and stores them in separate vectors.
Frequency Comparison (Sorting):

It sorts both v1 and v2 vectors using the sort function. This ensures that the order of frequencies doesn't affect the comparison.
Frequency Comparison (Matching):

It checks if the sorted vectors v1 and v2 are equal using the comparison operator (v1 == v2).
If the sorted vectors are equal, it means the frequencies of each character match in both strings. In this case, the function returns true to indicate that the strings are close.
If the vectors are not equal, the frequencies don't match, and the function returns false.
