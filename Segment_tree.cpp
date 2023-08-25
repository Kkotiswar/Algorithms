#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    vector<int>arr,seg;

    SegmentTree(vector<int>&arr) {
        this.arr = arr;
        seg.resize(4*arr.size());
    } 

    void build(int index,int low, int high) {
        if(low == high){
            seg[index] = arr[low];
        }

        int mid = low + (high-low)/2;
        build(2*index+1,low,mid);
        build(2*index+2,mid+1,high);

        seg[index] = max(seg[2*index+1],seg[2*index+2]);
    }

    void query(int index, int low,int high,int l,int h) {
        if(l<=low && h>=high)return seg[index];
        if(high<l || low>h)return INT_MIN;

        int mid = low+(high-mid)/2;
        int left = query(2*index+1,low,mid,l,h);
        int right = query(2*index+2,mid+1,high,l,h);
        
        // for maximum in range
        return max(left,right);
        //for sum in this range
        return left+right;
        //for xoring in this range
        return left^right;
    }
};