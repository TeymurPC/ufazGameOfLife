#include "game.h"



void neighbours_clipped_test(void){

    struct board test_brd;
    test_brd.circular_flag=CLIPPED_BOARD;
    test_brd.width=7;
    test_brd.height=4;
    (&test_brd)->cells = malloc(test_brd.height * sizeof(unsigned short *));
    for(int i = 0; i < test_brd.height; i++){
       (&test_brd)->cells[i] = malloc(test_brd.width * sizeof(unsigned short));
    }


    test_brd.cells[0][0]=0;     test_brd.cells[0][1]=1;     test_brd.cells[0][2]=0;     test_brd.cells[0][3]=0;     
    test_brd.cells[0][1]=1;     test_brd.cells[1][1]=0;     test_brd.cells[2][1]=1;     test_brd.cells[3][1]=0;
    test_brd.cells[0][2]=0;     test_brd.cells[1][2]=1;     test_brd.cells[2][2]=0;     test_brd.cells[3][2]=0;
    test_brd.cells[0][3]=0;     test_brd.cells[1][3]=0;     test_brd.cells[2][3]=0;     test_brd.cells[3][3]=1;
    test_brd.cells[0][4]=1;     test_brd.cells[1][4]=1;     test_brd.cells[2][4]=0;     test_brd.cells[3][4]=0;
    test_brd.cells[0][5]=0;     test_brd.cells[1][5]=1;     test_brd.cells[2][5]=1;     test_brd.cells[3][5]=1;
    test_brd.cells[0][6]=0;     test_brd.cells[1][6]=0;     test_brd.cells[2][6]=0;     test_brd.cells[3][6]=1;


    CU_ASSERT_EQUAL(neighbours_clipped(test_brd,4,2),5);
    CU_ASSERT_EQUAL(neighbours_clipped(test_brd,3,2),3);
    CU_ASSERT_EQUAL(neighbours_clipped(test_brd,6,1),2);



}


