/*question details
name: Stock Price Fluctuation
link: https://leetcode.com/problems/stock-price-fluctuation/
submission link: https://leetcode.com/problems/stock-price-fluctuation/submissions/877890716/
*/

#include<bits/stdc++.h>
using namespace std;

class StockPrice {
private:
    int time;
    map<int, int>stock;
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
public:
    StockPrice() {
        time = 0;
    }
    
    void update(int timestamp, int price) {
        stock[timestamp] = price;
        time = max(time, timestamp);
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }
    
    int current() {
        return stock[time];
    }
    
    int maximum() {
        while(!maxHeap.empty()){
            pair<int, int> x = maxHeap.top();
            if(stock[x.second] == x.first) return x.first;
            maxHeap.pop();
        }
        return -1;
    }
    
    int minimum() {
        while(!minHeap.empty()){
            pair<int, int> x = minHeap.top();
            if(stock[x.second] == x.first) return x.first;
            minHeap.pop();
        }
        return -1;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */