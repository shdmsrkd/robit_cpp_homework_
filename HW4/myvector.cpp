#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

template<typename T>

class MyVector
{

private:
    T*vector_stack;
    T*temp_arr;
    int length;
    int capacity;
    int idx;

public:
    MyVector(const int& temp=10)
    {
        vector_stack = new T[temp];
        temp_arr = new T[temp];

        length = 0;
        capacity = temp;
    };

    ~MyVector()
    {
        delete[] vector_stack;
        delete[] temp_arr;
    }


    void push_back(const T& data)
    {
        if(length >= capacity)
        {
            capacity *= 2;

            T*temp_arr = new T[capacity];

            for (int i = 0; i < length; ++i)
            {
                temp_arr[i] = vector_stack[i];
            }

            delete [] vector_stack;

            vector_stack = temp_arr;
        }

        vector_stack[length] = data;

        length++;
    }

    T at(int index) const
    {
        return vector_stack[index];
    }

    T begin() const
    {
        return vector_stack[0];
    }

    T end() const
    {
        return vector_stack[length - 1];
    };

    bool empty() const
    {
        if(length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void erase(int index)
    {
        if(length < 1)
        {
            std::cout << "No data exists to be erased" << std::endl;
        }
        else
        {
            for(int i = index; i < length - 1; i++)
            {
                vector_stack[i] = vector_stack[i + 1];
            }
        }

        length--;
    }

    void insert(int index, T& data)
    {
        if(length >= capacity)
        {

            capacity *= 2;

            T*tmep_arr = new T[capacity];

            for (int i = 0; i < length; ++i)
            {
                temp_arr[i] = vector_stack[i];
            }

            delete [] vector_stack;

            vector_stack = temp_arr;
        }

        // 배열 temp_arr에 저장
        for (int i = length; i > index; i--)
        {
            vector_stack[i] = vector_stack[i - 1];
        }
        temp_arr[index] = data;

        length++;
    }

    int size()
    {
        return length;
    }

    MyVector&operator++(const MyVector& other)
    {
        return this + other;
    }


};
#endif // MYVECTOR_H
