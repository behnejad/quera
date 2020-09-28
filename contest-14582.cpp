#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
int const M=3e5+10;
map<string,int>has;
pair<string,int>ans[M];
string x[M];
bool cmp(string xx,string y)
{
	int t1=xx.size(),t2=y.size();
	for(int i=0;i<min(t1,t2);i++)
	{
		if(xx[i]!=y[i])return xx[i]<y[i];
	}
	return xx.size()<y.size();
}
int main()
{
	int n,q;
	cin>>n>>q;
	string now;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		int k,p;
		cin>>k>>p;
		for(int j=1;j<=k;j++)
		{
			cin>>x[j];
		}
		now="";
		for(int j=1;j<=k;j++)
		{
			for(int l=0;l<x[j].size();l++)now+=x[j][l];
			now+='*';
			string tmp="";;
			for(int t=j+1;t<=k;t++)
			{
				for(int l=0;l<x[t].size();l++)tmp+=x[t][l];
				tmp+=' ';
			}
			if(!has[now]){
				has[now]=cnt++;
				ans[has[now]]=mp(tmp,p);
			}
			else
			{
				if(p>ans[has[now]].S)ans[has[now]]=mp(tmp,p);
				else if(p==ans[has[now]].S && tmp<ans[has[now]].F)ans[has[now]]=mp(tmp,p);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int k;
		cin>>k;
		string now="";
		for(int j=0;j<k;j++)
		{
			string t;
			cin>>t;
			for(int l=0;l<t.size();l++)now+=t[l];
			now+='*';
			cout<<t<<" ";
		}
		if(has[now])
			cout<<ans[has[now]].F;
		cout<<'\n';
	}
}