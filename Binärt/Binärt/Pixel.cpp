

typedef usigned int Uint32;
typedef usinged char Byte;
enum Color {RED =0, GREEN=1, BLUE=2, ALPHA=3};

Byte getColorComponent(Uint32 pixel, Color color) {
	return  (pixel >> (3 - color) * 8) & 0xff;
}

void setColorComponent(Uint32& pixel, Byte value, Color color) {
	pixel &= ~(0xff << (3 - color) * 8);
	pixel |= (value << (3 - color) * 8) ;
}