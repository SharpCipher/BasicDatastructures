int lonelyinteger(vector<int> a) {
    set<int> s;
    for(int i=0; i<a.size(); i++){
        if(s.find(a[i]) != s.end()){
            s.erase(a[i]);
        }
        else{
            s.insert(a[i]);
        }
    }
    set<int>::iterator it = s.begin();
    return *it;
}