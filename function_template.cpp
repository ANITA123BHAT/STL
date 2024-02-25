/*
generic programming with function templates:
    template is the generic blueprint that the compiler uses to generate specialized functions in classes
    allows "plugging-in" any data type;
    compiler generates the appropriate function/class from the blueprint;
    generic programing /meta programming;

    ex: max function as a template function:
        we may also use "class " instead of "typename";

    template<class T>
    Many times the compiler can deduce the type and the template paramater is not needed ;
    we can use "almost "type we need

ex:
    the following wil not compile unless "Player" overloads "operator >"
    Player p1{"hero",100}
    Player p2{"enemy",99};
    std::cout<<max<Player>(p1,p2);

*/
#include<iostream>
#include<string>
template<typename T>//template<class T>
T min (T a, T b){
    return (a<b)?a:b;
} 

template<class T1, class T2>
void func(T1 a, T2 b){
    std::cout<<a<<" "<<b<<std::endl;
}

struct Person{
    std::string name;
    int age;
    bool operator < (const Person &rhs) const{
        return this->age < rhs.age;
    }

};

//public structure so no need friend
std::ostream &operator << (std::ostream &os, const Person &p){
    os<<p.name;
    return os;
}
template<typename T>
void my_swap(T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){
    Person p1{"Anita",50};
    Person p2{"Moe",30};

    Person p3=min(p1,p2);
    std::cout<<p3.name<<" is younger "<<std::endl;
    std::cout<<min<int>(2,3)<<std::endl;
    std::cout<<min(2,3)<<std::endl;
    std::cout<<min('A','B')<<std::endl;
    std::cout<<min(12.8,9.2)<<std::endl;
    std::cout<<min(5+2*2,7+40)<<std::endl;

    func(p1,p2);

    std::cout<<"\n";
    func<int,int>(10,20);
    func(10,20);//compiler deduce it;
    func<char,double>('A',12.7);
    func('C',13.5);
    func(1000,"Testing");
    func(2000,std::string{"frank"});

    std::cout<<"\n";
    int x{100};
    int y{200};
    my_swap(x,y);
    std::cout<<x<<" "<<y<<std::endl;
    float z{100.90};
    float a{89.0};
    my_swap(z,a);
    std::cout<<z<<" "<<a<<std::endl;
    return 0;
}