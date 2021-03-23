#ifndef LinkedList_h
#define LinkedList_h

template <class T>
class LinkedList {

 public:

  LinkedList();
  ~LinkedList();

  class Iterator {

    friend class LinkedList<T>;

   public:

    Iterator();
    ~Iterator();
    T& operator*();              // dereference
    Iterator& operator++();      //  prefix increment
    Iterator  operator++( int ); // postfix increment
    Iterator& operator--();      //  prefix decrement
    Iterator  operator--( int ); // postfix decrement
    bool operator==( const Iterator& iter );
    bool operator!=( const Iterator& iter );

   private:

    // flag iterators to be:
    //   inside the list,
    //   beyond the end,
    //   before the begin.
    enum status { valid, fw_end, bw_end };
    status validity;
    typename LinkedList<T>::Node* node;

  };

  Iterator begin();  // first element    of the list
  Iterator end();    // beyond the end   of the list
  Iterator rbegin(); // last  element    of the list
  Iterator rend();   // before the begin of the list

  // insert an element before a position
  void insert( const T& x, const Iterator& iter );

 private:

  class Node {

   public:

    // all members are public, the whole class is private to LinkedList

    Node( const T& x );
    ~Node();

    T content;
    Node* pNode; // previous node
    Node* nNode; // next     node

  private:

    // prevent unadvertent copy

    Node           ( const Node& x );
    Node& operator=( const Node& x );

  };

  Node* fNode; // first node in the list
  Node* lNode; //  last node in the list

  LinkedList           ( const LinkedList& x );
  LinkedList& operator=( const LinkedList& x );

};

#include "LinkedList.hpp"
#endif

