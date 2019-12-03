#include "./Enemy2.h"

Enemy2::Enemy2()
{
	m_Points[0] = vec4(0.0f, 0.0f, 0.0f, 1.0f); //半圓圓心
	m_Points[1] = vec4(0.2f, 0.0f, 0.0f, 1.0f); //半圓
	m_Points[2] = vec4(0.2f*cosf(M_PI * 1 / 20), 0.2f*sinf(M_PI * 1 / 20), 0.0f, 1.0f);
	m_Points[3] = vec4(0.2f*cosf(M_PI * 2 / 20), 0.2f*sinf(M_PI * 2 / 20), 0.0f, 1.0f);
	m_Points[4] = vec4(0.2f*cosf(M_PI * 3 / 20), 0.2f*sinf(M_PI * 3 / 20), 0.0f, 1.0f);
	m_Points[5] = vec4(0.2f*cosf(M_PI * 4 / 20), 0.2f*sinf(M_PI * 4 / 20), 0.0f, 1.0f);
	m_Points[6] = vec4(0.2f*cosf(M_PI * 5 / 20), 0.2f*sinf(M_PI * 5 / 20), 0.0f, 1.0f);
	m_Points[7] = vec4(0.2f*cosf(M_PI * 6 / 20), 0.2f*sinf(M_PI * 6 / 20), 0.0f, 1.0f);
	m_Points[8] = vec4(0.2f*cosf(M_PI * 7 / 20), 0.2f*sinf(M_PI * 7 / 20), 0.0f, 1.0f);
	m_Points[9] = vec4(0.2f*cosf(M_PI * 8 / 20), 0.2f*sinf(M_PI * 8 / 20), 0.0f, 1.0f);
	m_Points[10] = vec4(0.2f*cosf(M_PI * 9 / 20), 0.2f*sinf(M_PI * 9 / 20), 0.0f, 1.0f);
	m_Points[11] = vec4(0.2f*cosf(M_PI * 10 / 20), 0.2f*sinf(M_PI * 10 / 20), 0.0f, 1.0f);
	m_Points[12] = vec4(0.2f*cosf(M_PI * 11 / 20), 0.2f*sinf(M_PI * 11 / 20), 0.0f, 1.0f);
	m_Points[13] = vec4(0.2f*cosf(M_PI * 12 / 20), 0.2f*sinf(M_PI * 12 / 20), 0.0f, 1.0f);
	m_Points[14] = vec4(0.2f*cosf(M_PI * 13 / 20), 0.2f*sinf(M_PI * 13 / 20), 0.0f, 1.0f);
	m_Points[15] = vec4(0.2f*cosf(M_PI * 14 / 20), 0.2f*sinf(M_PI * 14 / 20), 0.0f, 1.0f);
	m_Points[16] = vec4(0.2f*cosf(M_PI * 15 / 20), 0.2f*sinf(M_PI * 15 / 20), 0.0f, 1.0f);
	m_Points[17] = vec4(0.2f*cosf(M_PI * 16 / 20), 0.2f*sinf(M_PI * 16 / 20), 0.0f, 1.0f);
	m_Points[18] = vec4(0.2f*cosf(M_PI * 17 / 20), 0.2f*sinf(M_PI * 17 / 20), 0.0f, 1.0f);
	m_Points[19] = vec4(0.2f*cosf(M_PI * 18 / 20), 0.2f*sinf(M_PI * 18 / 20), 0.0f, 1.0f);

	m_Colors[0] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[1] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[2] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[3] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[4] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[5] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[6] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[7] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[8] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[9] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[10] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[11] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[12] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[13] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[14] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[15] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[16] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[17] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[18] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Colors[19] = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	m_Points[20] = vec4(-0.2f, 0.0f, 0.0f, 1.0f); //半圓左邊的點
	m_Colors[20] = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Points[21] = vec4(0.0f, 0.0f, 0.0f, 1.0f); //半圓圓心
	m_Colors[21] = vec4(1.0f, 1.0f, 1.0f, 1.0f);


	m_Points[22] = vec4(0.0f, 0.1f, 0.0f, 1.0f); //黑圓
	m_Colors[22] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	//黑圓
	m_Points[23] = vec4(0.1f*cosf(M_PI * 2.0f * 0 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 0 / 19), 0.0f, 1.0f);
	m_Points[24] = vec4(0.1f*cosf(M_PI * 2.0f * 1 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 1 / 19), 0.0f, 1.0f);
	m_Points[25] = vec4(0.1f*cosf(M_PI * 2.0f * 2 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 2 / 19), 0.0f, 1.0f);
	m_Points[26] = vec4(0.1f*cosf(M_PI * 2.0f * 3 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 3 / 19), 0.0f, 1.0f);
	m_Points[27] = vec4(0.1f*cosf(M_PI * 2.0f * 4 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 4 / 19), 0.0f, 1.0f);
	m_Points[28] = vec4(0.1f*cosf(M_PI * 2.0f * 5 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 5 / 19), 0.0f, 1.0f);
	m_Points[29] = vec4(0.1f*cosf(M_PI * 2.0f * 6 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 6 / 19), 0.0f, 1.0f);
	m_Points[30] = vec4(0.1f*cosf(M_PI * 2.0f * 7 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 7 / 19), 0.0f, 1.0f);
	m_Points[31] = vec4(0.1f*cosf(M_PI * 2.0f * 8 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 8 / 19), 0.0f, 1.0f);
	m_Points[32] = vec4(0.1f*cosf(M_PI * 2.0f * 9 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 9 / 19), 0.0f, 1.0f);
	m_Points[33] = vec4(0.1f*cosf(M_PI * 2.0f * 10 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 10 / 19), 0.0f, 1.0f);
	m_Points[34] = vec4(0.1f*cosf(M_PI * 2.0f * 11 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 11 / 19), 0.0f, 1.0f);
	m_Points[35] = vec4(0.1f*cosf(M_PI * 2.0f * 12 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 12 / 19), 0.0f, 1.0f);
	m_Points[36] = vec4(0.1f*cosf(M_PI * 2.0f * 13 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 13 / 19), 0.0f, 1.0f);
	m_Points[37] = vec4(0.1f*cosf(M_PI * 2.0f * 14 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 14 / 19), 0.0f, 1.0f);
	m_Points[38] = vec4(0.1f*cosf(M_PI * 2.0f * 15 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 15 / 19), 0.0f, 1.0f);
	m_Points[39] = vec4(0.1f*cosf(M_PI * 2.0f * 16 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 16 / 19), 0.0f, 1.0f);
	m_Points[40] = vec4(0.1f*cosf(M_PI * 2.0f * 17 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 17 / 19), 0.0f, 1.0f);
	m_Points[41] = vec4(0.1f*cosf(M_PI * 2.0f * 18 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 18 / 19), 0.0f, 1.0f);
	m_Points[42] = vec4(0.1f*cosf(M_PI * 2.0f * 19 / 19), 0.1f + 0.1f*sinf(M_PI * 2.0f * 19 / 19), 0.0f, 1.0f);

	m_Colors[23] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[24] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[25] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[26] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[27] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[28] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[29] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[30] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[31] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[32] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[33] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[34] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[35] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[36] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[37] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[38] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[39] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[40] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[41] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Colors[42] = vec4(0.0f, 0.0f, 0.0f, 0.0f);

	m_Points[43] = vec4(-0.35f, -0.1f, 0.0f, 1.0f); //身體上半部
	m_Points[44] = vec4(-0.2f, 0.0f, 0.0f, 1.0f);
	m_Points[45] = vec4(0.0f, -0.1f, 0.0f, 1.0f);
	m_Points[46] = vec4(0.2f, 0.0f, 0.0f, 1.0f);
	m_Points[47] = vec4(0.35f, -0.1f, 0.0f, 1.0f);
	
	m_Colors[43] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[44] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[45] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[46] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[47] = vec4(1.0f, 1.0f, 0.0f, 1.0f);

	m_Points[48] = vec4(-0.35f, -0.1f, 0.0f, 1.0f); //身體下半部
	m_Points[49] = vec4(-0.35f, -0.18f, 0.0f, 1.0f);
	m_Points[50] = vec4(0.0f, -0.1f, 0.0f, 1.0f);
	m_Points[51] = vec4(0.0f, -0.18f, 0.0f, 1.0f);
	m_Points[52] = vec4(0.35f, -0.1f, 0.0f, 1.0f);
	m_Points[53] = vec4(0.35f, -0.18f, 0.0f, 1.0f);
	
	m_Colors[48] = vec4(0.09f, 0.47f, 1.0f, 1.0f);
	m_Colors[49] = vec4(0.09f, 0.47f, 1.0f, 1.0f);
	m_Colors[50] = vec4(0.09f, 0.47f, 1.0f, 1.0f);
	m_Colors[51] = vec4(0.09f, 0.47f, 1.0f, 1.0f);
	m_Colors[52] = vec4(0.09f, 0.47f, 1.0f, 1.0f);
	m_Colors[53] = vec4(0.09f, 0.47f, 1.0f, 1.0f);

	m_Points[54] = vec4(-0.3f, -0.18f, 0.0f, 1.0f);
	m_Points[55] = vec4(-0.225f, -0.3, 0.0f, 1.0f);
	m_Points[56] = vec4(-0.15, -0.18, 0.0f, 1.0f);

	m_Points[57] = vec4(-0.1f, -0.18f, 0.0f, 1.0f);
	m_Points[58] = vec4(0.0f, -0.3f, 0.0f, 1.0f);
	m_Points[59] = vec4(0.1f, -0.18f, 0.0f, 1.0f);

	m_Points[60] = vec4(0.15f, -0.18f, 0.0f, 1.0f);
	m_Points[61] = vec4(0.225f, -0.3f, 0.0f, 1.0f);
	m_Points[62] = vec4(0.3f, -0.18f, 0.0f, 1.0f);

	m_Colors[54] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[55] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[56] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[57] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[58] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[59] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[60] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[61] = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_Colors[62] = vec4(1.0f, 1.0f, 0.0f, 1.0f);

	/*Create and initialize a buffer object */
	CreateBufferObject();
	m_bUpdateProj = false;
}


