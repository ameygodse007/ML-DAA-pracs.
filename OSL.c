#include<stdio.h>
#include<stdlib.h>
#define INF 1000000
int arr[100],n,curr,length;

void SSTF(){
    int total_track_dist = 0;
    int tmpcurr = curr;
    int isvisited[100] = {0};

    int mindiff = INF;
    int cl_index;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isvisited[j]==0){
                if(abs(tmpcurr-arr[j])<mindiff){
                    cl_index = j;
                    mindiff= abs(tmpcurr-arr[j]);
                }
            }
        }
        isvisited[cl_index]=1;
        total_track_dist += abs(tmpcurr - arr[cl_index]);
        tmpcurr = arr[cl_index];
        mindiff = INF ;
        printf("%d --> ",tmpcurr);
    }
    printf("\nTotal track movement = %d \n", total_track_dist);
}

int cmpfunc(const void* a,const void* b){
    return (*(int*)a > *(int*)b) ;
}

void SCAN(){
    int total_track_dist = 0;
    qsort(arr,n,sizeof(int),cmpfunc);
    total_track_dist = length  - curr;

    total_track_dist += length  -arr[0];
    printf("\nDisk schedulling by SCAN method...\n");
    printf("%d ---> ",curr);
    for(int i=0;i<n;i++){
        if(arr[i]>curr){
            printf("%d --->",arr[i]);
        }
    }

    for(int i=n-1;i>=0;i--){
        if(arr[i]<curr){
            printf("%d --->",arr[i]);
        }
    }
    printf("\nTotal track moment = %d",total_track_dist);
}


void CLook(){
    int total_track_dist = 0;
    qsort(arr,n,sizeof(int),cmpfunc);
    total_track_dist = arr[n-1] - curr;
    
    if(arr[0]< curr){
        total_track_dist+= arr[n-1] - arr[0];
        int p;
        for(int i=0;i<n;i++){
            if(arr[i]<curr){
                continue;
            }
            else{
                p=i-1;
                break;
            }
        }
        if(p!=0){
            total_track_dist+= arr[p] - arr[0];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>curr){
            printf("%d --->",arr[i]);
        }
    }

    for(int i=0;arr[i]<curr;i++){
        printf("%d --->",arr[i]);
    }
    printf("\nTotal track moment = %d",total_track_dist);
}


int main(){
    int selection;
    printf("Enter number of Request (Less than 100) ");
    scanf("%d",&n);
    printf("\nEnter the request numbers: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter total size of the track: ");
    scanf("%d",&length);
    printf("\nEnter the current position of R/O head: ");
    scanf("%d",&curr);
    do{
        printf("\n------Process------\n");
        printf("1.SSTF\n2.SCAN\n3.C-LOOK\n4.Exit\nSelection choice is: ");
        scanf("%d",&selection);
        switch(selection){
            case 1:
                SSTF();
                break;
            case 2:
                SCAN();
                break;
            case 3:
                CLook();
                break;
            case 4:
            printf("\n");
                break;
        }
    }
    while(selection!=4);
}