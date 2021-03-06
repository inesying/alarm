/*
 * MusicLibrary.c
 *
 *  Created on: Mar 5, 2021
 *      Author: ??????
 */

#include "MusicLibrary.h"
#include "Types.h"

Music MusicLibrary_rainbow;
Music MusicLibrary_test1;
Music MusicLibrary_test2;

static const int8 tune1[] = {7,7,5,4,2,7,4,4,5,4,-1,0,2,4,2,0,4,5,4};
static const int8 duration1[] = {4,1,1,2,2,6,4,2,1,9,4,2,1,1,4,2,1,1,6};

static const int8 tune2[] = {0,1,2,3,4,5,6,7,8,9,10,11};
static const int8 duration2[] = {2,2,2,2,2,2,2,2,2,2,2,2};

void MusicLibrary_init()
{
	MusicLibrary_rainbow.tune = tune1;
	MusicLibrary_rainbow.duration = duration1;
	MusicLibrary_rainbow.length = sizeof(tune1);
	MusicLibrary_rainbow.name = "Rainbow";
	
	MusicLibrary_test1.tune = tune2;
	MusicLibrary_test1.duration = duration2;
	MusicLibrary_test1.length = sizeof(tune2);
	MusicLibrary_test1.name = "Test-Seq";
	
	MusicLibrary_test2.tune = &tune1;
	MusicLibrary_test2.duration = &duration1;
	MusicLibrary_test2.length = sizeof(tune1);
	MusicLibrary_test2.name = "Test-2";
}
