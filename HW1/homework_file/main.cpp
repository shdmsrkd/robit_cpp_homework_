#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    Stack stack_nodes;
    Queue queue_nodes;

    stack_nodes.push(1);
    stack_nodes.push(0);
    stack_nodes.push(1);
    stack_nodes.push(1);
    stack_nodes.push(1);

    stack_nodes.printNodes();

    queue_nodes.enqueue(1);
    queue_nodes.enqueue(1);
    queue_nodes.enqueue(0);
    queue_nodes.enqueue(1);
    queue_nodes.enqueue(0);

    queue_nodes.printNodes();


    std::cout << std::endl;

    std::cout << "stack size : " << stack_nodes.getSize() << std::endl;
    std::cout << "returns true if the stack is empty, false otherwise : "<< stack_nodes.isEmpty() << std::endl;
    std::cout << "return top value : " << stack_nodes.top() << std::endl;
    std::cout << "return pop value : " << stack_nodes.pop() << std::endl;
    stack_nodes.printNodes();

    std::cout << std::endl;


    std::cout << "queue size : " << queue_nodes.getSize() << std::endl;
    std::cout << "returns true if the queue is empty, false otherwise : "<< queue_nodes.isEmpty() << std::endl;
    std::cout << "return front value : " << queue_nodes.front() << std::endl;
    std::cout << "return dequeue value : " << queue_nodes.dequeue() << std::endl;
    queue_nodes.printNodes();


    return 0;
}
