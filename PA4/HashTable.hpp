#pragma once
#include <iostream>
#include <list>
using namespace std;


template<typename T>
class HashTable {

private:
	int size; //number of buckets
	list<pair<int,T>> *table; // hash table    
    int hash(const int _key) {
        return _key % size;
    }
public:
    HashTable(const int _size) {
		size = _size;
		table = new list<pair<int,T>>[size];
    }
	
	~HashTable(){
		size = 0;
		for(int i = 0; i < size; i++){
			table[i].clear();
		}
		delete[] table;
	}
    
    void insert(const int _key, T _value) {
		int index = hash(_key);
		table[index].push_back(pair<int, T>(_key, _value));
    }
	
	int minChainLen(){
		int min = table[0].size();
		for(int i = 0; i < size; i++){
			if(table[i].size()< min){
				min = table[i].size();
			}
		}
		return min;
	}
	
	int maxChainLen(){
		int max = table[0].size();
		for(int i = 0; i < size; i++){
			if(table[i].size() > max){
				max = table[i].size();
			}
		}
		return max;
	}
	
	double averageChainLen(){
		double sum = 0;
		for(int i = 0; i < size; i++){
			sum += table[i].size();
		}
		double average = sum/size;
		return average;
	}

	T* search(int _key) {
		int index = hash(_key);
		for(typename list<pair<int,T>>::iterator it = table[index].begin(); it != table[index].end(); it++){
			if(it->first == _key){
				return &(it->second);
			}
		}
		return nullptr;
    }
    
};
