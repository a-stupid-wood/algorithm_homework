class Solution {
    //线段树节点存储区间高度的最大值
    int nodemax[100005];
    //当必须用到某个区间节点的时候，判断是否需要进行更新区间子区间的nodemax值
    int lazymark[100005];
public:
    //构建线段树
    void build(int root,int l,int r){
        if(l==r){
            nodemax[root]=0;
            lazymark[root]=0;
            return ;
        }
        int mid=(r-l)/2+l;
        build(root<<1,l,mid);
        build(root<<1|1,mid+1,r);
        nodemax[root]=max(nodemax[root<<1],nodemax[root<<1|1]);
    }
    //更新需要用到的区间的子区间的nodemax值
    void releaselazy(int root){
        lazymark[root<<1]=max(lazymark[root<<1],lazymark[root]);
        lazymark[root<<1|1]=max(lazymark[root<<1|1],lazymark[root]);
        nodemax[root<<1]=max(nodemax[root<<1],lazymark[root<<1]);
        nodemax[root<<1|1]=max(nodemax[root<<1|1],lazymark[root<<1|1]);
        //更新后，去掉标记
        lazymark[root]=0;
        return ;
    }
    int query(int root,int l, int r,int ql,int qr){
        if(qr<l||ql>r){
            return 0;
        }
        if(ql<=l&&r<=qr){
            return nodemax[root];
        }
        //更新查询到的区间的子区间的nodemax
        if(lazymark[root]){
            releaselazy(root);
        }
        int mid=(r-l)/2+l;
        if(qr<=mid){
            return query(root<<1,l,mid,ql,qr);
        }
        else if(ql>mid){
            return query(root<<1|1,mid+1,r,ql,qr);
        }
        else{
            return max(query(root<<1,l,mid,ql,qr),query(root<<1|1,mid+1,r,ql,qr));
        }
    }
    void updatesegtree(int root,int l,int r,int ql,int qr,int val){
        if(qr<l||r<ql){
            return ;
        }
        if(ql<=l&&r<=qr){
            nodemax[root]=max(nodemax[root],val);
            //设置延迟标记
            lazymark[root]=max(lazymark[root],val);
            return ;
        }
        if(lazymark[root]){
            releaselazy(root);
        }
        int mid=(r-l)/2+l;
        updatesegtree(root<<1,l,mid,ql,qr,val);
        updatesegtree(root<<1|1,mid+1,r,ql,qr,val);
        nodemax[root]=max(nodemax[root<<1],nodemax[root<<1|1]);
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int>vcpos;
        for(int i=0;i<positions.size();i++){
            vcpos.push_back(positions[i][0]);
            vcpos.push_back(positions[i][0]+positions[i][1]-1);
        }
        sort(vcpos.begin(),vcpos.end());
        vcpos.erase(unique(vcpos.begin(),vcpos.end()),vcpos.end());
        int len=vcpos.size();
        unordered_map<int,int>ump;
        for(int i=0;i<len;i++){
            ump[vcpos[i]]=i;
        }
        build(1,0,len-1);
        vector<int>ans;
        int maxa=0;
        for(int i=0;i<positions.size();i++){
            int start=positions[i][0];
            int end=positions[i][0]+positions[i][1]-1;
            int startindex=ump[start];
            int endindex=ump[end];
            int ansnum=query(1,0,len-1,startindex,endindex);
            maxa=max(ansnum+positions[i][1],maxa);
            ans.push_back(maxa);
            updatesegtree(1,0,len-1,startindex,endindex,ansnum+positions[i][1]);
        }
        return ans;
    }
};