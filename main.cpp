#include <iostream>
#include <string>
using namespace std;

enum OrderType {MARKET, LIMIT, STOP};

struct Order{
    OrderType type;
    uint volume;
    float price;
    int status;
};


class OrderBook{
    private:
        unordered_map<string, Order> orders;
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

        string status(string name){
            if(orders.find(name) != orders.end()){
                string order;
                switch(orders[name].type){case MARKET: order="MARKET";break;case LIMIT: order="LIMIT";break;case STOP: order="STOP";}
                return name+" ["+order+" "+to_string(orders[name].status) + " "+to_string(orders[name].price)+" "+to_string(orders[name].volume) + "]";
            }
            return "Order Not Found";
        }
};


int main(){
    OrderBook orderbook;
    Order myOrder = {MARKET, 10, 20.00, 0};
    orderbook.AddOrder(myOrder, "Warren Lazarraga");
    cout << orderbook.status("Warren Lazarraga");
    return 0;
}