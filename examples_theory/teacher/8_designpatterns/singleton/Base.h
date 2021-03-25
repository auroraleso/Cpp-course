#ifndef Base_h
#define Base_h

class Base {

 public:

  static Base* instance();

  virtual void f();

/*
-------------------------------------PROTECTED MEMBERS DEFINITION-----------------------------------------------------
      A protected member variable or function is very similar to a private member but it provided one 
      additional benefit that they can be accessed in child classes 
      which are called derived classes. 
*/
 protected:

  Base();
  virtual ~Base();

 private:

  static Base*& instRef();

  Base           ( const Base& x ) = delete;
  Base& operator=( const Base& x ) = delete;

};

#endif

