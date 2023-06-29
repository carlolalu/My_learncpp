/*
 * Here I would like to work with ptr, arrays and infer their type so to gain sleith of hand with them
 *
 * At the same time I would like to see a bit how to allocate and work with multidimentional arrays in
 * the theoretical and surely less practical way
 *
 * The inspiration is drawn also by seeing section 11.14
 * */

#include<iostream>
#include<typeinfo>

int main (void)
{
    int a {5};

    //pointer
    int *ptr = &a;
    std::cout << typeid(ptr).name() << "\n";

    //array (should be int[7])
    int array[7] = {};
    std::cout << typeid(array).name() << "\n";

    //array of ptrs
    int *array_ptrs[7];
    std::cout << typeid(array_ptrs).name() << "\n";

    //ptr to an array (should be (*int)[7])
    int (*ptr_to_array)[7] {&array};
    std::cout << typeid(ptr_to_array).name() << "\n";
    std::cout << (*ptr_to_array)[4] << "\n";

    //double ptr
    int **double_ptr {&ptr};
    std::cout << typeid(double_ptr).name() << "\n";

    //double pointer to an array of 7 members
    int (**double_ptr_to_array)[7] = &ptr_to_array;
    std::cout << typeid(double_ptr_to_array).name() << "\n";

    //pointer to an array of 7 pointers
    // on a parenthesis level this is like as if it was written as *((*ptr_to_ptrsarray)[7])
    int *(*ptr_to_ptrsarray)[7] = &array_ptrs;
    std::cout << typeid(ptr_to_ptrsarray).name() << "\n";

    // some random operation to exercise with the syntax of the commands
    (*ptr_to_array)[4] = {**double_ptr};
    std::cout << array[4] << "\n";


    /* BY doing this exercise ones learn really well to understand the
     * left and right associativity of the operators "*" and "[]" and the way their precedence
     * affects them
     *
     * As a crazy idea one could operate ONLY with dynamically allocated object and
     * never with a real variable to exercise how to use variables and stuff. Of course always handling
     * the exceptions in which there is no memory available. A very crazy idea,
     * but indeed worthy to be tried. After that you can officially declare yourself the master of
     * pointers. Fascinating.
     *
     * Actually I can imagine a very cool way to draw a categorical diagram which could
     * illustrate precisely and simply how to deal with ptrs of arbitrary levels. After that
     * there will be no fear of working with pointers.
     *
     * Now the question is: imagine to allocate an array of 7 elements dynamically. Then you have only a pointer
     * to the first element but NOT to the array. Is there any way to obtain a pointer to the
     * dynamically allocated array in general?
     *
     * ps: I note another thing: the tutorial prefers the notation in which the asterisc is placed
     * next to the type declaration to declare a pointer (ex: int* ptr), while some prefer the opposite
     * (ex: int *ptr). The tutorial makes this choice to be sure that ones distinguish immediately
     * when we are declaring a pointer and when we are dereferencing a rvalue. Personally
     * I prefer the notation with the asteric NEXT TO THE IDENTIFIER, because it evidentiate better
     * the syntax rules, for example for a multideclaration (ex: int *a, *b and not int* a, b),
     * but also to work as I have done in all this file, with array of pointers and pointers to arrays.
     * */

    //$$$$$$
    // now some stuff with mem allocation and multidimensional arrays
    //NOTE: I didn't cover exceptions yet, thus the code will assume that the OS
    // will always have memory available to allocate for the program
    // or I will simply use the std""nothrow, but it is less likely



    return 0;
}