void neighbours_circular_test(void){

    struct board test_brd;
    test_brd.circular_flag=CIRCULAR_BOARD;
    test_brd.width=7;
    test_brd.height=4;
    (&test_brd)->cells = malloc(test_brd.height * sizeof(unsigned short *));
    for(int i = 0; i < test_brd.height; i++){
       (&test_brd)->cells[i] = malloc(test_brd.width * sizeof(unsigned short));
    }

    test_brd.cells[0][0]=0;     test_brd.cells[1][0]=1;     test_brd.cells[2][0]=0;     test_brd.cells[3][0]=0;     
    test_brd.cells[0][1]=1;     test_brd.cells[1][1]=0;     test_brd.cells[2][1]=1;     test_brd.cells[3][1]=0;
    test_brd.cells[0][2]=0;     test_brd.cells[1][2]=1;     test_brd.cells[2][2]=0;     test_brd.cells[3][2]=0;
    test_brd.cells[0][3]=0;     test_brd.cells[1][3]=0;     test_brd.cells[2][3]=0;     test_brd.cells[3][3]=1;
    test_brd.cells[0][4]=1;     test_brd.cells[1][4]=1;     test_brd.cells[2][4]=0;     test_brd.cells[3][4]=0;
    test_brd.cells[0][5]=0;     test_brd.cells[1][5]=1;     test_brd.cells[2][5]=1;     test_brd.cells[3][5]=1;
    test_brd.cells[0][6]=0;     test_brd.cells[1][6]=0;     test_brd.cells[2][6]=0;     test_brd.cells[3][6]=1;
        

    
    CU_ASSERT_EQUAL(neighbours_circular(test_brd,0,3),3);
    CU_ASSERT_EQUAL(neighbours_circular(test_brd,4,0),4);
    CU_ASSERT_EQUAL(neighbours_circular(test_brd,3,3),1);

}


 void next_board_clipped_test(void){

    struct board old_brd;
    old_brd.circular_flag=CLIPPED_BOARD;
    old_brd.width=7;
    old_brd.height=4;
    
    (&old_brd)->cells = (unsigned short **)malloc(old_brd.height * sizeof(unsigned short *));

    for(int i = 0; i < old_brd.height; i++){
       (&old_brd)->cells[i] = (unsigned short *)malloc(old_brd.width * sizeof(unsigned short));
    }


    old_brd.cells[0][0]=0;     old_brd.cells[1][0]=1;     old_brd.cells[2][0]=0;     old_brd.cells[3][0]=0;     
    old_brd.cells[0][1]=1;     old_brd.cells[1][1]=0;     old_brd.cells[2][1]=1;     old_brd.cells[3][1]=0;
    old_brd.cells[0][2]=0;     old_brd.cells[1][2]=1;     old_brd.cells[2][2]=0;     old_brd.cells[3][2]=0;
    old_brd.cells[0][3]=0;     old_brd.cells[1][3]=0;     old_brd.cells[2][3]=0;     old_brd.cells[3][3]=1;
    old_brd.cells[0][4]=1;     old_brd.cells[1][4]=1;     old_brd.cells[2][4]=0;     old_brd.cells[3][4]=0;
    old_brd.cells[0][5]=0;     old_brd.cells[1][5]=1;     old_brd.cells[2][5]=1;     old_brd.cells[3][5]=1;
    old_brd.cells[0][6]=0;     old_brd.cells[1][6]=0;     old_brd.cells[2][6]=0;     old_brd.cells[3][6]=1;


    struct board new_brd;
    new_brd.circular_flag=CLIPPED_BOARD;
    new_brd.width=7;
    new_brd.height=4;
    (&new_brd)->cells =(unsigned short **) malloc(new_brd.height * sizeof(unsigned short *));
    for(int i = 0; i < new_brd.height; i++){
       (&new_brd)->cells[i] = (unsigned short *)malloc(new_brd.width * sizeof(unsigned short));
    }
     
    new_brd.cells[0][0]=0;     new_brd.cells[1][0]=1;     new_brd.cells[2][0]=0;     new_brd.cells[3][0]=0;     
    new_brd.cells[0][1]=1;     new_brd.cells[1][1]=0;     new_brd.cells[2][1]=1;     new_brd.cells[3][1]=0;
    new_brd.cells[0][2]=0;     new_brd.cells[1][2]=1;     new_brd.cells[2][2]=1;     new_brd.cells[3][2]=0;
    new_brd.cells[0][3]=1;     new_brd.cells[1][3]=1;     new_brd.cells[2][3]=1;     new_brd.cells[3][3]=0;
    new_brd.cells[0][4]=1;     new_brd.cells[1][4]=1;     new_brd.cells[2][4]=0;     new_brd.cells[3][4]=1;
    new_brd.cells[0][5]=1;     new_brd.cells[1][5]=1;     new_brd.cells[2][5]=0;     new_brd.cells[3][5]=1;
    new_brd.cells[0][6]=0;     new_brd.cells[1][6]=0;     new_brd.cells[2][6]=0;     new_brd.cells[3][6]=1;


    CU_ASSERT(next_board(old_brd).cells[2][2] == new_brd.cells[2][2]);
    CU_ASSERT(next_board(old_brd).cells[1][5] == new_brd.cells[1][5]);
    CU_ASSERT(next_board(old_brd).cells[3][4] == new_brd.cells[3][4]);
    CU_ASSERT(next_board(old_brd).cells[2][3] == new_brd.cells[2][3]);
    CU_ASSERT(next_board(old_brd).cells[0][3] == new_brd.cells[0][3]);
    CU_ASSERT(next_board(old_brd).cells[1][6] == new_brd.cells[1][6]);

 }



 void next_board_circular_test(void){

    struct board old_brd;
    old_brd.circular_flag=CIRCULAR_BOARD;
    old_brd.width=7;
    old_brd.height=4;
    (&old_brd)->cells = malloc(old_brd.height * sizeof(unsigned short *));
    for(int i = 0; i < old_brd.height; i++){
       (&old_brd)->cells[i] = malloc(old_brd.width * sizeof(unsigned short));
    }

    old_brd.cells[0][0]=0;     old_brd.cells[1][0]=1;     old_brd.cells[2][0]=0;     old_brd.cells[3][0]=0;     
    old_brd.cells[0][1]=1;     old_brd.cells[1][1]=0;     old_brd.cells[2][1]=1;     old_brd.cells[3][1]=0;
    old_brd.cells[0][2]=0;     old_brd.cells[1][2]=1;     old_brd.cells[2][2]=0;     old_brd.cells[3][2]=0;
    old_brd.cells[0][3]=0;     old_brd.cells[1][3]=0;     old_brd.cells[2][3]=0;     old_brd.cells[3][3]=1;
    old_brd.cells[0][4]=1;     old_brd.cells[1][4]=1;     old_brd.cells[2][4]=0;     old_brd.cells[3][4]=0;
    old_brd.cells[0][5]=0;     old_brd.cells[1][5]=1;     old_brd.cells[2][5]=1;     old_brd.cells[3][5]=1;
    old_brd.cells[0][6]=0;     old_brd.cells[1][6]=0;     old_brd.cells[2][6]=0;     old_brd.cells[3][6]=1;


    struct board new_brd;
    new_brd.circular_flag=CIRCULAR_BOARD;
    new_brd.width=7;
    new_brd.height=4;
   (&new_brd)->cells = malloc(new_brd.height * sizeof(unsigned short *));
    for(int i = 0; i < new_brd.height; i++){
       (&new_brd)->cells[i] = malloc(new_brd.width * sizeof(unsigned short));
    }

    new_brd.cells[0][0]=1;     new_brd.cells[1][0]=1;     new_brd.cells[2][0]=1;     new_brd.cells[3][0]=1;     
    new_brd.cells[0][1]=1;     new_brd.cells[1][1]=0;     new_brd.cells[2][1]=1;     new_brd.cells[3][1]=0;
    new_brd.cells[0][2]=1;     new_brd.cells[1][2]=1;     new_brd.cells[2][2]=1;     new_brd.cells[3][2]=1;
    new_brd.cells[0][3]=0;     new_brd.cells[1][3]=1;     new_brd.cells[2][3]=1;     new_brd.cells[3][3]=0;
    new_brd.cells[0][4]=1;     new_brd.cells[1][4]=1;     new_brd.cells[2][4]=0;     new_brd.cells[3][4]=0;
    new_brd.cells[0][5]=0;     new_brd.cells[1][5]=1;     new_brd.cells[2][5]=0;     new_brd.cells[3][5]=1;
    new_brd.cells[0][6]=0;     new_brd.cells[1][6]=1;     new_brd.cells[2][6]=0;     new_brd.cells[3][6]=1;


    CU_ASSERT_EQUAL(next_board(old_brd).cells[2][0],new_brd.cells[2][0]);
    CU_ASSERT_EQUAL(next_board(old_brd).cells[0][6],new_brd.cells[0][6]);
    CU_ASSERT_EQUAL(next_board(old_brd).cells[3][4],new_brd.cells[3][4]);
    CU_ASSERT_EQUAL(next_board(old_brd).cells[2][3],new_brd.cells[2][3]);
    CU_ASSERT_EQUAL(next_board(old_brd).cells[0][3],new_brd.cells[0][3]);
    CU_ASSERT_EQUAL(next_board(old_brd).cells[3][4],new_brd.cells[3][4]);

 }


int main (){


        CU_pSuite suite = NULL;

        if(CUE_SUCCESS != CU_initialize_registry()){
            return CU_get_error();
        }


        suite = CU_add_suite("game_test", NULL, NULL);

        if(NULL == suite){
            CU_cleanup_registry();
            return CU_get_error();
        }


        if( (NULL == CU_add_test(suite, "neighbours_clipped_test", neighbours_clipped_test)) ||
            (NULL == CU_add_test(suite, "neighbours_circular_test", neighbours_circular_test)) ||
            (NULL == CU_add_test(suite, "next_board_clipped_test", next_board_clipped_test)) ||
            (NULL == CU_add_test(suite, "next_board_circular_test", next_board_circular_test))){

                CU_cleanup_registry();
                return CU_get_error();
            }
            
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();

        return CU_get_error();


}
    
