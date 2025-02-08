
class dsu{
    private:
    vector<int>parent;
    vector<int> rank;
    int component;
    public:

    dsu(int n){
        parent.resize(n);;
        for(int i = 0 ; i < n ; i++)parent[i]=i;
        rank.resize(n);
        component = n;
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }


    void Union(int u , int v){
        int u_find = find(u);
        int v_find = find(v);

        if(u_find  == v_find) return;

        if(rank[u_find] > rank[v_find]){
            parent[v_find] = u_find;
        }else if(rank[u_find] < rank[v_find]){
            parent[u_find] = v_find;
        }else{
            parent[u_find] = v_find;
            rank[v_find]++;
        }
        component--;
    }
    int numberOfcomponent(){
        return component;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       
        dsu g(n);
        int cnt =0;
        for(auto tt: connections){
            int u = tt[0];
            int v= tt[1];
            if(g.find(u) != g.find(v)){
                g.Union(u,v);
            }else{
                cnt++;
            }
        }
        cout << g.numberOfcomponent()<< " " << cnt << endl;
        if(cnt < g.numberOfcomponent()-1){return -1;}
        return g.numberOfcomponent()-1;
    }
};
