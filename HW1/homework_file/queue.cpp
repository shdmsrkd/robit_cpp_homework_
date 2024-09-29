    #include "Queue.h"
#include <stdexcept>
#include <iostream>

Queue::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

Queue::~Queue()
{
    while (!isEmpty())
    {
        dequeue();  // 스택이 비어질 때까지 항목 제거
    }
}

void Queue::enqueue(bool item) // 새로운 노드르 추가하는 함수
{
    Node* newNode = new Node(item);   // 새로운 노드 생성
    newNode->next = nullptr;

    if(isEmpty()) // 노드가 아무것도 없는 경우
    {
        rearNode = newNode;                // rearNode를 새 노드로 갱신
        frontNode = newNode;               // frontNode를 새 노드로 갱신
        size++;                            // 큐의 크기 증가
    }
    else
    {
        rearNode->next = newNode;          // 새 노드의 next를 기존 rearNode로 설정
        rearNode = newNode;                // rearNode를 새 노드로 갱신
        size++;                            // 큐의 크기 증가
    }
}

bool Queue::dequeue()   // 노드 삭제하는 함수
{
    if (isEmpty())
    {
    // 큐가 비어있을 때 예외 처리
        throw std::out_of_range("Queue is empty, cannot dequeue.");
    }

    Node* tempNode = frontNode;        // 현재 frontNode 값 tempNode에 저장
    bool removedData = frontNode->data; // 현재 frontNode가 가리키는 데이터값 따로 저장
    frontNode = frontNode->next;     // forontNode를 새 노드로 갱신
    delete tempNode;                 // tempNode 메모리 할당 해제
    size--;                          //  크기 감소
    return removedData;               // 꺼낸 데이터 반환
}




bool Queue::front() // front 노드가 가리키는 데이터값을 반환 하는 함수
{
    if (isEmpty())
    {
    // 스택이 비어있을 때 예외 처리
        throw std::out_of_range("Queue is empty, top is not exist.");
    }

    return frontNode->data;

}

bool Queue::isEmpty() // stack 비어있는지 여부를 확인하는 함수
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

int Queue::getSize()  // 사이즈를 반환하는 함수
{
    return size;
}

void Queue::printNodes() // 현재 stack에 있는 값을 전체 출력하는 함수
{
    Node* tempNode = frontNode; // 빈 노드에 topNode 값 저장
    while(tempNode != nullptr) // stack 끝까지 반복
    {
        std::cout << tempNode->data << " "; // 앞서 지정한 노드(tmepNode)가 가리키는 데이터 출력
        tempNode = tempNode->next; // 다음으로 넘어가기
    }

    std::cout << std::endl; // 줄바꿈
}

