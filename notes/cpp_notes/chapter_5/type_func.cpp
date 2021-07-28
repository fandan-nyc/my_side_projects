#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

template<typename T> 
void print(T& t){
    for(auto& i: t){
        cout << i << endl;
    }
    cout << "----" << endl;
}

template<typename Ran>
void sortHelper(Ran begin, Ran end, random_access_iterator_tag){
    sort(begin, end);
}

template<typename For>
void sortHelper(For begin, For end, forward_iterator_tag){
    vector<typename For::value_type> v {begin, end};
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), begin);
}

template<typename T>
void sort(T& t){
    sortHelper(t.begin(), t.end(), typename std::iterator_traits<typename T::iterator>::iterator_category{});
}

int main(){
    vector<int> v {3,2,1,4};
    sort(v);
    print(v);
    
    forward_list<double> tt {1,9.0, 4.2};
    sort(tt);
    print(tt);
}
