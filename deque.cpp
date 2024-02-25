/*
std::deque (double ended queue);
#include<deque>
->dynamic size:
    ->handleed automatically;
    ->can expand an contract as needed
    ->element are NOT stored in contigous memory;
->direct element access(constant time);
->insertion/deletion at front and back(constant time);
->insertion or removal of elements(linear time)
->all iterators available and may invalidate;

NOTE: deque elements are not in continous memory;
usually deque is implemented as collection of memory blocks, and these memory blocks contain elements that are in a continous memeory
but blocks themselves are not in continous memory.

it is like when we add an element it just add if space not theer just add a block and thenlink to that another block;

*/

#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
template<typename T>
void display(const std::deque<T>&d){
    std::cout<<"[";
    for(const auto &element:d){
        std::cout<<element<<" ";
    }
    std::cout<<"]"<<std::endl;
}
void test1(){
    std::cout<<"\n Test1========================================="<<std::endl;
    std::deque<int> d{1,2,3,4,5};
    display(d);

    d={2,4,5,6};
    display(d);
    std::deque<int>d1(10,100);
    display(d1);

    d[0]=100;
    d.at(1)=200;
    display(d);
}
void test2(){
    //push and pops
    std::cout<<"\n test2============================================="<<std::endl;
    std::deque<int>d{0,0,0};
    display(d);
    d.push_back(10);
    d.push_back(20);
    display(d);

    d.push_front(100);
    d.push_front(200);
    display(d);

    std::cout<<"front: "<<d.front()<<std::endl;
    std::cout<<"Back:"<<d.back()<<std::endl;
    std::cout<<"size: "<<d.size()<<std::endl;

    d.pop_back();
    std::cout<<"after popoing back(): "<<std::endl;
    display(d);
    d.pop_front();
    std::cout<<"after poping front(): "<<std::endl;
    display(d);

}
void test3(){
//insert all even numbers into the back of a deque and all;
//odd number into the front;
std::cout<<"\n=================================================="<<std::endl;
std::vector<int>vec{1,2,3,4,5,6,7,8,9,10};
std::deque<int>d;

for(const auto &element:vec){
    if(element%2==0){
        d.push_back(element);
    }
    else{
        d.push_front(element);
    }
    display(d);
}
}

void test4(){
//push  front vs. back ordering..
    std::cout<<"\n Test4======================================"<<std::endl;
    std::vector<int>vec{1,2,3,4,5,6,7,8,9,10};
    std::deque<int>d;
    for(const auto &element :vec){
        d.push_front(element);
    }
    display(d);
    d.clear();
    for(const auto &element:vec){
        d.push_back(element);
    }
    display(d);
}
void test5(){
//same  as test 4 using std::copy
std::cout<<"\n Test5========================================"<<std::endl;
std::vector<int>vec{1,2,3,4,5,6,7,8,9,10};
std::deque<int>d;
std::cout<<"front insertor(): "<<std::endl;
std::copy(vec.begin(),vec.end(),std::front_inserter(d));
display(d);
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}