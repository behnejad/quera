#include <iostream>
#include <limits>
#include <vector>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
    ll maxplus = numeric_limits<ll>::min(), maxid = 0;
    ll minplus = numeric_limits<ll>::max(), minid = 0;
    ll maxminues = numeric_limits<ll>::min(), maxidm = 0;
    ll minminues = numeric_limits<ll>::max(), minidm = 0;
    vector<pair<ll, ll>> points;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        points.emplace_back(x, y);

        if (x + y > maxplus)
        {
            maxplus = x + y;
			maxid = i;
		}
        else if (x + y < minplus)
        {
            minplus = x + y;
			minid = i;
		}
        if (x - y > maxminues)
        {
            maxminues = x - y;
			maxidm = i;
		}
        else if (x - y < minminues)
        {
            minminues = x - y;
			minidm = i;
		}
	}
    ll a1 = abs(points[maxid].first - points[minid].first) + abs(points[maxid].second - points[minid].second);
    ll a2 = abs(points[maxidm].first - points[minidm].first) + abs(points[maxidm].second - points[minidm].second);
	cout << max(a1, a2);
}
