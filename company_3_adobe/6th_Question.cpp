/*question details
name: knight-probability-in-chessboard
link: https://leetcode.com/problems/knight-probability-in-chessboard/
submission link: https://leetcode.com/problems/knight-probability-in-chessboard/submissions/878691289/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        if(k==0) return 1.0;
        
        vector<vector<double>> parentBoard(n,vector<double>(n,0.0));
        vector<vector<double>> childBoard(n,vector<double>(n,0.0));
        
        int rowoffset[] = {-2,-2,-1,-1,2,2,1,1};
        int coloffset[] = {1,-1,2,-2,1,-1,2,-2};
        
        int cx,cy;
        parentBoard[r][c] = 1.0;

        for(int i=0;i<k;i++)
        {
            for(int p=0;p<n;p++)
            {
                for(int q=0;q<n;q++)
                {
                    double moveProb = parentBoard[p][q]/8.0;
                    for(int w=0;w<8;w++)
                    {
                        cx = p + rowoffset[w];
                        cy = q + coloffset[w];
                        if(cx>=0 && cx<n && cy>=0 && cy<n)
                            childBoard[cx][cy] += moveProb;
                    }                    
                }
            }
            parentBoard = childBoard;
            fill(childBoard.begin(),childBoard.end(),vector<double>(n,0.0));
        }
        
        double knightProb = 0.0;
        
        for(int p=0;p<n;p++)
            for(int q=0;q<n;q++)
                   knightProb+=parentBoard[p][q];

        return knightProb;
    }
};