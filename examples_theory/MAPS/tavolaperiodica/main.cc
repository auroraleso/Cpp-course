#include<iostream>
#include<map>
#include<string>

int main()
{
    //maybe I can improve a class "element" with mass number and other stuff about atoms
    std::map<std::string,int>PeriodicTable;
    PeriodicTable["H"]=1;
    PeriodicTable["He"]=2;
    PeriodicTable["Li"]=3;
    PeriodicTable["Be"]=4;
    PeriodicTable["B"]=5;
    //...

 std::map< std::string,int >::iterator itr;
     std::cout<<"Elements listed:\n" << "\tKEY\tELEMENT\n"; 
    for (itr = PeriodicTable.begin(); itr != PeriodicTable.end(); ++itr) { 
        std::cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 

std::string num;
std::cout<<"Element desired: ";
std::cin>>num;

std::cout<<"Your element has "<<PeriodicTable[num]<<" electrons\n";
    return 0;
}