#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    // Custom hash for pair<int,int> for unordered_map
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    
    // (shop, movie) -> price
    unordered_map<pair<int,int>, int, pair_hash> priceMap;
    
    // For each movie -> available shops sorted by (price, shop)
    unordered_map<int, set<pair<int,int>>> available;
    
    // Rented movies sorted by (price, shop, movie)
    set<tuple<int,int,int>> rented;
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[{shop, movie}] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            int count = 0;
            for (auto it = available[movie].begin(); it != available[movie].end() && count < 5; ++it, ++count) {
                res.push_back(it->second);
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; ++it, ++count) {
            int shop = get<1>(*it);
            int movie = get<2>(*it);
            res.push_back({shop, movie});
        }
        return res;
    }
};
