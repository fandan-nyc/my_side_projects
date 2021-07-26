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
# Algorithms

# Advice
