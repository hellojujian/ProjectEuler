/**
 * @Copyright (c) 2012, JuJian
 * All rights reserved.
 * 
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>

int pow_int(int a,int pow);
int main(int argc, char *argv[]){
	int prime_number[] = {2,3,5,7,11,13,17,19};
	int left_number[] = {4,6,8,9,10,12,14,15,16,18,20};
	int prime_count[11][8]={0};
	
	/*after circle,we get an array of every left number's(except prime number)
	 *prime factor
	 */
	int i = 0,tmp_factor = 2;
	for(i; i<12; i++){
		int j = 0;
		tmp_factor = prime_number[0];
		while(left_number[i] != 1){//while not evenly divided
			if(left_number[i] >= tmp_factor){
				if(left_number[i]%tmp_factor == 0){
					left_number[i] = left_number[i]/tmp_factor;
					prime_count[i][j]++;
				}else{
					j++;
					tmp_factor = prime_number[j];
				}
			}else{
				break;
			}			
		}
	}
	
	/*get the least common multiple
	 */
	int prime_number_new[] = {2,3,5,7,11,13,17,19};
	int lcm = 1,j = 0,max_times = 0;
	i = 0;
	for(i; i<8; i++){
		int max_times = 1;
		for(j; j<12; j++){
			if(prime_count[j][i] > max_times){
				max_times = prime_count[j][i];
			}
		}
		if(max_times == 1){
			lcm *= prime_number_new[i];
		}else{
			lcm *= pow_int(prime_number_new[i],max_times);
		}
		j = 0;
	}
	
	printf("%d",lcm);
	return 0;
}

int pow_int(int a,int pow){
	if(pow>1){
		int i = 1,res = 1;
		for(i; i<=pow; i++){
			res *= a;
		}
		return res;
	}
	return 0;
}