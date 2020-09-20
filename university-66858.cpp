#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1510;
int n,k,ans[maxn],deg[maxn*10];

struct point{
    int x,y,ind;
    point(){}
    point(int _x,int _y,int i){
        x=_x;
        y=_y;
        ind=i;
    }
    point operator-(point p){
        return point(x-p.x,y-p.y,-1);
    }

};


int32_t main()
{
    cin>>n>>k;
    vector<point> p(n);
    for(int i=1;i<(1<<k);i++){
        deg[i]=2;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].ind=i;
    }
    sort(p.begin(),p.end(),[](point p1,point p2){
        if(p1.x!=p2.x){
            return p1.x>p2.x;
        }
        return p1.y>p2.y;
    });
    vector<point> v;
    v.push_back(p.back());
    ans[p.back().ind]=1;
    p.pop_back();
    while(v.size()){
        if(deg[ans[v.back().ind]]>0){
            sort(p.begin(),p.end(),[v](point p1,point p2){
                point q1=(p1-v.back());
                point q2=(p2-p1);
                return q1.x*q2.y<q1.y*q2.x;
            });
            deg[ans[v.back().ind]]--;
            ans[p.back().ind]=ans[v.back().ind]*2+deg[ans[v.back().ind]];
            v.push_back(p.back());
            p.pop_back();
        }else{
            v.pop_back();
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
