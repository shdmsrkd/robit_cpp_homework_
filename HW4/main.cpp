#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
    MyVector<int> vector1;

    vector1.push_back(14);
    vector1.push_back(277);
    vector1.push_back(98);
    vector1.push_back(140);
    cout << "initialization vector : " ;
    vector1.print_vector();
    cout << endl;


    cout << "1 index value : " ;
    cout << vector1[1] << endl;
    cout << endl;


    cout << "First value : " << vector1.begin() << endl;
    cout << "Last value : " << vector1.end() << endl;
    cout << endl;

    cout << "3 insert value 10 for first index : " ;
    vector1.insert(2, 10);
    vector1.print_vector();
    cout << endl;


    cout << "Delete 4 index value" << endl;
    vector1.erase(3);
    vector1.print_vector();

    cout << endl;


    if (vector1.empty() == true)
    {
        cout << "This vector is not empty" << endl;
    }
    else
    {
        cout << "This vector is empty" << endl;
    }

    cout << endl;


    MyVector<int> vector2;
    vector2 = vector1;
    cout << "Copy vector1 value to vector2 value" << endl;
    cout << "Value of Vector 2 : ";
    vector2.print_vector();

    cout << endl;

    // 벡터 크기 확인 (size)
    cout << "Size of vector1: " << vector1.size() << endl;
    cout << "Size of vector2: " << vector2.size() << endl;

    cout << endl;

    MyVector<int> Addition_between_vectors;
    Addition_between_vectors = vector1 + vector2;
    Addition_between_vectors.print_vector();

    return 0;
}

