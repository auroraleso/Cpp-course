//#include "RecursiveTree.h"

// *************** RecursiveTree implementation ***************

template <class Key, class Content>
RecursiveTree<Key,Content>::RecursiveTree():
 rNode( nullptr ) {
}


template <class Key, class Content>
RecursiveTree<Key,Content>::~RecursiveTree() {
  delete rNode;
}

// first element    of the list
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator
         RecursiveTree<Key,Content>::begin() {
  RecursiveTree<Key,Content>::Iterator iter;
  // if there's a root branch set iterator to point to its first element
  // otherwise set iterator as "beyond the end"
  if ( rNode != nullptr ) {
    iter.validity = Iterator::valid;
    iter.node = rNode->first();
  }
  else {
    iter.validity = Iterator::fw_end;
    iter.node = nullptr;
  }
  return iter;
}


// beyond the end   of the list
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator
         RecursiveTree<Key,Content>::end() {
  RecursiveTree<Key,Content>::Iterator iter;
  iter.validity = Iterator::fw_end;
  // if there's a main branch find its last element
  if ( rNode != nullptr ) iter.node = rNode->last();
  return iter;
}


// last  element    of the list
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator
         RecursiveTree<Key,Content>::rbegin() {
  RecursiveTree<Key,Content>::Iterator iter;
  // if there's a root branch set iterator to point to its last element
  // otherwise set iterator as "before the begin"
  if ( rNode != nullptr ) {
    iter.validity = Iterator::valid;
    iter.node = rNode->last();
  }
  else {
    iter.validity = Iterator::bw_end;
    iter.node = nullptr;
  }
  return iter;
}


// before the begin of the list
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator
         RecursiveTree<Key,Content>::rend() {
  RecursiveTree<Key,Content>::Iterator iter;
  iter.validity = Iterator::bw_end;
  // if there's a main branch find its first element
  if ( rNode != nullptr ) iter.node = rNode->first();
  return iter;
}


// find an element in the tree
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Association&
         RecursiveTree<Key,Content>::find( const Key& k, const Content& c ) {
  // if there's not a main branch create it,
  // otherwise find the element inside it
  if ( rNode == nullptr ) {
    rNode = new Node( k, c );
    return rNode->content;
  }
  return rNode->find( k, c );

}

// *************** RecursiveTree::Iterator implementation ***************

template <class Key, class Content>
RecursiveTree<Key,Content>::Iterator::Iterator() {
}


template <class Key, class Content>
RecursiveTree<Key,Content>::Iterator::~Iterator() {
}


// dereference
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Association&
         RecursiveTree<Key,Content>::Iterator::operator*() {
  if ( validity == valid ) return node->content;
  static Association* dum = new Association;
  return *dum;
}


//  prefix increment
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator&
         RecursiveTree<Key,Content>::Iterator::operator++() {
  switch( validity ) {
  case valid:
    // valid iterator:
    //   if there's a next element move to it,
    //   otherwise flag the iterator as "beyond the end"
    RecursiveTree<Key,Content>::Node* tNode;
    tNode = node->next();
    if ( tNode != nullptr ) node = tNode;
    else                    validity = fw_end;
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
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator
         RecursiveTree<Key,Content>::Iterator::operator++( int ) {
  // save a copy
  Iterator iter = *this;
  // step forward
  operator++();
  // return the copy
  return iter;
}


//  prefix decrement
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator&
         RecursiveTree<Key,Content>::Iterator::operator--() {
  switch( validity ) {
  case valid:
    // valid iterator:
    //   if there's a previous element move to it,
    //   otherwise flag the iterator as "before the begin"
    RecursiveTree<Key,Content>::Node* tNode;
    tNode = node->prev();
    if ( tNode != nullptr ) node = tNode;
    else                    validity = bw_end;
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
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Iterator
         RecursiveTree<Key,Content>::Iterator::operator--( int ) {
  // save a copy
  Iterator iter = *this;
  // step backward
  operator--();
  // return the copy
  return iter;
}


template <class Key, class Content>
bool RecursiveTree<Key,Content>::Iterator::operator==( const Iterator& iter ) {
  return ( node == iter.node ) && ( validity == iter.validity );
}


template <class Key, class Content>
bool RecursiveTree<Key,Content>::Iterator::operator!=( const Iterator& iter ) {
  return ( node != iter.node ) || ( validity != iter.validity );
}


// first node in a branch
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Node*
         RecursiveTree<Key,Content>::Node::first() {
  // if there's a left branch return its first node
  if ( lNode != nullptr ) return lNode->first();
  return this;
}


//  last node in a branch
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Node*
         RecursiveTree<Key,Content>::Node::last() {
  // if there's a left branch return its last node
  if ( rNode != nullptr ) return rNode->last();
  return this;
}

// *************** RecursiveTree::Node implementation ***************

template <class Key, class Content>
RecursiveTree<Key,Content>::Node::Node( const Key& k, const Content& c ):
  mNode( nullptr ),
  lNode( nullptr ),
  rNode( nullptr ) {
  content.key = k;
  content.content = c;
}


template <class Key, class Content>
RecursiveTree<Key,Content>::Node::~Node() {
  delete lNode;
  delete rNode;
}


// find an element in a branch or create it with initial content
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Association&
         RecursiveTree<Key,Content>::Node::find( const Key& k,
                                                 const Content& c ) {
  if ( k < content.key ) {
    // key less than key of the root node:
    //   if there's a left branch continue the search inside it
    //   otherwise create it
    if ( lNode != nullptr ) {
      return lNode->find( k, c );
    }
    else {
      // create new node
      lNode = new Node( k, c );
      // link new node with this one
      lNode->mNode = this;
      return lNode->content;
    }
  }
  if ( k > content.key ) {
    // key greater than key of the root node:
    //   if there's a right branch continue the search inside it
    //   otherwise create it
    if ( rNode != nullptr ) {
      return rNode->find( k, c );
    }
    else {
      // create new node
      rNode = new Node( k, c );
      // link new node with this one
      rNode->mNode = this;
      return rNode->content;
    }
  }
  return content;
}


// find an element in a branch or create it with initial content
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Node*
         RecursiveTree<Key,Content>::Node::next( RecursiveTree<Key,Content>::Node* tNode ) {
  if ( rNode != tNode ) return rNode->first();
  if ( mNode == nullptr ) return nullptr;
  if ( mNode->lNode == this ) return mNode;
  else                        return mNode->next( this );
}


// find an element in a branch or create it with initial content
template <class Key, class Content>
typename RecursiveTree<Key,Content>::Node*
         RecursiveTree<Key,Content>::Node::prev( RecursiveTree<Key,Content>::Node* tNode ) {
  if ( lNode != tNode ) return lNode->last();
  if ( mNode == nullptr ) return nullptr;
  if ( mNode->rNode == this ) return mNode;
  else                        return mNode->prev( this );
}

