#ifndef MathException_h
#define MathException_h
class MathException {
 public:
   enum errorType { divByZero, sqrNeg };
   MathException( errorType e ) { error = e; }
   ~MathException() {}
   const char* message() const;
   errorType get() const { return error; }
 private:
   errorType error;
};
#endif
