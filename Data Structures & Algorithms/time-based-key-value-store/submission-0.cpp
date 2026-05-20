class TimeMap {
public:
    unordered_map<string,map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
     
    string get(string key, int timestamp) {
        auto it = mp[key];
        auto it1 = it.upper_bound(timestamp);

        if(it1 == it.begin()) return "";
        it1--;
        return it1->second;
    }
};
