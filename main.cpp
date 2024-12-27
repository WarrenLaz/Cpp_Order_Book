#include <iostream>
#include <string>
using namespace std;

enum OrderType { SELL, BUY };

//class Book {
//    public: 
//        int[]
//};

class List{
    public:
        size_t capacity;
        size_t size;
        int* value;
        

        List(){
            capacity = 1;
            size = 0;
            value[capacity];
        }

        void push(int value){

        }
};


int main(){
    List newlist = List();

    cout << newlist.value;
    
    return 0;
}