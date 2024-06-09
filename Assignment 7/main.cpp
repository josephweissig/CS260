#include <iostream>
#include "HashTable.hpp"

using std::cout;
using std::endl;

int main() {
    HashTable table(10);
    cout << "Empty table: " << table.prettyPrint() << endl;
    cout << "Size of the empty table: " << table.getSize() << endl;

    table.insertItem("key", "this is the first value");
    table.insertItem("another key", "this is the second value");

    cout << "Table after inserting two items: " << table.prettyPrint() << endl;
    cout << "Size of the table after inserting two items: " << table.getSize() << endl;

    cout << "Let's try removing the second item." << endl;
    table.removeItem("another key");
    cout << "Table after removing the second item: " << table.prettyPrint() << endl;
}