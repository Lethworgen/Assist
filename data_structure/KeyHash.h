#include <iostream>

static const int TABLE_SIZE = 128;

// Default hash function class
template<typename K>
struct MyKeyHash {
	unsigned long operator()(const University &key) const {
		return key.getHashCode() % 128;
	}
};
