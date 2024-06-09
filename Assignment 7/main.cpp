#include <iostream>
#include "HashTable.hpp"
#include "ChainedHashTable.hpp"

using std::cout;
using std::endl;

int main() {
    HashTable table(10);
    cout << "HASHTABLE" << endl;
    cout << "Empty table: " << table.prettyPrint() << endl;
    cout << "Size of the empty table: " << table.getSize() << endl;

    table.insertItem("key", "this is the first value");
    table.insertItem("another key", "this is the second value");
    table.insertItem("oof", "this is the third value, it collides with the first key!");

    cout << "Table after inserting three items: " << table.prettyPrint() << endl;
    cout << "Size of the table after inserting three items: " << table.getSize() << endl;

    cout << "Let's try removing the second item." << endl;
    table.removeItem("another key");
    cout << "Table after removing the second item: " << table.prettyPrint() << endl;

    ChainedHashTable chainedTable(10);
    cout << endl << "CHAINED HASHTABLE" << endl;
    cout << "Empty table: " << chainedTable.prettyPrint() << endl;
    cout << "Size of the empty table: " << chainedTable.getSize() << endl;

    chainedTable.insertItem("key", "this is the first value");
    chainedTable.insertItem("another key", "this is the second value");
    chainedTable.insertItem("oof", "this is the third value, does it collide?");

    cout << "Table after inserting three items: " << chainedTable.prettyPrint() << endl;
    cout << "Size of the table after inserting three items: " << chainedTable.getSize() << endl;

    cout << "Let's try removing the second item." << endl;
    chainedTable.removeItem("another key");
    cout << "Table after removing the second item: " << chainedTable.prettyPrint() << endl;
}