
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

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

/**
 * Resize the queue to n. Only resizes if our current bufsize is smaller than n and n >= 0.
 * As such, we only resize to a larger size. 
*/
template<typename T>
void Queue<T>::resize(unsigned int n)
{
    int c_bufsize = this->bufsize();
    if (n < c_bufsize)
    {
        T* n_buf = new T[n];
        for (unsigned int i = this->low; i < this->high; i++)
        {
            n_buf[i-this->low] = this->buf[i];
        }
        delete[] this->buf;
        unsigned int m = this->high - this->low;
        this->buf = n_buf;
        this->buf_size = n;
        this->low = 0;
        this->high = m;
    }
    else if (n > c_bufsize)
    {
        T* n_buf = new T[n];
        for (unsigned int i = 0; i < c_bufsize; i++)
        {
            n_buf[i] = this->buf[i];
        }
        delete[] this->buf;
        this->buf = n_buf;
        this->buf_size = n;
    }
}

/**
 * Return the size of the internal buffer. 
*/
template<typename T>
unsigned int Queue<T>::bufsize()
{
    return this->buf_size;
}

/**
 * Default empty constructor.
*/
template<typename T>
Queue<T>::Queue()
{
    this->buf = new T[0];
    this->low = 0;
    this->high = 0;
    this->buf_size = 0;
}

/**
 * Default size n constructor.
*/
template<typename T>
Queue<T>::Queue(unsigned int n)
{
    Queue();
    this->resize(n);
}

/**
 * Constructor to copy our passed array as our queue. T[0] is the back and T[n-1] is the front.
*/
template<typename T>
Queue<T>::Queue(const T* addr, unsigned int n)
{
    Queue();
    this->buf = addr;
    this->buf_size = n;
    this->low = 0;
    this->high = n - 1;
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] buf;
}

/**
 * Get the size of our queue in number of *elements*. 
*/
template<typename T>
unsigned int Queue<T>::size()
{
    if (this->high < this->low)
    {
        return this->high + this->buf_size - this->low;
    }
    else if (this->high > this->low)
    {
        return this->high - this->low;
    }
    return 0; // high == low so the size is 0.  
}

/**
 * Get the element at the end of the queue. If we have an empty queue return NULL. 
*/
template<typename T>
T Queue<T>::pop()
{
    T ret;
    if (!this->empty())
    {  
        ret = this->buf[this->high];
        if (this->high == 0)
        {
            this->high = this->buf_size - 1;
        }
        else 
        {
            this->high--;
        }
        return ret;
    }
    return NULL;
}

/**
 * Put an element on the start of the queue. We resize if we need more space in pushing. 
*/
template<typename T>
void Queue<T>::push(const T& in)
{
    T ret;
    if (this->size() > this->buf_size)
    {
        this->buf[this->low] = in;
        if (this->low == 0)
        {
            this->low = this->buf_size - 1;
        }
        else 
        {
            this->low--;
        }
    }
    else 
    {
        this->resize(this->buf_size + 1);
        this->push(in);
    }
}

/**
 * Get the front element of the queue. IE: T[0]
*/
template<typename T>
T Queue<T>::front()
{
    if(!this->empty())
    {
        return this->buf[high];
    }
    return NULL;
}

/**
 * Get the back element of the queue. IE: T[n-1]
*/
template<typename T>
T Queue<T>::back()
{
    if(!this->empty())
    {
        return this->buf[low];
    }
    return NULL;
}

/**
 * Says if the queue has no elements in the queue.
*/
template<typename T>
bool Queue<T>::empty()
{
    return this->size() == 0 ? true : false;
}


void ppi();

#endif
