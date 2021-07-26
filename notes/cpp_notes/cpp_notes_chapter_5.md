# A tour of C++: Concurrency and Utilities

* resouce management: unique_ptr and shared_ptr
* Concurrency: tasks and threads, passing arguments, returning results, sharing data, communicating tasks
* small utility components: time, type func, pair and tuple
* regular expression
* math

## Resource Management
* what resource: resource is something that must be acquired and released later (implicitly / explictly). 
* examples are: memory, socket handles, lock, file handles
* unique_ptr:
  * RAII (resource acquisition is initialization)
  * it is very light-weight, no overhead compared with raw pointers.
  * it controls the lifetime of the pointed object, and the return is following *move* semantics. 
* shared_ptr:
  * have a copy semantics, not move
  * provides a garbage collection mechanism that respects the destructor-based resource management of mem managed objects. 
  * this is not cost free. and it is not too expensive either. 
  * but this makes the lifetime of the shared object hard to predict. only use when u need to share owenship.
  * will destroy the shared reousrce when the last shared_ptr referencing to it is destroyed.
* check this example for both shard_ptr and unique_ptr. [here](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/unique_pt_shard_ptr_sample.cpp)


## Concurrency
