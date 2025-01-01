#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, int> ages;

    // Inserting elements
    ages["Rishab"] = 28;
    ages["Rahul"] = 25;
    ages["Rohit"] = 26;

    ages.insert(std::make_pair("Raj", 30));
    ages.insert({"Hrithik", 27});

    // Lookup
    std::cout << "Persons and their ages: \n";
    for(auto& entry : ages) {
        std::cout << entry.first << " : " << entry.second << '\n';
    }

    // Check if a key exists using find()
    std::string key = "Rahul";
    if(ages.find(key) != ages.end()) {
        std::cout << key << " exists in the map and is " << ages[key] << " years old\n";
    }
    else {
        std::cout << key << " does not exist in the map\n";
    }

    // Checking existence using count()
    std::string ekey = "Hrithik";
    if(ages.count(ekey) > 0) {
        std::cout << ekey << " exists in the map and is " << ages[ekey] << " years old\n";
    }
    else {
        std::cout << ekey << " does not exist in the map\n";
    }

    // Accessing and chaning values using []
    std::cout << "Raj's age before: " << ages["Raj"] << '\n';
    ages["Raj"] = 31;
    std::cout << "Raj's age after: " << ages["Raj"] << '\n';

    // Accessing and chanign values using at()
    std::cout << "Rishab's age before: " << ages.at("Rishab") << '\n';
    ages.at("Rishab") = 29;
    std::cout << "Rishab's age after: " << ages.at("Rishab") << '\n';

    // Searching using [] (Adds a new element if not found)
    std::cout << "Size of map before accessing non-existant key: " << ages.size() << '\n';
    std::string skey = "Rohan";
    std::cout << "Trying to access non-existant key: " << ages[skey] << '\n';
    std::cout << "Size of map after accessing non-existant key: " << ages.size() << '\n';

    // Iteration using iterators
    std::cout << "Persons and their ages using iterators: \n";
    std::unordered_map<std::string, int>::iterator it = ages.begin();
    while(it != ages.end()) {
        std::cout << it->first << " : " << it->second << '\n';
        it++;
    }
    
    // Iteration using auto
    std::cout << "Persons and their ages using auto: \n";
    for(auto& entry : ages) {
        std::cout << entry.first << " : " << entry.second << '\n';
    }

    // Erasing elements
    ages.erase("Raj");

    std::cout << "Current Size of map: " << ages.size() << '\n';

    return 0;
}