#include <iostream>

using namespace std;

void t(){};

template <typename Head>
void h(Head v){
    cout << v << " ";
}

template <typename Head, typename... Tail>
void t(Head head, Tail... tail){
    h(head);
    t(tail...);
}
int main(){
    t(1,2,3,4,5);
}
