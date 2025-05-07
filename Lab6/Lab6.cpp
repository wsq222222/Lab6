#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>  // Для std::runtime_error

// Шаблонный класс Queue
template <typename T>
class Queue {
private:
    std::vector<T> data;

public:
    void push(const T& item) {
        data.push_back(item);
    }

    void pop() {
        if (!data.empty()) {
            data.erase(data.begin());
        }
        else {
            throw std::runtime_error("Queue is empty. Cannot remove element.");
        }
    }

    void show() const {
        std::cout << "Queue elements:\n";
        for (const auto& element : data) {
            std::cout << element << '\n';
        }
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    try {
        Queue<int> numberQueue;
        numberQueue.push(10);
        numberQueue.push(20);
        numberQueue.push(30);

        std::cout << "Integer Queue:\n";
        numberQueue.show();

        numberQueue.pop();
        numberQueue.show();

        numberQueue.pop();
        numberQueue.pop();
        numberQueue.pop(); //Исключение

    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "\n";

    try {
        Queue<std::string> wordQueue;
        wordQueue.push("healthpotion");
        wordQueue.push("pickaxe");
        wordQueue.push("card");

        std::cout << "String Queue:\n";
        wordQueue.show();

        wordQueue.pop();
        wordQueue.pop();
        wordQueue.pop();
        wordQueue.pop();  // Исключение

    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}