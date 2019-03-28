

typedef unsigened long int Uint;

void copyNibble(Uint source, Uint& dest, int nibbleNr){

	unsigned int bit = (source >> nibbleNr * 4) & fU;
	dest &= ~(fU << nibbleNr * 4);
	dest |= bit << nibbleNr * 4;


}