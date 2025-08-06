class Solution {
    vector<int> parent,size;
public:
    int find(int x){
        int root=x;
        while(root!=parent[root]){
            root=parent[root];
        }

        while(x!=root){
            int next=parent[x];
            parent[x]=root;
            x=root;
        }

        return root;
    }

    void Union(int u,int v){
        int up_u=find(u);
        int up_v=find(v);

        if(up_u==up_v) return;

        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }else{
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0;i<edges.size();i++){
            Union(edges[i][0],edges[i][1]);
        }

        if(find(source)==find(destination)){
            return true;
        }else{
            return false;
        }
    }
};