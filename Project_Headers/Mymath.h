/*
 * Mymath.h
 *
 *  Created on: Mar 6, 2021
 *      Author: »ÆÓÖÓÖ
 */

#ifndef MYMATH_H_
#define MYMATH_H_

double sqrt(double a){
	double x,y;
	x=0.0;
	y=a/2;
	while(x!=y){
		x=y;
		y=(x+a/x)/2;
	}
	return x;
	
}

int16 round(double a){
	return (a-a/1)>=0.5?a/1+1:a/1;
	
}

#endif /* MYMATH_H_ */
