#include <stdio.h>
#include <stdlib.h>
void swap_int(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swap_float(float *a,float *b)
{
    float temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(float array[], int size,float a[],float b[],int obj[]) 
{
    for (int step = 0; step < size - 1; ++step) 
    {
        for (int i = 0; i < size - step - 1; ++i) 
        {
            if (array[i] < array[i + 1]) 
            {
                swap_float(&array[i],&array[i+1]);
                swap_float(&a[i],&a[i+1]);
                swap_float(&b[i],&b[i+1]);
                swap_int(&obj[i],&obj[i+1]);
            }
        }
    }  
}

int main()
{
    int k,object;
    printf("Enter the Knapsack capacity : ");
    scanf("%d",&k);
    printf("Enter the number of objects : ");
    scanf("%d",&object);
    int obj[object];
    float weight[object];
    printf("-------------Enter weights------------\n");
    for(int i=0;i<object;i++)
    {
        obj[i]=i+1;
        printf("Enter the weight of object %d : ",i);
        scanf("%f",&weight[i]);
    }
    printf("-----------Enter values------------\n");
    float value[object];
    for(int i=0;i<object;i++)
    {
        printf("Enter the value of object %d : ",i);
        scanf("%f",&value[i]);
    }
    printf("Object\tWeight\tValue\n");
    for(int i=0;i<object;i++)
    {
        printf("%d\t %.2f\t %.2f\n",i,weight[i],value[i]);
    }
    float ratio[object];
    for(int i=0;i<object;i++)
    {
        ratio[i]=value[i]/weight[i];
    }
    printf("-----------Calculating ratio------------\n");
    printf("Object\tWeight\tValue\tRatio\n");
    for(int i=0;i<object;i++)
    {
        printf("%d\t %.2f\t %.2f\t %.2f\n",i,weight[i],value[i],ratio[i]);
    }
    bubbleSort(ratio,object,value,weight,obj);
    
    printf("-----------Sorting ratio------------\n");
    printf("Object\tWeight\tValue\tRatio\n");
    for(int i=0;i<object;i++)
    {
        printf("%d\t %.2f\t %.2f\t %.2f\n",obj[i],weight[i],value[i],ratio[i]);
    }
    int value1=0;
    printf("Items in knapasck are : ");
    for(int i=0;i<object;i++)
    {
        
        if(k>0 && weight[i]<=k)
        {
            k=k-weight[i];
            value1=value1+value[i];
            printf("%d\t",obj[i]);
        }
        else 
        {
            if(k>0)
            {
                printf("%d[%d/%.1f]\n",obj[i],k,weight[i]);
                value1=value1+value[i]*(k/weight[i]);
            }
            break;
        }
    }
    printf("Max value is %d\n",value1);
}