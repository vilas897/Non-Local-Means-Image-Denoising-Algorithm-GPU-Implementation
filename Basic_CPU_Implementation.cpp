#include<bits/stdc++.h>
#define imgH 100
#define imgW 100
#define patchW 3
using namespace std;

void printImg(float img[imgH][imgW])
{
    for(int i=0; i<imgH; i++)
    {
      for(int j=0; j<imgW; j++)
      {
        cout<<img[i][j]<<" ";
      }

      cout<<endl;
    }
  return;
}

int main()
{
  float img[imgH][imgW] = {0}, C[imgH][imgW] = {0};
  float h = 1;
  float imgTemp[imgH][imgW] = {0};

  for(int i=0; i<imgH; i++)
    for(int j=0; j<imgW; j++)
    {
      img[i][j] = 1.2;
    }

  //printImg(img);

  clock_t t = clock();

  for(int i=0; i<imgH - patchW + 1; i++)
    for(int j=0; j<imgW - patchW + 1; j++)
    {
      for(int k=i; k<imgH - patchW + 1; k++)
        for(int l=0; l<imgW - patchW + 1; l++)
        {

          if(l != j)
          {
            float v = 0;

            for(int p=k; p<k+patchW; p++)
              for(int q=l; q<l+patchW; q++)
              {
                v += (img[i+p-k][j+q-l] - img[p][q]) * (img[i+p-k][j+q-l] - img[p][q]);
              }

              float w = exp(-v/(h*h));

              imgTemp[i][j] += w * img[k][l];
              C[i][j] += w;
              imgTemp[k][l] += w * img[i][j];
              C[k][l] += w;
            }
          }

    }

    for(int i=0; i<imgH - patchW + 1; i++)
      for(int j=0; j<imgW - patchW + 1; j++)
      {
        img[i][j] = imgTemp[i][j]/C[i][j];
      }

    t = clock() - t;

    cout<<"Time elapsed for H = "<<imgH<<" and W = "<<imgW<<" is: "<<(1000*((double)t/CLOCKS_PER_SEC))<<" milliseconds";
    //printImg(img);
    return 0;
}
