// Figure 4.11 Implementation for the Link class with a freelist.
// Singly linked list node with freelist support
template <typename E> class Link {
private: 
    static Link<E>* freelist;   // Reference to freelist head
public:
    E element;      //Value for this node
    Link* next;     //Point to the next node in list

    //Constructors
    Link(const E& elemval, Link* nextval = NULL) {
        element = elemval;
        next = nextval;
    }

    Link(Link* nextval = NULL) {
        next = nextval;
    }

    //Overloaded new operator
    void* operator new(size_t) {
        if (freelist == NULL) {
            return ::new Link;
        }       //Creare space

        Link<E>* temp = freelist;       //Can take from freelist
        freelist = freelist->next;
        return temp;                    //Return the link
    }

    // Overloaded delete operator
    void operator delete(void* ptr) {
        ((Link<E>*)ptr)->next = freelist;       //Put on freelist
        freelist = (Link<E>*)ptr;
    }
};

// The freelist head pointer is actually created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;