int forest_predict(double *attr){
	int t = 0, f = 0;
tree1_predict:
	if(attr[1] < 63.000000){
		f++;
	}
	else{
		t++;
	}
tree2_predict:
	f++;
tree3_predict:
	t++;
tree4_predict:
	if(attr[1] < 71.000000){
		f++;
	}
	else{
		t++;
	}
tree5_predict:
	f++;
tree6_predict:
	if(attr[1] < 57.500000){
		f++;
	}
	else{
		t++;
	}
tree7_predict:
	if(attr[1] < 74.500000){
		f++;
	}
	else{
		t++;
	}
tree8_predict:
	if(attr[1] < 75.500000){
		t++;
	}
	else{
		f++;
	}
tree9_predict:
	if(attr[1] < 75.500000){
		t++;
	}
	else{
		f++;
	}
tree10_predict:
	if(attr[1] < 58.500000){
		f++;
	}
	else{
		t++;
	}
tree11_predict:
	f++;
tree12_predict:
	if(attr[1] < 71.000000){
		f++;
	}
	else{
		t++;
	}
tree13_predict:
	if(attr[1] < 66.500000){
		f++;
	}
	else{
		t++;
	}
tree14_predict:
	if(attr[1] < 66.500000){
		f++;
	}
	else{
		t++;
	}
tree15_predict:
	if(attr[1] < 60.000000){
		f++;
	}
	else{
		t++;
	}
tree16_predict:
	f++;
tree17_predict:
	if(attr[1] < 71.000000){
		f++;
	}
	else{
		t++;
	}
tree18_predict:
	if(attr[1] < 78.500000){
		t++;
	}
	else{
		f++;
	}
tree19_predict:
	if(attr[1] < 68.500000){
		f++;
	}
	else{
		t++;
	}
tree20_predict:
	f++;
tree21_predict:
	f++;
tree22_predict:
	f++;
tree23_predict:
	if(attr[1] < 74.500000){
		f++;
	}
	else{
		t++;
	}
tree24_predict:
	t++;
tree25_predict:
	f++;
tree26_predict:
	t++;
tree27_predict:
	if(attr[1] < 57.500000){
		f++;
	}
	else{
		t++;
	}
tree28_predict:
	if(attr[1] < 60.500000){
		f++;
	}
	else{
		t++;
	}
tree29_predict:
	if(attr[1] < 66.500000){
		f++;
	}
	else{
		t++;
	}
tree30_predict:
	if(attr[1] < 63.500000){
		f++;
	}
	else{
		t++;
	}
voting:
	if(t > f)	return 1;
	else	return -1;
}
