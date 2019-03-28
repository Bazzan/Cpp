#include "Dam.h"



Dam::Dam()
{
}


Dam::~Dam()
{
}


void Dam::move(int fromRow, int fromCol, int toRow, int toCol) {

	unsigned short bricka;
	bricka = (board[fromRow] >> fromCol * 2) & 3U;
	board[fromRow] &= ~(3U << fromCol * 2);
	board[toRow] &= ~(3U << toCol * 2);
	board[toRow] |= bricka << toCol * 2;

 }