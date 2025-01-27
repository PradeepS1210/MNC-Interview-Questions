#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hashMap;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            cache.splice(cache.begin(), cache, hashMap[key]);
            return hashMap[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            hashMap[key]->second = value;
            cache.splice(cache.begin(), cache, hashMap[key]);
        } else {
            if (cache.size() == capacity) {
                hashMap.erase(cache.back().first);
                cache.pop_back();
            }
            cache.emplace_front(key, value);
            hashMap[key] = cache.begin();
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 2);
    cout << cache.get(1) << endl;

    cache.put(2, 3);
    cache.put(1, 5);
    cache.put(4, 5);
    cache.put(6, 7);
    cout << cache.get(4) << endl;
    cache.put(1, 2);
    cout << cache.get(3) << endl;

    return 0;
}
