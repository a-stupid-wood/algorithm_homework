//
//  main.cpp
//  HomeWork
//
//  Created by 王凯彬 on 2021/6/20.
//

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode result(0, l1);
        ListNode *pre = &result;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val >= l2->val) {
                ListNode *l2Next = l2->next;
                pre->next = l2;
                l2->next = l1;
                pre = l2;
                l2 = l2Next;
            }else {
                pre = l1;
                l1 = l1->next;
            }
        }
        if (l2 != nullptr) {
            pre->next = l2;
        }
        return result.next;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> digits = {1,2,3};
    ListNode l11(1);
    ListNode l12(2);
    ListNode l13(4);
    l11.next = &l12;
    l12.next = &l13;
    
    ListNode l21(1);
    ListNode l22(3);
    ListNode l23(4);
    l21.next = &l22;
    l22.next = &l23;
    
    Solution solution;
    solution.mergeTwoLists(&l11, &l21);
    
    return 0;
}

