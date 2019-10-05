import java.lang.*;
import java.io.*;

class GFG {
    
    TrieNode root;
    Set<String> answer;
    GFG(){
        root=new TrieNode();
        answer=new TreeSet<>();
    }
    
    static class TrieNode{
        Map<Character,TrieNode> children;
        boolean isEnd;
        TrieNode(){
            children=new HashMap<>();
            isEnd=false;
        }
    }
    
    void insert(String word){
        if(word==null) return;
        TrieNode node=root;
        for(char ch:word.toCharArray()){
            if(node.children.get(ch)==null)
               node.children.put(ch,new TrieNode());
            node=node.children.get(ch);
        }
        node.isEnd=true;
    }
    
    void findWords(char boggle[][], int M, int N){
        boolean vis[][]=new boolean[M][N];
        TrieNode child=root;
        String str="";
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(child.children.get(boggle[i][j])!=null){
                    str+=boggle[i][j];
                    searchWord(child.children.get(boggle[i][j]),
                               boggle,i,j,vis,str);
                    str="";
                }
            }
        }
    }
    
    boolean isSafe(int i, int j, boolean vis[][]){
        return (i>=0 && i<vis.length && j>=0 && j<vis[0].length
               && !vis[i][j]);
    }
    
    void searchWord(TrieNode root, char boggle[][], int i, int j,
                    boolean vis[][], String str){
        char bog1=boggle[0][0];
        if(root.isEnd)
           answer.add(str);
        if(isSafe(i,j,vis)){
            vis[i][j]=true;
            for(int k=0;k<26;k++){
                char ch;
                if(Character.isUpperCase(bog1))
                   ch=(char)(k+'A');
                else
                   ch=(char)(k+'a');
                if(root.children.get(ch)!=null){
                    if(isSafe(i-1,j-1,vis) && boggle[i-1][j-1]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i-1,j-1,vis,str+ch);
                    if(isSafe(i-1,j,vis) && boggle[i-1][j]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i-1,j,vis,str+ch);
                    if(isSafe(i-1,j+1,vis) && boggle[i-1][j+1]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i-1,j+1,vis,str+ch);    
                    if(isSafe(i,j+1,vis) && boggle[i][j+1]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i,j+1,vis,str+ch);
                    if(isSafe(i+1,j+1,vis) && boggle[i+1][j+1]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i+1,j+1,vis,str+ch);   
                    if(isSafe(i+1,j,vis) && boggle[i+1][j]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i+1,j,vis,str+ch);
                    if(isSafe(i+1,j-1,vis) && boggle[i+1][j-1]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i+1,j-1,vis,str+ch);
                    if(isSafe(i,j-1,vis) && boggle[i][j-1]==ch)
                       searchWord(root.children.get(ch), boggle,
                        i,j-1,vis,str+ch);
                }
            }
            vis[i][j]=false;
        }
    }
    
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int tc=sc.nextInt();
		while(tc-->0){
		    GFG ob=new GFG();
		    int n=sc.nextInt();
		    String dict[]=new String[n];
		    for(int i=0;i<n;i++){
		      dict[i]=sc.next();
		      ob.insert(dict[i]);
		    }
		    int M=sc.nextInt();
		    int N=sc.nextInt();
		    char boggle[][]=new char[M][N];
		    for(int i=0;i<M;i++){
		        for(int j=0;j<N;j++){
		            boggle[i][j]=sc.next().charAt(0);
		        }
		    }
		  //  for(int i=0;i<M;i++){
		  //      for(int j=0;j<N;j++){
		  //          System.out.print(boggle[i][j]+" ");
		  //      }
		  //      System.out.println();
		  //  }
		    ob.findWords(boggle,M,N);
		    if(ob.answer.size()==0)
		    System.out.println(-1);
		    else{
		       for(String ans:ob.answer) 
		         System.out.print(ans+" ");
		       System.out.println();
		    }
		}
	}
}
