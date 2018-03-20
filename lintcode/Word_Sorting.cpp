class Solution {
public:
    /**
     * @param alphabet: the new alphabet
     * @param words: the original string array
     * @return: the string array after sorting
     */
    vector<string> wordSort(string &alphabet, vector<string> &words) {
        // Write your code here

        unordered_map<char,int>  m;
        int i = 0;
        for(auto &c : alphabet){
            m[c] = i++;
        }

        sort(words.begin(),words.end(),[&](const string &s1, const string &s2)->bool{
            size_t i = 0;
            for(i = 0; i < min(s1.size(),s2.size()); ++i){
                if(m[s1[i]] < m[s2[i]]){
                    return true;
                }else if(m[s2[i]] < m[s1[i]]){
                    return false;
                }
            }

            if(s1.size() < s2.size()){
                return true;
            }

            return false;
        });

        return words;
    }
};
