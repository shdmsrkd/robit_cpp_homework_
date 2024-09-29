#include "Stack.h"
#include <stdexcept>
#include <iostream>

Stack::Stack() : topNode(nullptr), size(0) {}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();  // 스택이 비어질 때까지 항목 제거
    }
}

void Stack::push(bool item)
{
    Node* newNode = new Node(item);   // 새로운 노드 생성
    newNode->next = topNode;          // 새 노드의 next를 최상단 노드 설정
    topNode = newNode;                // 최상단 노드를 새 노드로 갱신
    size++;                           // 스택의 크기 증가
}

bool Stack::pop()
{
    if (isEmpty())
    {
    // 스택이 비어있을 때 예외 처리
        throw std::out_of_range("Stack is empty, cannot pop.");
    }

    Node* tempNode = topNode;        // 현재 최상단 노드를 임시로 저장
    bool poppedData = topNode->data; // 최상단 노드의 데이터 저장
    topNode = topNode->next;         // 최상단 노드 다음으로 이동
    delete tempNode;                 // 이전 최상단 노드 메모리 해제
    size--;                          // 스택 크기 감소

    return poppedData;               // 꺼낸 데이터 반환
}

bool Stack::top() // 최상 노드 반환
{
    if (isEmpty())
    {
    // 스택이 비어있을 때 예외 처리
        throw std::out_of_range("Stack is empty, top is not exist.");
    }

    return topNode->data;
}


bool Stack::isEmpty() // stack 비어있는지 여부를 확인하는 함수
{
    // 스택이 비워져 있으면 true 반환 아닐경우 false 반환
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int Stack::getSize() // 사이즈를 반환하는 함수
{
    return size;
}


void Stack::printNodes() // 현재 stack에 있는 값을 전체 출력하는 함수
{
    Node* tempNode = topNode; // 빈 노드에 topNode 값 저장
    while(tempNode != nullptr) // stack 끝까지 반복
    {
        std::cout << tempNode->data << " "; // 앞서 지정한 노드(tmepNode)가 가리키는 데이터 출력
        tempNode = tempNode->next; // 다음으로 넘어가기
    }

    std::cout << std::endl; // 줄바꿈
}

