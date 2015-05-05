int tree_predict(double *attr){
	if(attr[13] < 4.500000){
		if(attr[3] < 3.500000){
			if(attr[10] < 2.300000){
				if(attr[5] < 154.500000){
					if(attr[1] < 46.500000){
						return -1;
					}
					else{
						return 1;
					}
				}
				else{
					if(attr[5] < 272.000000){
						return -1;
					}
					else{
						if(attr[3] < 1.500000){
							return 1;
						}
						else{
							if(attr[12] < 1.500000){
								return -1;
							}
							else{
								return 1;
							}
						}
					}
				}
			}
			else{
				if(attr[1] < 63.500000){
					return 1;
				}
				else{
					return -1;
				}
			}
		}
		else{
			if(attr[12] < 0.500000){
				if(attr[4] < 145.000000){
					if(attr[8] < 96.500000){
						return 1;
					}
					else{
						return -1;
					}
				}
				else{
					if(attr[1] < 63.000000){
						return 1;
					}
					else{
						return -1;
					}
				}
			}
			else{
				if(attr[2] < 0.500000){
					if(attr[1] < 63.500000){
						if(attr[1] < 59.500000){
							return -1;
						}
						else{
							return 1;
						}
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
		if(attr[12] < 0.500000){
			if(attr[3] < 3.500000){
				if(attr[1] < 39.000000){
					return 1;
				}
				else{
					if(attr[8] < 143.000000){
						if(attr[1] < 60.500000){
							return 1;
						}
						else{
							return -1;
						}
					}
					else{
						return -1;
					}
				}
			}
			else{
				if(attr[1] < 56.500000){
					if(attr[10] < 0.250000){
						if(attr[1] < 42.000000){
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
				else{
					if(attr[4] < 140.000000){
						return -1;
					}
					else{
						if(attr[9] < 0.500000){
							return -1;
						}
						else{
							return 1;
						}
					}
				}
			}
		}
		else{
			if(attr[5] < 151.500000){
				return -1;
			}
			else{
				return 1;
			}
		}
	}
}
