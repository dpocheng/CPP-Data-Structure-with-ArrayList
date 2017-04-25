#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
#include <string>



class OutOfBoundsIndexException
{
};



template <typename Type>
class ArrayList
{
public:
    ArrayList();

    ArrayList(const ArrayList<Type>& a);

    ~ArrayList();

    ArrayList<Type>& operator=(const ArrayList<Type>& a);

    Type& at(unsigned int index);
    const Type& at(unsigned int index) const;

    void add(const Type& s);

    unsigned int size() const;

    unsigned int capacity() const;


private:
    Type* items;
    unsigned int sz;
    unsigned int cap;
};



namespace
{
    const unsigned int initialCapacity = 10;

    template <typename Type>
    void arrayCopy(Type* target, Type* source, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            target[i] = source[i];
        }
    }
}


template <typename Type>
ArrayList<Type>::ArrayList()
    : items{new Type[initialCapacity]}, sz{0}, cap{initialCapacity}
{
//    std::cout << "ArrayList::ArrayList()" << std::endl;
}


template <typename Type>
ArrayList<Type>::ArrayList(const ArrayList<Type>& a)
    : items{new Type[a.cap]}, sz{a.sz}, cap{a.cap}
{
//    std::cout << "ArrayList::ArrayList(const ArrayList&)" << std::endl;
    arrayCopy(items, a.items, sz);
}


template <typename Type>
ArrayList<Type>::~ArrayList()
{
//    std::cout << "ArrayList::~ArrayList()" << std::endl;
    delete[] items;
}


template <typename Type>
ArrayList<Type>& ArrayList<Type>::operator=(const ArrayList<Type>& a)
{
//    std::cout << "ArrayList& ArrayList::operator=(const ArrayList&)" << std::endl;

    if (this != &a)
    {
        Type* newItems = new Type[a.cap];
        arrayCopy(newItems, a.items, a.sz);

        sz = a.sz;
        cap = a.cap;

        delete[] items;
        items = newItems;
    }

    return *this;
}


template <typename Type>
Type& ArrayList<Type>::at(unsigned int index)
{
    if (index > sz)
    {
        throw OutOfBoundsIndexException{};
    }
    return items[index];
}


template <typename Type>
const Type& ArrayList<Type>::at(unsigned int index) const
{
    return items[index];
}


template <typename Type>
void ArrayList<Type>::add(const Type& s)
{
    if (sz == cap)
    {
        int newCap = cap * 2 + 1;

        Type* newItems = new Type[newCap];
        arrayCopy(newItems, items, sz);

        cap = newCap;

        delete[] items;
        items = newItems;
    }

    items[sz] = s;
    sz++;
}


template <typename Type>
unsigned int ArrayList<Type>::size() const
{
    return sz;
}


template <typename Type>
unsigned int ArrayList<Type>::capacity() const
{
    return cap;
}



#endif // ARRAYLIST_HPP
