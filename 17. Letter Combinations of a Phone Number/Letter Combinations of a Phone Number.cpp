class Solution {
public:
    const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
    "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    //string keyboard[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};
        vector<string> res;
        DFS(digits, 0, "", res);
        return res;
        
    }
    void DFS(string& digits, int cur, string path, vector<string>& res){
        if(cur == digits.size()){
            res.push_back(path);
            return;
        }
        string key = keyboard[digits[cur] - '0'];
        for(int i = 0; i < key.size(); i++){
            DFS(digits, cur + 1, path + key[i], res);
        }
    }
};
class Solution {
public:
    
    
    vector<string> letterCombinations(string digits) {
        string keyboard[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.empty()) return {};
        vector<string> res{""};
        for(int i = 0; i < digits.size(); i++){
            vector<string> t;
            string key = keyboard[digits[i] - '0'];
            for(int j = 0; j < key.size(); j++){
                for(string s : res){
                    t.push_back(s + key[j]);
                }
            }
            res = t;
            
        }
       
        return res;
        
    }
   
};
