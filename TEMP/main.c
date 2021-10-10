#include <iostream>

using namespace std;

int main(){
    bool m[6][2] = {{false,true},{false,true},{false,true},{false,true},{false,true},{false,true}};
    bool r1,r2,r3,r4,r5,r6;
    for ( int a = 0 ; a < 2 ; a++)
    {
        for(int b=0;b<2;b++)
        {
            for (int c = 0; c < 2; c++)
            {
                for (int d = 0; d < 2; d++)
                {
                    for (int e = 0; e < 2; e++)
                    {
                        for (int f = 0; f < 2; f++)
                        {
                            if((m[0][a]||m[1][b]==true)&&
                              (m[0][a]||m[4][e]||m[5][f]==true)&&
                              (m[0][a]&&m[3][d]==false)&&
                              (m[1][b]&&m[2][c]==true)&&
                              (m[2][c]&&m[3][d]==false)&&
                              (m[3][d]&&m[4][e]==true))
                              {
                                  r1=m[0][a],r2=m[1][b],r3=m[2][c],
                                  r4=m[3][d],r5=m[4][e],r6=m[5][f];
                                  break;
                              }

                        }

                    }

                }

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
