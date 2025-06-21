class Solution {
  public:
  int pos(vector<string> & v, string a){
      for (int  i= 0; i < v.size(); i++){
          if (v[i] == a) return i;
      }
      return -1;
  }
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        string a  = startWord, b = targetWord;
        if (pos(wordList, b) == -1){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({a, 1});
        if (pos(wordList, a)!=-1) wordList.erase(wordList.begin() + pos(wordList, a));
        while(!q.empty()){
            string current = q.front().first;
            int denomination = q.front().second;
            q.pop();
            for (int i = 0; i < a.length(); i++){
                for(int j = 0; j < 26; j++){
                    string c = current;
                    c[i] = char('a' + j);
                    if (c == b) return denomination+1;
                    if (pos(wordList, c) != -1){
                        wordList.erase(wordList.begin() + pos(wordList, c));
                        q.push({c, denomination+1});
                    }
                }
            }
        }
        return 0;
    }
};