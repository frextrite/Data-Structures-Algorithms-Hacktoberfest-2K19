#include<bits/stdc++.h>
using namespace std;
int main(){
	char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    int M=strlen(pat);
    int N=strlen(txt);
    int i=0,j=0,l=0;
    while(l<N){
    	if(txt[i]==pat[j]){
    		i++;
    		j++;
		}
		else{
			l++;
			i=l;
			j=0;
		}
		if(j==M){
			cout<<i-j<<endl;
		}
	}
}
