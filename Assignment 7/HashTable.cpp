#include "HashTable.hpp"
#include <iostream>
#include <cstdlib>

HashTable::HashTable(int groups) {
    this->groups = groups;
    size = 0;
    storage = new string[groups];
    for (int i = 0; i < groups; i++) {
        storage[i] = "";
    }
}

void HashTable::insertItem(string key, string value) {
    if (size == groups) {
        std::cout << "Table is full" << std::endl;
        return;
    }
    int index = hash(key);
    storage[index] = value;
    size++;
}

string HashTable::removeItem(string key) {
    int index = hash(key);
    string toReturn = storage[index];
    storage[index] = "";
    size--;
    return toReturn;
}

string HashTable::getItem(string key) {
    int index = hash(key);
    return storage[index];
}

int HashTable::hash(string key) {
    // Initial implementation, but I want something simpler so I can design key/values that will collide
    // int sum = 0;
    // for (int i = 0; i < key.length(); i++) {
    //     sum += int(key[i]);
    // }
    // return sum % groups;

    return key.length() % groups;
}

string HashTable::prettyPrint() {
    string result = "\n";
    for (int i = 0; i < groups; i++) {
        result += "\t• " + storage[i] + "\n";
    }
    return result;
}

