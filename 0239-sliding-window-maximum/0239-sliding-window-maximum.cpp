class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < k; i++){
            pair<int,int> p;
            p.first = nums[i];
            p.second = i;
            pq.push(p);
        }
        ans.push_back(pq.top().first);
        int index = -1;
        // pq = 9,10,9,-7,-4,
        // ans = 10, 

        for(int i = 0; i < n - k; i++){
            while(true){
                int temp = pq.top().first;
                int idx = pq.top().second;
                if(idx <= i){
                    pq.pop();
                } else break;
            }
            int max_temp = pq.top().first; // = 10
            int new_term = nums[i+k]; // = -8
            if(max_temp == nums[i]){
                index = i;
            }
            
            // if(index == i){
            //     pq.pop();
            // }
            pair<int,int> idk;
            idk.first = new_term;
            idk.second = i+k;
            pq.push(idk);
            ans.push_back(pq.top().first);
        }

        return ans;

    }
};