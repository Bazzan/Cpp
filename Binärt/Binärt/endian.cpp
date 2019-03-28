int changeEndiannesss(int value) {
	unsigned int tmp = value >> 8 * 3;
	unsigned int tmp2 = 0xfU & value;
	value |= 0xfU & tmp;
	value |= (0xfU << 8 * 3) & tmp2;
	tmp = (value >> 8 * 2) & 0xfU;
	tmp2 = (value >> 8) & 0xfU;
	value |= ~(0xfU << 8 * 2) & tmp;
	value |= ~~(0xfU << 8) & tmp2;
	return value;

}

