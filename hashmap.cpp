#include <cassert>
#include <vector>
#include <cstring>
#include "hashmap.hpp"

HashMap::HashMap(int size): map(size)
{
    assert(size > 0);
}

unsigned int HashMap::index(uint64_t key)
{
    return key%map.size();
}

void HashMap::put(uint64_t key, uint8_t value) 
{
    assert(key < MAX_KEY);
    unsigned int i = index(key);
    map[i].key = key;
    map[i].value = value;
}

int HashMap::get(uint64_t key)
{
    assert(key < MAX_KEY);
    unsigned int i = index(key);
    if(map[i].key == key) 
      return map[i].value;
    else 
      return 0;
}

void HashMap::reset() 
{
    memset(&map[0], 0, map.size()*sizeof(Entry));
}