
long insertionSort(int arr[], int n, int desc)  
{  

    int i, key, j; 
    long cont=0;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        if (desc==1) {
            while (j >= 0 && arr[j] < key) {  
                cont++;
                arr[j + 1] = arr[j];  
                j = j - 1;
            }  
        }else {
            while (j >= 0 && arr[j] > key) {  
                cont++;
                arr[j + 1] = arr[j];  
                j = j - 1;
            } 
        }  
        arr[j + 1] = key; 
    }  
    return cont;
}  
  
  

  

