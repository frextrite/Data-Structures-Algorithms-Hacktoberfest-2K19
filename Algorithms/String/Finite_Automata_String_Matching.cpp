#include<bits/stdc++.h>
using namespace std;
const int characters=256;
int getNextState(char pat[],int M,int i,int x){
	if(i<M && pat[i]==x){
		return i+1;
	}
	for(int j=i;j>0;j--){
		if(pat[j-1]==x){
			int s=0;
			for(s=0;s<j-1;s++){
				if(pat[s]!=pat[i-j+1+s]){
					break;
				}
			}
			if(s==j-1){
				return j;
			}
		}
	}
	return 0;
}
void computefa(char pat[],int M,int fa[][characters]){
	for(int i=0;i<=M;i++){
		for(int ch=0;ch<256;ch++){
			fa[i][ch]=getNextState(pat,M,i,ch);
		}
	}
}
int main() 
{ 
    char txt[]="AABAACAADAABAAABAA";
    char pat[]="ABAA";
    int N=strlen(txt);
    int M=strlen(pat);
    int fa[M+1][characters];
    computefa(pat,M,fa);
    for(int i=0;i<=M;i++){
    	for(int j=0;j<characters;j++){
    		cout<<fa[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	int state=0;
	for(int i=0;i<N;i++){
		state=fa[state][txt[i]];
		if(state==M){
			cout<<i-M+1<<endl;
		}
	}
    return 0;
} 
