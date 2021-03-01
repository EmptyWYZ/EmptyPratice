#include <iostream>
#include <vector>
#include <string>
using namespace std;
//单链表
struct ListNode{
    int val;//节点上存储的元素
    ListNode *next;//指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}//节点构造函数
};
class ListNode_Test
{
public:
    ListNode *removeElements(ListNode* head, int val){
        if(head->next == NULL) return NULL;
        ListNode* pre = new ListNode(-1);
        pre->next = head;//设置虚拟头节点
        ListNode* cur = pre;
        ListNode* del = NULL;
        while(cur->next != NULL){
            if(cur->next->val == val){
                del = cur->next;//记录需要删除的节点
                cur->next = cur->next->next;
                delete del;//清理无效节点内存
            }else{
                cur = cur->next;
            }
        }
        return pre->next;
    }
};

int main(){
    cout<<"Hello HuaWei Cloud!"<<endl;
    return 0;
}
