#ifndef Funct_h
#define Funct_h

// a functor multiplying the argument by a factor


/*
-------------------------------------------FUNCTOR DEF--------------------------------------------
        Functors are objects that can be treated as though they are a function or function pointer. 
        Functors are most commonly used along with STLs in a scenario like following:
*/
class Func {

  public:

   Func( int n ): f( n ) {};
   float operator()( float x ) const { return f * x; }

  private:

   int f;

};

#endif
