int tree_predict(double *attr){
	if(attr[1] < 63.500000){
		return -1;
	}
	else{
		if(attr[3] < 20.000000){
			return -1;
		}
		else{
			return 1;
		}
	}
}
