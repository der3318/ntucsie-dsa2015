int forest_predict(double *attr){
	int t = 0, f = 0;
tree1_predict:
	if(attr[0] < 68){
		f++;
	}
	else{
		t++;
	}
tree2_predict:
	if(attr[0] < 90){
		f++;
	}
	else{
		t++;
	}
voting:
	if(t > n)       return 1;
	else    return -1;
}

