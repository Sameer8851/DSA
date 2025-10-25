class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            temp = temp->next;
        }
        while (list1 != NULL) {
            temp->next = new ListNode(list1->val);
            list1 = list1->next;
            temp = temp->next;
        }
        while (list2 != NULL) {
            temp->next = new ListNode(list2->val);
            list2 = list2->next;
            temp = temp->next;
        }
        newHead = newHead->next;
        return newHead;
    }
};