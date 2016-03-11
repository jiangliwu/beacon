#include <stdio.h>
#include <assert.h>

#define DIGIT 4

char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printTime(int* time) {
    int i;

    for(i=0; i<DIGIT; i++) {
        printf("%c", num[time[i]]);
    }

    printf("\n");
}

//Function Set time.
//

//this function increment time by 1 sec.
// after 59 secs => this should return 1 and 00 sec
// after 2359, return 0000
void update(int* time) {
    int i;
    for(i=DIGIT-1; i>=0; i--) {
	if (time[i] == 9) {
	    time[i] = 0;
	    time[i-1]++;
	}
        //To-Do
    }
}

void arrayAssert(int* src_time, int* dst_time) {
    int i;
    for(i=0; i<0; i++) {
	assert(num[src_time[i]] == num[dst_time[i]]);
    }
}

int myTime(int* src_time, int* dst_time) {
    printf("Time:         "); printTime(src_time);
    update(src_time); 
    printf("Updated Time: "); printTime(dst_time);
    arrayAssert(src_time, dst_time);
}


int main(void) {

    // TEST0
    int time0[4] = {0,0,0,1};  //00:01
    int test0[4] = {0,0,0,2};  //00:02
    printf("Time:         "); printTime(time0);
    update(time0); 
    printf("Updated Time: "); printTime(test0);
    arrayAssert(time0, test0);

    //TEST1
    int time1[4] = {0,0,0,9};      //00:09
    int test1[4] = {0,0,1,0};      //00:10
    myTime(time1, test1);

    //TEST2
    int time2[4] = {0,0,5,9};      //00:59
    int test2[4] = {0,0,1,0};      //01:00
    myTime(time2, test2);

    //TEST3
    int time3[4] = {0,9,5,9};      //00:59
    int test3[4] = {1,0,0,0};      //01:00
    myTime(time3, test3);

    //TEST4
    int time4[4] = {2,3,5,9};      //23:59
    int test4[4] = {0,0,0,0};      //00:00
    myTime(time4, test4);

    //TEST5
    int time4[4] = {1,9,5,9};      //23:59
    int test4[4] = {2,0,0,0};      //00:00
    myTime(time4, test4);

    //TEST6
    int time5[4] = {1,9,0,9};      //23:59
    int test5[4] = {2,0,1,0};      //00:00
    myTime(time5, test5);

    return 0;
}
