// Figure 4.18: Array-based stack class implementation
#include "StackADT.h"

template <typename E> class AStack
{
private:
    int maxSize;        // Maximum size of stack
    int top;            // Index for top element
    E *listArray;       // Array holding stack elements
public:
    // Constructor
    AStack(int size = defaultSize) {
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }

    // Destructor
    ~AStack() {
        delete [] listArray;
    }

    // Reinitialize
    void clear() {
        top = 0;
    }

    // Push "it" on stack
    void push(const E& it) {
        Assert(top != maxSize, "Stack is full.");
        listArray[top++] = it;
    }

    // Pop top element
    E pop() {
        Assert(top != 0, "Stack is empty.");
        return listArray[--top];
    }

    // Return top element
    const E& topValue() const {
        Assert(top != 0, "Stack is empty.");
        return listArray[top - 1];
    }

    // Return lenght
    int length() const {
        return top;
    }
};


