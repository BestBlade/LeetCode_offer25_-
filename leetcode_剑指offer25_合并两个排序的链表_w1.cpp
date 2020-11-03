/* ------------------------------------------------------------------|
����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
ʾ�� 1:
����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ�� 2:
����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��: 0->1->2->NULL
������ת 4 ��: 2->0->1->NULL
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rotate-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*	
*
*	ִ����ʱ��40 ms, ������ C++ �ύ�л�����89.55%���û�
*	�ڴ����ģ�19.1 MB, ������ C++ �ύ�л�����42.44%���û�
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* node = new ListNode(0);
    ListNode* preHead = node;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            node->next = l1;
            l1 = l1->next;
        }
        else {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    node->next = l1 ? l1 : l2;
    return preHead->next;
}
