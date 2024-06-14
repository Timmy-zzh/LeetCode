
/**
 * 单链表数据结构Bean：
 * - 数据域：int val
 * - 指针域：ListNode *next
 */
class ListNode
{
public:
    int val;
    ListNode *next;
    
    ListNode(int x):val(x),next(nullptr){

    }
    ~ListNode(){

    };

    // int getValue(){
    //     return this->val;
    // }

    // ListNode* getNext(){
    //     return this->next;
    // }

    // void setNext(ListNode next){
    //     this->next = &next;
    // }
};

