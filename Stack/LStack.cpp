// Figure 4.19: Linked stack class implementation
#include "StackADT.h"
#include "LinkFreeList.h"

// Linked Stack implementation
template <typename E> class LStack : public Stack<E> {
private:
    Link<E>* top;
    int size;
public:
    // Constructor
    LStack(int size = defaultSize) {
        top = NULL;
        size = 0;
    }

    // Destructor
    ~LStack() {
        clear();
    }

    void clear() {
        while (top != NULL) 
        {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    // Push "it" on stack
    void push(const E& it) {
        top = new Link<E>(it, top);
        size++;
    }

    // Remove "it" from stack
    E pop() {
        Assert(top != NULL, "Stack is empty.");
        E it = top->element;
        Link<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    // Return top value
    const E& topValue() const {
        Assert(top != 0, "Stack is empty");
        return top->element;
    }

    // Return length
    int length() const {
        return size;
    }
};