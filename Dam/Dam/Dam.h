#pragma once
class Dam
{
private:
	unsigned short board[8];
	
public:
	Dam();

	void move(int fromRow, int fromCol, int toRow, int toCol);
	~Dam();
};

