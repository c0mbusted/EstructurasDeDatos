
long bubbleSort(int arr[], int length, int desc) {
    int i,j,aux;
    long cont=0;
    for (i=0; i<length-1;i++) {
        for(j=0;j<length-i-1;j++){
            cont++;
            if (desc==1) {
                if(arr[j]<arr[j+1]) {
                    aux=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=aux;
                }
            } else {
                if(arr[j]>arr[j+1]) {
                    aux=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=aux;
                }
            }    
        }
    }
    return cont;
}