#ifndef ENEMY4_H
#define ENEMY4_H
#include "./Header/Angel.h"

typedef Angel::vec4  color4;
typedef Angel::vec4  point4;

#define QUAD_NUM 200  // 2 faces, 2 triangles/face 

class Enemy4
{
private:
	vec4 m_Points[QUAD_NUM];
	vec4 m_Colors[QUAD_NUM];
	// VAO
	GLuint m_uiVao;
	// VBO
	GLuint m_uiBuffer;
	//  for Shader
	GLuint m_uiProgram;
	// Vertex Position Attribute
	GLuint m_uiModelView, m_uiProjection;
	GLuint m_uiMove;
	// Matrix 
	mat4 m_mxView, m_mxProjection;
	mat4 m_mxMVFinal, m_mxTRS;
	mat4 mxS = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	// 紀錄是否有矩陣的更新
	bool  m_bUpdateMV;
	bool  m_bUpdateProj;

	void CreateBufferObject();

public:
	int blood = 15;
	GLfloat Blood1[4] = { 0.21f, 0.58f, 0.96f, 1.0f };
	GLfloat Blood2[4] = { 1.0f, 0.6f, 0.18f, 1.0f };
	GLfloat Blood3[4] = { 0.15f,0.98f,0.51f,1.0f };
	bool Flag = false;
	bool BloodFlag = true;
	Enemy4();
	void DetectBlood();
	float x = 0.0f, y = 1.0f;
	void SetShader(mat4 &mxModelView, mat4 &mxProjection, GLuint uiShaderHandle = MAX_UNSIGNED_INT);
	GLuint GetShaderHandle() { return m_uiProgram; }
	void SetViewMatrix(mat4 &mat);
	void SetProjectionMatrix(mat4 &mat);
	void SetTRSMatrix(mat4 &mat);
	void SetColor(GLfloat vColor[4]); // Single color
	void SetVtxColors(GLfloat vLFColor[], GLfloat vLRColor[], GLfloat vTRColor[], GLfloat vTLColor[]); // four Vertices' Color
	void Draw();
	void DrawW();
};

#endif