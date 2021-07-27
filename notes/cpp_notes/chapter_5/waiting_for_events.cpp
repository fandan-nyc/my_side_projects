#include <mutex>
#include <deque>
#include <chrono>
#include <iostream>
#include <condition_variable>
#include <thread>

using namespace std;

mutex globalLock;
condition_variable cv ; 
deque<int> queue;
int counter ;

template<typename T>
void print(const T& data){
   cout << data << endl;
}

void consumer(){
   while(true){
      unique_lock<mutex> ul {globalLock};
      cv.wait(ul, [&]{return !queue.empty();});
      print("consumer start");
      auto m = queue.back();
      queue.pop_back();
      print(m);
      print("consumer finish");
      ul.unlock();
   }
}

void producer(){
   while(counter < 10){
     unique_lock<mutex> ul {globalLock};
     print("producer start");
     queue.push_back(counter++);
     print("producer end");
     ul.unlock();
     cv.notify_all();
     std::this_thread::sleep_for(chrono::seconds(1));
   }
}

int main(){
   thread consumerT {consumer};
   thread producerT {producer};

   consumerT.join();
   producerT.join();
}
