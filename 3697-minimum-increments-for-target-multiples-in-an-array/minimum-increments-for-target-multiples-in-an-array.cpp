typedef long long ll;

class Solution {
public:
    ll lcm(ll a, ll b) {  
        return a / __gcd(a, b) * b;  
    }
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        ll k = target.size();
        vector<ll> lcm_subset(1 << k);

       
        for (ll mask = 1; mask < (1 << k); mask++) {
            ll curr_lcm = 1;
            for (ll i = 0; i < k; i++) {
                if (mask & (1 << i)) {
                    curr_lcm = lcm(curr_lcm, target[i]);
                }
            }
            lcm_subset[mask] = curr_lcm;
        }

        vector<ll> dp(1 << k, INT_MAX);
        dp[0] = 0;

        for (ll num : nums) {
            vector<ll> new_dp = dp;  
            for (ll mask = 1; mask < (1 << k); mask++) {
                ll lcm_val = lcm_subset[mask];
                ll remainder = num % lcm_val;
                ll cost = (remainder == 0) ? 0 : (lcm_val - remainder);

                
                for (ll prev_mask = 0; prev_mask < (1 << k); prev_mask++) {
                    if (dp[prev_mask] == INT_MAX) continue;
                    ll new_mask = prev_mask | mask;
                    new_dp[new_mask] = min(new_dp[new_mask], dp[prev_mask] + cost);
                }
            }
            dp = new_dp; 
        }

        return dp[(1 << k) - 1] == INT_MAX ? -1 : dp[(1 << k) - 1];
    }
};
