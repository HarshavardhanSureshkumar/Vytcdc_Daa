#include <stdio.h>

int main(){
    int a=0;
    printf("Enter the no of elements:");
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        printf("Enter the element %d :",i+1);
        scanf("%d",&arr[i]);

    }
    int key=0;
    printf("Enter the element to be searched :");
    scanf("%d",&key);
    int flag=0;
    for(int i=0;i<a;i++){
        if(arr[i]==key){
            printf("The element has been found at the position %d",i+1);
            flag=1;
            break;
        }

    }
    if(flag==0){
        printf("The element is not found");
    }

}