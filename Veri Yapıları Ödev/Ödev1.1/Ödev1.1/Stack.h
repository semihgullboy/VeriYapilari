#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top = new Node;
public:
    Stack() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            return;
        }
        cout << top->data + 1 << " numarali kisinin islemi bitti. " << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int getTop() {
        if (top == NULL) {
            return -1;
        }
        return top->data;
    }
    bool empty() {
        return top == nullptr;
    }
};