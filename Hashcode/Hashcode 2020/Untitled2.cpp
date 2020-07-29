#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
//typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);
#define debug(a) cout<<#a<<" --> "<<(a)<<endl;
#define fastInput ios_base::sync_with_stdio(false);cin.tie(0)
#define INPUT freopen("f_libraries_of_the_world.txt","r",stdin)
#define OUTPUT freopen("output6.txt","w",stdout)
#define Error  1e-9
#define pi (2*acos(0))
//const ll mod =1e9 +7;
const int N = 1e5 +5;
unsigned seed = 7;
int books,lib,days;
vector<int>book_values;
vector<bool>taken(N);
struct info
{
    int id, n, tim, per_day_shift,total;
    vector<int>has;
};

struct ansinfo
{
    int id ;
    vector<int>bookstoscan;
};
vector<info>libinfo;
vector<ansinfo>ans;
int max_score = -1;
bool comp1(int a, int b)
{
    return book_values[a]>book_values[b];
}
bool comp2(info &a, info &b)
{
    if(a.tim == b.tim)
    {
        if( a.total == b.total)
            return a.n > b.n;
        return a.total>b.total;
    }
    return a.tim< b.tim;
}
bool comp3( info &a, info &b)
{
    return a.per_day_shift < b.per_day_shift;
}
void Print()
{
    for(info v:libinfo)
    {
        cout<<v.n<<" "<<v.tim<<" "<<v.per_day_shift<<endl;
        cout<<v.has<<endl;
    }
}
void Print_ans()
{
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].id<<" "<<ans[i].bookstoscan.size()<<endl;
        for(int j:ans[i].bookstoscan)
        {
            cout<<j<<" ";
        }
        if(ans[i].bookstoscan.size())
            cout<<endl;
    }
}
vector<bool>lib_taken;
void problem_solve(vector<info>&v)
{
    taken.assign(books,false);
    lib_taken.assign()
    vector<ansinfo>tmpans;
    int now = 0;
    int score =0;
    for(int i=0; i<v.size(); i++)
    {

        ansinfo xx;
        int now_id = v[i].id;
        xx.id = now_id;
        if(now+v[i].tim>= days)
        {
            continue;
        }
        now+= v[i].tim;
        int niteparbo = ((days - now )*v[i].per_day_shift);
        int cnt =0;
        for(int j:v[i].has)
        {
            if(taken[j])
                continue;
            score+= book_values[j];
            taken[j]= true;
            xx.bookstoscan.push_back(j);
            cnt++;
            if(cnt==niteparbo)
                break;
        }
        if(xx.bookstoscan.size())
            tmpans.push_back(xx);
        else
        {
            now-= v[i].tim;
        }
    }
    if(score>max_score)
    {
        max_score = score;
        swap(ans,tmpans);
    }
}

void Solve(int cas)
{
    //int sum =0;
    cin>>books>>lib>>days;
    book_values.resize(books);
    libinfo.resize(lib);
    for(int &i:book_values)
    {

        cin>>i;
        //sum+=i;
    }
    for(int i=0; i<lib; i++)
    {
        int sum =0;
        libinfo[i].id = i;
        cin>>libinfo[i].n>>libinfo[i].tim>>libinfo[i].per_day_shift;
        vector<int>tmp(libinfo[i].n);
        for(int &j:tmp)
        {
            cin>>j;
            sum+=j;
        }
        libinfo[i].total = sum;
        sort(tmp.begin(),tmp.end(),comp1);
        libinfo[i].has = tmp;
    }
    sort(libinfo.begin(),libinfo.end(),comp2);
    int koto= 1e5;
    for(int i=0; i<koto; i++)
    {
        //Print();
        problem_solve(libinfo);
        shuffle(libinfo.begin(), libinfo.end(), default_random_engine(seed));
    }
    sort(libinfo.begin(),libinfo.end(),comp3);
    problem_solve(libinfo);
    debug(max_score);
    Print_ans();



}



int main()
{

    INPUT;
    OUTPUT;
    int t=1,cas=0;
    //scanf("%d",&t);
    while(t--)
    {
        Solve(++cas);
    }
    return 0;
}
/*

*/



template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}
