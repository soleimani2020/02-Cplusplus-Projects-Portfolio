class Solution{
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids){
        
        stack<int> st;
        
        for(int asteroid: asteroids){
            // Collision is possible only when:
            // current asteroid moves left (asteroid < 0 )
            // AND stack top moves right (st.top() > 0)
            while(!st.empty()  && asteroid < 0 && st.top() > 0){
                // Calculate which asteroid is larger
                int diff = asteroid + st.top();
                if(diff < 0){
                    // Current asteroid is larger
                    // Stack asteroid explodes
                    st.pop();
                }else if(diff > 0){
                    // Current asteroid is smaller
                    // Stack asteroid is larger
                    // Current asteroid explodes
                    asteroid =0;
                }else if(diff == 0){
                    // Both asteroids have the same size
                    // Both explode
                    asteroid =0;
                    st.pop();
                }
            }
            
            // If current asteroid survived, add it to stack
            if(asteroid != 0){
                st.push(asteroid);
            }
        }
        
        // Convert stack to vector
        vector<int> result(st.size());
        
        // Stack gives elements in reverse order
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
        
    }
    

}; // End of the class 
