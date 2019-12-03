#include "./BG.h"

BG::BG()
{
	m_Points[0] = vec4(-0.1f+0.1f*cosf(M_PI*2.0f*0/5), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5),0.0f,1.0f);//第一圓圓心
	m_Colors[0] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	//畫黃圓
	m_Points[1] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 0 / 10), 0.01f+0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[2] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 1 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[3] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 2 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[4] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 3 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[5] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 4 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[6] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 5 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[7] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 6 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[8] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 7 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[9] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 8 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[10] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 9 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[11] = vec4(-0.1f + 0.1f*cosf(M_PI*2.0f * 0 / 5)+0.1f * cosf(M_PI * 2.0f * 10 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 0 / 5)+0.1f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Points[12] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 0 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[13] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 1 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[14] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 2 / 10), 0.1f*sinf(M_PI*2.0f * 1/ 5) + 0.05f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[15] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 3 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[16] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 4 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[17] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 5 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[18] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 6 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[19] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 7 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[20] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 8 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[21] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 9 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[22] = vec4(0.1f*cosf(M_PI*2.0f * 1 / 5) + 0.05f * cosf(M_PI * 2.0f * 10 / 10), 0.1f*sinf(M_PI*2.0f * 1 / 5) + 0.05f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Points[23] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 0 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[24] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 1 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[25] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 2 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[26] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 3 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[27] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 4 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[28] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 5 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[29] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 6 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[30] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 7 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[31] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 8 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[32] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 9 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[33] = vec4(0.1f*cosf(M_PI*2.0f * 2 / 5) + 0.05f * cosf(M_PI * 2.0f * 10 / 10), 0.1f*sinf(M_PI*2.0f * 2 / 5) + 0.05f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Points[34] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 0 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[35] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 1 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[36] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 2 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[37] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 3 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[38] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 4 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[39] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 5 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[40] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 6 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[41] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 7 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[42] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 8 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[43] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 9 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[44] = vec4(0.1f*cosf(M_PI*2.0f * 3 / 5) + 0.05f * cosf(M_PI * 2.0f * 10 / 10), 0.1f*sinf(M_PI*2.0f * 3 / 5) + 0.05f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Points[45] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 0 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[46] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 1 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[47] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 2 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[48] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 3 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[49] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 4 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[50] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 5 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[51] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 6 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[52] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 7 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[53] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 8 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[54] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 9 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[55] = vec4(0.1f*cosf(M_PI*2.0f * 4 / 5) + 0.05f * cosf(M_PI * 2.0f * 10 / 10), 0.01f + 0.1f*sinf(M_PI*2.0f * 4 / 5) + 0.05f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Points[56] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 0 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[57] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 1 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[58] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 2 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[59] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 3 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[60] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 4 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[61] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 5 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[62] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 6 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[63] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 7 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[64] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 8 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[65] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 9 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[66] = vec4(0.1f*cosf(M_PI*2.0f * 5 / 5) + 0.05f * cosf(M_PI * 2.0f * 10 / 10), 0.1f*sinf(M_PI*2.0f * 5 / 5) + 0.05f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Colors[1] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[2] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[3] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[4] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[5] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[6] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[7] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[8] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[9] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[10] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[11] = vec4(1.0f, 0.87f, 0.96f, 1.0f);

	m_Colors[12] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[13] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[14] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[15] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[16] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[17] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[18] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[19] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[20] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[21] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[22] = vec4(1.0f, 0.87f, 0.96f, 1.0f);

	m_Colors[23] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[24] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[25] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[26] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[27] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[28] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[29] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[30] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[31] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[32] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[33] = vec4(1.0f, 0.87f, 0.96f, 1.0f);

	m_Colors[34] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[35] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[36] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[37] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[38] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[39] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[40] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[41] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[42] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[43] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[44] = vec4(1.0f, 0.87f, 0.96f, 1.0f);

	m_Colors[45] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[46] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[47] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[48] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[49] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[50] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[51] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[52] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[53] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[54] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[55] = vec4(1.0f, 0.87f, 0.96f, 1.0f);

	m_Colors[56] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[57] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[58] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[59] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[60] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[61] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[62] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[63] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[64] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[65] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	m_Colors[66] = vec4(1.0f, 0.87f, 0.96f, 1.0f);
	// Create and initialize a buffer object 
	CreateBufferObject();
	m_bUpdateProj = false;
}


void BG::CreateBufferObject()
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

void BG::SetShader(mat4 &mxView, mat4 &mxProjection, GLuint uiShaderHandle)
{
	// Load shaders and use the resulting shader program
	if (uiShaderHandle == MAX_UNSIGNED_INT) m_uiProgram = InitShader("vsBGShader.glsl", "fsVtxColor.glsl");
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
	m_uiMove = glGetUniformLocation(m_uiProgram, "mxT"); //新增shader 要加這行!
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BG::SetViewMatrix(mat4 &mat)
{
	m_mxView = mat;
	m_bUpdateMV = true;
}
//void BG::SetMove() {
//	glUseProgram(m_uiProgram); //新增的函式要有這行
//	mxT[1][3] -= 1 * 0.005f;
//	/*printf("%f",mxT[1][3]);*/
//	/*Print("Hello");*/
//	glUniformMatrix4fv(m_uiMove, 1, GL_TRUE, mxT); //新增的函式要有這行 需要在最後一行!  傳入的值是mat4 才是glUniformMatrix4fv open2 ppt
//}

void BG::SetProjectionMatrix(mat4 &mat)
{
	m_mxProjection = mat;
	m_bUpdateProj = true;
}

void BG::SetTRSMatrix(mat4 &mat)
{
	m_mxTRS = mat;
	m_bUpdateMV = true;
}

void BG::SetColor(GLfloat vColor[4])
{
	for (int i = 0; i < 6; i++) {
		m_Colors[i].x = vColor[0];
		m_Colors[i].y = vColor[1];
		m_Colors[i].z = vColor[2];
		m_Colors[i].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_Points), sizeof(m_Colors), m_Colors);
}

void BG::SetVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[])
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

void BG::Draw()
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
	glDrawArrays(GL_TRIANGLE_FAN, 0, 12);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 11);
	glDrawArrays(GL_TRIANGLE_FAN, 23, 11);
	glDrawArrays(GL_TRIANGLE_FAN, 34, 11);
	glDrawArrays(GL_TRIANGLE_FAN, 45, 11);
	glDrawArrays(GL_TRIANGLE_FAN, 56, 11);

}
