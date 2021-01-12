#include<stdio.h>
#include<stdlib.h>

struct node {
    int nilai;
    node* next;
}*head = NULL, * tail = NULL, * temp = NULL;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = NULL;
    return temp;
}

void pushhead(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushtail(int value) {
    node* temp = createnode(value);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}




void printall() {
    if (!head) {
        return;
    }
    node* temp = head;
    while (temp) {
        if (!temp->next) {
            printf("%d\n", temp->nilai);
        }
        else {
            printf("%d -> ", temp->nilai);
        }
        temp = temp->next;
    }
}

void pophead() {
    if (!head) {
        return;
    }
    else if (head == tail) {
        head = tail = NULL;
    }
    else {
        node* temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }

}

void poptail() {
    if (!head) {
        return;
    }
    else if (head == tail) {
        head = tail = NULL;
    }
    else {
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void reverse() {
    node* curr = head;
    while (curr) {
        node* newnode = createnode(curr->nilai);
        newnode->next = temp;
        temp = newnode;
        curr = curr->next;
    }
    while (temp) {
        if (!temp->next) {
            printf("%d\n", temp->nilai);
        }
        else {
            printf("%d -> ", temp->nilai);
        }
        temp = temp->next;
    }
    puts("");
}

int main() {
    pushhead(10);
    pushtail(20);
    pushtail(30);
    pushtail(20);
    printall();
    reverse();
    return 0;
}