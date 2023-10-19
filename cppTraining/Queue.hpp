
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
private:
    T* buf; // Our object's buffer of data for our queue. We use a circular array for our queue. 
    unsigned int low, high; // Low/High array index values.
    unsigned int buf_size; // size of our internal buffer. 

    void resize(unsigned int n); // resize the buffer to the new size, keeping the same elements. 
    unsigned int bufsize(); // get the size of the buffer used for the queue. 
public:
    Queue(); // constructor
    Queue(unsigned int n); // constructor w/ initial size
    Queue(const T* addr, unsigned int n); // constructor with initial queue.
    ~Queue(); // destructor 

    unsigned int size(); // get's the current number of elements in the queue.
    T pop(); // pop the end element in the queue.
    void push(const T& in); // push in to the queue.
    T front(); // get the first element of the queue (next to be popped).
    T back(); // get the last element of the queue (last to be popped).
    bool empty(); // returns `true` if the queue is empty.
};

#endif
