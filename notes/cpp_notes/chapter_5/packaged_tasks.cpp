#include <numeric>
#include <future>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

double accumu(double* begin, double* end, double init){
   // sum of [begin, end) starting with init value 
   return accumulate(begin, end, init);
}

template<typename T>
double compute(vector<T> data, int concurrency){
   using Task_type = double(double*, double*, double);
   vector<packaged_task<Task_type>> tasks ;
   vector<future<double>> results;

   for (int i = 0 ; i < concurrency; i++){
      packaged_task<Task_type> pt {accumu};
      tasks.push_back(move(pt));
      results.push_back(tasks.back().get_future());
   }
   
   vector<thread> threads;
   double* start = &data[0];
   double* curr = start;
   for(int i = 0; i < concurrency; i++){
      threads.push_back(thread {move(tasks[i]), curr, curr + data.size()/concurrency, 0.0});
      curr += data.size()/concurrency;
   }
   
   double res = 0.0;
   for(int i = 0; i < concurrency; i++){
      res += results[i].get();
   }
   
   for(auto& t: threads){
      t.join();
   }
   
   cout << res << endl;
}

int main(){
   vector<double> data {1,2,3,4,5,6,7,8,9,10};
   compute(data, 5);
}
