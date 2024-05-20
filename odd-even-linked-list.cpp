**Odd Even Linked List**

pROBLEM sTATEMENT 29) Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106

----------------------------------------------------------------------------------------------------------------
solution = class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;  // Empty or single-node list
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Store the head of the even list

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;  // Connect odd and even lists
        return head;
    }
};

----Explanation:- Reordering Odd-Even Nodes in a Linked List:

Handling Empty or Single-Node List:

The function takes a pointer head to the head node of the linked list as input.
It first checks for edge cases:
If head is null (empty list) or head->next is null (single-node list), it means there's nothing to rearrange. The function simply returns the original head in this case.
Initializing Pointers:

If the list has more than one node, it initializes three pointers:
odd: A pointer that will traverse the linked list and point to the current odd node.
even: A pointer that will traverse the linked list and point to the current even node (always one node ahead of odd).
evenHead: A pointer that stores the head of the even nodes list. This is important for connecting the odd and even lists later. It's initialized to point to the second node (head->next) since that's the first even node.
Separating Odd and Even Nodes:

It uses a while loop that continues as long as even is not null and even->next is not null (to avoid going out of bounds).

Inside the loop:
It rearranges the linked list structure to separate odd and even nodes:
odd->next = even->next: This connects the odd node to the node after the current even node (effectively skipping the even node).
odd = odd->next: Moves the odd pointer to the next node (which should be odd based on the condition in the loop).
even->next = odd->next: This connects the current even node to the node after the next odd node (again, skipping an odd node).
even = even->next: Moves the even pointer to the next node (which should be even based on the loop condition).
By iteratively performing these steps, the loop essentially moves all even nodes together while maintaining the order of odd nodes and their connections.

Connecting Odd and Even Lists:

After the while loop, the odd pointer will be pointing to the last odd node, and even will be pointing to the first even node (or null if there are no more even nodes).
To create the final rearranged list, it connects the end of the odd list to the head of the even list:
odd->next = evenHead: This sets the next pointer of the last odd node to point to the head of the even list (evenHead).
Returning the Head:

The function returns the original head pointer. Even though the linked list structure is modified, the head pointer still points to the beginning of the rearranged list.
