#include<stdio.h>
#include<time.h>

////For SelectionSort.....
void selection_sort(int arr[],int size)
{
    int i, j, min, temp;
    for (i=0; i<size; i++)
    {
        min = i;
        for (j=i+1; j<size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("\n\n*************Sorted value for Selection_Sort:**************\n");
    printf("\nAscending Order:\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);

     for (i=0; i<size; i++)
    {
        min = i;
        for (j=i+1; j<size; j++)
        {
            if (arr[j] > arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("\nDiscending Order:\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);

}

////For BubleSort.....
void Buble_Sort(int arr[],int size)
{
    int i,j,temp;

    for (j = 1; j < size; ++j)
    {
      for (i = 0; i < size - 1; ++i)
      {
         if (arr[ i ] > arr[ i + 1])
         {
            temp = arr[ i ];
            arr[ i ] = arr[ i + 1 ];
            arr[ i + 1 ] = temp;
         }
       }
    }
   printf("\n\n****************Sorted value for Buble_Sort:****************\n");
   printf("\nAscending Order:\n");
   for (j= 0; j < size; j++)
   {
      printf("%d ", arr[ j ]);
   }

    for(i=1;i<size;i++)
    {
        for(j=0;j<size-i;j++)
        if(arr[j]<arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    printf("\nDiscending Order:\n");
   for (j= 0; j < size; j++)
   {
      printf("%d ", arr[ j ]);
   }
   printf("\nThe complexity of this sort is: O(n)\n");
}

////For insertionSort....
void Insertion_sort(int arr[], int size)
{
    int i,j,key;
        for(j=1;j<size;j++){
        key=arr[j];
        i=j-1;
        while(i>=0&&arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;

        }
        arr[i+1]=key;
    }
    printf("\n\n*************Sorted value for Insertion_Sort:**************\n");
    printf("\nAscending Order:\n");
    for(j=0;j<size;j++)
    {
        printf("%d ",arr[j]);
    }

      for(j=1; j<=size-1; j++)
        {
        key=arr[j];
        i=j-1;
        while(i>=0&&arr[i]<key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    printf("\nDiscending Order:\n");
    for(j=0;j<size;j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\nThe complexity of this sort is: O(n)\n");

}

////For MergeSort......

void merge_sort1(int arr[],int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;

    merge_sort1(arr,low,mid);
    merge_sort1(arr,mid+1,high);

    merge1(arr,low,mid,high);

  }

}

void merge1(int arr[],int l,int m,int h)
{
  int arr1[10],arr2[10];

  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;

  for(i=0;i<n1;i++)
    arr1[i]=arr[l+i];
  for(j=0;j<n2;j++)
    arr2[j]=arr[m+j+1];

  arr1[i]=9999;
  arr2[j]=9999;

  i=0;j=0;
  for(k=l;k<=h;k++)
  {
    if(arr1[i]<=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }

}


void merge_sort2(int arr[],int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;

    merge_sort2(arr,low,mid);
    merge_sort2(arr,mid+1,high);

    merge2(arr,low,mid,high);

  }

}
void merge2(int arr[],int l,int m,int h)
{
  int arr1[10],arr2[10];

  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;

  for(i=0;i<n1;i++)
    arr1[i]=arr[l+i];
  for(j=0;j<n2;j++)
    arr2[j]=arr[m+j+1];

  arr1[i]=0000;
  arr2[j]=0000;

  i=0;j=0;
  for(k=l;k<=h;k++)
  {
    if(arr1[i]>=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }
}

////For Quick_Sort.....

void quicksort1(int *arr, int low, int high)
{
  int pivot, i, j, temp;
  if(low < high) {
    pivot = low;
    i = low;
    j = high;
    while(i < j) {

      while(arr[i] <= arr[pivot] && i <= high)
        i++;

      while(arr[j] > arr[pivot] && j >= low)
        j--;

      if(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    quicksort1(arr, low, j-1);
    quicksort1(arr, j+1, high);
  }
}


void quicksort2(int *arr, int low, int high)
{
  int pivot, i, j, temp;
  if(low < high) {
    pivot = low;
    i = low;
    j = high;
    while(i < j) {

      while(arr[i] >= arr[pivot] && i <= high)
        i++;

      while(arr[j] < arr[pivot] && j >= low)
        j--;

      if(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    quicksort2(arr, low, j-1);
    quicksort2(arr, j+1, high);
  }
}
int main()
{
    int arr[20],n,i,j;
    printf("Enter the size of array:\n");
    scanf("%d",&n);

    printf("Enter the value of array :\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",& arr[j]);
    }

    clock_t t;
    t = clock();
    selection_sort(arr,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("\n\nThe runtime of Selection_Sort is: %f seconds to execute \n", time_taken);
    printf("\nThe complexity of this sort is: O(n^2)\n");
    Buble_Sort(arr,n);
    Insertion_sort(arr, n);


    printf("\n\n***************Sorted value for Merge_Sort:****************\n");
    merge_sort1(arr,0,n-1);
    printf("\nAscending order:\n");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);

    merge_sort2(arr,0,n-1);
    printf("\nDiscending order:\n");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\nThe complexity of this sort is: O(nlogn)\n");

    printf("\n\n**************Sorted value for Quick_Sort:*****************\n");
    quicksort1(arr, 0, n-1);
    printf("\nAscending order:\n");
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);

    quicksort2(arr, 0, n-1);
    printf("\nDiscending order:\n");
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n\nThe complexity of this sort is: O(nlogn)\n");

    printf("\n\n******Final result:******\n");
    printf("The best complexity is: 1.Merge_SortO(nlogn) and 2.Quick_SortO(nlogn)\n");

    return 0;
}





