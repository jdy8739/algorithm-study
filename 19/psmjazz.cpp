/**
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* current = head;
        do
        {
            current = current->next;
            size++;
        }
        while(current !=nullptr);
        int nFromStart = size - n;

        if(nFromStart == 0)
        {
            head = head->next;
            return head;
        }

        current = head;
        for(int index = 0; index < nFromStart - 1; index++)
        {
            current = current->next;
        }
        ListNode* newNext = current->next->next;
        current->next = newNext;
        return head;
    }
};
