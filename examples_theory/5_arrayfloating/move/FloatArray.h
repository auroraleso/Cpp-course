#ifndef FloatArray_h
#define FloatArray_h

class FloatArray {

 public:

  FloatArray();
  FloatArray( unsigned int n );
  FloatArray( const FloatArray& a );
  ~FloatArray();

  FloatArray& operator=( const FloatArray& a );

  // move constructor and assignment,
  // used when arguments are rvalues (temporary)
  FloatArray( FloatArray&& a );
  FloatArray& operator=( FloatArray&& a );

  unsigned int size() const;
  const
  float& operator[]( unsigned int i ) const;
  float& operator[]( unsigned int i );

  class OutOfRange {
   public:
    OutOfRange() {}
    ~OutOfRange() {}
  };
  bool checkRange( unsigned int i ) const;

  static bool debug;

 private:

  unsigned int eltn;
  float* cont;

  void copy( const FloatArray& a );
  void move(       FloatArray& a );

};

#endif

