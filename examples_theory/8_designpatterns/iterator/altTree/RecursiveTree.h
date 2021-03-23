#ifndef RecursiveTree_h
#define RecursiveTree_h

template <class Key, class Content>
class RecursiveTree {

 public:

  RecursiveTree();
  RecursiveTree           ( const RecursiveTree& x ) = delete;
  RecursiveTree& operator=( const RecursiveTree& x ) = delete;

  ~RecursiveTree();

  // associate a key to a content
  class Association {
   public:
    Key key;
    Content content;
  };

  class Iterator {

    friend class RecursiveTree<Key, Content>;

   public:

    Iterator();
    ~Iterator();
    Association& operator*();    // dereference
    Iterator& operator++();      //  prefix increment
    Iterator  operator++( int ); // postfix increment
    Iterator& operator--();      //  prefix decrement
    Iterator  operator--( int ); // postfix decrement
    bool operator==( const Iterator& iter );
    bool operator!=( const Iterator& iter );

   private:

    // flag iterators to be:
    //   inside the tree,
    //   beyond the end,
    //   before the begin.
    enum status { valid, fw_end, bw_end };
    status validity;
    typename RecursiveTree<Key,Content>::Node* node;

  };

  Iterator begin();  // first element    of the list
  Iterator end();    // beyond the end   of the list
  Iterator rbegin(); // last  element    of the list
  Iterator rend();   // before the begin of the list

  // find an element in the tree or create it with initial content
  Association& find( const Key& k, const Content& c );

 private:

  class Node {

   public:

    // all members are public, the whole class is private to RecursiveTree

    Node( const Key& k, const Content& c );
    ~Node();

    Node* first(); // first node in a branch
    Node* last();  //  last node in a branch

    // find an element in a branch or create it with initial content
    Association& find( const Key& k, const Content& c );

    Association content;
    Node* pNode; // previous node
    Node* nNode; // next     node
    Node* lNode; // left  branch
    Node* rNode; // right branch

  private:

    // prevent unadvertent copy

    Node           ( const Node& x );
    Node& operator=( const Node& x );

  };

  // main branch
  Node* rNode;

};

#include "RecursiveTree.hpp"
#endif

