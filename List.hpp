#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <cassert>
#include <cstddef>


template <typename T>
class List {
private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    // test requirements
    assert(empty());

    // copy nodes
    for (Iterator it = other.begin(); it != other.end(); ++it) {
      push_back(*it);
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  size_t num_elements;

public:
  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    return num_elements == 0;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const {
    return num_elements;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    assert(!empty());
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back() {
    assert(!empty());
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    // declare and initialize new node
    Node *new_node = new Node{nullptr, nullptr, datum};

    // place new node at the end of the list
    if (empty()) {
      first = last = new_node;
    } else {
      new_node->next = first;
      first->prev = new_node;
      first = new_node;
    }

    // increment size
    num_elements++;
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    // declare and initialize new node
    Node *new_node = new Node{nullptr, nullptr, datum};

    // place new node at the end of the list
    if (empty()) {
      first = last = new_node;
    } else {
      last->next = new_node;
      new_node->prev = last;
      last = new_node;
    }

    // increment size
    num_elements++;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front() {
    // test requirements
    assert(!empty());

    // declare temp variable to hold first
    Node *delete_node = first;

    if (size() == 1) {
      first = last = nullptr;
    } else {
      first = first->next;
      first->prev = nullptr;
    }

    // delete old first
    delete delete_node;

    // decrement size
    num_elements--;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    // test requirements
    assert(!empty());

    // declare temp variable to hold last
    Node *delete_node = last;

    if (size() == 1) {
      first = last = nullptr;
    } else {
      last = last->prev;
      last->next = nullptr;
    }

    // delete isolated node
    delete delete_node;

    // decrement size
    num_elements--;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while (!empty()) {
      pop_back();
    }
  }

  // default constructor
  List() : first(nullptr), last(nullptr), num_elements(0) {}

  // copy constructor
  List(const List<T> &list) {
    num_elements = 0;
    copy_all(list);
  }

  // overloaded assignment operator
  List<T> & operator=(const List<T> &list) {
    // return object if they are the same
    if (this == &list) { return *this; }

    clear(); // delete current nodes

    // copy list
    //num_elements = list.size();
    copy_all(list);

    return *this;
  }

  // destructor
  ~List() {
    clear();
  }

public:
  class Iterator {
    friend class List;
  private:
    Node *node_ptr; //current Iterator position is a List node

    // construct an Iterator at a specific position
    Iterator(Node *p) : node_ptr(p) {}

  public:
    // default constructor
    Iterator() : node_ptr(nullptr) {}

    // overloaded pre-decrementation operator
    Iterator & operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

    // overloaded pre-incrementation operator
    Iterator & operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      // doesn't consider if there would be a prev node
      return *this;
    }

    // overloaded dereference operator
    T & operator*() const {
      assert(node_ptr);
      return node_ptr->datum;
    }

    // overloaded == operator
    bool operator==(const Iterator &iter) const {
      return node_ptr == iter.node_ptr;
    }

    // overloaded != operator
    bool operator!=(const Iterator &iter) const {
      return node_ptr != iter.node_ptr;
    }
  };

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return Iterator(nullptr);
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i) {
    // check that iterator is valid
    if (i.node_ptr == nullptr && !empty()) { assert(false); }

    // initialize nodes for and around node to delete
    Node *node_erase = i.node_ptr;
    Node *node_before = node_erase->prev;
    Node *node_after = node_erase->next;

    // isolate node from list
    if (empty()) { return; }
    else if (size() == 1) { 
      first = last = nullptr;
    }
    else if (node_before == nullptr) {
      node_after->prev = nullptr;
      first = node_after;
    }
    else if (node_after == nullptr) {
      node_before->next = nullptr;
      last = node_before;
    } 
    else {
      node_before->next = node_after;
      node_after->prev = node_before;
    }

    // delete node
    delete node_erase;

    // decrement size
    num_elements--;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum) {
    // check that iterator is valid
    if (i.node_ptr == nullptr && !empty()) { assert(false); }

    // create new node and node for iterator
    Node *new_node = new Node{nullptr, nullptr, datum};
    Node *iter_node = i.node_ptr;

    // insert node into list
    if (iter_node == nullptr) {
      first = last = new_node;
    }
    else if (iter_node->prev == nullptr) {
      new_node->next = first;
      iter_node->prev = new_node;
      first = new_node;
    }
    else {
      iter_node->prev->next = new_node;
      new_node->prev = iter_node->prev;
      new_node->next = iter_node;
      iter_node->prev = new_node;
    }

    // increment size
    num_elements++;
  }

};

#endif
