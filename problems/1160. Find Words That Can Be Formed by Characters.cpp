class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(auto i : chars){
            mp[i]++;
        }
        int sum =0;

        for(auto it : words){
            bool flag = true;
            string a = it;
            unordered_map<char , int> tmp;
            for(auto i : a){
                tmp[i]++;
                if(tmp[i] > mp[i]){
                    flag =false;
                    break;
                }

            }
            if(flag != false) sum += a.size();

        }


        return sum ;

    }
};
