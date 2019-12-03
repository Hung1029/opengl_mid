#include "./Bullet.h"
#include "./Header/mat.h"

Bullet1::Bullet1()
{
	m_Points[0] = vec4(0.0f, 0.0f, 0.0f, 1.0f);//圓心
	m_Colors[0] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	//畫圓
	m_Points[1] = vec4(0.07f * cosf(M_PI * 2.0f * 0 / 10), 0.07f * sinf(M_PI * 2.0f * 0 / 10), 0.0f, 1.0f);
	m_Points[2] = vec4(0.07f * cosf(M_PI * 2.0f * 1 / 10), 0.07f * sinf(M_PI * 2.0f * 1 / 10), 0.0f, 1.0f);
	m_Points[3] = vec4(0.07f * cosf(M_PI * 2.0f * 2 / 10), 0.07f * sinf(M_PI * 2.0f * 2 / 10), 0.0f, 1.0f);
	m_Points[4] = vec4(0.07f * cosf(M_PI * 2.0f * 3 / 10), 0.07f * sinf(M_PI * 2.0f * 3 / 10), 0.0f, 1.0f);
	m_Points[5] = vec4(0.07f * cosf(M_PI * 2.0f * 4 / 10), 0.07f * sinf(M_PI * 2.0f * 4 / 10), 0.0f, 1.0f);
	m_Points[6] = vec4(0.07f * cosf(M_PI * 2.0f * 5 / 10), 0.07f * sinf(M_PI * 2.0f * 5 / 10), 0.0f, 1.0f);
	m_Points[7] = vec4(0.07f * cosf(M_PI * 2.0f * 6 / 10), 0.07f * sinf(M_PI * 2.0f * 6 / 10), 0.0f, 1.0f);
	m_Points[8] = vec4(0.07f * cosf(M_PI * 2.0f * 7 / 10), 0.07f * sinf(M_PI * 2.0f * 7 / 10), 0.0f, 1.0f);
	m_Points[9] = vec4(0.07f * cosf(M_PI * 2.0f * 8 / 10), 0.07f * sinf(M_PI * 2.0f * 8 / 10), 0.0f, 1.0f);
	m_Points[10] = vec4(0.07f * cosf(M_PI * 2.0f * 9 / 10), 0.07f * sinf(M_PI * 2.0f * 9 / 10), 0.0f, 1.0f);
	m_Points[11] = vec4(0.07f * cosf(M_PI * 2.0f * 10 / 10), 0.07f * sinf(M_PI * 2.0f * 10 / 10), 0.0f, 1.0f);

	m_Colors[1] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[2] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[3] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[4] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[5] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[6] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[7] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[8] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[9] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[10] = vec4(0.25f, 0.98f, 0.73f, 1.0f);
	m_Colors[11] = vec4(0.25f, 0.98f, 0.73f, 1.0f);

	/*Create and initialize a buffer object */
	CreateBufferObject();
	m_bUpdateProj = false;
}


void Bullet1::CreateBufferObject()
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

void Bullet1::SetShader(mat4 &mxView, mat4 &mxProjection, GLuint uiShaderHandle)
{
	// Load shaders and use the resulting shader program
	if (uiShaderHandle == MAX_UNSIGNED_INT) m_uiProgram = InitShader("vsBulletShader.glsl", "fsVtxColor.glsl");
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

void Bullet1::SetViewMatrix(mat4 &mat)
{
	m_mxView = mat;
	m_bUpdateMV = true;
}

void Bullet1::SetProjectionMatrix(mat4 &mat)
{
	m_mxProjection = mat;
	m_bUpdateProj = true;
}

void Bullet1::SetTRSMatrix(mat4 &mat)
{
	m_mxTRS = mat;
	m_bUpdateMV = true;
}

void Bullet1::SetColor(GLfloat vColor[4])
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
void Bullet1::SetMove() {
	glUseProgram(m_uiProgram); //新增的函式要有這行
	mxT[1][3] = yi + ShootTime * 10.0f;
	y = mxT[1][3];
	/*Print(y);*/
	/*printf("%f",mxT[1][3]);*/
	/*Print("Hello");*/
	glUniformMatrix4fv(m_uiMove, 1, GL_TRUE, mxT); //新增的函式要有這行 需要在最後一行!  傳入的值是mat4 才是glUniformMatrix4fv open2 ppt
}
void Bullet1::GetPos(GLfloat x1, GLfloat y1) {
	mxT[0][3] = x1;
	x = mxT[0][3];
	yi = y1;
}
GLfloat Bullet1::GBulletPos() {
	return(mxT[1][3]);
}
void Bullet1::GetTime(float time) {
	ShootTime += time;
}
void Bullet1::SetVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[])
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

void Bullet1::Draw()
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

}

void Bullet1::DrawW()
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
