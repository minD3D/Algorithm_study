#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

map<string, int> m;

struct abc {
	int x, y;
	double w, d, l;
} a[6];

int s[4];
double r[4];
pair<int, int> t[4];

void go(int n, double p) {
	if (n == 6) {
		for (int i = 0; i < 4; i++) {
			t[i].fst = s[i];
			t[i].snd = i;
		}
		sort(t, t+4);
		int A = t[0].fst, B = t[1].fst, C = t[2].fst, D = t[3].fst;
		int a = t[0].snd, b = t[1].snd, c = t[2].snd, d = t[3].snd;
		if (B != C) {
			r[c] += p; r[d] += p;
		} else if (A == B && C == D) {
			r[a] += p/2.0; r[b] += p/2.0;
			r[c] += p/2.0; r[d] += p/2.0;
		} else if (A == B) {
			r[a] += p/3.0; r[b] += p/3.0;
			r[c] += p/3.0; r[d] += p;
		} else if (C == D) {
			r[b] += p*2.0/3.0; r[c] += p*2.0/3.0;
			r[d] += p*2.0/3.0;
		} else {
			r[b] += p/2.0; r[c] += p/2.0;
			r[d] += p;
		}
		return;
	}

	int x = a[n].x, y = a[n].y;

	s[x] += 3;
	go(n+1, p*a[n].w);
	s[x] -= 3;

	s[x] += 1; s[y] += 1;
	go(n+1, p*a[n].d);
	s[x] -= 1; s[y] -= 1;

	s[y] += 3;
	go(n+1, p*a[n].l);
	s[y] -= 3;
}

int main() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		m[str] = i;
	}

	for (int i = 0; i < 6; i++) {
		string s1, s2;
		cin >> s1 >> s2 >> a[i].w >> a[i].d >> a[i].l;
		a[i].x = m[s1];
		a[i].y = m[s2];
	}

	go(0, 1.0);

	for (int i = 0; i < 4; i++) {
		printf("%.18lf\n", r[i]);
	}

	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 2005;

int p1[6], p2[6];
float pt[6][3];
float ans[4];

int main(){
	string s[4];
	map<string, int> mp;
	for(int i=0; i<4; i++){
		cin >> s[i];
		mp[s[i]] = i;
	}
	for(int i=0; i<6; i++){
		string a, b;
		double x, y, z;
		cin >> a >> b >> x >> y >> z;
		p1[i] = mp[a];
		p2[i] = mp[b];
		pt[i][0] = x; 
		pt[i][1] = y; 
		pt[i][2] = z; 
	}
	int r[6];
	for(r[0] = 0; r[0] < 3; r[0]++)
	for(r[1] = 0; r[1] < 3; r[1]++)
	for(r[2] = 0; r[2] < 3; r[2]++)
	for(r[3] = 0; r[3] < 3; r[3]++)
	for(r[4] = 0; r[4] < 3; r[4]++)
	for(r[5] = 0; r[5] < 3; r[5]++){
		double prob = 1;
		int sc[4] = {}, p[4] = {0, 1, 2, 3};
		for(int j=0; j<6; j++){
			prob *= pt[j][r[j]];
			if(r[j] == 0) sc[p1[j]] += 3;
			if(r[j] == 1) sc[p1[j]] += 1, sc[p2[j]] += 1;
			if(r[j] == 2) sc[p2[j]] += 3;
		}
		sort(p, p + 4, [&](int x, int y){
			return sc[x] > sc[y];
		});
		if(sc[p[1]] == sc[p[2]]){
			int lop = 1, rip = 2;
			if(sc[p[0]] == sc[p[1]]) lop = 0;
			if(sc[p[2]] == sc[p[3]]) rip = 3;
			for(int j=lop; j<=rip; j++){
				ans[p[j]] += prob * (2 - lop) / (rip - lop + 1);
			}
			for(int j=0; j<lop; j++) ans[p[j]] += prob;
		}
		else{
			ans[p[0]] += prob;
			ans[p[1]] += prob;
		}
	}
	for(int i=0; i<4; i++) printf("%.10f\n", ans[i]);
}