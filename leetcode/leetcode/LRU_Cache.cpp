/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include "stdafx.h"
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache{
private:
    int m_capacity;
    struct DataNode {
        int key;
        int value;        
        DataNode(int _key, int _value) : key(_key), value(_value) {}
    };
    list<DataNode> data_list;
    unordered_map<int, list<DataNode>::iterator> data_hash;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        data_list.clear();
        data_hash.clear();
    }
    
    int get(int key) {
        auto it_member = data_hash.find(key);
        if (it_member == data_hash.end()) {
            return -1;
        }
        auto it_value = it_member->second;
        int value = it_value->value;
        
        set(key, value);
        return value;
    }
    
    void set(int key, int value) {                
        data_list.push_front(DataNode(key, value));

        auto it_member = data_hash.find(key);        
        if (it_member == data_hash.end()) {
            data_hash.insert(make_pair(key, data_list.begin()));
            if (data_list.size() > m_capacity) {
                int del_key = data_list.back().key;
                data_hash.erase(del_key);
                data_list.pop_back();
            }
        } else {
            auto it_value = it_member->second;
            data_list.erase(it_value);            
            it_member->second = data_list.begin(); 
        }                   
    }
};
