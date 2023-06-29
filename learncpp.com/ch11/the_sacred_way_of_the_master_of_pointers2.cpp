/*
<<<<<<< HEAD
Here I try to implement what I learned about multilevel pointers and dereferencing to the
 case o0f memory allocation. In particular I see that the operator new returns ALWAYS a 1 level pointer
 to the kind of object after it. If it is a multi-level array, then it gets treated as an array with
 respect to the last squared parenthesis. Precisely:
 type *ptr {new (std::nothrow) type};       //single value
 type *ptr {new (std::nothrow) type[x]};        //array of values
 type (*ptr)[a][b] {new (std::nothrow) type[x][a][b]}        //multidimensional array where a b are CONSTEXPR
 * basically I never know the last dimension. NEVER, because I get returned always a pointer.
 *
 * There is still A LOT of work which needs to be done to take confidence with which sqaured parenthesis operator\
 does have the privilege to not be returned to the pointer. Precisely is the leftmost one, but
 what is the meaning of it, and hwo to use on a practical level? I need to do some exercise with
 multi-level pointers, multi-dimensional arrays and dynamic memory allocation all together
 and array of pointers to multi-diumensional arrays or similar. A world of reference to be discovered

 * */

#include<iostream>
#include<typeinfo>

int main (void)
{
    int (*ptr)[4][7] {new int[5][4][7] };


    return 0;
=======
Here I try to implement what I learned about multilevel pointers and
dereferencing to the case o0f memory allocation. In particular I see that the
operator new returns ALWAYS a 1 level pointer to the kind of object after it. If
it is a multi-level array, then it gets treated as an array with respect to the
last squared parenthesis. Precisely: type *ptr {new (std::nothrow) type};
//single value type *ptr {new (std::nothrow) type[x]};        //array of values
 type (*ptr)[a][b] {new (std::nothrow) type[x][a][b]}        //multidimensional
array where a b are CONSTEXPR
 * basically I never know the last dimension. NEVER, because I get returned
always a pointer.
 *
 * There is still A LOT of work which needs to be done to take confidence with
which sqaured parenthesis operator\ does have the privilege to not be returned
to the pointer. Precisely is the leftmost one, but what is the meaning of it,
and hwo to use on a practical level? I need to do some exercise with multi-level
pointers, multi-dimensional arrays and dynamic memory allocation all together
 and array of pointers to multi-diumensional arrays or similar. A world of
reference to be discovered

 * */

#include <iostream>
#include <typeinfo>

int main(void) {
  int(*ptr)[4][7]{new (std::nothrow) int[5][4][7]};

  // stupid and totally unuseful idea
  // in the spirit of the mathematics: create an multidimensional array
  // of pointers to a multidimensional array of the same signature

  if (ptr) {
    std::cout << (*ptr)[3][3] << "\n";
  }

  int left_most_dimension{400};

  // let us try with an multidimensional array of type (400,3,4,5)
  using basic_t = int;

  basic_t *(*ptr2)[30300][4][5]{
      new (std::nothrow) basic_t *[left_most_dimension][30300][4][5]};

  if (ptr2) {
    std::cout << "a totally unuseful result here for you: " << (*ptr2)[2][3][3]
              << "\n";
  }

  return 0;
>>>>>>> e29b156 (the sacred way of the master of pointers)
}