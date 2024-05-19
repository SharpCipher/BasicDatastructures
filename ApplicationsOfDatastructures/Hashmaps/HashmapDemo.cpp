#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    // Create an unordered map with string keys and int values
    std::unordered_map<std::string, int> myMap;

    // Inserting elements into the Hashmap
    myMap["apple"] = 10;
    myMap["banana"] = 20;
    myMap["orange"] = 30;

    // Accessing elements
    std::cout << "Value of apple: " << myMap["apple"] << '\n';

    // Modifying an element
    myMap["apple"] = 15;
    std::cout << "Updated value of apple: " << myMap["apple"] << '\n';

    // Checking if a key exists
    if(myMap.find("banana") != myMap.end()) {
        std::cout << "Found banana\n";
    }

    // Iterating over the elements
    for(const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    // Size of the map
    std::cout << "Size of map: " << myMap.size() << '\n';

    // Deleting an element
    std::cout << "Removed banana\n";
    myMap.erase("banana");

    // Size of the map
    std::cout << "Size of map: " << myMap.size() << '\n';

    return 0;
}