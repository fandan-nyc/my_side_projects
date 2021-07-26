# A tour of C++: Containers and Algorithms

# Libraries
* the facilities provided by the standard library can be classified as
  * run time language support (for allocation, runtime type)
  * the c lib
  * strings and I/O stream
  * a framework of containers and algorithms
  * numeric computation
  * regular expression
  * concurrent programming
  * template metaprogramming
  * smart pointers
  * special purpose container
# String
* substr, replace, toupper, and you can == to compare
* +/+= concatenation

# Stream I/O
* cout
* cin
  * you can read the whole line by `getline(cin, local_var)`
* I/O stream for user defined types 
  *  here is one [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_4/user_defined_iostream.cpp).
  *  the istream example is skipped (check page 92).

# Containers
* a class with the main purpose of holding objects is commonly called a container. 
* vector
  * assigning a vector involves copying its elements
  * vector does not have range check when calling []. but ::at(i) does. We can have a wrapper like [this](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_4/vector_at.cpp). Note that, this a try catch example here as well. watch out for `...` for all other exceptions catch block.
* list 
  * this is a double linked list in cpp
  * you can do insert, erase. there is no find, so you need to traverse the list.
  * it performs better with a small verctor, than a small list. unless you have a strong reason, always use vector, which works better for find, count, sort and binary_search etc.
* map: this is red-black tree, unordered_map, provides a default hash func for string. you can provide your own when needed.
# Algorithms
* the standard algorithm are expressed in terms of *sequence* of elements. 
* A sequence is represented by a pair of iterators specifying the first element and the one beyond-the-last element. 
* here are 3 ways to implement the findFunc (a wrapper of algorithm::find) with iterator. [here](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_4/use_of_iterator.cpp). Note that, we can have template for iterator in this case `findFunc3`.
* using predict
```
#include <iostream>
#include <unordered_map> 
#include <algorithm> 

using namespace std;

int main(){
   unordered_map<string, int> um {{"a", 11 }, {"b", 10}};
   auto x = find_if(um.begin(), um.end(), [](const pair<string, int>& r){ return r.second > 5 ;});
   cout << (*x).first;
}
```
