#include<bits/stdc++.h>
using namespace std;
static int flow=0;
static int minCapacity=INT_MAX;
/*
    static map<string,map<string,int>> dag; //directed  acyclic graph
    static int flow=0;
    static map<string,bool> processed;
    static int minCapacity=INT_MAX;
*/
int hasPath(string v1name,string v2name,int mCap,map<string,map<string,int> > &dag,map<string,bool> &processed)
{
    processed[v1name]=true;

    if(v1name==v2name)
    {
        flow+=mCap;
        return mCap;
    }

    map<string,int> nbrs=dag[v1name];
    map<string,int>::iterator mi;
    map<string,int>::iterator mi2;
    for(mi=nbrs.begin();mi!=nbrs.end();mi++){
       // cout<<mi->first<<mi->second;
    }

    for(mi=nbrs.begin();mi!=nbrs.end();mi++)
    {
           // cout<<"test1"<<endl;
     //   mi=mi2;
       // mi2->first=processed.find(mi->first);
       /* if(processed.find(mi->first)!=processed.end()){
            continue;
        }*/
        if(processed.find(mi->first)==processed.end() && dag[v1name][mi->first]>0)
        {


            int cap=dag[v1name][mi->first];
            int revcap=dag[mi->first][v1name];
//cout<<"test2"<<endl;
            int localMCap=hasPath(mi->first,v2name,min(cap,mCap),dag,processed);

            if(localMCap!=-1)
                {
  //                  cout<<"test3"<<endl;
                dag[v1name][mi->first]=cap-localMCap;
                dag[mi->first][v1name]=revcap+localMCap;
                return localMCap;
            }


        }
   //     mi++;
    }

    return -1;
}

int main()
{
    map<string,map<string,int> > dag; //directed  acyclic graph
  //  static int flow=0;
  //  static map<string,bool> processed;


    //vces
    /*dag["S"]=new map<0>;
    dag["A"]=new map;
    dag["B"]=new map;
    dag["C"]=new map;
    dag["D"]=new map;
    dag["T"]=new map;*/

    //edges

    dag["S"]["A"]=10;
    dag["A"]["S"]=0;

    dag["S"]["C"]=8;
    dag["C"]["S"]=0;

    dag["A"]["C"]=2;
    dag["C"]["A"]=0;

    dag["C"]["D"]=10;
    dag["D"]["C"]=0;

    dag["A"]["B"]=5;
    dag["B"]["A"]=0;

    dag["D"]["B"]=8;
    dag["B"]["D"]=0;

    dag["B"]["T"]=7;
    dag["T"]["B"]=0;

    dag["D"]["T"]=10;
    dag["T"]["D"]=0;


    //ford fulkerson
    while(true)
    {
        //processed=new map();
        map<string,bool> processed;
        int localMCap=hasPath("S","T",INT_MAX,dag,processed);
        if(localMCap==-1)
        {
            break;
        }
    }

    cout<<flow;

    return 0;
}
