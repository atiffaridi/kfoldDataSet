#include<stdio.h>
int insertionSort(int *,int n);
#define MAX 100
int main()
{
   int a[MAX],n,i;
   printf("\nEnter no. of elements in array:-->");
   scanf("%d",&n);
   printf("\nEnter elements of array:");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   insertionSort(a,n);
}

int insertionSort(int *a,int n)
{
   int pass,j,z,i,temp,flag;
   for(pass=1;pass<n;pass++) { flag=1;
       printf("\n\nBefore Pass %d, Temp=a[%d]=%d:",pass,pass,a[pass]);
       temp=a[pass];
       for(i=0;i<n;i++){
           printf("\t%d",a[i]);
       }
       for(j=pass;j>0 && temp<a[j-1];j--){  
           a[j]=a[j-1];flag=0;
           printf("\nPass=%d,j=%d,Temp=a[%d]=%d,Temp(%d)<(%d)a[%d]-true:",pass,j,pass,temp,temp,a[j-1],j-1);
           for(i=0;i<n;i++){
               printf("\t%d",a[i]);
           }
           
       }
       a[j]=temp;
       printf("\nInsert %d at %d location",temp, j);
       for(z=pass;z>0;z--){
           if(temp>a[j-1]&&flag){
               printf("\nPass=%d,j=%d,Temp=a[%d]=%d,Temp(%d)<(%d)a[%d]-false:",pass,z,pass,temp,temp,a[z-1],z-1);
               printf("\nNo insert action in array");
               for(i=0;i<n;i++){
                  printf("\t%d",a[i]);
               }
           break;
           }           
       }
       
       printf("\n\nNew array After Pass %d:",pass);
       for(i=0;i<n;i++){
           printf("\t%d",a[i]);
       }
       printf("\n");
      
   }
}
