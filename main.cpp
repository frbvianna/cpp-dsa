#include <iostream>
#include "SinglyLinkedList/SinglyLinkedList.hpp"
#include "Stack/Stack.hpp"

int main(void) {

    SinglyLinkedList<std::string> *list = new SinglyLinkedList<std::string>{};

    try {
        list->insert("um", 0);
        list->insert("dois", 1);
        list->insert("tres", 2);
        list->insert("quatro", 3);
    }
    catch (const std::string &e) {
        std::cout << e << std::endl;
    }
    
    list->print();

    delete list;

    Stack<std::string> *stack = new Stack<std::string>{};
    stack->push("my");
    stack->push("name");
    stack->push("name");
    stack->pop();
    stack->push("is");
    stack->push("felipe");
    std::cout << *stack->top() << std::endl;
    stack->print();

    return EXIT_SUCCESS;
}