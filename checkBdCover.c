/*
* @Author: barry_g
* @Date:   2018-10-04 10:24:29
* @Last Modified by:   barry_g
* @Last Modified time: 2018-10-11 21:17:31
*/
/**
 * 棋盘覆盖问题
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
int checkBoard[SIZE][SIZE];
//产生特殊格子
int randRow = rand()%SIZE;
int randCol = rand()%SIZE;
int tag = 1;
/**
 * [initBoard 棋盘初始化]  特殊格子标记为-1
 */
void initBoard(){
	int i,j;
	for (i=0;i<SIZE;++i){
		for(j=0;j<SIZE;++j){
			checkBoard[i][j] = 0;
		}
	}
	checkBoard[randRow][randCol] = -1;
}
/**
 * [printBoard 打印棋盘]
 */
void printBoard(){
	int i,j;
	for(i=0;i<SIZE;++i){
		for(j=0;j<SIZE;++j){
			printf("%d\t", checkBoard[i][j]);
		}
		printf("\n\n");
	}
}
/**
 * [coverBoard 棋盘覆盖]
 * @param size    [棋盘大小]
 * @param randRow [特殊格子的横坐标]
 * @param randCol [特殊格子的纵坐标]
 * @param row     [棋盘左上角横坐标]
 * @param col     [棋盘左上角纵坐标]
 */
void coverBoard(int size,int randRow,int randCol,int row,int col){
	int newSize = size/2;
	if(newSize>=1){
		if(randCol<col+newSize && randRow<row+newSize){
			//特殊格子在左上角
			checkBoard[row+newSize-1][col+newSize]=tag;//右上角
			checkBoard[row+newSize][col+newSize-1]=tag;//左下角
			checkBoard[row+newSize][col+newSize]=tag;//右下角
			tag++;
			coverBoard(newSize,randRow,randCol,row,col);//左上角递归
			coverBoard(newSize,row+newSize-1,col+newSize,row,col+newSize);//右上角递归
			coverBoard(newSize,row+newSize,col+newSize-1,row+newSize,col);//左下角递归
			coverBoard(newSize,row+newSize,col+newSize,row+newSize,col+newSize);//右下角递归
		}
		if(randCol>=col+newSize && randRow<row+newSize){
			//特殊格子在右上角
			checkBoard[row+newSize-1][col+newSize-1]=tag;//左上角
			checkBoard[row+newSize][col+newSize-1]=tag;//左下角
			checkBoard[row+newSize][col+newSize]=tag;//右下角
			tag++;
			coverBoard(newSize,row+newSize-1,col+newSize-1,row,col);//左上角递归
			coverBoard(newSize,randRow,randCol,row,col+newSize);//右上角递归
			coverBoard(newSize,row+newSize,col+newSize-1,row+newSize,col);//左下角递归
			coverBoard(newSize,row+newSize,col+newSize,row+newSize,col+newSize);//右下角递归
		}
		if(randCol<col+newSize && randRow>=row+newSize){
			//特殊格子在左下角
			checkBoard[row+newSize-1][col+newSize-1]=tag;//左上角
			checkBoard[row+newSize-1][col+newSize]=tag;//右上角
			checkBoard[row+newSize][col+newSize]=tag;//右下角
			tag++;
			coverBoard(newSize,row+newSize-1,col+newSize-1,row,col);//左上角递归
			coverBoard(newSize,row+newSize-1,col+newSize,row,col+newSize);//右上角递归
			coverBoard(newSize,randRow,randCol,row+newSize,col);//左下角递归
			coverBoard(newSize,row+newSize,col+newSize,row+newSize,col+newSize);//右下角递归
		}
		if(randCol>=col+newSize && randRow>=row+newSize){
			//特殊格子在右下角
			checkBoard[row+newSize-1][col+newSize-1]=tag;//左上角
			checkBoard[row+newSize-1][col+newSize]=tag;//右上角
			checkBoard[row+newSize][col+newSize-1]=tag;//左下角
			tag++;
			coverBoard(newSize,row+newSize-1,col+newSize-1,row,col);//左上角递归
			coverBoard(newSize,row+newSize-1,col+newSize,row,col+newSize);//右上角递归
			coverBoard(newSize,row+newSize,col+newSize-1,row+newSize,col);//左下角递归
			coverBoard(newSize,randRow,randCol,row+newSize,col+newSize);//右下角递归
		}
	}
}
int main()
{
	initBoard();
	coverBoard(SIZE,randRow,randCol,0,0);
	printBoard();
	return 0;
}