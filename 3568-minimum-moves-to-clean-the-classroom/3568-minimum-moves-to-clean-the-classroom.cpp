class Solution {
public:
   int minMoves(vector<string>& classroom, int energy) {
       int m =  classroom.size(), n = classroom[0].size();
       int startr = 0, startc = 0, litter = 0;
       unordered_map<int, int> littermap;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(classroom[i][j]=='S'){
                   startr = i;
                   startc = j;
               } else if(classroom[i][j]=='L') {
                   littermap[i*n+j]=litter++;
               }
           }
       }
       bool visited[m][n][energy+1][(1<<litter)];
       memset(visited, false, sizeof(visited));
       queue<tuple<int, int, int, int, int>> q;
       q.push({startr, startc, energy, 0, 0});
       visited[startr][startc][energy][0] = true;
       while(!q.empty()){
           auto [r, c, e, l, d] = q.front();


           q.pop();
           if (classroom[r][c]=='L') l|=(1<<littermap[r*n+c]);
           else if (classroom[r][c]=='R') e=energy;
          
           if (l == ((1<<litter)-1)) return d;
           if (e<=0) continue;
          
           if (r+1<m && classroom[r+1][c]!='X' && visited[r+1][c][e-1][l]==false){
               visited[r+1][c][e-1][l]=true;
               q.push({r+1, c, e-1, l, d+1});
           }
           if (c+1<n && classroom[r][c+1]!='X' && visited[r][c+1][e-1][l]==false){
               visited[r][c+1][e-1][l]=true;
               q.push({r, c+1, e-1, l, d+1});
           }
           if (r-1>=0 && classroom[r-1][c]!='X' && visited[r-1][c][e-1][l]==false){
               visited[r-1][c][e-1][l]=true;
               q.push({r-1, c, e-1, l, d+1});
           }
           if (c-1>=0 && classroom[r][c-1]!='X' && visited[r][c-1][e-1][l]==false){
               visited[r][c-1][e-1][l]=true;
               q.push({r, c-1, e-1, l, d+1});
           }           
       }
       return -1;
   }
};
