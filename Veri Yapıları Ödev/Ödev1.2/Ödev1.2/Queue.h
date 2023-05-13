#pragma once
#include <iostream>
#include "Stack.h"

//Oluþturulan yýðýn yapýsý ile kuyruk tasarýmý

class Queue {
private:
    Stack s1, s2;
public:

    void enqueue(int x)
    {
        s1.push(x);
    }


    int dequeue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // if s2 is empty, move
        // elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.Top());
                s1.pop();
            }
        }

        // return the top item from s2
        s2.pop();
        return 0;

    }
};
