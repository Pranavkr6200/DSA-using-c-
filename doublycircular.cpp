#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

ListNode *insertAtHead(int data, ListNode *head) {
    if (head == NULL) {
        ListNode *node = new ListNode(data);
        node->next = node;
        node->prev = node;
        return node;
    }
    ListNode *temp = new ListNode(data);
    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp; 
    head->prev = temp;
    return temp;
}

ListNode *insertAtTail(int data, ListNode *head) {
    if (head == NULL) {
        ListNode *node = new ListNode(data);
        node->next = node;
        node->prev = node;
        return node;
    }
    set<ListNode*> visited;

    ListNode *temp = head;
    while (visited.find(temp->next) == visited.end()) {
        visited.insert(temp);
        temp = temp->next;
    }

    temp->next = new ListNode(data);
    temp->next->prev = temp;
    temp->next->next = head;
    head->prev = temp->next; 
    return head;
}

ListNode *deleteAtHead(ListNode *head) {
    if (head == NULL) return head;
    if (head->next == head) {
        delete(head);
        return NULL;
    }

    ListNode *temp = head;
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
    delete(temp);

    return head;
}

ListNode *deleteAtTail(ListNode *head) {
    if (head == NULL) return head;
    if (head->next == head) {
        delete(head);
        return NULL;
    }
    set<ListNode*> visited;

    ListNode *temp = head;
    while (visited.find(temp->next) == visited.end()) {
        visited.insert(temp);
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);

    return head;
}

void display(ListNode *head) {
    set<ListNode*> visited;

    ListNode *temp = head;
    while (visited.find(temp) == visited.end()) {
        visited.insert(temp);
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
   
    ListNode *head;
    head = insertAtHead(10, head);
    head = insertAtHead(20, head);
    head = insertAtHead(30, head);
    display(head);
    head = insertAtTail(40, head);
    head = insertAtTail(50, head);
    head = insertAtTail(60, head);
    display(head);
    head = deleteAtHead(head);
    head = deleteAtTail(head);
    display(head);
    return 0;
}