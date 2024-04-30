**Maximum Number of Vowels in a Substring of Given length**

Problem Statement 14) Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length

----------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maxVowels(string s, int k) {
        int res=0;
        map<char,int> mp;
        for(int i=0;i<k;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                mp[s[i]]++;
            }
        }
        res=max(res,mp['a']+mp['e']+mp['i']+mp['o']+mp['u']);
        int j=0;
        for(int i=k;i<(int)s.size();i++){
            mp[s[j]]--;
            mp[s[j]]=max(0,mp[s[j]]);
            mp[s[i]]++;
            res=max(res,mp['a']+mp['e']+mp['i']+mp['o']+mp['u']);
            j++;
        }
        return res;
    }
};

----Explanation:- 
