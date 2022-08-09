#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <stdint.h>

#define MAX_KEY 0xFFFFFFFFFFFFF
struct Entry 
{
    uint64_t key : 56;
    uint8_t value;
};

class HashMap
{
    private:
        std::vector<Entry> map;
        unsigned int index(uint64_t key);
        
    public:
        HashMap(int size);
        void put(uint64_t key, uint8_t value);
        int get(uint64_t key);
        void reset(); 
};

#endif