//#include "LinkedList.h"

// *************** LinkedList implementation ***************

template <class T>
LinkedList<T>::LinkedList() {
  fNode = lNode = nullptr;
}


template <class T>
LinkedList<T>::~LinkedList() {
  Node* node = fNode;
  Node* next;
  while ( node != nullptr ) {
    next = node->nNode;
    delete node;
    node = next;
  }
}


// first element    of the list
template <class T>
typename LinkedList<T>::Iterator
         LinkedList<T>::begin() {
  LinkedList<T>::Iterator iter;
  // if there's a first element set iterator to point there
  // otherwise set iterator as "beyond the end"
  if ( fNode != nullptr ) {
    iter.validity = Iterator::valid;
    iter.node = fNode;
  }
  else {
    iter.validity = Iterator::fw_end;
    iter.node = lNode;
  }
  return iter;
}


// beyond the end   of the list
template <class T>
typename LinkedList<T>::Iterator
         LinkedList<T>::end() {
  LinkedList<T>::Iterator iter;
  iter.validity = Iterator::fw_end;
  iter.node = lNode;
  return iter;
}


// last  element    of the list
template <class T>
typename LinkedList<T>::Iterator
         LinkedList<T>::rbegin() {
  LinkedList<T>::Iterator iter;
  // if there's a last element set iterator to point there
  // otherwise set iterator as "before the begin"
  if ( lNode != nullptr ) {
    iter.validity = Iterator::valid;
    iter.node = lNode;
  }
  else {
    iter.validity = Iterator::bw_end;
    iter.node = fNode;
  }
  return iter;
}


// before the begin of the list
template <class T>
typename LinkedList<T>::Iterator
         LinkedList<T>::rend() {
  LinkedList<T>::Iterator iter;
  iter.validity = Iterator::bw_end;
  iter.node = fNode;
  return iter;
}


// insert an element before a position
template <class T>
void LinkedList<T>::insert( const T& x, const LinkedList<T>::Iterator& iter ) {

  // create a new node
  Node* node = new Node( x );
  Node* prev = nullptr;
  Node* next = nullptr;

  // find previous and next nodes
  switch( iter.validity ) {
  case Iterator::valid:
    next = iter.node;
    prev = next->pNode;
    break;
  case Iterator::fw_end:
    prev = lNode;
    break;
  case Iterator::bw_end:
    next = fNode;
    break;
  };

  // link previous and next nodes to the new one
  if ( prev != nullptr ) {
    prev->nNode = node;
    node->pNode = prev;
  }
  else {
    fNode = node;
  }
  if ( next != nullptr ) {
    node->nNode = next;
    next->pNode = node;
  }
  else {
    lNode = node;
  }

  return;

}

// *************** LinkedList::Iterator implementation ***************

template <class T>
LinkedList<T>::Iterator::Iterator() {
}


template <class T>
LinkedList<T>::Iterator::~Iterator() {
}


// dereference
template <class T>
T& LinkedList<T>::Iterator::operator*() {
  if ( validity == valid ) return node->content;
  static T* dum = new T;
  return *dum;
}


//  prefix increment
template <class T>
typename LinkedList<T>::Iterator&
         LinkedList<T>::Iterator::operator++() {
  switch( validity ) {
  case valid:
    // valid iterator:
    //   if there's a next element move to it,
    //   otherwise flag the iterator as "beyond the end"
    if ( node->nNode != nullptr ) node = node->nNode;
    else                          validity = fw_end;
    break;
  case fw_end:
    // "beyond the end" iterator: no action
    break;
  case bw_end:
    // "before the begin" iterator:
    //   if there's an element stay there and flag the iterator as valid
    //   otherwise flag the iterator as "beyond the end"
    if ( node != nullptr ) validity = valid;
    else                   validity = fw_end;
    break;
  };
  return *this;
}


// postfix increment
template <class T>
typename LinkedList<T>::Iterator
         LinkedList<T>::Iterator::operator++( int ) {
  // save a copy
  Iterator iter = *this;
  // step forward
  operator++();
  // return the copy
  return iter;
}


//  prefix decrement
template <class T>
typename LinkedList<T>::Iterator&
         LinkedList<T>::Iterator::operator--() {
  switch( validity ) {
  case valid:
    // valid iterator:
    //   if there's a previous element move to it,
    //   otherwise flag the iterator as "before the begin"
    if ( node->pNode != nullptr ) node = node->pNode;
    else                          validity = bw_end;
    break;
  case fw_end:
    // "beyond the end" iterator:
    //   if there's an element stay there and flag the iterator as valid
    //   otherwise flag the iterator as "before the begin"
    if ( node != nullptr ) validity = valid;
    else                   validity = bw_end;
    break;
  case bw_end:
    // "before the begin" iterator: no action
    break;
  };
  return *this;
}


// postfix decrement
template <class T>
typename LinkedList<T>::Iterator
         LinkedList<T>::Iterator::operator--( int ) {
  // save a copy
  Iterator iter = *this;
  // step backward
  operator--();
  // return the copy
  return iter;
}


template <class T>
bool LinkedList<T>::Iterator::operator==( const Iterator& iter ) {
  return ( node == iter.node ) && ( validity == iter.validity );
}


template <class T>
bool LinkedList<T>::Iterator::operator!=( const Iterator& iter ) {
  return ( node != iter.node ) || ( validity != iter.validity );
}

// *************** LinkedList::Node implementation ***************

template <class T>
LinkedList<T>::Node::Node( const T& x ):
  content( x ),
  pNode( nullptr ),
  nNode( nullptr ) {
}


template <class T>
LinkedList<T>::Node::~Node() {
}


