#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// bubble
// selection
// quick




// case [5,4,3,2,1] ,up
// case [2,3,4,1,6] ,up
// case [2,3,5,4,6] ,up
//
int arr_len;


int arr_pri(int arr[],int len)
{
	for(int i=0;i<len;i++){
		printf("%d ",arr[i]);
	}

	return 0;
}

int arr_print(const char *type,int arr[],int len,int sw_cnt,int loop)
{
	printf("%-10s:",type);
	arr_pri(arr,len);
	printf("[sw:%d,loop:%d]\n",sw_cnt,loop);
	
	return 0;
}

int origin_print(int arr[],int len)
{
	
	// origin data
	printf("origin data\n");
	arr_pri(arr,len);
	printf("\n\n");

	return 0;
}

int bubble(int arr[],int len)
{
	origin_print(arr,len);
	int cnt = 0;
	int loop = 0;

	int i,j;
	
	for(i = 0;i < len - 1;i++){
		for(j = 0;j < len -1 - i;j++){
			loop++;
			// > for up, < for down
			if(arr[j] > arr[j+1]){
				// do switch
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			
				// debug
				cnt++;
				printf("%-3d:",cnt);
				arr_pri(arr,len);
				printf("\n");
			}
		}
	}
	
	arr_print("bubble",arr,len,cnt,loop);
	return 0;
}


int selection(int arr[],int len)
{
	origin_print(arr,len);
	int sw_cnt = 0,loop = 0;

	int i,j;
	int min_index;

	for(i=0;i<len - 1;i++){
		min_index = i;
		for(j=i+1;j<len;j++){
			loop++;
			if(arr[min_index] > arr[j]){
				min_index = j;
			}
		}

		int tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
		
		//debug
		sw_cnt++;
		printf("%-3d:",sw_cnt);
		arr_pri(arr,len);
		printf("\n");


	
	}


	arr_print("select",arr,len,sw_cnt,loop);
	return 0;
}

int insert(int arr[],int len)
{
	origin_print(arr,len);

	int switch_cnt = 0;
	int loop = 0;
	int do_switch = 0;

	int tmp,i,j;
	for(i=1;i<len;i++){
		tmp = arr[i];
		j=i;

		for (;j > 0 && arr[j - 1] > tmp;j--) {//is beeter ,
				arr[j]=arr[j-1];
			
				// debug cnt
				switch_cnt++;
				do_switch = 1;

		}
		
		// j is always 0 here?	
		arr[j]=tmp;
		
		// debug print
		if(do_switch){
			printf("%-3d:",switch_cnt);
			arr_pri(arr,len);
			printf("\n");
	
			do_switch = 0;
		}
	}

	arr_print("insert",arr,len,switch_cnt,loop);
	return 0;
}


int shell(int arr[],int len)
{
        origin_print(arr,len);

        int switch_cnt = 0;
        int loop = 0;
        int do_switch = 0;

        int tmp,i,j;
	int gap;
	for(gap = len >> 1; gap > 0; gap >>= 1) {
		for(i=gap;i<len;i++){
			tmp = arr[i]; // store cur pos val
			j=i;

			for (;j > 0 && arr[j - gap] > tmp;j -= gap) {//is beeter ,
					arr[j]=arr[j-gap];

					// debug cnt
					switch_cnt++;
					do_switch = 1;
			}

			// j is always 0 here?
			arr[j]=tmp;

			// debug print
			if(do_switch){
				printf("%-3d:",switch_cnt);
				arr_pri(arr,len);
				printf("\n");

				do_switch = 0;
			}
		}
	}

        arr_print("shell",arr,len,switch_cnt,loop);
        return 0;
}

int quick_cnt;
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left){
	quick_cnt++;
    	printf("L ,S %d, E %d |",start,left -1);
	arr_pri(arr,arr_len);
	printf("\n");
	quick_sort_recursive(arr, start, left - 1);
    }

    quick_cnt++;
    printf("R ,S %d, E %d |",left + 1, end);
    arr_pri(arr,arr_len);
    printf("\n");
    quick_sort_recursive(arr, left + 1, end);
    
}

void quick_sort(int arr[], int len) {
	quick_cnt = 0;
    	printf("S ,S %d, E %d |",0,len -1);
	arr_pri(arr,arr_len);
    	printf("\n");

    	quick_sort_recursive(arr, 0, len - 1);
	arr_print("quick sort",arr,len,quick_cnt,0);
}


int main(int argc,char *argv)
{
	int method = 0;
	int data[] = {5,4,3,2,1};
	int data_num = sizeof(data)/sizeof(int);
	int *data_tmp = malloc(sizeof(data));

	arr_len = data_num;

	if(argc){
		printf("%s",argv);
		method = atoi(argv);
		printf("method %d\n",method);
	}



	if(!method || (1 == method)){
		printf("\n==>insert.\n");
		memcpy(data_tmp,data,sizeof(data));
		insert(data_tmp,data_num);
	}


	if(!method || (10 == method)){
		printf("\n==>shell.\n");
		memcpy(data_tmp,data,sizeof(data));
		shell(data_tmp,data_num);
	}

	if(!method || (2 == method)){
		printf("\n==>bubble.\n");
		memcpy(data_tmp,data,sizeof(data));
		bubble(data_tmp,data_num);
	}


	if(!method || (3 == method)){
		printf("\n==>selecttion.\n");
		memcpy(data_tmp,data,sizeof(data));
		selection(data_tmp,data_num);
	}

	if(!method || (5 == method)){
		printf("\n==>quick recursive.\n");
		memcpy(data_tmp,data,sizeof(data));
		quick_sort(data_tmp,data_num);
	}

	return 0;
}
