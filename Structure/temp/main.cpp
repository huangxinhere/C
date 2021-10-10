#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int m[6][2] = {{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}};
    int r1,r2,r3,r4,r5,r6;
    int a,b,c,d,e,f;
    for ( int a = 0 ; a < 2 ; a++)
    {
        for(int b=0;b<2;b++)
        {
            for (int c = 0; c < 2; c++)
            {
                if(c==0) b=0;
                else if(c==1) b=1;
                //for (int e = 0; e < 2; e++)
                //{
                    ////if(e==0) d=0,c=1,b=1;
                    //if(d==0) c=1,b=1;
                    //else if(d==1) c=0,b=0,a=0;  //a和d不可能都是案犯
                    //for (int d = 0; d < 2; d++)
                    //{
                        ////if(e==0) d=0,c=1,b=1;
                        d=0,c=1,b=1,e=0;
                        //else if(d==1) c=0,b=0,a=0;
                        for (int f = 0; f < 2; f++)
                        {
                            if(
                               (m[0][a]||m[1][b]==true)&&
                              ((m[0][a]&&m[4][e]) || (m[0][a]&&m[5][f]) || (m[4][e]&&m[5][f]) || (m[0][a]&&m[4][e]&&m[5][f]) ==true)
                               )
                              {
                                  r1=m[0][a],r2=m[1][b],r3=m[2][c],
                                  r4=m[3][d],r5=m[4][e],r6=m[5][f];
                                  break;
                              }

                        }

                    //}

                //}

            }

        }
    }
    cout << "A: " <<r1<<endl;
    cout << "B: " <<r2<<endl;
    cout << "C: " <<r3<<endl;
    cout << "D: " <<r4<<endl;
    cout << "E: " <<r5<<endl;
    cout << "F: " <<r6<<endl;

    return 0;
}
//d是惯犯的时候，矛盾
