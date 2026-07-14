class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>isvisited(n,0);
        vector<int> indegree(n, 0);
      int node=0;
     for (int i = 0; i < n; i++) {
              if (leftChild[i] != -1)
                     indegree[leftChild[i]]++;
           if (rightChild[i] != -1)
                     indegree[rightChild[i]]++;
     }
     for(int i=0;i<n;i++){
        if(indegree[i]>1) return false;
        else if(indegree[i]==0){
            node=i;
            break;
        }
     }
        queue<int>q;
        q.push(node);
        isvisited[node]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(leftChild[top]!=-1) {
                int lc=leftChild[top];
                if(isvisited[lc]!=1){
                   isvisited[lc]=1;
                   q.push(lc);
                }
                else return false;
            }
            if(rightChild[top]!=-1){
                int rc=rightChild[top];
                if(isvisited[rc]!=1){
                    isvisited[rc]=1;
                    q.push(rc);
                }
                else return false;
            }
        }

        for(int i=0;i<n;i++){
            if(isvisited[i]==0) return false;
        }


        return true;
    }
};