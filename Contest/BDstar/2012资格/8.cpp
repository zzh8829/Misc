#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define MAX 100100  
#define BIG(a,b) ((a)<(b)?(b):(a))  
#define SML(a,b) ((a)>(b)?(b):(a))  
char s[MAX];  
int sag[5][MAX];  
  
int len, *rk, *sa, *h, *hh, *jl;  
int ans[3], rmq[17][MAX], rmq2[17][MAX];  
  
  
int cmp(int i, int j, int k) {  
if(rk[i] - rk[j]) return rk[i] - rk[j];  
i = (i + k >= len ? 0 : rk[i + k]);  
j = (j + k >= len ? 0 : rk[j + k]);  
return i - j;  
}  
  
void suffixArray(char *s) {  
int k, i, j, l, num, *nr, *ns, *rdx, *p;  
rk = sag[0], sa = sag[1], nr = sag[2], ns = sag[3], rdx = sag[4];  
len = strlen(s) + 1;  
memset(rk, 0, sizeof(sag[0]));  
for(i = 0; i < len; ++i) ++rk[s[i]];  
for(i = 1; i < 256; ++i) rk[i] += rk[i - 1];  
for(i = 0; i < len; ++i) sa[--rk[s[i]]] = i;  
for(i = 1, j = rk[sa[0]] = 0; i < len; ++i) {  
   if(s[sa[i]] != s[sa[i - 1]]) ++j;  
   rk[sa[i]] = j;  
}  
for(k = 1; k < len; k <<= 1) {  
   memset(rdx, -1, sizeof(sag[0]));  
   for(i = len - k; i < len; ++i) {  
    nr[i] = rdx[rk[i]];  
    rdx[rk[i]] = i;  
   }  
   for(i = 0; i < len; ++i) {  
    if(sa[i] - k < 0) continue;  
    num = rk[sa[i] - k];  
    nr[sa[i] - k] = rdx[num];  
    rdx[num] = sa[i] - k;  
   }  
   for(i = j, l = len; i >= 0; --i) {  
    for(num = rdx[i]; num != -1; num = nr[num]) ns[--l] = num;  
   }  
   for(i = 1, j = nr[ns[0]] = 0; i < len; ++i) {  
    if(cmp(ns[i], ns[i - 1], k)) ++j;  
    nr[ns[i]] = j;  
   }  
   p = rk; rk = nr; nr = p;  
   p = sa; sa = ns; ns = p;  
}  
  
h = nr; hh = ns;  
  
for(i = 0; i < len; ++i) {  
   rk[sa[i]] = i;  
}  
  
h[len - 1] = 0;  
for(int i = 0, j = 0; i < len - 1; ++i) {  
   while(s[sa[rk[i] - 1] + j] == s[i + j]) ++j;  
   h[i] = j;  
   hh[rk[i]] = j;  
   if(j > 0) --j;  
}  
}  
  
void init() {  
    int i, j, l;  
    for(j = 0; j < len; ++j) {  
        rmq[0][j] = hh[j];  
        rmq2[0][j] = rk[j];  
    }  
    for(i = 2, l = 1; i < len; i <<= 1, ++l) {  
        for(j = 0; j + i / 2 < len; ++j) {  
            if(rmq[l - 1][j + i / 2] < rmq[l - 1][j]) rmq[l][j] = rmq[l - 1][j + i / 2];  
            else rmq[l][j] = rmq[l - 1][j];  
            if(rmq2[l - 1][j + i / 2] < rmq2[l - 1][j]) rmq2[l][j] = rmq2[l - 1][j + i / 2];  
            else rmq2[l][j] = rmq2[l - 1][j];  
        }  
    }  
}  
  
  
int find(int a, int b, int xx[17][MAX] = rmq) {  
    if(a > b) a ^= b ^= a ^= b;  
    if(a == b) return xx[0][a];  
    int i, j, l;  
    i = 1, j = 0, l = b - a;  
    while(i * 2 < l + 1) {  
        i <<= 1;  
        ++j;  
    }  
    return SML(xx[j][a], xx[j][b - i + 1]);  
}  
  
int bf(int a, int b, int c) {  
    int d = b - a;  
    int beg = a - d + 1, end = a, mid;  
    if(beg < 0) beg = 0;  
    while(beg < end) {  
        mid = (beg + end) / 2;  
        if(mid + find(SML(rk[mid], rk[mid + d]) + 1, BIG(rk[mid], rk[mid + d])) == a + c) end = mid;  
        else beg = mid + 1;  
    }  
    return end;  
}  
  
void solve() {  
    int i, j, l, a, b, c;  
suffixArray(s);  
init();  
ans[0] = 1;  
    ans[1] = sa[1];  
    ans[2] = sa[1] + 1;  
  
    for(i = 1; i < len / 2 + 1; ++i) {  
        for(j = 0; j < len - ans[0] * i; j += i) {  
            b = SML(rk[j], rk[j + i]);  
            c = BIG(rk[j], rk[j + i]);  
            a = find(b + 1, c);  
            l = bf(j, j + i, a);  
            b = SML(rk[l], rk[l + i]);  
            c = BIG(rk[l], rk[l + i]);  
            a = find(b + 1, c);  
            if(a >= i) {  
     if(a % i != 0) l = sa[find(l, l + a % i, rmq2)];  
                a -= (a % i);  
                if(a / i + 1 > ans[0] || (a / i + 1 == ans[0] && rk[ans[1]] > rk[l])) {  
                    ans[0] = a / i + 1;  
                    ans[1] = l;  
                    ans[2] = l + a + i;  
                }  
            }  
        }  
    }  
    s[ans[2]] = '\0';  
    puts(&s[ans[1]]);  
      
}  
  
int main() {  
    int tt = 1;  
while(gets(s)) {  
        if(s[0] == '#') break;  
        printf("Case %d: ", tt++);  
   solve();  
}  
return 0;  
}  
