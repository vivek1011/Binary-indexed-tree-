// spoj - KQUERY
#include<bits/stdc++.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define P(x) printf("%d",x)
#define fl(i , a, b) for(i = a; i<b; i++)
#define MOD 1000000007
#define MAX 1000000010
#define ll long long
#define mp make_pair
#define pb push_back
typedef pair<int,int> pp;
struct s
{	
	int pos, value; 
}a[200003];

struct s1
{
	int pos , l , r,  value; 
}qa[300002];
int ans[300003] , bits[3000002];
int n ;  
/*
get function batata hai ki ek particular index tak ka cumuative sum kitna ayega logn compleity mein  
aur update function bits array me update karta hai logn complexity mein . 

*/
int get(int index)
{
	int c=0 ; 
	while(index>0)
	{	
		c+= bits[index];
		index = (index - (index & -index)); 
	}
	return c; 
}
void update(int index , int value)
{
	while(index<=n)
	{
		bits[index]+= value; 
		index += (index & -index); 
	}
}
bool cmp(struct s1 a, struct s1 b ){
	return a.value>b.value; 
}
bool cmpare(struct s a , struct s b)
{
	return a.value>b.value; 
}
int main()
{
	// std::ios_base::sync_with_stdio(false);
	S(n); 
	int l,r, k ; 
	int i ; 
	fl(i , 0, n)
	{
		S(a[i].value); 
		a[i].pos = i+1; 
	}
	sort(a, a+n , cmpare);

	// offline processing
	
	int q; S(q); 
	fl(i , 0 , q)
	{	
		S(l); S(r); S(k); 
		qa[i].l = l ; 
		qa[i].r = r; 
		qa[i].value = k ; 
		qa[i].pos = i ; 
	}

	sort(qa , qa+q , cmp); 

	int pos = 0 ; 
	fl(i ,0, q)
	{
		while(a[pos].value> qa[i].value){
			update(a[pos].pos ,1 );
			pos++;
		}
		int i1 = qa[i].l ;
		int j1 = qa[i].r; 
		i1 = get(i1-1);
		j1 = get(j1);
		ans[qa[i].pos] = j1-i1;

	}	
	fl(i , 0 , q) printf("%d\n", ans[i]);
	return 0;
}
