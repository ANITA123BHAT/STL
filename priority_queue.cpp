/*
std::priority_queue: is  also comes under adaptive container;
->Allows insertion and removal of elements in order from the front of the container;
->elemnts are stored internally as a vector by defaukt;
->elements are stored internally as a vector by defaukt;
->elements are inserted in priority order
(largest value will always  be at front)

->No iterator are are supported;

#include<queue>

*/

#include<iostream>
#include<queue>
class Person{
    friend std::ostream &operator << (std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person():name{"Unknow"},age{0}{}
    Person(std::string name, int age):name{name},age{age}{}
    bool operator < (const Person &rhs)const {
        return (this->age <  rhs.age);
    }
    bool operator == (const Person &rhs)const{
        return (this->name==rhs.name &&  this->age == rhs.age);
    }
};

std::ostream &operator << (std::ostream &os, const Person &p){
    os << p.name<<":"<<p.age;
    return os;
}

//this display the priority queue by;

template<typename T>
void display(std::priority_queue<T>pq){
    std::cout<<"[";
    while(!pq.empty()){
        T element=pq.top();
        pq.pop();
        std::cout<<element<<" ";
    }
    std::cout<<"]"<<std::endl;
}
void test1(){
    std::cout<<"Test1============================================"<<std::endl;
    std::priority_queue<int>pq;
    for(int i:{3,5,7,12,23,12,4,100,0,3,5,7})
        pq.push(i);
    std::cout<<"Size:"<<pq.size()<<std::endl;//12 
    std::cout<<"Top:"<<pq.top()<<std::endl;//100 top is always largets elements in queue

    display(pq);

    pq.pop();//100 is deleted in queue nad p_queue alway delete an elmenet from front and insertion at back;
    display(pq);

}

void test2(){
    std::cout<<"\nTest2====================================================="<<std::endl;
    std::priority_queue<Person>pq;
    pq.push(Person{"A",10});
    pq.push(Person{"B",1});
    pq.push(Person{"C",14});
    pq.push(Person{"D",18});
    pq.push(Person{"E",7});
    pq.push(Person{"F",27});

    display(pq);
}
int main(){
    test1();
    test2();
    return 0;
}