#include<stdio.h> 
#include<stdlib.h> 
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
const int INF=1e8+10;

struct node{
    int val, maxLeft, maxRight;
    node* left,* right;
};

node* create_new_node(int val, int L, int R, node* left, node* right){
    node* tmp = new node;
    tmp->val = val;
    tmp->maxLeft = L;
    tmp->maxRight = R;
    tmp->left = left;
    tmp->right = right;
    return tmp;
}

// build Segment Tree for array a from st to en
node* build_tree(vector<int>& vt , int st , int en ){
    if (st == en){
        return create_new_node(vt[st], st, en, NULL, NULL);
    }
    else{
        int tmp = (st+en)/2;
        node* left = build_tree(vt, st, tmp);
        node* right = build_tree(vt, tmp+1, en);
        return create_new_node(min(left->val, right->val), st, en, build_tree(vt,st,tmp), build_tree(vt,tmp+1,en));
    }
}

// build Segment Tree from array a
node* SegmentTree( vector<int>& vt){
    return build_tree(vt, 0, vt.size()-1 );
}

// traverse the whole tree in inorder
void inorder( node* cur ){
    if (cur->left != NULL) inorder(cur->left);
    cout << cur->val << " ";
    if (cur->right != NULL) inorder(cur->right);
}

// obtain the minimum value between arr[st] and arr[en]
int get_min_build_tree( node* cur , int st , int en ){
    if (st <= cur->maxLeft && cur->maxRight <= en){
        return cur->val;
    }
    int S = INF;
    if (cur->left->maxLeft <= st && st <= cur->left->maxRight) S = min(S, get_min_build_tree(cur->left, st, min(cur->left->maxRight,en) ) );
    if (cur->right->maxRight >= en && en >= cur->right->maxLeft) S = min(S, get_min_build_tree(cur->right, max(st,cur->right->maxLeft), en) );
    return S;
}

// Testing the RMQ tree
int main()
{
    // Create RMQ for array (1, 4, 7, 2, 8, 3, 4)
    int arr[] = {1, 4, 7, 2, 8, 3, 2};
    std::vector<int> vect (arr, arr + sizeof(arr) / sizeof(int) );
    node* Seg = SegmentTree(vect);

    // query minimum value between ranges
    printf("Min value between index 0 and 3 is %d\n", get_min_build_tree(Seg, 0, 3) ); // 1
    printf("Min value between index 0 and 6 is %d\n", get_min_build_tree(Seg, 0, 6) ); // 1
    printf("Min value between index 4 and 5 is %d\n", get_min_build_tree(Seg, 3, 5) ); // 2
    printf("Min value between index 2 and 5 is %d\n", get_min_build_tree(Seg, 2, 5) ); // 2
    printf("Min value between index 6 and 6 is %d\n", get_min_build_tree(Seg, 6, 6) ); // 2
    printf("Min value between index 4 and 4 is %d\n", get_min_build_tree(Seg, 4, 4) ); // 8
}