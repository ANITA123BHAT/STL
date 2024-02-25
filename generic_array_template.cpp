/*
class template-Array;
note: since c++11 the STL has std::array which is template-based array class;
use std::srray instead of raw arrays whenever possile;

we can have  a non -type template parameters
thats i what N in this case;


*/
#include<iostream>
#include<string>
template<int N, typename T>
class Array{
    T size{N};
    T value[N];

    friend std::ostream &operator << (std::ostream &os, const Array< N,T> &arr){
        os<<"[";
        for(const auto &val:arr.value){
            os<<val<<" ";
        }
        os<<"]";
        std::cout<<std::endl;
        return os; 
    }

    public:
        Array()=default;
        Array(T init_val){
            for(auto &item:value)
                item=init_val;
        }
        void fill(T val){
            for(auto &item :value)
                item=val;
        }
        int get_size()const{
            return size;
        }
        //overloaded subscript operator for easy use;
        T &operator[](int index){
            return value[index];
        }
};
int main(){
    Array<5,int>nums;
    std::cout<<"The size of nums is:"<<nums.get_size()<<std::endl;
    std::cout<<nums<<std::endl;

    nums.fill(0);
    std::cout<<"The size of nums is:"<<nums.get_size()<<std::endl;
    std::cout<<nums<<std::endl;

    nums.fill(10);
    std::cout<<nums<<std::endl;

    nums[0]=1000;
    nums[1]=2000;
    std::cout<<nums<<std::endl;

    Array<50,float>nums2{1.11};
    std::cout<<"the size of nums2 is: "<<nums2.get_size()<<std::endl;
    std::cout<<nums2<<std::endl;
}
