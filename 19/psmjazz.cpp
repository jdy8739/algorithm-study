// 시간복잡도: 리스트의 길이를 sz라 하면 리스트의 길이를 일단 재야 하므로 O(sz)
// 공간복잡도: 추가적인 메모리는 사용하지 않음 O(1)
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
