#include <iostream>
using namespace std;
const double eps=1e-8;
int main() {
	int vp,vd,t,f,c;
    cin>>vp>>vd>>t>>f>>c;
	if (vp>=vd){
		cout<<0<<"\n";
		return 0;
	}
	int ans=0;
	double pos=t*vp;
	while (pos+eps<c){
		double time=pos/(double)(vd-vp);
		double meet=time*vd;
		if (meet+eps>=c) break;
        ans++;
        pos+=time*2.0*vp+f*vp;
	}
	cout<<ans<<endl;
}
