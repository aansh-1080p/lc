struct Node{
    char pref,suff;
    int ans,prefLen,suffLen,count;
    Node() : pref('#'),suff('#'),ans(0),prefLen(0),suffLen(0),count(0) {}
};
class SegmentTree{
    private:
    vector<Node>seg;
    int size;
    public:
    SegmentTree(int n){
        size = 1;
        while(size < n) size *= 2;
        seg.resize(4*n,Node());
    }
    Node merge(Node &left,Node &right){ 
        if(right.count==0)return left;
        Node res; 
        res.ans = max({left.ans,right.ans,(left.suff==right.pref?left.suffLen+right.prefLen:0)});
        res.count = left.count + right.count;
        res.suff = right.suff;
        res.pref = left.pref;
        res.suffLen = right.suffLen + (right.suffLen==right.count?(right.suff==left.suff?left.suffLen:0):0);
        res.prefLen = left.prefLen + (left.prefLen==left.count?(left.pref==right.pref?right.prefLen:0):0);
        return res;
    }
    void build(int index,int lx,int rx,string &s){
        if(rx-lx==1){
            if(lx<s.size()){
                seg[index].pref = s[lx];
                seg[index].suff = s[lx];
                seg[index].ans = 1;
                seg[index].prefLen = 1;
                seg[index].suffLen = 1;
                seg[index].count = 1;
            }
            return;
        }
        int mid = (lx + rx)/2;
        build(2*index+1,lx,mid,s);
        build(2*index+2,mid,rx,s);
        seg[index] = merge(seg[2*index+1],seg[2*index+2]);
    }
    void build(string &s){
        build(0,0,size,s);
    }
    void update(int index,int lx,int rx,int l,char c){
        if(rx - lx == 1){
            seg[index].pref = c;
            seg[index].suff = c;
            seg[index].ans = 1;
            seg[index].prefLen = 1;
            seg[index].suffLen = 1;
            seg[index].count = 1;
            return;
        }
        int mid = (lx + rx) / 2;
        if(l < mid)update(2*index+1,lx,mid,l,c);
        else update(2*index+2,mid,rx,l,c);
        seg[index] = merge(seg[2*index+1],seg[2*index+2]);
    }
    void update(int l,char c){
        update(0,0,size,l,c);
    }
    int get_top(){
        return seg[0].ans;
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size(),m = queryCharacters.size();
        vector<int>ans(m);
        SegmentTree sg(n);
        sg.build(s);
        for(int i=0;i<m;i++){
            sg.update(queryIndices[i],queryCharacters[i]);
            ans[i] = sg.get_top();
        }
        return ans;
    }
};