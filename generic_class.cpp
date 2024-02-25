/*
what is c++ generic class template?
    similar to function template, but at the class level
    allows "Plugin-in " any data type;
    compiler generates the approproiates class from the blueprint;


*/

#include<iostream>
#include<string>
#include<vector>

template <typename T>
class Item{
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value):name{name},value{value}{}
    std::string get_name()const {return name;}
    T get_value ()const{return value;}
};

template<typename T1, typename T2>
struct My_pair{
    T1 first;
    T2 second;
};
int main(){
    Item <int>item1{"Frank",100};
    std::cout<<item1.get_name()<<" "<<item1.get_value()<<std::endl;

    Item <std::string>item2{"Frank","professor"};
    std::cout<<item1.get_name()<<" "<<item1.get_value()<<std::endl;

    Item<Item<std::string>>item3{"Frank",{"c++","Professor"}}; //here ite3 is an object of Item class and it has an 
    //value as Item <> and that hold valeu string
    /*
    item3 has name and value again value is< name and value>;
    */
   std::cout<<item3.get_name()<<" "
   <<item3.get_value().get_name()<<" "
   <<item3.get_value().get_value()<<std::endl;

   std::cout<<"======================================"<<std::endl;
   std::vector<Item<double>>vec{};
   vec.push_back(Item<double>("Larry",100.0));
    vec.push_back(Item<double>("Moe",200.0));
    for(const auto &item :vec){
        std::cout<<item.get_name()<<" "<<item.get_value()<<std::endl;
    }

    std::cout<<"============================================="<<std::endl;
    My_pair<std::string ,int>p1{"Frank",100};
    My_pair<int, double>p2{123,13.8};

    std::cout<<p1.first<<","<<p1.second<<std::endl;
    std::cout<<p2.first<<","<<p2.second<<std::endl;
    return 0;
}