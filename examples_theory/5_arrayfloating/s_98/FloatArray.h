#ifndef FloatArray_h
#define FloatArray_h

class FloatArray {

 public:

  FloatArray();
  FloatArray( unsigned int n );
  ~FloatArray();

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

  FloatArray( const FloatArray& a );
  FloatArray& operator=( const FloatArray& a );

  unsigned int eltn;
  float* cont;

};

#endif

