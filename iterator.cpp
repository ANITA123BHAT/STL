#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>

//display any vector using range based for loop
void display(const std::vector<int>&vec){
    std::cout<<"[";
    for(auto const &i:vec){
        std::cout<<i<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1(){
    std::cout<<"\n=================================="<<std::endl;
    std::vector<int> nums1{1,2,3,4,5};
    auto it=nums1.begin();
    std::cout<<*it<<std::endl;
    it++;
    std::cout<<*it<<std::endl;

    it+=2;
    std::cout<<*it<<std::endl;

    it-=2;
    std::cout<<*it<<std::endl;

    it=nums1.end()-1;
    std::cout<<*it<<std::endl;
}

void test2(){
    std::cout<<"\n=================================="<<std::endl;
    //display all vector elements using an iterator;
    std::vector<int>nums1 {1,2,3,4,5};
    std::vector<int>::iterator it=nums1.begin();
    while(it!=nums1.end()){
        std::cout<<*it<<std::endl;
        it++;
    } 
    //change all vector elements to 0
    it=nums1.begin();
    while (it!=nums1.end())
    {
        /* code */
        *it=0;
        it++;
    }
    display(nums1);
}
void test3(){
    //using a const_iterator
    std::cout<<"\n======================="<<std::endl;
    std::vector<int>nums1{1,2,3,4,5};
    std::vector<int>::const_iterator it=nums1.begin();
    while(it!=nums1.end()){
        std::cout<<*it<<std::endl;
        it++;
    }
    it=nums1.begin();
    while(it!=nums1.end()){
        *it++;
    }
}
void test4(){
    std::vector<int>vec{1,2,3,4};
    auto it1=vec.rbegin();
    while(it1!=vec.rend()){
        std::cout<<*it1<<" ";
        ++it1;
    }

    std::list<std::string>name={"Larry","MOe","Curly"};
    //list is basically doubly linked list;
    auto it2=name.crbegin();
    std::cout<<*it2<<std::endl;
    it2++;
    std::cout<<*it2<<std::endl;

    std::map<std::string, std::string>m1{
        {"Frank","c++"},
        {"Bill","jAVA"},
        {"James","Haskel"}
    };
    auto it3=m1.begin();
    while(it3!=m1.end()){
        std::cout<<it3->first<<" "<<it3->second<<"\n";
        it3++;
    }
    std::cout<<"\n";
}

void test5(){
    std::vector<int>vec{1,2,3,4,5,6,7,8,9,10};
    auto start=vec.begin()+2;//2 
    auto finish=vec.end()-3;//8
    while(start!=finish){
        std::cout<<*start<<std::endl;
        start++;
    }
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

