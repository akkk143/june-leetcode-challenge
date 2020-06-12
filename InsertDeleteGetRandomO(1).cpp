class RandomizedSet {
    unordered_map<int,list<int>::iterator> Map;
    list<int> List;
    int listSize;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        listSize = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(Map.find(val)!=Map.end())
        {
            return false;
        }
        else
        {
            list<int> ::iterator it;
            List.push_back(val);
            it = List.end();it--;
            Map[val] = it;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(Map.find(val)==Map.end())
        {
            return false;
        }
        else
        {
            List.erase(Map[val]);
            Map.erase(val);
            return true;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {

        listSize = List.size();
        int pos = rand()% (listSize);
        list<int> ::iterator it;
        it = List.begin();
        std::advance(it, pos);
        return *it;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */