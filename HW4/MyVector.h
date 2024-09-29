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
            T*tmep_arr = new T[2*capacity];

            capacity *= 2;

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

    int at(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "index out of range";
        }
        else
        {
            return vector_stack[index];
        }
    }

    int begin()
    {
        return vector_stack[0];
    }

    int end()
    {
        return vector_stack[length];
    };

    int size()
    {
        return length;
    }


    bool empty()
    {
        if(length != 0)
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
        if (index < 0 || index >= length)
        {
            std::cout << "index out of range";
        }

        else if(length < 1)
        {
            std::cout << "No data exists to be erased" << std::endl;
        }
        else
        {
            for(int i = index; i<= index-1; i++)
            {
                vector_stack[i] = vector_stack[i + 1];
            }
        }

        length--;
    }

    void insert(int index, const T& data)
    {

        if (index < 0 || index >= length)
        {
            std::cout << "index out of range";
        }

        else if(length >= capacity)
        {
            T*tmep_arr = new T[2*capacity];

            capacity *= 2;

            for (int i = 0; i < length; ++i)
            {
                temp_arr[i] = vector_stack[i];
            }

            delete [] vector_stack;

            vector_stack = temp_arr;
        }

        // 배열 temp_arr에 저장
        for(int i = 0; i <= length; i++)
        {
            temp_arr[i] = vector_stack[i];
        }

        temp_arr[index] = data;

        for(int i = index; i <= length; i++)
        {
            vector_stack[i+1] = temp_arr[i];
        }

        length++;
    }


    T& operator[](int index)
    {
        return vector_stack[index];
    }

    MyVector<T>& operator=(const MyVector<T>& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] vector_stack;

        capacity = other.capacity;
        length = other.length;
        vector_stack = new T[capacity];

        for (int i = 0; i < length; ++i)
        {
            vector_stack[i] = other.vector_stack[i];
        }

        return *this;
    }

    MyVector<T> operator+(const MyVector<T>& other)
       {
           MyVector<T> Addition_between_vectors(this->length + other.length);
           for (int i = 0; i < this->length; i++)
           {
               Addition_between_vectors.push_back(this->vector_stack[i]);
           }
           for (int i = 0; i < other.length; i++)
           {
               Addition_between_vectors.push_back(other.vector_stack[i]);
           }

           return Addition_between_vectors;
       }

    void print_vector()
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << vector_stack[i] << " ";
        }
        std::cout << std::endl;
    }



};
#endif // MYVECTOR_H
