// Vectorized representation of letters on a grid
// Vectors: https://github.com/CSCWLab2015/NXT/wiki/Letter-Representation-System

const bool vectors[35][25] = {
	// 0-9
	{0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1,1,1,0}, // 0
	{1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1}, // 1
	{1,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,1,1,1}, // 2
	{1,1,1,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0}, // 3
	{1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0}, // 4
	{1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0}, // 5
	{0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0}, // 6
	{1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0}, // 7
	{0,1,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,0}, // 8
	{0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0}, // 9

	// A-Z
	{0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1}, // 10 A
	{1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0}, // 11 B
	{0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0}, // 11 C
	{1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0}, // 11 D
	{1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1}, // 11 E
	{1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0}, // 11 F
	{0,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,1,1,1}, // 11 G
	{1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1}, // 11 H
	{1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1}, // 11 I
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,1,0}, // 11 J
	{1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1}, // 11 K
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1}, // 11 L
	{1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1}, // 11 M
	{1,0,0,0,1,1,1,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1}, // 11 N
	{0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0}, // 11 O
	{1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0}, // 11 P
	{0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,1,1,1,1}, // 11 Q
	{1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1}, // 11 R
	{0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,0}, // 11 S
	{1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0}, // 11 T
	{1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0}, // 11 U
	{1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0}, // 11 V
	{1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0}, // 11 W
	{1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1}, // 11 X
	{1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0}, // 11 Y
	{1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1}, // 11 Z
	
};

//bool * vectorLetter(ubyte asciiCode){
//if(asciiCode<48)
//	return "";

// 0 - 9
//ascii[0] =
//ascii[1] =
//ascii[2] =
//ascii[3] =
//ascii[4] =
//ascii[5] =
//ascii[6] =
//ascii[7] =
//ascii[8] =
//ascii[9] =

//// A - Z
//ascii[17] =
//ascii[18] =
//ascii[19] = 
//ascii[20] = 
//ascii[21] = "1111110000111001000011111"; // E
//ascii[22] = "1111110000111001000010000"; // F
//ascii[23] = "0111110000100111000101111"; // G
//ascii[24] = "1000110001111111000110001"; // H
//ascii[25] = "1111100100001000010011111"; // I
//ascii[26] = "0000100001000011000101110"; // J
//ascii[27] = "1000110010111001001010001"; // K
//ascii[28] = "1000010000100001000011111"; // L
//ascii[29] = "1000111011101011000110001"; // M
//ascii[30] = "1000111001101011001110001"; // N
//ascii[31] = "0111010001100011000101110"; // O
//ascii[32] = "1111010001111101000010000"; // P
//ascii[33] = "0111010001100011001101111"; // Q
//ascii[34] = "1111010001111101000110001"; // R
//ascii[35] = "0111110000011100000111110"; // S
//ascii[36] = "1111100100001000010000100"; // T
//ascii[37] = "1000110001100011000101110"; // U
//ascii[38] = "1000110001100010101000100"; // V
//ascii[39] = "1000110001101011010101010"; // W
//ascii[40] = "1000101010001000101010001"; // X
//ascii[41] = "1000101010001000010000100"; // Y
//ascii[42] = "1111100010001000100011111"; // Z

//	return ascii[asciiCode-48];
//}
