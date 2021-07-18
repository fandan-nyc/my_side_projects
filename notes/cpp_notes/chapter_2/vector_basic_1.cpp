#include <iostream>

using namespace std;
struct Vector {
    int size ; 
    double* data;
};

void vector_init(const int size, Vector& v) {
    v.data = new double[size];
    v.size = size;
}

void read_and_sum(const int s) {
    Vector v ;
    vector_init(s, v);
    for(int i = 0; i < s; i++){
        cin >> v.data[i];
    }
    double sum {0};
    for(int i = 0; i < s; i++){
        sum += v.data[i];
    }
    cout << sum;
}

int main(){
    
    read_and_sum(5);
}
