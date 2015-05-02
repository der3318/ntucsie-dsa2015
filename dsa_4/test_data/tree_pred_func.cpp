int tree_predict(double *attr){
	if(attr[0] < 68){
		return -1;
	}
	else{
		if(attr[2] < 22){
			return -1;
		}
		else{
			return 1;
		}
	}
}
