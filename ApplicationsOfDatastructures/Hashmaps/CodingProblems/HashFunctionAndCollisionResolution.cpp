#include <iostream>
#include <unordered_map>
#include <string>

struct Key {
    std::string first;
    std::string second;

    // Equality operator
    bool operator==(const Key& other) const {
        return first == other.first && second == other.second;
    }
};

// Hash function for Key
struct KeyHash {
    std::size_t operator()(const Key& k) const {
        std::hash<std::string> hasher1; // Create an instance of the hash functor
        std::size_t hashValue1 = hasher1(k.first); // Call the operator() to compute the hash

        std::hash<std::string> hasher2;
        std::size_t hashValue2 = hasher2(k.second);

        // Combine hashes using a technique that reduces collisions
        return hashValue1^(hashValue2 << 1); // Shift hashValue2 bits to mix
    }
};

int main()
{
    std::unordered_map<Key, int, KeyHash> hashMap;
    hashMap[{"John", "Doe"}] = 42;
    std::cout << "John Doe's age: " << hashMap[{"John", "Doe"}] << '\n';
    return 0;
}