#include <iostream>
#include <algorithm>

using namespace std;
int cointype[100];
int coinchange[10000];
const int INF=1000000000;
void setup(){
    int count, buf;
    cin>>count;
    for(int i=0; i<count;i++){
        cin>>buf;
        cointype[i]=buf;
        coinchange[buf]=1;
    }
}
int change(int money) {
	if(money<0) return INF;
	if(coinchange[money]) return coinchange[money];
	int count=INF;
	for(int i=0; cointype[i];i++){
	    count=min(count, change(money-cointype[i])+1);
	}
	return coinchange[money]=count;
}
int main(){
    int a;
    setup();
    while(cin>>a) cout<<change(a);
}
