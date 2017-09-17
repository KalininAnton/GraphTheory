#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;


Graph::Graph(){
}

void Graph::readGraph(string fileName){
    fstream fin(fileName);
    fin >> state;
    if(state == 'C')
    {
        fin >> N;
        AdjMatrix.reserve(N);
        for(int i = 0; i < N; i++)
            AdjMatrix[i].reserve(N);
        fin >> W;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                fin >> AdjMatrix[i][j];
    }
    if(state == 'L')
    {
        fin >> N;
        fin >> R;
        fin >> W;
        vector <int> temp;
        int n;
        int i=0;
        while (fin >> n)
        {
            temp.push_back(n);
            if (fin.peek() == '\n' || fin.peek() == EOF)
            {
                if(W == 0)
                    AdjListUnweighted.push_back(temp);
                else
                {
                    vector <pair <int,int>> temp2 ;
                    for(int j = 0;j < temp.size(); j = j+2)
                        temp2.push_back(make_pair(temp[j],temp[j+1]));
                    AdjListWeighted.push_back(temp2);
                }
                temp.clear();
                i++;
            }
        }
    }
    if(state == 'E')
    {
        fin >> N;
        
        fin >> M;
        ListOfEdgesWeighted.reserve(M);
        fin >> R;
        fin >> W;
        for (int i = 0; i < M; ++i)
        {
            if(W == 0)
            {
                int t1,t2;
                fin >> t1;
                fin >> t2; 
                ListOfEdgesUnweighted.push_back(make_pair(t1,t2));
            }
            else
            {
                int t1,t2,t3;
                fin >> t1 >> t2 >> t3; 
                ListOfEdgesWeighted.push_back( make_tuple(t1,t2,t3));
            }
        }
    }
}

void Graph::writeGraph(const string fileName){
    ofstream fout (fileName);
    if(state == 'C')
    {
        fout << 'C' << endl;
        fout << "N = " << N << endl;
        fout << "W = " << W << endl;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                fout << AdjMatrix[i][j] << ' ';
            fout << endl;
        }
    }
    if(state == 'L')
    {
        fout << 'L' << endl;
        fout << "N = " << N << endl;
        fout << "R = " << R << endl;
        fout << "W = " << W << endl;
        for(int i = 0; i < N; i++)
        {
            if(W == 0)
                for(int j = 0; j < AdjListUnweighted[i].size(); j++)
                    fout << AdjListUnweighted[i][j] << ", " ;
            else
                for(int j = 0; j < AdjListWeighted[i].size(); j++)
                    fout << '(' << AdjListWeighted[i][j].first << ", " << AdjListWeighted[i][j].second << ") " ;
            fout << endl;
        }
    }
    if(state == 'E')
    {
        fout << 'E' << endl;
        fout << "N = " << N << endl;
        fout << "M = " << M << endl;
        fout << "R = " << R << endl;
        fout << "W = " << W << endl;
        if(W == 0)
            for(int i = 0; i < ListOfEdgesUnweighted.size(); i++)
            {
                fout << '(' << ListOfEdgesUnweighted[i].first << ", " << ListOfEdgesUnweighted[i].second << ") ";
                fout << endl;
            }
        else
            for(int i = 0; i < ListOfEdgesWeighted.size(); i++)
            {
                fout << '(' << get<0>(ListOfEdgesWeighted[i]) << ", " << 
                get<1>(ListOfEdgesWeighted[i]) << ", " << 
                get<2>(ListOfEdgesWeighted[i]) << ") ";
                fout << endl;
            }
    }
}
