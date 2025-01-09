#include <iostream>
#include <string>
using namespace std;

enum OrderType {MARKET, LIMIT, STOP};
enum Type{SELL, BUY};

struct Order{
    Type type;
    OrderType ordertype;
    uint volume;
    float price;
    int status;
};


class OrderBook{
    private:
        unordered_map<string, Order> orders;
    protected:
        int* Market_(Order ord_){
            return nullptr;
        }
        int* Limit_(Order ord_){
            return nullptr;
        }
        int* Stop_(Order ord_){
            return nullptr;
        }
    public: 
        OrderBook(){}

        bool AddOrder(Order order_, string name){
            try{
                orders[name] = order_;
            } catch (exception){
                return false;
            }
            return true;

        }

        bool AddOrder_s(Order* order_, string* name){
            return true;
        }

        string Status(string name){
            if(orders.find(name) != orders.end()){
                string order;
                switch(orders[name].ordertype){case MARKET: order="MARKET";break;case LIMIT: order="LIMIT";break;case STOP: order="STOP";}
                return name+" ["+order+" "+to_string(orders[name].status) + " "+to_string(orders[name].price)+" "+to_string(orders[name].volume) + "]";
            }
            return "Order Not Found";
        }

        int* Sell(string name){
            return nullptr;
        }

        int* Buy(string name){
            return nullptr;
        }


};


int main(){
    OrderBook orderbook;
    Order myOrder = {BUY, MARKET, 10, 20.00, 0};
    orderbook.AddOrder(myOrder, "Warren Lazarraga");
    cout << orderbook.Status("Warren Lazarraga");
    return 0;
}