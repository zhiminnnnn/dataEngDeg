template <class T>
int search(T arr[], int size, T val){
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