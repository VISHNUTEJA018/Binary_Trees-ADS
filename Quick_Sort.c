#include<stdio.h>
void swap(int *p1,int *p2)
{
    int temp = *p1 ;
    *p1= *p2 ;
    *p2 = temp ;

}
int partition(int a[],int n,int l,int r)
{
    //pivot element starts with l ,that means first element
    int p = l  ;
    while(l<r)
    {
        while(a[p]<=a[r] && p<r)
        {
            r-- ;
        }
        if(a[p]>a[r])
        {
            swap(&a[p],&a[r]) ;
            p=r ;
            l++ ;
        }
        while(a[p]>=a[l] && l<p)
        {
                l++ ;
        }
        if(a[p]<a[l])
        {
            swap(&a[p],&a[l]) ;     
            p = l;
            r-- ;
        }
    }
    return p ;
}
void QuickSort(int a[],int n,int l,int r)
{
    int pivot;
    if(l<r)
    {
        pivot = partition(a,n,l,r);
        QuickSort(a,n,l,pivot-1);
        QuickSort(a,n,pivot+1,r);

    }
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int a[100];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);    
    }

    printf("\n");
    printf("Sorted elements are: \n");
    QuickSort(a,n,0,n-1);

    printArray(a,n);

    return 0;
}

