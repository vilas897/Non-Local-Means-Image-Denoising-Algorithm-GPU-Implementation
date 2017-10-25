#include<bits/stdc++.h>
#define imgH 10
#define imgW 10
#define patchW 3
using namespace std;

void printImg(double img[imgH][imgW])
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
  double img[imgH][imgW] = {0}, C[imgH][imgW] = {0};
  double h = 1;
  double imgTemp[imgH][imgW] = {0};

  for(int i=0; i<imgH; i++)
    for(int j=0; j<imgW; j++)
    {
      img[i][j] = 1.2;
    }

  printImg(img);

  for(int i=0; i<imgH - patchW + 1; i++)
    for(int j=0; j<imgW - patchW + 1; j++)
    {
      for(int k=i+1; k<imgH - patchW + 1; k++)
        for(int l=0; l<imgW - patchW + 1; l++)
        {
          double v = 0;

          for(int p=k; p<k+patchW; p++)
            for(int q=l; q<l+patchW; q++)
            {
              v += (img[i+p-k][j+q-k] - img[p][q]) * (img[i+p-k][j+q-k] - img[p][q]);
            }

          int w = exp(-v/(h*h));

          imgTemp[i][j] += w * img[k][l];
          C[i][j] += w;
          imgTemp[k][l] += w * img[i][j];
          C[k][l] += w;
         }
    }

    for(int i=0; i<imgH - patchW + 1; i++)
      for(int j=0; j<imgW - patchW + 1; j++)
      {
        img[i][j] = imgTemp[i][j]/C[i][j];
      }

    printImg(img);
    return 0;
}
