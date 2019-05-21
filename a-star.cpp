//
//  main.cpp
//  a_star
//
//  Created by 謝盈昊 on 2019/5/21.
//  Copyright © 2019 謝盈昊. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int stage = 5,target;
    int adj[25][25];
    int dotstage[12];
    int d[12],h[12],f[12];
    d[1]=0;
    f[1]=0;
    dotstage[1]=1;
    dotstage[2]=2;
    dotstage[3]=2;
    dotstage[4]=2;
    dotstage[5]=3;
    dotstage[6]=3;
    dotstage[7]=3;
    dotstage[8]=4;
    dotstage[9]=4;
    dotstage[10]=4;
    dotstage[11]=5;
    memset(adj, 0, sizeof(adj));
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    cin >> adj[1][2] >> adj[1][3] >> adj[1][4];
    cin >> adj[2][5] >> adj[2][6] >> adj[2][7];
    cin >> adj[3][5] >> adj[3][6] >> adj[3][7];
    cin >> adj[4][5] >> adj[4][6] >> adj[4][7];
    cin >> adj[5][8] >> adj[5][9] >> adj[5][10];
    cin >> adj[6][8] >> adj[6][9] >> adj[6][10];
    cin >> adj[7][8] >> adj[7][9] >> adj[7][10];
    cin >> adj[8][11] >> adj[9][11] >> adj[10][11];
    cin >> target;
    
    
    //start a*
    //start from stage 2
    for(int i = 2; i <=target ; i++){
        //for node in this stage
        for(int x = 1; x <= 11; x++){
            //calulate g[x] means from node 1 to node x
            int min =999,min2 =999;
            if(dotstage[x] == i){
                //first, pre stage to currnet nod
                for(int j = 1; j <= 11;j++){
                    if(adj[j][x] != 0 && d[j]+adj[j][x]<min){
                        min = d[j]+adj[j][x];
                        d[x]=min;
                    }
                }
                //scoend,node to next stage
                for(int k = 1; k <= 11;k++){
                    if(adj[x][k] != 0 && adj[x][k]< min2){
                        min2 = adj[x][k];
                        h[x] = min2;
                    }
                }
                //sum
                f[x] = d[x]+h[x];
            }
        }
    }
    int value;
    if(target == 1){
        value = min(adj[1][2],adj[1][3]);
        value = min(value,adj[1][4]);
        cout << value << endl;
    }
    else if( target == 2){
        value = min(f[2], f[3]);
        value = min(value,f[4]);
        cout << value <<endl;
    }
    else if(target == 3){
        value = min(f[5], f[6]);
        value = min(value,f[7]);
        cout << value <<endl;
    }
    else if(target == 4 || target == 5){
        value = min(f[8], f[9]);
        value = min(value,f[10]);
        cout << value <<endl;
    }
    
    
    return 0;
}
