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
        unordered_map<string, Order> orders_Asks;
        unordered_map<string, Order> orders_Bids;
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
                if(order_.type == SELL){
                    orders_Asks[name] = order_;
                }
                if(order_.type == BUY){
                    orders_Bids[name] = order_;
                }
            } catch (exception){
                return false;
            }
            return true;

        }

        bool AddOrder_s(Order* order_, string* name, int size){
            for(int i = 0; i < size; i++){
                AddOrder(order_[i], name[i]);
            }
            return true;
        }

        string Status(string name){
            if(orders_Asks.find(name) != orders_Asks.end() || orders_Bids.find(name) != orders_Bids.end()){
                Order orders = orders_Bids.find(name) != orders_Asks.end() ? orders_Asks[name] : orders_Bids[name];
                string order;
                string type;
                switch(orders.ordertype){case MARKET: order="MARKET";break;case LIMIT: order="LIMIT";break;case STOP: order="STOP";}
                type = orders.type == SELL ? "SELL" : "BUY";
                return name+" ["+type+" "+order+" "+to_string(orders.status) + " "+to_string(orders.price)+" "+to_string(orders.volume) + "]";
            }
            return "Order Not Found";
        }

        string printBook(){
            string book = "ASKS\tBIDS\n"
            for(const auto& pair : orders) {
                book += 
            }
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