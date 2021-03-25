#include<iostream>
#include<string>
#include<map>
/*
    ---------------- DESCRIPTION:---------------------------

    Map is a container that stores elements in key-value pairs. 
    It's similar to collections in Java, associative arrays in PHP, 
    or objects in JavaScript.
    An #include<map> is needed.

*/


//lets create an example: numero di matricola e studente associato
int main (){
  std::map<int,std::string> matricole;
  
  //three ways 
  matricole[1187622]="Aurora Leso";
  matricole.insert(std::make_pair(1193258, "Sabrina Ciarlantini"));
  matricole.insert(std::pair<int,std::string>(1193880, "Alice Barbon"));
    std::cout<<"_______________________________________________________\n";
   std::map< int ,std::string >::iterator it;
   for(it=matricole.begin(); it!=matricole.end(); ++it){
      std::cout << it->second << " si identifica con numero di matricola " << it->first << "\n";
   }
   std::cout<<"\nWe're going to delete the unlucky "<<matricole[1193258]<<"\n"; 
   int deleted = matricole.erase(1193258); 

    std::cout << deleted << " removed \n"; //if more the one had that key, there would have been more deleted obj
     std::map< int ,std::string >::iterator itr;
     //printing remained students
     
     std::cout<<"Remained students:\n" << "\tKEY\tELEMENT\n"; 
    for (itr = matricole.begin(); itr != matricole.end(); ++itr) { 
        std::cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 

  return 0;
}