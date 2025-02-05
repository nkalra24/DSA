#include<stdio.h>
#include<conio.h>
int partition(int a[],int start,int end){
    int i,j,temp,pivot;
    pivot=a[end];
    i=start;
    j=i-1;
    for(i=start;i<end;i++){
        if(a[i]<pivot){
            j=j+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j+1];
    a[j+1]=a[end];
    a[end]=temp;
    return j+1;
}
void quick_sort(int a[],int start,int end){
    int p;
    if(start<end){
    p=partition(a,start,end);
    quick_sort(a,start,p-1);
    quick_sort(a,p+1,end);
    }
}


int main(){
    int i,j,n,a[100];
    printf("Enter the no of elements");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The elements are as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    i=0;
    j=n-1;
    quick_sort(a,i,j);
    printf("\nThe sorted elements are as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
