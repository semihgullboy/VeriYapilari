#pragma once

#include <iostream>
#define MAX_SIZE 100

using namespace std;

// Array veri yap�s� ile y���n olu�turuldu

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    bool empty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value)
    {

        if (top >= MAX_SIZE - 1) { // Y���n dolu ise hata mesaj� yazd�r
            cout << "HATA: Y���n dolu!\n";
        }
        else {
            top++;
            arr[top] = value;
            cout << arr[top] + 1;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Yigin Bos" << endl;

        }
        int val = arr[top];
        top--;
    }

    int Top() {
        return arr[top];
    }
};

