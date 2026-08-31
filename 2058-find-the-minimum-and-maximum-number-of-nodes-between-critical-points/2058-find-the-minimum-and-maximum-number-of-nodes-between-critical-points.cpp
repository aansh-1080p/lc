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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1);
        if(head->next==NULL || head->next->next==NULL) return ans;
        vector<int>points;
        ListNode* temp = head->next;
        int prev = head->val;
        int cnt = 1;
        while(temp->next!=NULL)
        {
            if(temp->val > temp->next->val && temp->val > prev) points.push_back(cnt);
            else if(temp->val < temp->next->val && temp->val < prev) points.push_back(cnt);
            cnt++;
            prev = temp->val;
            temp = temp->next;
        }
        if(points.size()==0 || points.size()==1) return ans;
        int n = points.size();
        ans[1] = points[n-1] - points[0];
        int mini = INT_MAX;
        for(int i=1;i<n;i++)
        {
            mini=min(mini,points[i]-points[i-1]);
        }
        ans[0] = mini;
        return ans;
    }
};