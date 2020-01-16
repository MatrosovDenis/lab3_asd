#include <vector>
#include <string>
#include <iostream>

class Stack
{
public:
    Stack() {
        sizeStack = 0;
    }
    ~Stack() = default;
    size_t size() {
        return sizeStack;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    void push(const int elem)
    {
        stack.push_back(elem);
        sizeStack += 1;
    }
    int pop()
    {
        if (!isEmpty()) {
            int elem = stack.back();
            stack.pop_back();
            sizeStack -= 1;
            return elem;
        }
        else {
            std::cerr << "Error. Stack is empty";
            exit(1);
        }
    }
    int top()
    {
        if (!isEmpty()) {
            return stack.back();
        }
        else {
            std::cerr<< "Error. Stack is empty";
            exit(1);
        }
    }
private:
    std::vector <int> stack;
    std::size_t sizeStack;
    int index;
};