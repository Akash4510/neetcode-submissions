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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while (curr != nullptr) {
            ListNode* temp = curr;
            bool f = false;

            if (temp->val == val) {
                prev->next = temp->next;
                f = true;
            } else {
                prev = curr;
            }

            curr = curr->next;

            if (f) delete temp;
        }

        return head;
    }
};