class Solution {
public:
    bool find(int i, int j, vector<vector<char>>&board, string &word, int wordInd, vector<vector<int>> &vis)
    {
        if(wordInd >= word.size()) return true;
        if(i<0 or i >= board.size() or j < 0 or j >= board[0].size() or vis[i][j]) return false;
        bool flag = false;
        if(word[wordInd] == board[i][j]){
            vis[i][j] = 1;
            if(find(i+1,j,board,word,wordInd+1,vis)) return true;
            if(find(i-1,j,board,word,wordInd+1,vis)) return true;
            if(find(i,j+1,board,word,wordInd+1,vis)) return true;
            if(find(i,j-1,board,word,wordInd+1,vis)) return true;
            vis[i][j] = 0;
        }
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
                if(find(i,j,board,word,0,vis))
                return true;
            }
        }
        return false;
    }
};
