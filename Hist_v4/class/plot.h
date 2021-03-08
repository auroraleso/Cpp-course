#ifndef plot_h
#define plot_h

class plot {

 public:

  // constructor
  plot();
  // deleted copy constructor and assignment to prevent unadvertent copy
  plot           ( const plot& x ) = delete;
  plot& operator=( const plot& x ) = delete;

  // destructor
  virtual ~plot();

  sim 100();

 private:


};

#endif

