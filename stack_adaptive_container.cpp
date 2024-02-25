/*
std::stack:
    ->Last-In-First-Out data structure:
    ->Implemented as an adapter over other STL  container can be implmented as a vector , list or deque;
    ->all operation occur on one end of the stack(top)
    ->No iterator are supported;

*/

#include<iostream>
#include<stack>
#include<vector>
#include<list>

template<typename T>
void display(std::stack <T>s){
    std::cout<<"[";
    while(!s.empty()){
        T element=s.top();
        s.pop();
        std::cout<<element<<" ";
    }
    std::cout<<"]"<<std::endl;
}

int main(){
    std::stack<int>s;
    std::stack<int,std::vector<int>>s1;
    std::stack<int, std::list<int>>s2;//stack of interger but underlying container is vector,list, etc..
    std::stack<int, std::deque<int>>s3;

    for(int i:{1,2,3,4,5})
        s.push(i);
    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while(!s.empty())
        s.pop();
    display(s);

    std::cout<<"Size:"<<s.size()<<std::endl;
    s.push(10);
    display(s);

    s.top()=100;
    display(s);
    
    return 0;
}