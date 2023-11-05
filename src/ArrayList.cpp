#include "ArrayList.hpp"

/**
 * Remove an item at the given index and return the value of the pointer at that index.
 * Is O(n)
*/
// template<typename T>
// T& ArrayList<T>::pop(size_t index)
// {
//     T *ret = this[index];
//     for(size_t i = index; i < this->end - 1; i++)
//     {
//         this[i] = this[i + 1];
//     }
//     this->end--;
//     return ret;
// }