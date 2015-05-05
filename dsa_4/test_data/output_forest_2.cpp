int forest_predict(double *attr){
	int t = 0, f = 0;
tree1_predict:
	if(attr[3] < 3.500000){
		if(attr[8] < 147.000000){
			if(attr[1] < 64.000000){
				if(attr[1] < 48.500000){
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
			if(attr[1] < 57.500000){
				f++;
			}
			else{
				if(attr[3] < 2.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
	}
	else{
		if(attr[12] < 0.500000){
			if(attr[1] < 47.500000){
				t++;
			}
			else{
				if(attr[4] < 150.000000){
					if(attr[1] < 60.000000){
						f++;
					}
					else{
						if(attr[1] < 66.000000){
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
		}
		else{
			t++;
		}
	}
tree2_predict:
	if(attr[8] < 148.500000){
		if(attr[2] < 0.500000){
			f++;
		}
		else{
			if(attr[1] < 63.500000){
				t++;
			}
			else{
				if(attr[5] < 258.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
	}
	else{
		if(attr[13] < 5.000000){
			if(attr[4] < 115.000000){
				if(attr[1] < 51.000000){
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
			if(attr[3] < 3.500000){
				if(attr[4] < 171.000000){
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
tree3_predict:
	if(attr[13] < 4.500000){
		if(attr[10] < 3.300000){
			if(attr[4] < 167.000000){
				if(attr[5] < 322.500000){
					if(attr[4] < 111.000000){
						if(attr[5] < 198.000000){
							t++;
						}
						else{
							if(attr[1] < 46.000000){
								f++;
							}
							else{
								if(attr[1] < 48.500000){
									t++;
								}
								else{
									f++;
								}
							}
						}
					}
					else{
						if(attr[10] < 2.300000){
							f++;
						}
						else{
							if(attr[1] < 63.500000){
								t++;
							}
							else{
								f++;
							}
						}
					}
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
			t++;
		}
	}
	else{
		if(attr[3] < 2.500000){
			f++;
		}
		else{
			if(attr[4] < 111.000000){
				if(attr[1] < 57.500000){
					f++;
				}
				else{
					t++;
				}
			}
			else{
				if(attr[10] < 0.350000){
					if(attr[1] < 52.000000){
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
		}
	}
tree4_predict:
	if(attr[13] < 5.000000){
		if(attr[1] < 51.500000){
			f++;
		}
		else{
			if(attr[7] < 0.500000){
				if(attr[1] < 53.000000){
					t++;
				}
				else{
					if(attr[4] < 145.000000){
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
			}
			else{
				if(attr[1] < 58.500000){
					if(attr[9] < 0.500000){
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
	}
	else{
		if(attr[12] < 0.500000){
			if(attr[3] < 3.500000){
				f++;
			}
			else{
				if(attr[8] < 167.000000){
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
tree5_predict:
	if(attr[3] < 3.500000){
		if(attr[10] < 1.950000){
			if(attr[4] < 176.000000){
				if(attr[8] < 117.000000){
					if(attr[1] < 61.000000){
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
		else{
			if(attr[3] < 2.000000){
				f++;
			}
			else{
				t++;
			}
		}
	}
	else{
		if(attr[13] < 6.500000){
			if(attr[8] < 125.500000){
				if(attr[1] < 63.000000){
					t++;
				}
				else{
					if(attr[1] < 65.500000){
						f++;
					}
					else{
						t++;
					}
				}
			}
			else{
				if(attr[8] < 166.000000){
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
tree6_predict:
	if(attr[12] < 0.500000){
		if(attr[8] < 148.500000){
			if(attr[1] < 50.500000){
				t++;
			}
			else{
				if(attr[4] < 167.000000){
					if(attr[8] < 83.500000){
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
		}
		else{
			f++;
		}
	}
	else{
		if(attr[2] < 0.500000){
			if(attr[4] < 169.000000){
				f++;
			}
			else{
				t++;
			}
		}
		else{
			if(attr[8] < 172.500000){
				t++;
			}
			else{
				if(attr[1] < 51.000000){
					f++;
				}
				else{
					t++;
				}
			}
		}
	}
tree7_predict:
	if(attr[12] < 0.500000){
		if(attr[4] < 146.000000){
			if(attr[8] < 114.500000){
				if(attr[4] < 141.000000){
					t++;
				}
				else{
					f++;
				}
			}
			else{
				if(attr[13] < 6.500000){
					f++;
				}
				else{
					if(attr[8] < 163.500000){
						f++;
					}
					else{
						t++;
					}
				}
			}
		}
		else{
			if(attr[3] < 2.000000){
				f++;
			}
			else{
				t++;
			}
		}
	}
	else{
		if(attr[13] < 4.500000){
			if(attr[11] < 1.500000){
				if(attr[5] < 317.000000){
					f++;
				}
				else{
					if(attr[1] < 61.500000){
						t++;
					}
					else{
						f++;
					}
				}
			}
			else{
				if(attr[11] < 2.500000){
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
tree8_predict:
	if(attr[3] < 3.500000){
		if(attr[8] < 153.500000){
			if(attr[12] < 1.500000){
				if(attr[13] < 4.500000){
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
	}
	else{
		if(attr[9] < 0.500000){
			if(attr[12] < 0.500000){
				if(attr[5] < 303.500000){
					f++;
				}
				else{
					t++;
				}
			}
			else{
				if(attr[13] < 5.000000){
					f++;
				}
				else{
					t++;
				}
			}
		}
		else{
			if(attr[8] < 170.500000){
				t++;
			}
			else{
				f++;
			}
		}
	}
tree9_predict:
	if(attr[13] < 4.500000){
		if(attr[12] < 2.500000){
			if(attr[5] < 242.500000){
				f++;
			}
			else{
				if(attr[5] < 249.500000){
					t++;
				}
				else{
					if(attr[10] < 0.750000){
						f++;
					}
					else{
						t++;
					}
				}
			}
		}
		else{
			t++;
		}
	}
	else{
		if(attr[12] < 0.500000){
			if(attr[3] < 3.500000){
				f++;
			}
			else{
				if(attr[8] < 158.500000){
					t++;
				}
				else{
					if(attr[5] < 254.000000){
						f++;
					}
					else{
						t++;
					}
				}
			}
		}
		else{
			if(attr[8] < 108.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
tree10_predict:
	if(attr[12] < 0.500000){
		if(attr[3] < 3.500000){
			if(attr[10] < 3.050000){
				if(attr[8] < 156.000000){
					if(attr[1] < 60.000000){
						if(attr[4] < 104.000000){
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
					f++;
				}
			}
			else{
				t++;
			}
		}
		else{
			if(attr[4] < 141.000000){
				if(attr[2] < 0.500000){
					f++;
				}
				else{
					if(attr[1] < 45.500000){
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
	}
	else{
		if(attr[1] < 46.500000){
			f++;
		}
		else{
			if(attr[1] < 70.500000){
				if(attr[1] < 55.000000){
					if(attr[2] < 0.500000){
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
		}
	}
tree11_predict:
	if(attr[3] < 3.500000){
		if(attr[5] < 253.000000){
			if(attr[4] < 113.000000){
				if(attr[5] < 232.500000){
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
			if(attr[2] < 0.500000){
				if(attr[12] < 1.500000){
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
		if(attr[10] < 0.700000){
			if(attr[1] < 65.500000){
				if(attr[4] < 146.000000){
					if(attr[12] < 0.500000){
						f++;
					}
					else{
						if(attr[5] < 231.500000){
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
				t++;
			}
		}
		else{
			if(attr[2] < 0.500000){
				if(attr[4] < 134.000000){
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
tree12_predict:
	if(attr[8] < 148.000000){
		if(attr[2] < 0.500000){
			if(attr[5] < 284.500000){
				f++;
			}
			else{
				t++;
			}
		}
		else{
			if(attr[3] < 1.500000){
				if(attr[7] < 1.000000){
					t++;
				}
				else{
					f++;
				}
			}
			else{
				if(attr[8] < 107.000000){
					f++;
				}
				else{
					if(attr[4] < 155.000000){
						t++;
					}
					else{
						if(attr[5] < 237.000000){
							f++;
						}
						else{
							t++;
						}
					}
				}
			}
		}
	}
	else{
		if(attr[13] < 6.500000){
			f++;
		}
		else{
			if(attr[5] < 248.000000){
				if(attr[8] < 170.500000){
					f++;
				}
				else{
					if(attr[4] < 126.000000){
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
	}
tree13_predict:
	if(attr[10] < 3.100000){
		if(attr[13] < 4.500000){
			if(attr[3] < 3.500000){
				f++;
			}
			else{
				if(attr[9] < 0.500000){
					if(attr[8] < 164.500000){
						f++;
					}
					else{
						if(attr[4] < 134.000000){
							t++;
						}
						else{
							f++;
						}
					}
				}
				else{
					if(attr[1] < 46.000000){
						f++;
					}
					else{
						t++;
					}
				}
			}
		}
		else{
			if(attr[1] < 52.000000){
				t++;
			}
			else{
				if(attr[12] < 1.500000){
					if(attr[3] < 2.500000){
						t++;
					}
					else{
						if(attr[5] < 269.500000){
							f++;
						}
						else{
							if(attr[1] < 62.000000){
								t++;
							}
							else{
								f++;
							}
						}
					}
				}
				else{
					t++;
				}
			}
		}
	}
	else{
		t++;
	}
tree14_predict:
	if(attr[13] < 4.500000){
		if(attr[8] < 119.500000){
			t++;
		}
		else{
			if(attr[9] < 0.500000){
				if(attr[10] < 2.800000){
					if(attr[4] < 109.000000){
						if(attr[2] < 0.500000){
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
			else{
				if(attr[3] < 3.500000){
					f++;
				}
				else{
					if(attr[1] < 58.000000){
						if(attr[5] < 255.000000){
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
			}
		}
	}
	else{
		if(attr[8] < 158.500000){
			if(attr[10] < 0.400000){
				if(attr[8] < 151.500000){
					if(attr[1] < 65.000000){
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
		else{
			if(attr[4] < 137.500000){
				f++;
			}
			else{
				t++;
			}
		}
	}
tree15_predict:
	if(attr[3] < 3.500000){
		if(attr[10] < 1.950000){
			if(attr[5] < 278.500000){
				if(attr[5] < 154.500000){
					t++;
				}
				else{
					if(attr[8] < 142.000000){
						if(attr[8] < 140.000000){
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
			}
			else{
				if(attr[4] < 134.000000){
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
		if(attr[9] < 0.500000){
			if(attr[13] < 5.000000){
				if(attr[8] < 96.500000){
					t++;
				}
				else{
					f++;
				}
			}
			else{
				if(attr[1] < 45.500000){
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
tree16_predict:
	if(attr[12] < 0.500000){
		if(attr[3] < 3.500000){
			if(attr[4] < 109.000000){
				if(attr[2] < 0.500000){
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
			if(attr[1] < 61.500000){
				if(attr[10] < 0.700000){
					if(attr[4] < 147.000000){
						if(attr[1] < 60.000000){
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
			else{
				f++;
			}
		}
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[13] < 4.500000){
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
tree17_predict:
	if(attr[3] < 3.500000){
		if(attr[8] < 129.500000){
			if(attr[2] < 0.500000){
				f++;
			}
			else{
				t++;
			}
		}
		else{
			if(attr[4] < 133.000000){
				f++;
			}
			else{
				if(attr[5] < 237.000000){
					t++;
				}
				else{
					f++;
				}
			}
		}
	}
	else{
		if(attr[12] < 0.500000){
			if(attr[13] < 6.500000){
				if(attr[4] < 149.000000){
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
				if(attr[10] < 0.250000){
					if(attr[1] < 41.500000){
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
		}
		else{
			if(attr[5] < 298.500000){
				if(attr[4] < 109.000000){
					f++;
				}
				else{
					t++;
				}
			}
			else{
				if(attr[1] < 51.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
	}
tree18_predict:
	if(attr[12] < 0.500000){
		if(attr[13] < 4.500000){
			if(attr[10] < 3.100000){
				if(attr[4] < 109.000000){
					if(attr[1] < 43.000000){
						f++;
					}
					else{
						t++;
					}
				}
				else{
					if(attr[1] < 60.000000){
						f++;
					}
					else{
						if(attr[1] < 61.500000){
							t++;
						}
						else{
							f++;
						}
					}
				}
			}
			else{
				t++;
			}
		}
		else{
			if(attr[4] < 122.000000){
				if(attr[1] < 40.500000){
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
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[11] < 1.500000){
				f++;
			}
			else{
				if(attr[11] < 2.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
		else{
			if(attr[5] < 301.000000){
				t++;
			}
			else{
				if(attr[5] < 303.500000){
					f++;
				}
				else{
					t++;
				}
			}
		}
	}
tree19_predict:
	if(attr[13] < 4.500000){
		if(attr[4] < 167.000000){
			if(attr[10] < 3.300000){
				if(attr[5] < 311.000000){
					if(attr[4] < 115.000000){
						if(attr[1] < 46.500000){
							f++;
						}
						else{
							if(attr[1] < 58.000000){
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
				else{
					if(attr[1] < 57.500000){
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
	}
	else{
		if(attr[4] < 111.000000){
			if(attr[1] < 58.000000){
				f++;
			}
			else{
				t++;
			}
		}
		else{
			if(attr[12] < 0.500000){
				if(attr[9] < 0.500000){
					if(attr[8] < 143.000000){
						if(attr[1] < 60.500000){
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
				else{
					t++;
				}
			}
			else{
				t++;
			}
		}
	}
tree20_predict:
	if(attr[12] < 0.500000){
		if(attr[13] < 6.500000){
			if(attr[8] < 83.500000){
				t++;
			}
			else{
				if(attr[4] < 146.000000){
					if(attr[4] < 109.000000){
						if(attr[2] < 0.500000){
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
					if(attr[1] < 63.000000){
						t++;
					}
					else{
						f++;
					}
				}
			}
		}
		else{
			if(attr[8] < 143.000000){
				t++;
			}
			else{
				if(attr[4] < 122.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[13] < 5.000000){
				if(attr[5] < 277.500000){
					f++;
				}
				else{
					if(attr[2] < 0.500000){
						if(attr[8] < 154.500000){
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
			}
			else{
				t++;
			}
		}
		else{
			t++;
		}
	}
tree21_predict:
	if(attr[13] < 4.500000){
		if(attr[3] < 3.500000){
			f++;
		}
		else{
			if(attr[2] < 0.500000){
				if(attr[4] < 145.000000){
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
	}
	else{
		if(attr[8] < 153.500000){
			if(attr[10] < 0.250000){
				if(attr[1] < 65.000000){
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
			if(attr[5] < 231.000000){
				if(attr[4] < 111.000000){
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
	}
tree22_predict:
	if(attr[10] < 1.950000){
		if(attr[13] < 4.500000){
			if(attr[8] < 96.500000){
				t++;
			}
			else{
				if(attr[4] < 109.000000){
					if(attr[2] < 0.500000){
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
		}
		else{
			if(attr[5] < 217.000000){
				f++;
			}
			else{
				if(attr[3] < 3.500000){
					if(attr[1] < 55.000000){
						f++;
					}
					else{
						if(attr[1] < 60.500000){
							t++;
						}
						else{
							f++;
						}
					}
				}
				else{
					if(attr[4] < 109.000000){
						if(attr[1] < 55.000000){
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
		}
	}
	else{
		if(attr[11] < 1.500000){
			if(attr[1] < 62.000000){
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
tree23_predict:
	if(attr[10] < 0.850000){
		if(attr[12] < 2.500000){
			if(attr[8] < 152.500000){
				if(attr[1] < 58.500000){
					if(attr[4] < 129.000000){
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
			else{
				f++;
			}
		}
		else{
			t++;
		}
	}
	else{
		if(attr[8] < 155.500000){
			if(attr[2] < 0.500000){
				if(attr[4] < 125.000000){
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
			if(attr[10] < 2.250000){
				f++;
			}
			else{
				t++;
			}
		}
	}
tree24_predict:
	if(attr[13] < 4.500000){
		if(attr[12] < 0.500000){
			if(attr[5] < 327.500000){
				if(attr[4] < 109.000000){
					if(attr[1] < 49.000000){
						if(attr[1] < 46.000000){
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
					f++;
				}
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
			if(attr[1] < 64.000000){
				if(attr[1] < 48.500000){
					if(attr[3] < 3.500000){
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
		}
	}
	else{
		if(attr[3] < 1.500000){
			f++;
		}
		else{
			if(attr[2] < 0.500000){
				f++;
			}
			else{
				if(attr[8] < 108.000000){
					if(attr[1] < 63.000000){
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
		}
	}
tree25_predict:
	if(attr[13] < 6.500000){
		if(attr[3] < 3.500000){
			if(attr[13] < 4.500000){
				if(attr[3] < 1.500000){
					if(attr[1] < 58.000000){
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
				if(attr[1] < 59.500000){
					t++;
				}
				else{
					f++;
				}
			}
		}
		else{
			if(attr[1] < 66.500000){
				if(attr[1] < 44.500000){
					t++;
				}
				else{
					if(attr[8] < 117.000000){
						t++;
					}
					else{
						if(attr[5] < 327.500000){
							if(attr[4] < 144.000000){
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
							if(attr[1] < 61.500000){
								t++;
							}
							else{
								f++;
							}
						}
					}
				}
			}
			else{
				t++;
			}
		}
	}
	else{
		if(attr[3] < 3.500000){
			if(attr[5] < 250.500000){
				if(attr[4] < 136.000000){
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
		else{
			if(attr[1] < 64.000000){
				if(attr[4] < 114.000000){
					if(attr[1] < 55.000000){
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
		}
	}
tree26_predict:
	if(attr[12] < 1.500000){
		if(attr[4] < 146.000000){
			if(attr[8] < 147.500000){
				if(attr[12] < 0.500000){
					if(attr[1] < 38.500000){
						t++;
					}
					else{
						f++;
					}
				}
				else{
					if(attr[8] < 128.500000){
						if(attr[1] < 49.000000){
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
			}
			else{
				f++;
			}
		}
		else{
			if(attr[1] < 61.500000){
				if(attr[4] < 151.000000){
					if(attr[1] < 50.000000){
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
				f++;
			}
		}
	}
	else{
		if(attr[11] < 1.500000){
			if(attr[8] < 155.500000){
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
tree27_predict:
	if(attr[13] < 4.500000){
		if(attr[1] < 51.500000){
			f++;
		}
		else{
			if(attr[9] < 0.500000){
				if(attr[2] < 0.500000){
					f++;
				}
				else{
					if(attr[1] < 56.500000){
						if(attr[4] < 120.000000){
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
			}
			else{
				if(attr[3] < 3.000000){
					f++;
				}
				else{
					t++;
				}
			}
		}
	}
	else{
		if(attr[4] < 117.500000){
			if(attr[8] < 151.000000){
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
tree28_predict:
	if(attr[13] < 4.500000){
		if(attr[10] < 2.300000){
			if(attr[4] < 149.000000){
				if(attr[8] < 112.000000){
					t++;
				}
				else{
					f++;
				}
			}
			else{
				if(attr[1] < 63.500000){
					if(attr[5] < 242.000000){
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
		}
		else{
			t++;
		}
	}
	else{
		if(attr[12] < 0.500000){
			if(attr[9] < 0.500000){
				if(attr[3] < 2.500000){
					if(attr[1] < 60.000000){
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
			else{
				if(attr[4] < 141.000000){
					t++;
				}
				else{
					if(attr[1] < 56.000000){
						f++;
					}
					else{
						t++;
					}
				}
			}
		}
		else{
			t++;
		}
	}
tree29_predict:
	if(attr[3] < 3.500000){
		if(attr[12] < 0.500000){
			if(attr[4] < 158.000000){
				f++;
			}
			else{
				if(attr[4] < 169.000000){
					t++;
				}
				else{
					f++;
				}
			}
		}
		else{
			if(attr[10] < 0.300000){
				if(attr[5] < 303.500000){
					f++;
				}
				else{
					t++;
				}
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
	}
	else{
		if(attr[5] < 235.000000){
			if(attr[8] < 133.000000){
				t++;
			}
			else{
				if(attr[8] < 153.000000){
					f++;
				}
				else{
					if(attr[5] < 193.000000){
						t++;
					}
					else{
						if(attr[10] < 0.500000){
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
	}
tree30_predict:
	if(attr[13] < 4.500000){
		if(attr[8] < 111.000000){
			t++;
		}
		else{
			if(attr[10] < 3.100000){
				if(attr[4] < 146.000000){
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
			}
			else{
				t++;
			}
		}
	}
	else{
		if(attr[12] < 0.500000){
			if(attr[1] < 55.000000){
				if(attr[4] < 105.500000){
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
			if(attr[4] < 110.000000){
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
