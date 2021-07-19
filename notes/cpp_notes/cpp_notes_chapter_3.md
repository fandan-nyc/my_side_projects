  
# Chapter 3: a tour of C++ abstraction mechanisms

In this section, we will have 4 sub-sections. classes, copy and move, templates, and advice. 

## Classes

In this section, we cover concrete types (arithmetic type, a container, and container initialization), abstract types (also virtual functions), and class hierarchies.

### concrete types
* concrete types are used / behave just like built-in types, such as int and var
* The defining characteristic of a concrete type is that its represenation is part of its definition. it allows 
  *  place objects of concrete types on the stack, in statically allocated mem and in other objects
  *  refer to objects directly 
  *  initialize objects immediately and completely
  *  copy objects
* meanwhile, if the concrete class change in a significant way, the user has to recompile. it is the cost to pay.
* Container
  * RAII (resource allocation is initialization) allows us to eliminate naked new operations and we leverage destructor to eliminate the naked delete. 
  * check example: [here](https://github.com/fandan-nyc/my_side_projects/tree/master/notes/cpp_notes/chapter_3/vector_initializer.cpp)

### Abstract Types
* virtual means "MAYBE redefined later in a class derived from this one"
* = 0 means the function is pure virtual; that is, some class derived from Container must define the func.
* This is just interface as in Java. 
* You generally do NOT define constructor, but always have destructor in the interface
  * exmaple is [here](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_3/virtual_class_sample.cpp)
