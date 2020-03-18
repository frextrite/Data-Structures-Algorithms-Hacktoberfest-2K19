#include<bits/stdc++.h>
using namespace std;

void KMPsearch(char txt[],char pat[],int lps[],int M){
	int i=0,j=0;
	int N=strlen(txt);
	while(i<N){
		if(txt[i]!=pat[j]){
			if(j!=0)
                j=lps[j-1];
            else
                i++;
		}
		else if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==M){
			cout<<i-j<<endl;
			j==lps[j-1];
		}
		
	}
}

void computeLPSArray(char pat[],int M,int lps[]){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<M){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len==0){
				lps[i]=0;
				i++;
			}
			else{
				len=lps[len-1];
			}
		}
	}
}

int main() 
{ 
	int M=9;
	int lps[M];
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    computeLPSArray(pat,M,lps);
    for(int i=0;i<M;i++){
    	cout<<lps[i]<<" ";
	}
	cout<<endl;
	KMPsearch(txt,pat,lps,M);
    return 0; 
} 
