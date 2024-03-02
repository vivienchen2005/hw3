#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items_;
  void heapify(int idx, int k);
  void trickleUp(int loc);
  int k;
  PComparator c_;
};

// Add implementation of member functions here
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c) {
  k = m;
  c_ = c;
}

template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item) {
  items_.push_back(item);
  trickleUp (items_.size()-1);
}

template <typename T, typename Comparator>
bool Heap<T,Comparator>::empty() const {
  if (items_.size() == 0) {
    return true;
  }
  return false;
}

template <typename T, typename Comparator>
size_t Heap<T,Comparator>::size() const {
  return items_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap empty");
  }
  //swap first and last
  std::swap(items_[0], items_.back());

  //remove last
  items_.pop_back();

  //sort
  if (size() > 1) {
    heapify(0, k);
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index, int k) {

  T max_child = items_[(index*k) + 1];
  int max_child_index = (index*k) + 1;
  for (int i=2; i <= k; i++) { //for each child
    int childIndex = (index*k) + i;
    //find the max child
    if (childIndex < size()) { 
      if (c_(items_[childIndex], max_child)) {
        max_child = items_[childIndex];
        max_child_index = childIndex;
      }
    }
  }

  //swap index with max_child_index
  if (c_(max_child, items_[index])) {
    std::swap (items_[max_child_index], items_[index]);
  }
    
  //if max_child is not a leaf node
  //recursively call heapify with max_child_index
  if (((max_child_index*k) + 1) < size()) {
    heapify (max_child_index, k);
  }
  else {
    return;
  }
  
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc) {
  int parent_index = (loc-1)/k;
  while (parent_index >= 0 && c_(items_[loc], items_[parent_index])) {
    std::swap(items_[parent_index], items_[loc]);
    loc = parent_index;
    parent_index = (loc-1)/k;
  }
}


#endif

