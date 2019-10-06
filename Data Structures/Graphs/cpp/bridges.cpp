#include<bits/stdc++.h>
using namespace std;

class bridge
{
public:

    int a;
    int b;
};
class ArticulationPair
{
    public:

    int vert;
    int disc;
    int low;
    bool isAP;
    bool processed;
    int parent=-1;
};
//static int graph[n][n];
//static ArticulationPair result[n];

void DFT(int time,int currv,int **graph,ArticulationPair *result[],int n,vector<bridge> &bv)
{
    result[currv]->processed=true;
    result[currv]->disc=result[currv]->low=time;

    int rootChildCounter=0;

    for(int i=0;i<n;i++)
    {
        if(graph[currv][i]!=1)
        {
            continue;
        }

        if(result[i]->processed==false)
        {
       //     rootChildCounter++;
            result[i]->parent=currv;
            DFT(time+1,i,graph,result,n,bv);
            result[currv]->low=min(result[currv]->low,result[i]->low);


                if(result[currv]->disc<result[i]->low)
                {
                    //result[currv]->isAP=true;
                    bridge br;
                    br.a=currv;
                    br.b=i;
                    bv.push_back(br);

                }



        }
        else if(result[currv]->parent!=i)
        {
            result[currv]->low=min(result[currv]->low,result[i]->disc);
        }

    }

}

int main()
{
    int n,m;
    cin>>n;
    cin>>m;

    int **graph=new int*[n];
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
    }
    ArticulationPair *result[n];

    vector<bridge> bv;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x;
        cin>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }

    for(int i=0;i<n;i++)
    {
        result[i]=new ArticulationPair;
        result[i]->vert=i;
    }

    for(int i=0;i<n;i++)
    {
        if(result[i]->processed==true){
            continue;
        }
        DFT(0,i,graph,result,n,bv);
    }

    vector<int> ap;
   for(int i=0;i<n;i++)
    {
        //cout<<result[i]->vert<<" --> "<<result[i]->isAP<<endl;
        if(result[i]->isAP==true)
        {
            ap.push_back(result[i]->vert);
        }
    }

  //  for(int i=0;i<ap.size();i++){
   //     cout<<ap.at(i);
   // }
   // cout<<result[0]->isAP;

    vector<bridge>::iterator vi;
    for(vi=bv.begin();vi!=bv.end();vi++)
    {
        cout<<(*vi).a<<"--"<<(*vi).b<<endl;
    }


    return 0;
}
