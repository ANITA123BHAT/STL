
/*
find () algorithm: tried to locate the 1st occurence of an element in the container
auto loc=std::find(vec.begin(),vec.end(),3);
1.
find() need to able to compare objcet
operator ==  is used and must be provded by your class


-> for_each algorithm applies a function to each element in the iterator sequence;
example for  "functor"

struct  Square_Funcor{
    void operator () (int x){ //overload () operator
        std::cout<<x*x<<" ";
    }
}
->like ;;; Myclass& operator + (const Myclass& obj){}
Square_Functor square; //fucntion object

vector<int>vec{1,2,3,4};
std::for_each(vec.begin(),vec.end(),square);

NOTE: square is a function object; and square functor is a structure 

2.
example for_each-using  function pointers:
void sqaure(int x){
    std::cout<<x*x<<" ";
}
std::vector<int> vec {1,2,3,4};
std::for_each(vec.begin(),vec.end(),square);//pass the name of the function as parameter
3.
for_each-using lambda expression;

vector<int>vec{1,2,3,4};
std::for_each(vec.begin(), vec.end(),[](int x){std::cout<<x*x<<" ";})//;lambda


*/
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<cctype> // for conersion liek upper case to lower case <->

class Person{
std::string name;
int age;
public:
    Person()=default;
    Person(std::string name, int age):name{name},age{age}{}
    bool operator < (const Person &rhs)const {
        return this->age< rhs.age;
    }
    bool operator == (const Person &rhs){
        return (this->name== rhs.name 
        && this->age== rhs.age);
    }
};
//find the element in container
void find_test(){
    std::cout<<"\n======================================"<<std::endl;
    std::vector<int>vec{1,2,3,4};
    auto loc=std::find(vec.begin(), vec.end(),2);
    //auto loc=std::find(std::begin(vec), std::end(vec),1);
    if(loc!=vec.end()){
        std::cout<<"found the number"<<*loc<<std::endl;
    }
    else{
        std::cout<<"couldn't noy able to find number"<<std::endl;
    }

    std::list<Person>palyers{
        {"Larry",18},
        {"Moe",20},
        {"Curly",21}
    };
    auto loc1=find(palyers.begin(),palyers.end(),Person{"Moe",20});
    if(loc1!=palyers.end()){
        std::cout<<"found "<<std::endl;
    }
    else{
        std::cout<<" Not found "<<std::endl;
    }
}

void count_test(){
    std::cout<<"\n========================================"<<std::endl;
    std::vector<int>vec{1,2,3,4,5,1,2,1};
    int num=std::count(vec.begin(),vec.end(),1);
    std::cout<<num <<" occurence found"<<std::endl;
}

void count_if_test(){
    std::cout<<"\n=================================================="<<std::endl;
    std::vector<int>vec{1,2,3,4,5,1,2,1,100};
    int num=std::count_if(vec.begin(),vec.end(),[](int x){return x%2==0;});
    std::cout<<num<<" even numbers found"<<std::endl;

    num=std::count_if(vec.begin(),vec.end(),[](int x){return x%2!=0;});
    std::cout<<num<<" odd numbers found"<<std::endl;

}
void replace_test(){
    std::cout<<"\n=========================================================="<<std::endl;
    std::vector<int>vec{1,2,3 ,4,5,1,2,1};
    for(auto i:vec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::replace(vec.begin(),vec.end(),1,100);
    for(auto i:vec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
} 

void all_of_test(){
    std::cout<<"\n==================================================="<<std::endl;
    std::vector<int>vec1{1,3,5,7,13,13,19,5};
    if(std::all_of(vec1.begin(),vec1.end(),[](int x){return x>10;}))
        std::cout<<"allthe elements are >10 "<<std::endl;
    else
        std::cout<<"Not all elements are >10 "<<std::endl;

    if(std::all_of(vec1.begin(),vec1.end(),[](int x){return x<20;}))
        std::cout<<"all the elements are <20 "<<std::endl;
    else
        std::cout<<"Not all elements are <20 "<<std::endl;
}

void string_transform_test(){
    std::cout<<"\n==================================================="<<std::endl;
    std::string str1{"This is a test"};
    std::cout<<"before transform: "<<str1<<std::endl;
    std::transform(str1.begin(),str1.end(),str1.begin(),::toupper);//here replace entire string and where to start replc at the begin() and :: indicate global
    std::cout<<"after transform: "<<str1<<std::endl;

}

int main(){
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
    return 0;
}