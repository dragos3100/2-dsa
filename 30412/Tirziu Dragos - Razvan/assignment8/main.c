#include <stdio.h>
#include <stdlib.h>

int noOfActionsBubble=0;
int noOfActionsQuick=0;
int noOfActionsRadix=0;

void generateNr(int n);
void bubbleSort(int *array,int n);
int partition (int *array, int low, int high);
void quickSort(int arr[], int low, int high);
int getMax(int *array, int n);
void countSort(int *array, int n, int exp);
void radixSort(int *array, int n);

/*  Results
Nr of actions BubbleSort: 125253609
Nr of actions QuickSort: 20988894
Nr of actions RadixSort: 380098
 */

int main() {
    int n=10000;
    generateNr(n);
    int *array=(int*)malloc(n*sizeof(int));
    FILE *f=fopen("../Sequence","r");
    if(f==NULL){
        perror("File could not be open");
        exit(-1);
    }
    for(int i=0;i<n;i++)
        fscanf(f,"%d",&array[i]);
    bubbleSort(array,n);
    /*for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }*/
    printf("Nr of actions BubbleSort: %d\n",noOfActionsBubble);
    fclose(f);

    f=fopen("../Sequence","r");
    if(f==NULL){
        perror("File could not be open");
        exit(-1);
    }
    for(int i=0;i<n;i++)
        fscanf(f,"%d",&array[i]);
    quickSort(array,0,n-1);
    /*for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }*/
    printf("Nr of actions QuickSort: %d\n",noOfActionsQuick);
    fclose(f);

    f=fopen("../Sequence","r");
    if(f==NULL){
        perror("File could not be open");
        exit(-1);
    }
    for(int i=0;i<n;i++)
        fscanf(f,"%d",&array[i]);
    radixSort(array,n);
   /*for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }*/
   printf("Nr of actions RadixSort: %d",noOfActionsRadix);
   fclose(f);

    return 0;
}

void generateNr(int n){
    srand(0);
    FILE *f=fopen("../Sequence","w");
    for(int  i = 0 ; i < n ; i++) {
        fprintf(f,"%d ", rand());
        if(i%100==0 && i!=0)
            fprintf(f,"\n");
    }
}

void bubbleSort(int *array,int n){
    for (int i = 0; i < n - 1; i++) {
        noOfActionsBubble++;
        for(int j=i+1;j<n;j++){
            noOfActionsBubble+=2;
            if(array[i]>array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                noOfActionsBubble++;
            }
        }
    }
}

int partition (int *array, int low, int high)
{
    int pivot = array[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {noOfActionsQuick++;
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {noOfActionsQuick+=3;
            i++;    // increment index of smaller element
            int temp =array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    noOfActionsQuick+=3;
    int temp =array[i+1];
    array[i+1]=array[high];
    array[high]=temp;
    return (i + 1);
}

void quickSort(int *array, int low, int high)
{
    if (low < high)
    {noOfActionsQuick+=3;
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(array, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int getMax(int *array, int n)
{noOfActionsRadix++;
    int mx = array[0];
    for (int i = 1; i < n; i++){
        noOfActionsRadix++;
        if (array[i] > mx)
            mx = array[i];
        noOfActionsRadix+=2;
    }
    return mx;
}

void countSort(int *array, int n, int exp){
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++){
        noOfActionsRadix+=2;
        count[ (array[i]/exp)%10 ]++;
    }
    for (i = 1; i < 10; i++){
        noOfActionsRadix+=2;
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {  noOfActionsRadix+=3;
        output[count[ (array[i]/exp)%10 ] - 1] = array[i];
        count[ (array[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++){
        noOfActionsRadix+=2;
        array[i] = output[i];
    }
}

void radixSort(int *array, int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(array, n);
    for (int exp = 1; m/exp > 0; exp *= 10) {
        noOfActionsRadix+=2;
        countSort(array, n, exp);
    }
}
