class ThroneInheritance {
public:

    string rootPerson;
    set<string> dead;
    map<string, vector<string>> tree;
    map<string, bool> vis;
    vector<string> inheritanceOrder;
    bool flag = false;

    ThroneInheritance(string kingName) {
        rootPerson = kingName;
    }
    
    void birth(string parentName, string childName) {
        tree[parentName].push_back(childName);
        tree[childName].push_back(parentName);
        flag = false;
        vis.clear();
        inheritanceOrder.clear();
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        if(!flag)
            dfs(rootPerson);
        
        vector<string> temp;

        for(string name: inheritanceOrder)
        {
            if(dead.find(name) == dead.end())
                temp.push_back(name);
        }

        return temp;
    }

    void dfs(string name)
    {
        if(vis[name])
            return;
        else
        {
            vis[name] = true;
            inheritanceOrder.push_back(name);

            for(string child: tree[name])
                dfs(child);
        }
    }
};

