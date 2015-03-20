#!/bin/bash

./Random > input
./der_binary < input > der_out
./gcd_by_binary < input > your_out
diff der_out your_out
