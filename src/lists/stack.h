#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <optional>

template <typename T> class Stack {
private:
  struct Node {
    T value;
    Node *next;
  };

  Node *head;
  size_t length;

public:
  Stack() : head(nullptr), length(0) {};
  Stack(Stack &&) = delete;
  Stack(const Stack &) = delete;
  Stack &operator=(Stack &&) = delete;
  Stack &operator=(const Stack &) = delete;
  ~Stack() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  };

  void push(T item) {
    Node *node = new Node{item, head};
    head = node;
    length++;
  }

  std::optional<T> pop() {
    if (!head) return std::nullopt;

    const T result = head->value;
    Node *temp = head;
    head = head->next;
    delete temp;

    return result;
  }

  std::optional<T> peek() {
    if (!head) return std::nullopt;
    return head->value;
  }

  size_t size() { return length; }
};

#endif // !STACK_H
