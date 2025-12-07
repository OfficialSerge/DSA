#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <optional>

/**
 * A FIFO (First-In-First-Out) data structure implemented using a Singly Linked
 * List.
 */
template <typename T> class Queue {
private:
  struct Node {
    T value;
    Node *next;
  };

  Node *head;    // Points to the first element (deque here)
  Node *tail;    // Points to the last element (enqueue here)
  size_t length; // Tracks number of elements

public:
  // --- Rule of Five / boilerplate ---

  // 1. Default Constructor
  // Initializes an empty queue.
  Queue() : head(nullptr), tail(nullptr), length(0) {}

  // 2. Destructor
  // Cleans up all memory used by nodes when the Queue goes out of scope.
  ~Queue() {
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  // 3. copy constructor (deleted)
  // prevent copying (e.g. queue q2 = q1;) to avoid double-free bugs.
  Queue(const Queue &) = delete;

  // 4. Copy Assignment Operator (Deleted)
  // Prevent assignment (e.g. q2 = q1;) to avoid double-free bugs.
  Queue &operator=(const Queue &) = delete;

  // 5. Move Constructor (Deleted for simplicity)
  // Prevent moving ownership.
  Queue(Queue &&) = delete;

  // 6. Move Assignment Operator (Deleted for simplicity)
  Queue &operator=(Queue &&) = delete;

  void enqueue(T item) {
    Node *node = new Node{item, nullptr};
    if (length == 0) {
      tail = head = node;
      length++;
      return;
    }

    length++;
    tail->next = node;
    tail = node;
  }

  std::optional<T> deque() {
    if (head == nullptr) return std::nullopt;
    const T result = head->value;

    Node *temp = head;
    head = head->next;
    delete temp;

    if (!head) tail = nullptr;
    length--;

    return result;
  }

  std::optional<T> peek() const {
    if (head) return head->value; 
    return std::nullopt;
  }

  size_t size() const { return length; }
};

#endif // !QUEUE_H
