#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T> 
{
public:
    Stack() : std::vector<T>(){ 
    }

    ~Stack() {}

    size_t size() const {
        return std::vector<T>::size();
    }

    bool empty() const {
        if (std::vector<T>::size() == 0) {
            return true;
        }
        return false;
    }

    void push(const T& item) {
        std::vector<T>::push_back(item);
    }

    void pop() {
        if (std::vector<T>::empty()) {
            throw std::underflow_error("stack empty");
        }
        std::vector<T>::pop_back();
    }

    T const & top() const {
        if (std::vector<T>::empty()) {
            throw std::underflow_error("stack empty");
        }
        return std::vector<T>::back();
    }
};


#endif