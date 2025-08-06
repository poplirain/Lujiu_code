#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = createNode(0);
    struct ListNode* current = dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int num1, num2;
    printf("输入第一个链表的长度：");
    scanf("%d", &num1);
    printf("输入第二个链表的长度：");
    scanf("%d", &num2);
    
    struct ListNode *l1 = NULL, *l1_tail = NULL;
    struct ListNode *l2 = NULL, *l2_tail = NULL;
    
    printf("输入第一个链表的元素：\n");
    for (int i = 0; i < num1; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* node = createNode(val);
        if (l1 == NULL) {
            l1 = node;
            l1_tail = node;
        } else {
            l1_tail->next = node;
            l1_tail = node;
        }
    }
    
    printf("输入第二个链表的元素：\n");
    for (int i = 0; i < num2; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* node = createNode(val);
        if (l2 == NULL) {
            l2 = node;
            l2_tail = node;
        } else {
            l2_tail->next = node;
            l2_tail = node;
        }
    }
    
    struct ListNode* l3 = addTwoNumbers(l1, l2);
    
    printf("结果链表：");
    while (l3 != NULL) {
        printf("%d ", l3->val);
        l3 = l3->next;
    }
    printf("\n");
    
    freeList(l1);
    freeList(l2);
    freeList(l3);
    
    return 0;
}