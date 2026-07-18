int search(int arr[], int size, int val){
	int sub = -1;
	for(int i=0; i<size; i++){
		if(arr[i] == val){
			sub = i;
			break;
		}
 	}
	if(sub == -1) throw "Value not found";
	return sub;
}