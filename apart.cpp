#include<conio.h>
#include<stdio.h>
int a[100],num=0;
FILE *p1,*p2;
void sum(int k)
{
     int p,i;
     if(a[k-1]>=a[k])
     {
                      num++;
                      fprintf(p2,"%d=",a[0]);
                      for(i=1;i<k;i++)     fprintf(p2,"%d+",a[i]);
                      fprintf(p2,"%d\n",a[k]);
     }
     p=a[k];
     if(p>=2)
     {
             for(i=p-1;i>=1;i--)
             {
                                a[k]=i;
                                a[k+1]=p-i;
                                if((p-i>0)&&a[k-1]>=a[k])     sum(k+1);
             }
     }
}
main()
{
      p1=fopen("apart.in","r");
      p2=fopen("apart.out","w");
      int n,i,j;
      fscanf(p1,"%d",&a[0]);
      if(a[0]>=2)
      {
                 for(i=a[0]-1;i>=1;i--)
                 {
                                       a[1]=i;
                                       a[2]=a[0]-i;
                                       if(a[2]>0)  sum(2);
                 }
      }
      fprintf(p2,"%d",num);
      fclose(p1);
      fclose(p2);
}
