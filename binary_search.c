#include <stdio.h>
int main(){
    int a =0;
    
    printf("Enter the no of elements:");
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        printf("Enter the element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    int start=0;
    int end=a-1;
    int key=0;
    printf("Enter the element to be searched :");
    scanf("%d",&key);
    while(start<=end){
        int middle=(start +end)/2;
        if(arr[middle]==key){
            printf("The element has been fount at the postion %d",middle+1);
            break;
        }
        else if(arr[middle]<key){
            start=middle+1;
        }
        else{
            end=middle-1;

        }
        }
    
    if(start>end){
        printf("The element is not found");
    }
}
