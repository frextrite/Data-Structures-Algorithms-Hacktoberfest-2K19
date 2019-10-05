// Assumption -> All the strings are unique

/*
    Time Complexity->
        Insert = O(length)
        Search = O(length)
        Remove = O(length)
        isEmpty = O(Alphabet)
 */
 
/* Structure of Node */
struct Node
{
    bool leaf;
    Node *child[26];    // Alphabet => lowercase english alphabets
};
 
/* returns a new node */
Node *getNode()
{
    Node *temp = (Node *)malloc(sizeof(Node));
 
    // Initializing Node
    temp->leaf=false;
    for(int a=0;a<26;a++)
    {
        temp->child[a]=NULL;
    }
    return temp;
}
 
/* Inserts a string */
void insert(Node *root,string s)
{
    Node *head=root;
    for(auto y:s)
    {
        int b=y-'a';
        if(head->child[b]==NULL)
            head->child[b]=getNode();   // We create a node if it does not exist
        head=head->child[b];
    }
    head->leaf=true;
}
 
/* Searches for a string */
bool search(Node *root,string s)
{
    Node *head=root;
    for(auto y:s)
    {
        int b=y-'a';
        if(head->child[b]==NULL)
            return false;               // If a node does not exist , we return false
        head=head->child[b];
    }
    return head->leaf;
}
 
/* Checks if a node is empty */
bool isEmpty(Node *root)
{
    for(int a=0;a<26;a++)
    {
        if(root->child[a])
            return false;
    }
    return true;
}
 
/* Deletes a string */
Node *remove(Node *root,string s,int level=0)
{
    int n=s.length();
    if(level==n)
    {
        if(root->leaf)
        {
            root->leaf=false;
        }
        if(isEmpty(root))
        {
            delete(root);
            root=NULL;
        }
        return root;
    }
 
    int curr=s[level]-'a';
    root->child[curr]=remove(root->child[curr],s,level+1);
    if(isEmpty(root))
    {
        delete(root);
        root=NULL;
    }
    return root;
}
