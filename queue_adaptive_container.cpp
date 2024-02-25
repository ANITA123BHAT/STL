/*
std::queue:
    ->First -in First Out data structure
    ->implmented as an adapter over other STL container
    can be implmented as a list or deque;
    ->elements are pushed at the back and popped from the front;

    ->No iterators are supported;
*/
#include<iostream>
#include<queue>

template<typename T> 

void display(std::queue<T> q){
    std::cout<<"[";
    while(!q.empty()){
        T element=q.front();
        q.pop();
        std::cout<<element<<" ";
    }
    std::cout<<"]"<<std::endl;
}

int main(){
    std::queue<int>q;
    for(int i:{1,2,3,4,5})
        q.push(i);
    display(q);
    std::cout<<"Front: "<<q.front()<<std::endl;
    std::cout<<"Back:"<<q.back()<<std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while(!q.empty())
        q.pop();
    display(q);

    std::cout<<"size: "<<q.size()<<std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout<<"Front: "<<q.front()<<std::endl;
    std::cout<<"Back:"<<q.back()<<std::endl;

    q.front()=5;//starting
    q.back()=5000;  //at end of list 

    display(q);

    std::cout<<"Front: "<<q.front()<<std::endl;
    std::cout<<"Back:"<<q.back()<<std::endl;

}