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
class MyLinkedList{
    public:
        MyLinkedList() {//初始化
           pre = new ListNode(0);
           size = 0;
        }
        int get(int index){//取第index的值，若index无效，返回-1
            if(index < 0 || index > size -1) {
                return -1;
            }
            ListNode* cur = pre->next;
            while(index--) {
                cur = cur->next;
            }
            return cur->val;
        }
        void addAtHead(int val) {//在头部插入最新节点
            ListNode* cur = new ListNode(val);
            cur->next = pre->next;
            pre->next = cur;//重新更新为pre为最新链表
            size++;
        }
        void addAtTail(int val) {//在尾部插入最新节点
            ListNode* newNode = new ListNode(val);
            ListNode* cur = pre;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = newNode;//在尾部添加新节点
            size++;
        }
        void addAtIndex(int index, int val) {
            if(index > size){
                return;
            }
            if(index < 0){
               addAtHead(val);
            }
            ListNode* newNode = new ListNode(val);
            ListNode* cur = pre;
            while(index--){
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            size++;
        }
        void deleteAtIndex(int index) {
            if(index > size || index < 0){
                return;
            }
            ListNode* cur = pre;
            while(index--){
                cur = cur->next;
            }
            ListNode* delNode = cur->next;
            cur->next = cur->next->next;
            delete delNode;
            size--;          
        }
    private:
        ListNode* pre;
        int size;
};
class Reserve{
    public://单链表反转递归
        ListNode* reserve(ListNode* pre, ListNode *cur){
            if(cur == NULL) return pre;
            ListNode* tmp = cur->next;
            cur->next = pre;
            return reserve(cur, tmp);
        }
        ListNode* resrveList(ListNode *head){
            return reserve(NULL, head);
        }
        ListNode* reverseList_1(ListNode* head) {//双指针逆转链表
        if(head == NULL){
           return NULL; 
        } 
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *tmp = NULL;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
int main(){
    cout<<"Hello HuaWei Cloud!"<<endl;
    return 0;
}