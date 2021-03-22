#include<iostream>
#include<string>

class Sport
 {
     public:
     virtual ~Sport(){};
     virtual std::string Objective() const = 0;
 };

class Basket: public Sport {
    public:
     std::string Objective() const override 
     {
         return "CANESTRO\n";
     }

};
class Calcio: public Sport {
    public:
     std::string Objective() const override 
     {
         return "GOL\n";
     }

};
class Creator {
  /**
   * Note that the Creator may also provide some default implementation of the
   * factory method.
   */
 public:
  virtual ~Creator(){};
  virtual Sport* FactoryMethod() const = 0; //factorymethod is a pure virtual function,
  // of returning type Sport*, overrided in ConcreteCreators


  std::string SomeOperation() const {
    // Call the factory method to create a Product object.
    Sport* sport = this->FactoryMethod(); //pointer to Product*
    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
  }
};
int main()
{
    return 0;
}