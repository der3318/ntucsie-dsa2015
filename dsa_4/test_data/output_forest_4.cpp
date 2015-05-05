int forest_predict(double *attr){
	int t = 0, f = 0;
tree1_predict:
	if(attr[9] < 0.500000){
		f++;
	}
	else{
		if(attr[3] < 3.500000){
			f++;
		}
		else{
			t++;
		}
	}
tree2_predict:
	if(attr[13] < 6.500000){
		if(attr[1] < 57.500000){
			f++;
		}
		else{
			if(attr[2] < 0.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
	else{
		t++;
	}
tree3_predict:
	if(attr[8] < 147.000000){
		if(attr[10] < 1.100000){
			if(attr[5] < 285.500000){
				f++;
			}
			else{
				t++;
			}
		}
		else{
			t++;
		}
	}
	else{
		f++;
	}
tree4_predict:
	if(attr[13] < 6.500000){
		if(attr[4] < 115.000000){
			t++;
		}
		else{
			if(attr[5] < 185.500000){
				t++;
			}
			else{
				f++;
			}
		}
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[3] < 2.000000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
tree5_predict:
	if(attr[3] < 3.500000){
		if(attr[5] < 330.000000){
			if(attr[5] < 276.500000){
				f++;
			}
			else{
				if(attr[1] < 57.000000){
					f++;
				}
				else{
					t++;
				}
			}
		}
		else{
			t++;
		}
	}
	else{
		if(attr[4] < 147.500000){
			t++;
		}
		else{
			f++;
		}
	}
tree6_predict:
	if(attr[10] < 1.550000){
		if(attr[1] < 58.500000){
			if(attr[4] < 115.000000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			if(attr[1] < 66.500000){
				t++;
			}
			else{
				f++;
			}
		}
	}
	else{
		t++;
	}
tree7_predict:
	if(attr[10] < 0.900000){
		if(attr[4] < 162.500000){
			f++;
		}
		else{
			t++;
		}
	}
	else{
		if(attr[1] < 40.000000){
			f++;
		}
		else{
			if(attr[1] < 66.500000){
				t++;
			}
			else{
				f++;
			}
		}
	}
tree8_predict:
	if(attr[10] < 0.800000){
		if(attr[5] < 276.500000){
			f++;
		}
		else{
			t++;
		}
	}
	else{
		if(attr[13] < 5.000000){
			if(attr[10] < 2.300000){
				f++;
			}
			else{
				t++;
			}
		}
		else{
			t++;
		}
	}
tree9_predict:
	if(attr[3] < 3.500000){
		if(attr[8] < 114.500000){
			t++;
		}
		else{
			f++;
		}
	}
	else{
		if(attr[5] < 236.500000){
			f++;
		}
		else{
			t++;
		}
	}
tree10_predict:
	if(attr[11] < 1.500000){
		if(attr[9] < 0.500000){
			f++;
		}
		else{
			t++;
		}
	}
	else{
		if(attr[10] < 0.700000){
			f++;
		}
		else{
			if(attr[12] < 2.500000){
				if(attr[6] < 0.500000){
					t++;
				}
				else{
					if(attr[1] < 47.000000){
						t++;
					}
					else{
						f++;
					}
				}
			}
			else{
				f++;
			}
		}
	}
tree11_predict:
	if(attr[1] < 51.500000){
		f++;
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[4] < 137.500000){
				f++;
			}
			else{
				if(attr[6] < 0.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
		else{
			t++;
		}
	}
tree12_predict:
	if(attr[3] < 3.500000){
		if(attr[5] < 192.000000){
			t++;
		}
		else{
			if(attr[4] < 114.000000){
				if(attr[1] < 53.000000){
					t++;
				}
				else{
					f++;
				}
			}
			else{
				if(attr[5] < 318.500000){
					f++;
				}
				else{
					if(attr[1] < 61.000000){
						f++;
					}
					else{
						t++;
					}
				}
			}
		}
	}
	else{
		t++;
	}
tree13_predict:
	if(attr[13] < 6.500000){
		if(attr[10] < 1.650000){
			f++;
		}
		else{
			if(attr[1] < 54.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[3] < 2.500000){
				t++;
			}
			else{
				if(attr[1] < 65.000000){
					f++;
				}
				else{
					t++;
				}
			}
		}
		else{
			t++;
		}
	}
tree14_predict:
	if(attr[3] < 3.500000){
		f++;
	}
	else{
		if(attr[10] < 0.600000){
			if(attr[1] < 52.500000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
tree15_predict:
	if(attr[3] < 3.500000){
		if(attr[5] < 330.000000){
			f++;
		}
		else{
			t++;
		}
	}
	else{
		t++;
	}
tree16_predict:
	if(attr[10] < 0.500000){
		if(attr[9] < 0.500000){
			f++;
		}
		else{
			t++;
		}
	}
	else{
		if(attr[5] < 245.500000){
			if(attr[3] < 3.500000){
				if(attr[10] < 2.200000){
					f++;
				}
				else{
					t++;
				}
			}
			else{
				t++;
			}
		}
		else{
			t++;
		}
	}
tree17_predict:
	if(attr[11] < 1.500000){
		f++;
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[4] < 121.000000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
tree18_predict:
	if(attr[8] < 145.500000){
		t++;
	}
	else{
		if(attr[9] < 0.500000){
			f++;
		}
		else{
			if(attr[1] < 51.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
tree19_predict:
	if(attr[8] < 146.500000){
		t++;
	}
	else{
		if(attr[11] < 2.500000){
			if(attr[1] < 44.500000){
				if(attr[1] < 39.500000){
					f++;
				}
				else{
					t++;
				}
			}
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
tree20_predict:
	if(attr[10] < 1.700000){
		if(attr[4] < 156.000000){
			if(attr[3] < 3.500000){
				f++;
			}
			else{
				if(attr[1] < 48.500000){
					f++;
				}
				else{
					t++;
				}
			}
		}
		else{
			t++;
		}
	}
	else{
		t++;
	}
tree21_predict:
	if(attr[8] < 147.000000){
		t++;
	}
	else{
		if(attr[12] < 0.500000){
			f++;
		}
		else{
			if(attr[2] < 0.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
tree22_predict:
	if(attr[8] < 141.500000){
		t++;
	}
	else{
		if(attr[4] < 155.000000){
			f++;
		}
		else{
			t++;
		}
	}
tree23_predict:
	if(attr[3] < 3.500000){
		if(attr[8] < 131.500000){
			t++;
		}
		else{
			if(attr[5] < 280.500000){
				f++;
			}
			else{
				if(attr[5] < 296.000000){
					t++;
				}
				else{
					f++;
				}
			}
		}
	}
	else{
		if(attr[7] < 1.000000){
			f++;
		}
		else{
			t++;
		}
	}
tree24_predict:
	if(attr[8] < 134.000000){
		t++;
	}
	else{
		if(attr[10] < 1.550000){
			if(attr[5] < 321.500000){
				if(attr[4] < 155.000000){
					f++;
				}
				else{
					if(attr[1] < 63.000000){
						t++;
					}
					else{
						f++;
					}
				}
			}
			else{
				t++;
			}
		}
		else{
			if(attr[5] < 249.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
tree25_predict:
	if(attr[9] < 0.500000){
		if(attr[5] < 266.000000){
			if(attr[4] < 120.000000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			if(attr[5] < 292.000000){
				if(attr[1] < 65.000000){
					t++;
				}
				else{
					f++;
				}
			}
			else{
				f++;
			}
		}
	}
	else{
		t++;
	}
tree26_predict:
	if(attr[13] < 6.500000){
		f++;
	}
	else{
		if(attr[1] < 53.500000){
			f++;
		}
		else{
			t++;
		}
	}
tree27_predict:
	if(attr[13] < 5.000000){
		if(attr[3] < 3.500000){
			if(attr[5] < 194.500000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
	else{
		if(attr[4] < 107.500000){
			f++;
		}
		else{
			t++;
		}
	}
tree28_predict:
	if(attr[1] < 59.500000){
		if(attr[13] < 6.500000){
			f++;
		}
		else{
			if(attr[3] < 3.500000){
				if(attr[11] < 2.500000){
					f++;
				}
				else{
					t++;
				}
			}
			else{
				t++;
			}
		}
	}
	else{
		t++;
	}
tree29_predict:
	if(attr[3] < 3.500000){
		if(attr[4] < 160.000000){
			f++;
		}
		else{
			t++;
		}
	}
	else{
		if(attr[5] < 204.000000){
			if(attr[1] < 55.500000){
				t++;
			}
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
tree30_predict:
	if(attr[8] < 147.000000){
		t++;
	}
	else{
		if(attr[4] < 115.000000){
			t++;
		}
		else{
			if(attr[10] < 1.700000){
				f++;
			}
			else{
				t++;
			}
		}
	}
voting:
	if(t > f)	return 1;
	else	return -1;
}
