class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       
        if(score.empty())
            return {};
           
        unordered_map<int,string> mp;  // score → rank.
       
        vector<int> sortedScore = score;
        sort(sortedScore.rbegin(),sortedScore.rend());
       
        for(int i=0 ; i< sortedScore.size(); i++){
            if(i==0) mp[sortedScore[i]]="Gold Medal";
            else if(i==1) mp[sortedScore[i]]="Silver Medal";
            else if(i==2) mp[sortedScore[i]]="Bronze Medal";
            else mp[sortedScore[i]] = to_string(i + 1);
        }
       
        vector<string> result(score.size(),"");
       
        for(int i =0; i<result.size() ; i++){
            result[i]=mp[score[i]];
        }
       
        return result;
       
    }
};
