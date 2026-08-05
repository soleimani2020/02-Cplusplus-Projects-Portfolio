class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        
        sort(people.begin(),people.end());
        int boats = 0 ;
        int light = 0;
        int heavy = n-1;
        
        
        while(light<=heavy){
            if(people[light]+people[heavy] <= limit){
                light++; // Lightest joins heaviest
            }
            
            
            // Heaviest ALWAYS goes 
            heavy--;


            // One boat is used (either for 1 or 2 people)
            boats++;
            
            
            
        }

        
        
        
        
        return boats;
        
        
    }
};
