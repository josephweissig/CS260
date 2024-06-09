#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>

using std::string;

class HashTable {
public:
    HashTable(int groups);
    void insertItem(string key, string value);
    string removeItem(string key);
    string getItem(string key);
    int getSize() { return size; }
    string prettyPrint();

private:
    int groups;
    int size;

    string *storage;
    int hash(string key);
};

#endif // HASHTABLE_HPP