int tree_predict(double *attr){
	if(attr[3] < 3.500000){
		if(attr[1] < 57.500000){
			return -1;
		}
		else{
			if(attr[11] < 1.500000){
				if(attr[5] < 326.500000){
					return -1;
				}
				else{
					if(attr[1] < 61.000000){
						return -1;
					}
					else{
						return 1;
					}
				}
			}
			else{
				if(attr[5] < 253.000000){
					if(attr[5] < 208.000000){
						return 1;
					}
					else{
						return -1;
					}
				}
				else{
					return 1;
				}
			}
		}
	}
	else{
		if(attr[13] < 6.500000){
			if(attr[12] < 0.500000){
				return -1;
			}
			else{
				return 1;
			}
		}
		else{
			return 1;
		}
	}
}
