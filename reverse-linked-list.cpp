**Reverse Linked List**

PROBLEM STATEMENT 30) Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;
        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

----Explanation:-
Reversing a Singly Linked List:

Iterative Reversal with Three Pointers:

The function takes a pointer head to the head node of the linked list as input.
It initializes three pointers:
prev: A pointer that will traverse the list in the reversed direction, starting from null (since there's no previous node before the head in a reversed list).
curr: A pointer that will traverse the original list from the head (head).
nextNode: A temporary pointer to store the next node in the original list.
Reversing Links:

It uses a while loop that continues as long as curr is not null (i.e., it hasn't reached the end of the list).
Inside the loop, it performs the following steps to reverse the links:
nextNode = curr->next: This stores the next node in the original list (curr->next) in the nextNode pointer.
curr->next = prev: This reverses the link of the current node (curr). Instead of pointing to the next node in the original list, it now points to the previous node (prev) in the reversed list.
prev = curr: Moves the prev pointer one step forward in the reversed direction, pointing it to the current node (curr).
curr = nextNode: Moves the curr pointer one step forward in the original list, pointing it to the next node (nextNode) that was stored earlier.
Returning the Reversed List:

After the loop completes, the prev pointer will be pointing to the new last node (which was the original head) of the reversed list.
The function returns prev as it now represents the head of the reversed linked list.
