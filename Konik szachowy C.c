#include <stdio.h>
#include <stdlib.h>

#define N 8
int h[N][N], a[8], b[8];

void wypisz(int g[][N])
{
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
        printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}
int skok(int x, int y, int licznik){

    int pozycjax,pozycjay;
    licznik +=1;
    h[x][y] = licznik;
    if (licznik == N*N)
        return 1;
    for(int i=0;i<8;i++){
            pozycjax= x + a[i];
            pozycjay= y + b[i];
        if(pozycjax >= 0 && pozycjax < N && pozycjay >= 0 && pozycjay < N && h[pozycjax][pozycjay]==0){
            if(skok(pozycjax,pozycjay,licznik))
            {
                return 1;
            }
        }
    }
    h[x][y] = 0;
    return 0;


}

int main()
{
    a[0]=2; b[0]=1;
    a[1]=1; b[1]=2;
    a[2]=-1; b[2]=2;
    a[3]=-2; b[3]=1;
    a[4]=-2; b[4]=-1;
    a[5]=-1; b[5]=-2;
    a[6]=1; b[6]=-2;
    a[7]=2; b[7]=-1;
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
        h[i][j]=0;
        }
    }
    h[0][0]=1;
    if (skok(0,0,0)) wypisz(h);
    else printf("Nie ma rozwiazan!");
    return 0;
}
