// Figure 4.27: Linked queue class implementation
#include "Link.h"
#include "QueueADT.h"

// Linked queue implementation
template <typename E> class LQueue : public Queue<E> {
private:
    Link<E>* front;     // Pointer to front queue node
    Link<E>* rear;      // Pointer to rear queue node
    int size;           // The number of elements in queue
public:
    LQueue(int size = defaultSize) {
        front = rear = new Link<E>();
        size = 0;
    }

    ~LQueue() {
        clear();
        delete front;
    }

    void clear() {
        while (front->next != NULL) 
        {
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }

    void enqueue(const E& it) {
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }

    // Remove element from front
    E dequeue() {
        Assert(size != 0, "Queue is empty");
        E it = front->next->element;    // Store dequeued value
        Link<E>* ltemp = front->next;   // Hold dequeued link
        front->next = ltemp->next;      // Advance front
        if (rear == ltemp) {            // Delete last element
            rear = front;
        }
        delete ltemp;                   // Delete link
        size--;
        return it;                      // Return element value
    }

    const E& frontValue() const {
        Assert(size != 0, "Queue is empty.");
        return front->next->element;
    }

    virtual int length() const {
        return size;
    }
};