#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
class ArrayList
{
    private:
        T* buf; // buffer containing our data
        size_t end; // end pointer for the end of our list. Doubles as our length parameter.
        size_t bufsize; // maintain the count of the buffer memory allocated for us. 

        void resize(size_t newsize)
        {

        } // resize to some newsize.
    public:

        ArrayList(const T* arr, size_t arr_size) 
        {
            buf = new T[arr_size];
            end = arr_size;
            bufsize = arr_size;
            for(size_t i = 0; i < bufsize; i++)
            {
                buf[i] = arr[i];
            }
        } // copy an array to use as a list. Doesn't copy the arr ptr! Is O(n) relative to the size of the array passed. 
        ArrayList(const ArrayList<T>& other) : ArrayList(other.size(), other.buf)
        {} // copy another ArrayList to this object.
        ArrayList() : 
            buf(new T[0]),
            end(0),
            bufsize(0)
        {} // create an empty array with no elements. 

        ~ArrayList() 
        {
            delete[] this->buf;
        }

        inline bool is_empty() const {return this->bufsize == 0;} // determine if buffer contains no data. 
        inline size_t size() const {return this->end;} // get the current length of the list.
        friend std::ostream& operator<<(std::ostream& p, const ArrayList<T>& L)
        {
            p << "[";
            for(size_t i = 0; i < L.size(); i++)
            {
                p << L.buf[i];
                if(i != L.size() - 1)
                {
                    p << ", ";
                }
            }
            p << "]";
            return p;
        } // get the stream version of this list. 

        T& operator[](size_t i)
        {
            if (i >= this->end)
            {
                throw std::out_of_range("Index out of bounds");
            }
            return this->buf[i];
        } // operator element overloading... 

        T& pop(size_t index);
};

/**
 * Remove an item at the given index and return the value of the pointer at that index.
 * Is O(n)
*/
template<typename T>
T& ArrayList<T>::pop(size_t index)
{
    T *ret = this[index];
    for(size_t i = index; i < this->end - 1; i++)
    {
        this[i] = this[i + 1];
    }
    this->end--;
    return ret;
}





#endif 