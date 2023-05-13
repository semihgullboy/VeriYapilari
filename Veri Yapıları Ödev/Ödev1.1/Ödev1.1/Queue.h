#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

class Queue {
private:
    Stack s1, s2;

public:

    void enqueue(int val) {
        while (!s1.empty()) {
            s2.push(s1.getTop());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty()) {
            s1.push(s2.getTop());
            s2.pop();
        };
    }

    void dequeue() {
        if (s1.getTop() == -1) {
            return;
        }
        while (s1.getTop() != -1) {
            s1.pop();
        }
        s2.pop();
        while (s2.getTop() != -1) {
            s1.push(s2.getTop());
            s2.pop();
        }
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};