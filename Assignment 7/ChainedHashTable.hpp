#ifndef CHAINEDHASHTABLE_HPP
#define CHAINEDHASHTABLE_HPP

#include <string>

using std::string;

class ChainedHashTable {
public:
    ChainedHashTable(int groups);
    void insertItem(string key, string value);
    string removeItem(string key);
    string getItem(string key);
    int getSize() { return size; }
    string prettyPrint();
private:
    int groups;
    int size;

    // If we want more functionality, we need more complex data types.
    // Here, we use a pair of strings to store the key and value instead of just relying on the hash value to index a simple array.
    std::pair<string, string> *storage;
    bool *isOccupied;
    int hash(string key);
};

#endif // CHAINEDHASHTABLE_HPP