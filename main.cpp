#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

enum OrderType {MARKET, LIMIT, STOP};
enum Type{SELL, BUY};

struct Order{
    string name;
    Type type;
    OrderType ordertype;
    uint volume;
    float price;
    int status;
};


class OrderBook{
    private:
        std::unordered_map<int, Order> orders_Asks;
        std::unordered_map<int, Order> orders_Bids;
        std::unordered_map<Type, std::string> TypeToString;
        std::unordered_map<OrderType, std::string> OrderTypeToString;
        int id;
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
        OrderBook(int start)
        : id(start),
        TypeToString({ { SELL, "SELL" }, { BUY, "BUY" } }),
        OrderTypeToString({{ MARKET, "MARKET" }, { LIMIT, "LIMIT" }, {STOP, "STOP"}}){}

        int AddOrder(Order order_){
            try{
                if(order_.type == SELL){
                    orders_Asks[id] = order_;
                }
                if(order_.type == BUY){
                    orders_Bids[id] = order_;
                }
            } catch (exception){
                return -1;
            }
            return id++;
            
        }

        bool AddOrder_s(Order* order_, int*id, int size){
            for(int i = 0; i < size; i++){
                AddOrder(order_[i]);
            }
            return true;
        }

        Order* Status(int id){
            if(orders_Asks.find(id) != orders_Asks.end() || orders_Bids.find(id) != orders_Bids.end()){
                Order orders = orders_Bids.find(id) != orders_Asks.end() ? orders_Asks[id] : orders_Bids[id];
                std::string order;
                std::string type;
            }
        }
        std::string printBook(){
        }

        std::string OrdertoString(Order order_){
            return 
            order_.name + TypeToString[order_.type] + " " +
            OrderTypeToString[order_.ordertype] + " " +
            std::to_string(order_.volume) + " " +
            std::to_string(order_.price) + " " +
            std::to_string(order_.status);
        }
        int* Sell(int id){
            return nullptr;
        }

        int* Buy(int id){
            return nullptr;
        }


};


int main(){
    OrderBook orderbook(0);
    Order myOrder = {"Warren", BUY, MARKET, 10, 20.00, 0};
    cout << orderbook.OrdertoString(myOrder)<< std::newline;
    return 0;
}
