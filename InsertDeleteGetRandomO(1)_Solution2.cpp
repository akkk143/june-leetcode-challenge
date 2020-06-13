class RandomizedSet {
    map<int,int> hash;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(hash.find(val)!=hash.end())
        {
            return false;
        }
        else
        {
            v.push_back(val);
            int vsize = v.size();
            hash[val]= vsize-1;
            return true;
        }
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(hash.find(val)==hash.end())
        {
            return false;
        }
        else
        {
            int last = v.back();
            hash[last]= hash[val];
            v[hash[val]]= last;
            v.pop_back();
            hash.erase(val);
            return true;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int pos = rand()% v.size();
        return v[pos];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */