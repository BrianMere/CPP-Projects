#include "Queue.hpp"

#include <iostream>
#include <string>

/**
 * Resize the queue to n. Only resizes if our current bufsize is smaller than n and n >= 0.
 * As such, we only resize to a larger size. 
*/
template<typename T>
void Queue<T>::resize(unsigned int n)
{
    int c_bufsize = this->bufsize();
    if (n < c_bufsize && n >= 0)
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
    return (T)NULL;
}

/**
 * Put an element on the start of the queue. We resize if we need more space in pushing. 
*/
template<typename T>
void Queue<T>::push(const T& in)
{
    T ret;
    if (this->size() != this->buf_size)
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




// TEST CODE!!!



int main()
{
    

    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(1);

    std::cout << std::to_string(q.pop()) << std::endl;

    Queue<std::string> r;

    r.push("Test");
    r.push("This");
    r.push("Out");

    std::cout << r.pop() << std::endl;


    exit(0);
}