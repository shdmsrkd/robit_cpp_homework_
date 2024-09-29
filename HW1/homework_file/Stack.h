#ifndef STACK_H
#define STACK_H

class Stack {
private:
    struct Node
    {
        bool data;
        Node* next;
        Node(bool item) : data(item), next(nullptr) {}
    };

    Node* topNode;    // 스택의 최상단 노드를 가리킴
    int size;         // 스택의 크기

public:
    Stack();      // 생성자
    ~Stack();     // 소멸자

    void push(bool item);  // 항목 삽입
    bool pop();            // 항목 제거 및 반환
    bool top();      // 최상단 항목 반환
    bool isEmpty();  // 스택이 비어있는지 확인
    int getSize();   // 스택의 크기 반환
    void printNodes();

//    void printNodes();
};

#endif
