#include "ChainedHashTable.hpp"
#include <iostream>

ChainedHashTable::ChainedHashTable(int groups) {
    this->groups = groups;
    size = 0;
    storage = new std::pair<string, string>[groups];
    isOccupied = new bool[groups];
    for (int i = 0; i < groups; i++) {
        storage[i] = std::make_pair("", "");
        isOccupied[i] = false;
    }
}

int ChainedHashTable::hash(string key) {
    return key.length() % groups;
}

void ChainedHashTable::insertItem(string key, string value) {
    if (size == groups) {
        std::cout << "Table is full" << std::endl;
        return;
    }
    int index = hash(key);
    // Here's where the bigger changes are:
    // We check the `isOccupied` array to see if the index is already occupied,
    // and increment the index until we find an empty spot.
    // Remember to take this sum mod groups to ensure we stay within the bounds of the array.
    while (isOccupied[index]) {
        index++;
        index %= groups;
    }
    storage[index] = std::make_pair(key, value);
    isOccupied[index] = true;
    size++;
}

string ChainedHashTable::removeItem(string key) {
    int index = hash(key);
    string toReturn = "";
    // Because the hash doesn't necessarily indicate where in the array the value is stored,
    // we need to compare the key at the index to the key we're looking for,
    // and increment the index until we find the key we're looking for.
    while (storage[index].first != key && isOccupied[index]) {
        index++;
        index %= groups;
    }
    if (storage[index].first == key) {
        toReturn = storage[index].second;
        storage[index] = std::make_pair("", "");
        isOccupied[index] = false;
        size--;
    }
    return toReturn;
}

string ChainedHashTable::getItem(string key) {
    int index = hash(key);
    string toReturn = "";
    // Like we did in `removeItem`, we need to increment the index until we find the key we're looking for.
    while (storage[index].first != key && isOccupied[index]) {
        index++;
        index %= groups;
    }
    if (storage[index].first == key) {
        toReturn = storage[index].second;
    }
    return toReturn;
}

string ChainedHashTable::prettyPrint() {
    string result = "\n";
    for (int i = 0; i < groups; i++) {
        // Here, we can use the `isOccupied` array to determine if the index is occupied,
        // and omit it if it's not.
        if (isOccupied[i]) {
            result += "\t• " + storage[i].first + ": " + storage[i].second + "\n";
        }
    }
    return result;
}