void Enemy2::CreateBufferObject()
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

void Enemy2::SetShader(mat4 &mxView, mat4 &mxProjection, GLuint uiShaderHandle)
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

void Enemy2::SetViewMatrix(mat4 &mat)
{
	m_mxView = mat;
	m_bUpdateMV = true;
}

void Enemy2::SetProjectionMatrix(mat4 &mat)
{
	m_mxProjection = mat;
	m_bUpdateProj = true;
}

void Enemy2::SetTRSMatrix(mat4 &mat)
{
	m_mxTRS = mat;
	m_bUpdateMV = true;
}

void Enemy2::SetColor(GLfloat vColor[4])
{
	for (int i = 43; i < 48; i++) {
		m_Colors[i].x = vColor[0];
		m_Colors[i].y = vColor[1];
		m_Colors[i].z = vColor[2];
		m_Colors[i].w = vColor[3];
	}
	for (int j = 54;j < 63;j++) {
		m_Colors[j].x = vColor[0];
		m_Colors[j].y = vColor[1];
		m_Colors[j].z = vColor[2];
		m_Colors[j].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_Points), sizeof(m_Colors), m_Colors);
}
void Enemy2::SetColor2(GLfloat vColor[4])
{
	for (int j = 48;j < 54;j++) {
		m_Colors[j].x = vColor[0];
		m_Colors[j].y = vColor[1];
		m_Colors[j].z = vColor[2];
		m_Colors[j].w = vColor[3];
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, m_uiBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_Points), sizeof(m_Colors), m_Colors);
}
void Enemy2::DetectBlood(){
	if (BloodFlag == true)blood -= 1;
	if (blood == 0) { Flag = false; }
	BloodFlag = false;
}
void Enemy2::SetVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[])
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

void Enemy2::Draw()
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
	glDrawArrays(GL_TRIANGLE_FAN, 22, 21);
	glDrawArrays(GL_TRIANGLE_STRIP, 43, 5);
	glDrawArrays(GL_TRIANGLE_STRIP, 48, 6);
	glDrawArrays(GL_TRIANGLES, 54, 9);

}

void Enemy2::DrawW()
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
