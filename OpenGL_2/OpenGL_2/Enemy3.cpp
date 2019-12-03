#include "./Enemy3.h"

Enemy3::Enemy3()
{
	m_Points[0] = vec4(0.0f, 0.0f, 0.0f, 1.0f); //上半身
	m_Colors[0] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	
	m_Points[1] = vec4(1.0f*cosf(M_PI * 0 / 19), 1.0f*sinf(M_PI * 0 / 19), 0.0f, 1.0f);
	m_Points[2] = vec4(1.0f*cosf(M_PI * 1 / 19), 1.0f*sinf(M_PI * 1 / 19), 0.0f, 1.0f);
	m_Points[3] = vec4(1.0f*cosf(M_PI * 2 / 19), 1.0f*sinf(M_PI * 2 / 19), 0.0f, 1.0f);
	m_Points[4] = vec4(1.0f*cosf(M_PI * 3 / 19), 1.0f*sinf(M_PI * 3 / 19), 0.0f, 1.0f);
	m_Points[5] = vec4(1.0f*cosf(M_PI * 4 / 19), 1.0f*sinf(M_PI * 4 / 19), 0.0f, 1.0f);
	m_Points[6] = vec4(1.0f*cosf(M_PI * 5 / 19), 1.0f*sinf(M_PI * 5 / 19), 0.0f, 1.0f);
	m_Points[7] = vec4(1.0f*cosf(M_PI * 6 / 19), 1.0f*sinf(M_PI * 6 / 19), 0.0f, 1.0f);
	m_Points[8] = vec4(1.0f*cosf(M_PI * 7 / 19), 1.0f*sinf(M_PI * 7 / 19), 0.0f, 1.0f);
	m_Points[9] = vec4(1.0f*cosf(M_PI * 8 / 19), 1.0f*sinf(M_PI * 8 / 19), 0.0f, 1.0f);
	m_Points[10] = vec4(1.0f*cosf(M_PI * 9 / 19), 1.0f*sinf(M_PI  * 9 / 19), 0.0f, 1.0f);
	m_Points[11] = vec4(1.0f*cosf(M_PI * 10 / 19), 1.0f*sinf(M_PI * 10 / 19), 0.0f, 1.0f);
	m_Points[12] = vec4(1.0f*cosf(M_PI * 11 / 19), 1.0f*sinf(M_PI * 11 / 19), 0.0f, 1.0f);
	m_Points[13] = vec4(1.0f*cosf(M_PI * 12 / 19), 1.0f*sinf(M_PI * 12 / 19), 0.0f, 1.0f);
	m_Points[14] = vec4(1.0f*cosf(M_PI * 13 / 19), 1.0f*sinf(M_PI * 13 / 19), 0.0f, 1.0f);
	m_Points[15] = vec4(1.0f*cosf(M_PI * 14 / 19), 1.0f*sinf(M_PI * 14 / 19), 0.0f, 1.0f);
	m_Points[16] = vec4(1.0f*cosf(M_PI * 15 / 19), 1.0f*sinf(M_PI * 15 / 19), 0.0f, 1.0f);
	m_Points[17] = vec4(1.0f*cosf(M_PI * 16 / 19), 1.0f*sinf(M_PI * 16 / 19), 0.0f, 1.0f);
	m_Points[18] = vec4(1.0f*cosf(M_PI * 17 / 19), 1.0f*sinf(M_PI * 17 / 19), 0.0f, 1.0f);
	m_Points[19] = vec4(1.0f*cosf(M_PI * 18 / 19), 1.0f*sinf(M_PI * 18 / 19), 0.0f, 1.0f);
	m_Points[20] = vec4(1.0f*cosf(M_PI * 19 / 19), 1.0f*sinf(M_PI * 19 / 19), 0.0f, 1.0f);

	m_Points[21] = vec4(0.0f, -0.2f, 0.0f, 1.0f);
	m_Colors[21] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	
	m_Points[22] = vec4(-1.0f*cosf(M_PI * 0 / 19), -0.2f -1.0f*sinf(M_PI * 0 / 19), 0.0f, 1.0f);
	m_Points[23] = vec4(-1.0f*cosf(M_PI * 1 / 19), -0.2f -1.0f*sinf(M_PI * 1 / 19), 0.0f, 1.0f);
	m_Points[24] = vec4(-1.0f*cosf(M_PI * 2 / 19), -0.2f -1.0f*sinf(M_PI * 2 / 19), 0.0f, 1.0f);
	m_Points[25] = vec4(-1.0f*cosf(M_PI * 3 / 19), -0.2f -1.0f*sinf(M_PI * 3 / 19), 0.0f, 1.0f);
	m_Points[26] = vec4(-1.0f*cosf(M_PI * 4 / 19), -0.2f -1.0f*sinf(M_PI * 4 / 19), 0.0f, 1.0f);
	m_Points[27] = vec4(-1.0f*cosf(M_PI * 5 / 19), -0.2f -1.0f*sinf(M_PI * 5 / 19), 0.0f, 1.0f);
	m_Points[28] = vec4(-1.0f*cosf(M_PI * 6 / 19), -0.2f -1.0f*sinf(M_PI * 6 / 19), 0.0f, 1.0f);
	m_Points[29] = vec4(-1.0f*cosf(M_PI * 7 / 19), -0.2f -1.0f*sinf(M_PI * 7 / 19), 0.0f, 1.0f);
	m_Points[30] = vec4(-1.0f*cosf(M_PI * 8 / 19), -0.2f -1.0f*sinf(M_PI * 8 / 19), 0.0f, 1.0f);
	m_Points[31] = vec4(-1.0f*cosf(M_PI * 9 / 19), -0.2f -1.0f*sinf(M_PI * 9 / 19), 0.0f, 1.0f);
	m_Points[32] = vec4(-1.0f*cosf(M_PI * 10 / 19), -0.2f -1.0f*sinf(M_PI * 10 / 19), 0.0f, 1.0f);
	m_Points[33] = vec4(-1.0f*cosf(M_PI * 11 / 19), -0.2f -1.0f*sinf(M_PI * 11 / 19), 0.0f, 1.0f);
	m_Points[34] = vec4(-1.0f*cosf(M_PI * 12 / 19), -0.2f -1.0f*sinf(M_PI * 12 / 19), 0.0f, 1.0f);
	m_Points[35] = vec4(-1.0f*cosf(M_PI * 13 / 19), -0.2f -1.0f*sinf(M_PI * 13 / 19), 0.0f, 1.0f);
	m_Points[36] = vec4(-1.0f*cosf(M_PI * 14 / 19), -0.2f -1.0f*sinf(M_PI * 14 / 19), 0.0f, 1.0f);
	m_Points[37] = vec4(-1.0f*cosf(M_PI * 15 / 19), -0.2f -1.0f*sinf(M_PI * 15 / 19), 0.0f, 1.0f);
	m_Points[38] = vec4(-1.0f*cosf(M_PI * 16 / 19), -0.2f -1.0f*sinf(M_PI * 16 / 19), 0.0f, 1.0f);
	m_Points[39] = vec4(-1.0f*cosf(M_PI * 17 / 19), -0.2f -1.0f*sinf(M_PI * 17 / 19), 0.0f, 1.0f);
	m_Points[40] = vec4(-1.0f*cosf(M_PI * 18 / 19), -0.2f -1.0f*sinf(M_PI * 18 / 19), 0.0f, 1.0f);
	m_Points[41] = vec4(-1.0f*cosf(M_PI * 19 / 19), -0.2f -1.0f*sinf(M_PI * 19 / 19), 0.0f, 1.0f);

	m_Points[42] = vec4(-1.0f,0.0f,0.0f,1.0f);
	m_Points[43] = vec4(-1.0f,-0.2f, 0.0f, 1.0f);
	m_Points[44] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Points[45] = vec4(0.0f, -0.2f, 0.0f, 1.0f);
	m_Points[46] = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	m_Points[47] = vec4(1.0f, -0.2f, 0.0f, 1.0f);

	m_Points[48] = vec4(0.0f, 0.5f, 0.0f, 1.0f);//白圓心
	m_Colors[48] = vec4(1.0f, 1.0f, 1.0f, 0.0f);
	//畫上白圓
	m_Points[49] = vec4(0.4f * cosf(M_PI * 2.0f * 0 / 22), 0.5f+ 0.4f * sinf(M_PI * 2.0f * 0 / 22), 0.0f, 1.0f);
	m_Points[50] = vec4(0.4f * cosf(M_PI * 2.0f * 1 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 1 / 22), 0.0f, 1.0f);
	m_Points[51] = vec4(0.4f * cosf(M_PI * 2.0f * 2 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 2 / 22), 0.0f, 1.0f);
	m_Points[52] = vec4(0.4f * cosf(M_PI * 2.0f * 3 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 3 / 22), 0.0f, 1.0f);
	m_Points[53] = vec4(0.4f * cosf(M_PI * 2.0f * 4 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 4 / 22), 0.0f, 1.0f);
	m_Points[54] = vec4(0.4f * cosf(M_PI * 2.0f * 5 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 5 / 22), 0.0f, 1.0f);
	m_Points[55] = vec4(0.4f * cosf(M_PI * 2.0f * 6 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 6 / 22), 0.0f, 1.0f);
	m_Points[56] = vec4(0.4f * cosf(M_PI * 2.0f * 7 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 7 / 22), 0.0f, 1.0f);
	m_Points[57] = vec4(0.4f * cosf(M_PI * 2.0f * 8 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 8 / 22), 0.0f, 1.0f);
	m_Points[58] = vec4(0.4f * cosf(M_PI * 2.0f * 9 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 9 / 22), 0.0f, 1.0f);
	m_Points[59] = vec4(0.4f * cosf(M_PI * 2.0f * 10 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 10 / 22), 0.0f, 1.0f);
	m_Points[60] = vec4(0.4f * cosf(M_PI * 2.0f * 11 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 11 / 22), 0.0f, 1.0f);
	m_Points[61] = vec4(0.4f * cosf(M_PI * 2.0f * 12 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 12 / 22), 0.0f, 1.0f);
	m_Points[62] = vec4(0.4f * cosf(M_PI * 2.0f * 13 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 13 / 22), 0.0f, 1.0f);
	m_Points[63] = vec4(0.4f * cosf(M_PI * 2.0f * 14 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 14 / 22), 0.0f, 1.0f);
	m_Points[64] = vec4(0.4f * cosf(M_PI * 2.0f * 15 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 15 / 22), 0.0f, 1.0f);
	m_Points[65] = vec4(0.4f * cosf(M_PI * 2.0f * 16 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 16 / 22), 0.0f, 1.0f);
	m_Points[66] = vec4(0.4f * cosf(M_PI * 2.0f * 17 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 17 / 22), 0.0f, 1.0f);
	m_Points[67] = vec4(0.4f * cosf(M_PI * 2.0f * 18 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 18 / 22), 0.0f, 1.0f);
	m_Points[68] = vec4(0.4f * cosf(M_PI * 2.0f * 19 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 19 / 22), 0.0f, 1.0f);
	m_Points[69] = vec4(0.4f * cosf(M_PI * 2.0f * 20 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 20 / 22), 0.0f, 1.0f);
	m_Points[70] = vec4(0.4f * cosf(M_PI * 2.0f * 21 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 21 / 22), 0.0f, 1.0f);
	m_Points[71] = vec4(0.4f * cosf(M_PI * 2.0f * 22 / 22), 0.5f + 0.4f * sinf(M_PI * 2.0f * 22 / 22), 0.0f, 1.0f);

	m_Points[72] = vec4(0.0f, -0.7f, 0.0f, 1.0f);//白圓心
	m_Colors[72] = vec4(1.0f, 1.0f, 1.0f, 0.0f);
	//畫上白圓
	m_Points[73] = vec4(0.4f * cosf(M_PI * 2.0f * 0 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 0 / 22), 0.0f, 1.0f);
	m_Points[74] = vec4(0.4f * cosf(M_PI * 2.0f * 1 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 1 / 22), 0.0f, 1.0f);
	m_Points[75] = vec4(0.4f * cosf(M_PI * 2.0f * 2 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 2 / 22), 0.0f, 1.0f);
	m_Points[76] = vec4(0.4f * cosf(M_PI * 2.0f * 3 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 3 / 22), 0.0f, 1.0f);
	m_Points[77] = vec4(0.4f * cosf(M_PI * 2.0f * 4 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 4 / 22), 0.0f, 1.0f);
	m_Points[78] = vec4(0.4f * cosf(M_PI * 2.0f * 5 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 5 / 22), 0.0f, 1.0f);
	m_Points[79] = vec4(0.4f * cosf(M_PI * 2.0f * 6 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 6 / 22), 0.0f, 1.0f);
	m_Points[80] = vec4(0.4f * cosf(M_PI * 2.0f * 7 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 7 / 22), 0.0f, 1.0f);
	m_Points[81] = vec4(0.4f * cosf(M_PI * 2.0f * 8 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 8 / 22), 0.0f, 1.0f);
	m_Points[82] = vec4(0.4f * cosf(M_PI * 2.0f * 9 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 9 / 22), 0.0f, 1.0f);
	m_Points[83] = vec4(0.4f * cosf(M_PI * 2.0f * 10 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 10 / 22), 0.0f, 1.0f);
	m_Points[84] = vec4(0.4f * cosf(M_PI * 2.0f * 11 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 11 / 22), 0.0f, 1.0f);
	m_Points[85] = vec4(0.4f * cosf(M_PI * 2.0f * 12 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 12 / 22), 0.0f, 1.0f);
	m_Points[86] = vec4(0.4f * cosf(M_PI * 2.0f * 13 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 13 / 22), 0.0f, 1.0f);
	m_Points[87] = vec4(0.4f * cosf(M_PI * 2.0f * 14 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 14 / 22), 0.0f, 1.0f);
	m_Points[88] = vec4(0.4f * cosf(M_PI * 2.0f * 15 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 15 / 22), 0.0f, 1.0f);
	m_Points[89] = vec4(0.4f * cosf(M_PI * 2.0f * 16 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 16 / 22), 0.0f, 1.0f);
	m_Points[90] = vec4(0.4f * cosf(M_PI * 2.0f * 17 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 17 / 22), 0.0f, 1.0f);
	m_Points[91] = vec4(0.4f * cosf(M_PI * 2.0f * 18 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 18 / 22), 0.0f, 1.0f);
	m_Points[92] = vec4(0.4f * cosf(M_PI * 2.0f * 19 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 19 / 22), 0.0f, 1.0f);
	m_Points[93] = vec4(0.4f * cosf(M_PI * 2.0f * 20 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 20 / 22), 0.0f, 1.0f);
	m_Points[94] = vec4(0.4f * cosf(M_PI * 2.0f * 21 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 21 / 22), 0.0f, 1.0f);
	m_Points[95] = vec4(0.4f * cosf(M_PI * 2.0f * 22 / 22), -0.7f + 0.4f * sinf(M_PI * 2.0f * 22 / 22), 0.0f, 1.0f);

	m_Points[96] = vec4(0.0f, 0.5f, 0.0f, 1.0f);//黑圓心
	m_Colors[96] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	//畫上黑圓
	m_Points[97] = vec4(0.3f * cosf(M_PI * 2.0f * 0 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 0 / 22), 0.0f, 1.0f);
	m_Points[98] = vec4(0.3f * cosf(M_PI * 2.0f * 1 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 1 / 22), 0.0f, 1.0f);
	m_Points[99] = vec4(0.3f * cosf(M_PI * 2.0f * 2 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 2 / 22), 0.0f, 1.0f);
	m_Points[100] = vec4(0.3f * cosf(M_PI * 2.0f * 3 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 3 / 22), 0.0f, 1.0f);
	m_Points[101] = vec4(0.3f * cosf(M_PI * 2.0f * 4 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 4 / 22), 0.0f, 1.0f);
	m_Points[102] = vec4(0.3f * cosf(M_PI * 2.0f * 5 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 5 / 22), 0.0f, 1.0f);
	m_Points[103] = vec4(0.3f * cosf(M_PI * 2.0f * 6 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 6 / 22), 0.0f, 1.0f);
	m_Points[104] = vec4(0.3f * cosf(M_PI * 2.0f * 7 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 7 / 22), 0.0f, 1.0f);
	m_Points[105] = vec4(0.3f * cosf(M_PI * 2.0f * 8 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 8 / 22), 0.0f, 1.0f);
	m_Points[106] = vec4(0.3f * cosf(M_PI * 2.0f * 9 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 9 / 22), 0.0f, 1.0f);
	m_Points[107] = vec4(0.3f * cosf(M_PI * 2.0f * 10 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 10 / 22), 0.0f, 1.0f);
	m_Points[108] = vec4(0.3f * cosf(M_PI * 2.0f * 11 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 11 / 22), 0.0f, 1.0f);
	m_Points[109] = vec4(0.3f * cosf(M_PI * 2.0f * 12 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 12 / 22), 0.0f, 1.0f);
	m_Points[110] = vec4(0.3f * cosf(M_PI * 2.0f * 13 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 13 / 22), 0.0f, 1.0f);
	m_Points[111] = vec4(0.3f * cosf(M_PI * 2.0f * 14 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 14 / 22), 0.0f, 1.0f);
	m_Points[112] = vec4(0.3f * cosf(M_PI * 2.0f * 15 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 15 / 22), 0.0f, 1.0f);
	m_Points[113] = vec4(0.3f * cosf(M_PI * 2.0f * 16 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 16 / 22), 0.0f, 1.0f);
	m_Points[114] = vec4(0.3f * cosf(M_PI * 2.0f * 17 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 17 / 22), 0.0f, 1.0f);
	m_Points[115] = vec4(0.2f * cosf(M_PI * 2.0f * 18 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 18 / 22), 0.0f, 1.0f);
	m_Points[116] = vec4(0.3f * cosf(M_PI * 2.0f * 19 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 19 / 22), 0.0f, 1.0f);
	m_Points[117] = vec4(0.3f * cosf(M_PI * 2.0f * 20 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 20 / 22), 0.0f, 1.0f);
	m_Points[118] = vec4(0.3f * cosf(M_PI * 2.0f * 21 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 21 / 22), 0.0f, 1.0f);
	m_Points[119] = vec4(0.3f * cosf(M_PI * 2.0f * 22 / 22), 0.5f + 0.3f * sinf(M_PI * 2.0f * 22 / 22), 0.0f, 1.0f);

	m_Points[120] = vec4(0.0f, -0.7f, 0.0f, 1.0f);//黑圓心
	m_Colors[120] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	//畫下黑圓
	m_Points[121] = vec4(0.3f * cosf(M_PI * 2.0f * 0 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 0 / 22), 0.0f, 1.0f);
	m_Points[122] = vec4(0.3f * cosf(M_PI * 2.0f * 1 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 1 / 22), 0.0f, 1.0f);
	m_Points[123] = vec4(0.3f * cosf(M_PI * 2.0f * 2 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 2 / 22), 0.0f, 1.0f);
	m_Points[124] = vec4(0.3f * cosf(M_PI * 2.0f * 3 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 3 / 22), 0.0f, 1.0f);
	m_Points[125] = vec4(0.3f * cosf(M_PI * 2.0f * 4 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 4 / 22), 0.0f, 1.0f);
	m_Points[126] = vec4(0.3f * cosf(M_PI * 2.0f * 5 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 5 / 22), 0.0f, 1.0f);
	m_Points[127] = vec4(0.3f * cosf(M_PI * 2.0f * 6 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 6 / 22), 0.0f, 1.0f);
	m_Points[128] = vec4(0.3f * cosf(M_PI * 2.0f * 7 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 7 / 22), 0.0f, 1.0f);
	m_Points[129] = vec4(0.3f * cosf(M_PI * 2.0f * 8 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 8 / 22), 0.0f, 1.0f);
	m_Points[130] = vec4(0.3f * cosf(M_PI * 2.0f * 9 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 9 / 22), 0.0f, 1.0f);
	m_Points[131] = vec4(0.3f * cosf(M_PI * 2.0f * 10 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 10 / 22), 0.0f, 1.0f);
	m_Points[132] = vec4(0.3f * cosf(M_PI * 2.0f * 11 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 11 / 22), 0.0f, 1.0f);
	m_Points[133] = vec4(0.3f * cosf(M_PI * 2.0f * 12 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 12 / 22), 0.0f, 1.0f);
	m_Points[134] = vec4(0.3f * cosf(M_PI * 2.0f * 13 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 13 / 22), 0.0f, 1.0f);
	m_Points[135] = vec4(0.3f * cosf(M_PI * 2.0f * 14 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 14 / 22), 0.0f, 1.0f);
	m_Points[136] = vec4(0.3f * cosf(M_PI * 2.0f * 15 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 15 / 22), 0.0f, 1.0f);
	m_Points[137] = vec4(0.3f * cosf(M_PI * 2.0f * 16 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 16 / 22), 0.0f, 1.0f);
	m_Points[138] = vec4(0.3f * cosf(M_PI * 2.0f * 17 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 17 / 22), 0.0f, 1.0f);
	m_Points[139] = vec4(0.3f * cosf(M_PI * 2.0f * 18 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 18 / 22), 0.0f, 1.0f);
	m_Points[140] = vec4(0.3f * cosf(M_PI * 2.0f * 19 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 19 / 22), 0.0f, 1.0f);
	m_Points[141] = vec4(0.3f * cosf(M_PI * 2.0f * 20 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 20 / 22), 0.0f, 1.0f);
	m_Points[142] = vec4(0.3f * cosf(M_PI * 2.0f * 21 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 21 / 22), 0.0f, 1.0f);
	m_Points[143] = vec4(0.3f * cosf(M_PI * 2.0f * 22 / 22), -0.7f + 0.3f * sinf(M_PI * 2.0f * 22 / 22), 0.0f, 1.0f);

	m_Points[144] = vec4(0.0f, -0.1f, 0.0f, 1.0f);//小圓心
	m_Colors[144] = vec4(1.0f, 0.56f, 0.26f, 1.0f);

	m_Points[145] = vec4(0.07f * cosf(M_PI * 2.0f * 0 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[146] = vec4(0.07f * cosf(M_PI * 2.0f * 1 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[147] = vec4(0.07f * cosf(M_PI * 2.0f * 2 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[148] = vec4(0.07f * cosf(M_PI * 2.0f * 3 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[149] = vec4(0.07f * cosf(M_PI * 2.0f * 4 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[150] = vec4(0.07f * cosf(M_PI * 2.0f * 5 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[151] = vec4(0.07f * cosf(M_PI * 2.0f * 6 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[152] = vec4(0.07f * cosf(M_PI * 2.0f * 7 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[153] = vec4(0.07f * cosf(M_PI * 2.0f * 8 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[154] = vec4(0.07f * cosf(M_PI * 2.0f * 9 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[155] = vec4(0.07f * cosf(M_PI * 2.0f * 10 / 10), -0.1f + 0.07f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Colors[1] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[2] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[3] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[4] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[5] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[6] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[7] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[8] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[9] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[10] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[11] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[12] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[13] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[14] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[15] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[16] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[17] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[18] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[19] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[20] = vec4(0.21f, 0.58f, 0.96f, 1.0f);

	m_Colors[22] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[23] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[24] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[25] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[26] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[27] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[28] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[29] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[30] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[31] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[32] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[33] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[34] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[35] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[36] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[37] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[38] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[39] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[40] = vec4(0.21f, 0.58f, 0.96f, 1.0f);
	m_Colors[41] = vec4(0.21f, 0.58f, 0.96f, 1.0f);

	m_Colors[42] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[43] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[44] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[45] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[46] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[47] = vec4(1.0f, 1.0f, 0.0f, 1.0f);

	m_Colors[49] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[50] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[51] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[52] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[53] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[54] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[55] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[56] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[57] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[58] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[59] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[60] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[61] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[62] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[63] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[64] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[65] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[66] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[67] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[68] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[69] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[70] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[71] = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	
	m_Colors[73] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[74] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[75] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[76] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[77] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[78] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[79] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[80] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[81] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[82] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[83] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[84] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[85] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[86] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[87] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[88] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[89] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[90] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[91] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[92] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[93] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[94] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[95] = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	m_Colors[97] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[98] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[99] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[100] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[101] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[102] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[103] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[104] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[105] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[106] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[107] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[108] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[109] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[110] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[111] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[112] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[113] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[114] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[115] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[116] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[117] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[118] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[119] = vec4(0.0f, 0.0f, 0.0f, 1.0f);

	m_Colors[121] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[122] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[123] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[124] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[125] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[126] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[127] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[128] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[129] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[130] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[131] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[132] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[133] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[134] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[135] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[136] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[137] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[138] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[139] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[140] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[141] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[142] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Colors[143] = vec4(0.0f, 0.0f, 0.0f, 1.0f);

	m_Colors[145] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[146] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[147] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[148] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[149] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[150] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[151] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[152] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[153] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[154] = vec4(1.0f, 0.56f, 0.26f, 1.0f);
	m_Colors[155] = vec4(1.0f, 0.56f, 0.26f, 1.0f);

	/*Create and initialize a buffer object */
	CreateBufferObject();
	m_bUpdateProj = false;
}


void Enemy3::CreateBufferObject()
{
	glGenVertexArrays(1, &m_uiVao);
	glBindVertexArray(m_uiVao);

	// Create and initialize a buffer object

	glGenBuffers(1, &m_uiBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_uiBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Points) + sizeof(m_Colors), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(m_Points), m_Points);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_Points), sizeof(m_Colors), m_Colors);
}

void Enemy3::SetShader(mat4 &mxView, mat4 &mxProjection, GLuint uiShaderHandle)
{
	// Load shaders and use the resulting shader program
	if (uiShaderHandle == MAX_UNSIGNED_INT) m_uiProgram = InitShader("vsVtxColor.glsl", "fsVtxColor.glsl");
	else m_uiProgram = uiShaderHandle;

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation(m_uiProgram, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint vColor = glGetAttribLocation(m_uiProgram, "vColor");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(m_Points)));

	m_uiModelView = glGetUniformLocation(m_uiProgram, "ModelView");
	m_mxView = mxView;
	glUniformMatrix4fv(m_uiModelView, 1, GL_TRUE, m_mxView);

	m_uiProjection = glGetUniformLocation(m_uiProgram, "Projection");
	m_mxProjection = mxProjection;
	glUniformMatrix4fv(m_uiProjection, 1, GL_TRUE, m_mxProjection);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Enemy3::SetViewMatrix(mat4 &mat)
{
	m_mxView = mat;
	m_bUpdateMV = true;
}

void Enemy3::SetProjectionMatrix(mat4 &mat)
{
	m_mxProjection = mat;
	m_bUpdateProj = true;
}

void Enemy3::SetTRSMatrix(mat4 &mat)
{
	m_mxTRS = mat;
	m_bUpdateMV = true;
}

void Enemy3::SetColor(GLfloat vColor[4])
{
	for (int i = 0; i < 42; i++) {
		m_Colors[i].x = vColor[0];
		m_Colors[i].y = vColor[1];
		m_Colors[i].z = vColor[2];
		m_Colors[i].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_Points), sizeof(m_Colors), m_Colors);
}
void Enemy3::DetectBlood() {
	if (BloodFlag == true)blood -= 1;
	if (blood == 0) { Flag = false; }
	BloodFlag = false;
}
void Enemy3::SetVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[])
{
	m_Colors[0].x = vLFColor[0];
	m_Colors[0].y = vLFColor[1];
	m_Colors[0].z = vLFColor[2];
	m_Colors[0].w = vLFColor[3];
	m_Colors[3] = m_Colors[0];

	m_Colors[1].x = vLRColor[0];
	m_Colors[1].y = vLRColor[1];
	m_Colors[1].z = vLRColor[2];
	m_Colors[1].w = vLRColor[3];

	m_Colors[2].x = vTRColor[0];
	m_Colors[2].y = vTRColor[1];
	m_Colors[2].z = vTRColor[2];
	m_Colors[2].w = vTRColor[3];
	m_Colors[4] = m_Colors[2];

	m_Colors[5].x = vTLColor[0];
	m_Colors[5].y = vTLColor[1];
	m_Colors[5].z = vTLColor[2];
	m_Colors[5].w = vTLColor[3];

	glBindBuffer(GL_ARRAY_BUFFER, m_uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_Points), sizeof(m_Colors), m_Colors);
}

void Enemy3::Draw()
{
	glUseProgram(m_uiProgram);
	glBindVertexArray(m_uiVao);
	if (m_bUpdateMV) {
		m_mxMVFinal = m_mxView*m_mxTRS;
		m_bUpdateMV = false;
	}
	glUniformMatrix4fv(m_uiModelView, 1, GL_TRUE, m_mxMVFinal);

	if (m_bUpdateProj) {
		glUniformMatrix4fv(m_uiProjection, 1, GL_TRUE, m_mxProjection);
		m_bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLE_FAN, 0, 21);
	glDrawArrays(GL_TRIANGLE_FAN, 21, 21);
	glDrawArrays(GL_TRIANGLE_STRIP, 42, 6);
	glDrawArrays(GL_TRIANGLE_FAN, 48, 24);
	glDrawArrays(GL_TRIANGLE_FAN, 72, 24);
	glDrawArrays(GL_TRIANGLE_FAN, 96, 24);
	glDrawArrays(GL_TRIANGLE_FAN, 120, 24);
	glDrawArrays(GL_TRIANGLE_FAN, 144, 12);

}

void Enemy3::DrawW()
{
	glBindVertexArray(m_uiVao);

	if (m_bUpdateMV) {
		m_mxMVFinal = m_mxView*m_mxTRS;
		m_bUpdateMV = false;
	}

	glUniformMatrix4fv(m_uiModelView, 1, GL_TRUE, m_mxMVFinal);
	if (m_bUpdateProj) {
		glUniformMatrix4fv(m_uiProjection, 1, GL_TRUE, m_mxProjection);
		m_bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, QUAD_NUM);
}
