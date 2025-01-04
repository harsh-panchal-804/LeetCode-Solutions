class Solution
{
	public:
		vector<vector < int>> filter(vector<vector < int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
		{
			vector<vector < int>> temp;
			for (auto it: restaurants)
			{
				if (veganFriendly == 0)
				{
					if (it[3] <= maxPrice && it[4] <= maxDistance)
					{
						temp.push_back(it);
					}
				}
				else if (veganFriendly == 1)
				{
					if (it[2] == 1 && it[3] <= maxPrice && it[4] <= maxDistance)
					{
						temp.push_back(it);
					}
				}
			}

			return temp;
		}

	bool static comp(vector<int> &a, vector<int> &b)
	{
		if (a[1] == b[1])
		{
			return a[0] > b[0];
		}

		return a[1] > b[1];
	}

	vector<int> filterRestaurants(vector<vector < int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
	{
		vector<vector < int>> ans = filter(restaurants, veganFriendly, maxPrice, maxDistance);
		sort(ans.begin(), ans.end(), comp);
		vector<int> res;
		for (auto it: ans)
		{
			res.push_back(it[0]);
		}

		return res;
	}
};