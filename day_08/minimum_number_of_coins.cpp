int findMinimumCoins(int amount)
{
	vector <int> v = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int ind = v.size() - 1;
	int count = 0;
	while (amount > 0) {
		if (amount >= v[ind]) {
			count += amount / v[ind];
			amount = amount % v[ind];
		}
		else {
			ind--;
		}
	}
	return count;

}
