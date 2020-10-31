class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> midx;
    vector<int> arr;

    /** Initialize your data structure here. */
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        arr.push_back(val);
        midx[val].insert(arr.size() - 1);
        return midx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (midx.find(val) == midx.end()) {
            return false;
        }
        int idx = *(midx[val].begin());
        arr[idx] = arr.back();
        midx[val].erase(idx);
        midx[arr[idx]].erase(arr.size() - 1);
        if (idx < arr.size() - 1) {
            midx[arr[idx]].insert(idx);
        }
        if (midx[val].size() == 0) {
            midx.erase(val);
        }
        arr.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};