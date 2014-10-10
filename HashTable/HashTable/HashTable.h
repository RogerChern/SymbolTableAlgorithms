//
//  HashTable.h
//  HashTable
//
//  Created by RogerChen on 14-9-10.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef HashTable_HashTable_h
#define HashTable_HashTable_h
#include <array>
using namespace std;

template<typename Comparable, typename Value, size_t SIZE>
class HashTable{
private:
    using key_type   = Comparable;
    using value_type = Value;

private:
    array<value_type, SIZE> hashTable_;
    
private:
    size_t hash(Comparable &&item) const
    {
        
    }
    
    
};

#endif
