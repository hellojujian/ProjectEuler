/**
 * @Copyright (c) 2012, JuJian
 * All rights reserved.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef enum {false = 0, true = 1} bool;
bool is_palindrome(int num);
int  reverse_number(int num);

int main(int argc, char *argv[]){
	int start = 100,limit = 999,i = start,j = start,palindrome = 0;
	
	for(i; i<=limit; i++){
		for(j; j<=limit; j++){
			if(i*j == reverse_number(i*j) && (i*j) >= palindrome){
				printf("%d\t%d*%d\n",palindrome,i,j);
				palindrome = i*j;
			}
		}
		j=start;
	}
	
	//palindrome = reverse_number(1078);
	printf("%d\n",palindrome);
	return 0;
}

int reverse_number(int num){
	if(num>=0 && num<INT_MAX){
		//get digit of num
		int i = 10,digit = 0;
		for(i; i<=INT_MAX; i*=10){
			digit++;
			if(num%i == num){
				break;
			}
		}
		//separate number
		int j = 10,pos = 0,num_str[digit];
		for(j; j<=i; j*=10){
			num_str[pos] = (num%j)/(j/10);
			pos++;
		}
		//get the reverse number
		int r_number = 0;
		i = 0;
		pos -= 1;
		for(i; i<=pos; i++){
			if(i == pos){
				r_number += num_str[i];
			}else{
				int j = 1;
				for(j; j<=(pos-i); j++){
					num_str[i] *= 10;
				}
				r_number += num_str[i];
			}
		}
		return r_number;
	}
	return 0;
}
