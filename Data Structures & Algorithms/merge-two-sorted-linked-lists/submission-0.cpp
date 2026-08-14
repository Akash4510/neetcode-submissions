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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            ListNode** toSwap = list1->val <= list2->val ? &list1 : &list2;
            curr->next = *toSwap;
            *toSwap = (*toSwap)->next;
            curr = curr->next;
        }

        curr->next = list1 != nullptr ? list1 : list2;

        return dummy.next;
    }
};
