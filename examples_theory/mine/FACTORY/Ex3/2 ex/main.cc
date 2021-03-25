#include<iostream>

enum VehicleType { Two, Three, Four};

//create base class, abstract since I have a pure virtual
class Vehicle 
{
    public:
    virtual void print()=0;
    static Vehicle* create(VehicleType t);

};

//create derived classes
class Four_Wheel: public Vehicle {
    //implement pure virtual function of base or I will not be able to instantiate an obj Four_Wheel
    void  print()
    {
        std::cout<<"I have 4 wheels\n";
    }
    
};
class Two_Wheel: public Vehicle{
     void  print()
    {
        std::cout<<"I have 2 wheels\n";
    }

};
class Three_Wheel: public Vehicle{
     void  print()
    {
        std::cout<<"I have 3 wheels\n";
    }

};

//this is the Factory
Vehicle* Vehicle::create(VehicleType t)
{
    if (t== Two)
    return new Two_Wheel();
     if (t== Three)
    return new Two_Wheel();
     if (t== Four)
    return new Two_Wheel();
    else 
    {
        std::cout<<"No creation :( \n";
        return NULL;
    }

}

//client class
class Client
{
    public:
 Client()
 {
     VehicleType t= Two;
     pV=Vehicle::create(t);
 }
  ~Client() 
    { //destructor declared inline
        if (pV) 
        {
            delete[] pV;//delete vector
            pV = NULL;
        }
    }
Vehicle* getVehicle() 
    {
        return pV;
    }

private:
Vehicle* pV;
};

int main()
{

    Client* pClient=new Client(); //Created Client, there's a Two Wheel here
    Vehicle* pVehicle=pClient->getVehicle();
    pVehicle->print();
    return 0;
}