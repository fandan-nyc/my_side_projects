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
* tasks
  * [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/thread_example.cpp)
  * Note that, you need to compile `g++ -pthread main.cpp; ./a.out`, otherwise you will have a linux error: `undefined reference to `pthread_create'
/tmp/cc27j3ck.o: In function `std::thread::thread<F>(F&&)':`
  * This example above is not correct since `cout` has been shared without synchronization -> the result will be undetermined and could vary between different executions of the program.
  * Our goal is to keep tasks completely separate except where they communicate in simple and obvious way. 
* passing arguments
  * [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/passing_arguments.cpp)
* returning results
  * cref -> const reference
  * to return a value from thread, one way is to passing into a pointer and assign the result to the pointer. thus we can get the data out side of the thread after it is joint.  
* sharing data 
  * [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/sharing_data.cpp). 
  * use of defer_lock, so you can lock multiple locks at the same time. 
  * each object has its own mutex, so we know when to modify / lock which one. 
* waiting for events
  * producer consumer [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/waiting_for_events.cpp) with condition_varible
* communicating tasks
  * note: mainly using <future>, there are three facilities: futures and promise, async, packaged_task
  * future and promise
```
 promise<X> & px;
 X res ; 
 px.set_value(res);
 px.sex_exception(current_exception());
```
```
 future<X> fx;
 X res = fx.get(); 
```
  * packaged_tasks: [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/packaged_tasks.cpp)
  * async: do not using async for tasks sharing resources needing locking - with async you do not know how many threads will be used because it is up to async to decide based on what it knows about the system resources available at the time of a call.
    ```
      auto f0 = async(func, var1, var2, var3);
    ```
 
## small utility components 
* time
  ```
     #include <chrono>
     using namespace std::chrono;
     auto t0 = high_resolution_clock::now();
     do_work();
     auto t1 = high_resolution_clock::now();
     auto diff = duration_cast<milliseconds>(t1 - t0).count() << "msec\n";
  ```
* type function
  * a type function is a func that is evaluated at compile time given a type as its argument or returning a type. 
  * this is called metaprogramming. with template, it is called template metaprogramming.
    ```
        #include <limits> 
        #include <iostream>

        using namespace std;

        int main(){
            cout << numeric_limits<float>::min() << endl;
            constexpr int size = sizeof(int);
            cout << size << endl;
        }
    ```
  * another example is [here](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_5/type_func.cpp)
* tuple and pair
 
 
