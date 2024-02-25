/*
Containers:
    collection of objcets or promitive types;
    (array,vector, deque , stack, set , map, etc);

algorithms:
    fucntions for procressing sequences of element form containers
    (find , max, count, accumlate, sort, etc)
iteratorS:
    generate sequence of element from contianers;
    (forword, reverse, by valuem by reference, contstant etc;)


types of containers:
    sequence containers: it maintains the order of an element;
        array, vector, list, forward-list, deque;
    associtaive conatiners:
        set, multiset map, nulti map;
    containers adapters:this does not support iterator so they can't be used with stl algorithm.
        stack, queue, priority queue:

types of iterators:
    input iterators: from the containers to program;
    output iterators: from the program to the containers;
    forword iterators:navigate one  item ata  time in one direction;
    bi directionla iterators: navigate oneitem at a time both directions
    random access iteratators: directly access a containers item;


generic programming with macros:
    generic program:    
        writing the code that works witha  varityies of types as arguments, as long
        as those arguments types meet specific syntactic and semantic requirements";
    1. funcion template;
    2.class template;


1 way: use macros with arguments:(#define)
    we can write the generic macros:
    #define MAX(a,b) ((a,b)?a:b)
    std::cout<<MAX(10,20) <<std::endl;
    std:::cout<<MAX(12.90,7.8)<<std::endl;

    ex: #define SQUARE(a) (a*a)



Containers: 
    defualt constructor - initalizes an empty container
    overloaded constructor - initialize containrs with many option;
    copy constructor - initializes a containers as copy of another containers
    move constructor - moves existing container to new containers;
    destrcutor -destroy containers;
    copy assignmnet and move assignment for containers;
    size, insert, empty, swap, erase, clear, rbegin & rend, cbegin & cend ...
    etc... 


*/



