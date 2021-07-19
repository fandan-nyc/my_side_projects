#include <iostream>
#include <list>

using namespace std;
class Container {
public:
    virtual double& operator[] (int) = 0;
    virtual const int getSize() = 0;
    virtual ~Container()  {};
};

class test {
private:
    int i;
public:
    test(int v) {
        i = v;
    };
    
    ~test() {
        cout << "ah test is destructed " << i << endl;
    }
};


class ListContainer : public Container {
private:
    list<double> ld;
    test t;
public:
    ListContainer(): t{0} {};
    ListContainer(std::initializer_list<double> ild): ld{ild}, t{10} {};
    ~ListContainer() {
        std::cout << "clean up ListContainer";
        // the destructor of t is called implicitly by the class destructor
    }
    
    const int getSize(){
        return ld.size();
    }
    
    double& operator[](int i){
        for(auto& x: ld){
            if(i == 0) {
                return x;
            }
            i--;
        }
        throw out_of_range("cannot find, out of range");
    }
};



int main() {
    ListContainer lc {1,2,3,4, 5.5};
    cout << lc.getSize() << std::endl;
    cout << lc[2] << std::endl;
//cout << lc[10] << std::endl;
}
