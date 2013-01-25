/**
 * @Copyright (c) 2012, JuJian
 * All rights reserved.
 * 
 * The sum of the squares of the first ten natural numbers is,
 *		1*1 + 2*2 + ... + 10*10 = 385
 * The square of the sum of the first ten natural numbers is,
 *		(1 + 2 + ... + 10)2(square) = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>

int main(int argc, char *argv[]){
	/**
	* 1*1+2*2+...+n*n = n*(n+1)*(2*n+1)/6
	*/
	printf("%d\n",5050*5050-100*101*(2*100+1)/6);
	return 0;
}
