//https://leetcode.com/problems/letter-tile-possibilities/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void generateSequences(string& tiles, string& currentSequence,vector<bool>& isUsed,unordered_set<string>& uniqueSequences){
            uniqueSequences.insert(currentSequence);
            for(int index = 0;index<tiles.length();++index){
                if(isUsed[index]==0){
                    isUsed[index]=true;
                    currentSequence += tiles[index];
                    generateSequences(tiles,currentSequence,isUsed,uniqueSequences);
                    isUsed[index] = false;
                    currentSequence.pop_back();
                }
            }
        }
        int numTilePossibilities(string tiles) {
            unordered_set<string> uniqueSequences;
            vector<bool> isUsed(tiles.length(),false);
            string currentSequence = "";
            generateSequences(tiles, currentSequence, isUsed, uniqueSequences);
            return uniqueSequences.size()-1;
        }
    };