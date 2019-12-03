/*
功能需求
(7 % ) 操控與背景部分
  O(1 % ) 滑鼠可以控制戰鬥機的左右移動
  O(1 % ) 戰鬥機傭有防禦裝置，並以父子關係方式呈現
  O(1 % ) 可以發射飛彈
  O(2 % ) 能提供連續發射(LINKED LIST)
  O(2 % ) 能產生有速度感的背景物件，或是其他裝飾性的物件
(10 % ) 敵人部分
  O(1 % ) 有至少三種以上不同外形的敵人(不同的顏色)，基本的四方型不算在內
   (2 % ) 以物件導向的多型來控制所有的敵人
  O(1 % ) 敵人可以不斷的產生，而且具有不同的顏色
  O(1 % ) 敵人能隨機朝向玩家發射子彈攻擊
  O(2 % ) 戰鬥機發射的子彈可以打到敵人，而且敵人會消失
  O(3 % ) 有 BOSS 級的敵人，且至會根據被攻擊的多寡至少三種不同的狀態可以切換
(4 % ) (玩家部分)
  O(2 % ) 能判斷玩家是否被打中 並做出合理的反應(血量降低→變色)
  O(2 % ) 玩家的船艦至少有三種狀態，且有提供玩家的船艦可改變狀態的機制
(5 % ) 其他你覺得可以展示的技術，包含物理或是數學的運算
  O(1 % ) 戰鬥機被打到時有其他的效果(血量與顏色有關)
  O(1 % ) 背景除了速度感物件外，有其他的效果(背景顏色象徵關卡)
  O(1 % ) 碰到牆壁反彈
總分：  22 
*/

// Model-View matrix and Projection matrix
// Orthogonal or Orthographic projection
// Windows Events - Keyboard & Mouse
// Rotate Rectangle

#include "header/Angel.h"
#include "Common/CQuad.h"
#include "Common/CQuadEX1.h"
#include "./Enemy1.h"
#include "./Bullet.h"
#include "./VBullet.h"
#include "./Enemy2.h"
#include "./BG.h"
#include "./Ball.h"
#include "./Enemy3.h"
#include "./Enemy4.h"

#define SPACE_KEY 32
#define SCREEN_SIZE 600
#define HALF_SIZE (SCREEN_SIZE/2)

// 必須在 glewInit(); 執行完後,在執行物件實體的取得
CQuad *g_pQuad;	// 宣告 Quad 指標物件，結束時記得釋放
BG *g_pBG[3]; //背景指標物件
Ball *g_pBall[4]; //防禦球
Enemy1 *g_pEnemy1[3]; //敵人1指標物件
Enemy2 *g_pEnemy2[2]; //敵人2指標物件
Enemy3 *g_pEnemy3[1]; //敵人3指標物件
Enemy4 *g_pEnemy4[2]; //敵人4指標物件
VBullet *g_pVBullet; //敵人子彈
Bullet1 *g_pBullet; //主角子彈
VBullet *VHead, *VGet, *VTail, *VHeadShoot, *VGetShoot, *VTailShoot, *VLink,*VFlag;
Bullet1 *Head, *Get, *Tail, *HeadShoot, *GetShoot, *TailShoot, *Link, *Flag;

GLfloat g_fAngle = 0;   // X/Y/Z 三軸的旋轉角度
GLfloat BGTime = 0; //背景時間
GLfloat g_fZAngle = 0;     // 旋轉方向
GLfloat g_fTx = 0, g_fTy = 0;
GLfloat Pos[2] = { 0.0f,0.0f }; //鼠標(角色)位置

float Bx = 10.0f;//角色子彈位置
float By = 10.0f;
float EBx[2] = { 10.0f,10.0f };//敵人子彈位置
float EBy[2]= {10.0f,10.0f};
float Dir = -1.0f; //敵人2移動方向
float DirA = -1.0f;
float f_Dir = 1.0f; //敵人3旋轉方向
float E4DirX = 1.0f;
float E4DirY = 1.0f;
float E4ADirX = 1.0f;
float E4ADirY = 1.0f;
float g_ShootTime = 0.0f;
float g_Enemy1Time = 0.0f; //敵人1時間
float g_Enemy2Time = 0.0f; //敵人2出現判斷
float g_Enemy2BTime = 0.0f; //敵人2位移時間
float g_Enemy2CTime = 0.0f;
float g_Enemy3Time = 0.0f;
float g_Enemy3CTime = 0.0f;
float g_Enemy3BTime = 0.0f;
float g_Enemy4Time = 0.0f;
float g_Enemy4Atime = 0.0f;
float g_BallTime = 0.0f;
float Enemy2Init = -3.0f; //敵人2初始x座標
float Enemy2AInit = 3.0f;
float Enemy3Init = 0.0f;
float Enemy4Init = 2.0f;
float Enemy4InitY = 1.0f;
float Enemy4Ainit = -2.0f;
float Enemy4AInitY = 1.0f;
float g_Ball = 0.0f;
float f_Angle = 0.0f;

int VBulletNum = 0;//敵人子彈數量
int BulletCount = 0;//角色子彈數量
int i = 0;

bool VBFlag = true;//敵人子彈
bool HideB = true;//角色子彈是否顯示
bool HideVB = true;//敵人子彈是否顯示
					// For Model View and Projection Matrix
mat4 g_mxModelView(1.0f);
mat4 g_mxProjection;
mat4 mxInitE2=Translate(-3.0f,3.0f,0.0f);
mat4 mxInitE2A = Translate(3.0f, 3.0f, 0.0f);
mat4 mxInitE3=Translate(0.0f, 2.0f, 0.0f);
mat4 mxInitE4 = Translate(2.0f, 1.0f, 0.0f);
mat4 mxInitE4A = Translate(-2.0f, 1.0f, 0.0f);
mat4 mxT = Translate(-1.0f, 2.0f, 0.0f);

// For Rotation

//----------------------------------------------------------------------------
// 函式的原型宣告
void IdleProcess();
void Create();
void Shoot();
void VShoot(float, float);
void VRShoot();
void Enemy1AutoRotateion(float);
void Enemy2Action(mat4);
void RShoot();
void BgAction(float);
void Esc();
void BallShow(float);
void Enemy3Action(float);
void CheckEnemy1(Bullet1*);
void CheckMain(VBullet*);
void CheckBall(Bullet1*);
void Enemy4Action(float);
void Enemy4BAction(float);
void StarAttact();
void CheckEnemy2(Bullet1*);
void CheckEnemy2A(Bullet1*);


void init(void)
{
	// 必須在 glewInit(); 執行完後,在執行物件實體的取得
	g_pQuad = new CQuad;
	//  產生 projection 矩陣，此處為產生正投影矩陣
	g_mxProjection = Ortho(-4.0f, 4.0f, -4.0f, 4.0f, -2.0f, 1.0f);
	g_pQuad->SetShader(g_mxModelView, g_mxProjection);

	glClearColor(0.96, 0.58, 0.66, 1.0); // black background
	Create();
}

void Create(void) {
	g_pBG[0] = new BG;
	g_pBG[0]->SetShader(g_mxModelView, g_mxProjection);
	g_pBG[0]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pBG[1] = new BG;
	g_pBG[1]->SetShader(g_mxModelView, g_mxProjection);
	g_pBG[1]->SetTRSMatrix(Translate(Pos[0],Pos[1],0.0f)*Translate(1.0f, 1.0f, 0.0f));
	g_pBG[2] = new BG;
	g_pBG[2]->SetShader(g_mxModelView, g_mxProjection);
	g_pBG[2]->SetTRSMatrix(Translate(Pos[0], Pos[1], 0.0f)*Translate(1.0f, 1.0f, 0.0f));
	
	g_pEnemy1[0] = new Enemy1;
	g_pEnemy1[0]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy1[0]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pEnemy1[1] = new Enemy1;
	g_pEnemy1[1]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy1[1]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pEnemy1[2] = new Enemy1;
	g_pEnemy1[2]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy1[2]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	

	g_pEnemy2[0] = new Enemy2;
	g_pEnemy2[0]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy2[0]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pEnemy2[1] = new Enemy2;
	g_pEnemy2[1]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy2[1]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	
	g_pEnemy3[0] = new Enemy3;
	g_pEnemy3[0]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy3[0]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	//g_pEnemy3[0]->Flag = 0;

	g_pEnemy4[0] = new Enemy4;
	g_pEnemy4[0]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy4[0]->SetTRSMatrix(Translate(10.0f, 10.0f, 10.0f));
	g_pEnemy4[1] = new Enemy4;
	g_pEnemy4[1]->SetShader(g_mxModelView, g_mxProjection);
	g_pEnemy4[1]->SetTRSMatrix(Translate(10.0f, 10.0f, 10.0f));

	g_pBall[0] = new Ball;
	g_pBall[0]->SetShader(g_mxModelView, g_mxProjection);
	g_pBall[0]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pBall[1] = new Ball;
	g_pBall[1]->SetShader(g_mxModelView, g_mxProjection);
	g_pBall[1]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pBall[2] = new Ball;
	g_pBall[2]->SetShader(g_mxModelView, g_mxProjection);
	g_pBall[2]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));
	g_pBall[3] = new Ball;
	g_pBall[3]->SetShader(g_mxModelView, g_mxProjection);
	g_pBall[3]->SetTRSMatrix(Translate(10.0f, 10.0f, 0.0f));



	VHeadShoot = VTailShoot = NULL;
	g_pVBullet = new VBullet;
	g_pVBullet->SetShader(g_mxModelView, g_mxProjection);

	VHead = VTail = NULL;
	VHead = new VBullet;
	VHead->SetShader(g_mxModelView, g_mxProjection);

	VTail = VHead;

	for (int i = 0;i < 80;i++) {
		VGet = new VBullet;
		VGet->SetShader(g_mxModelView, g_mxProjection);

		VGet->next = NULL;
		VTail->next = VGet;
		VTail = VGet;
	}

	HeadShoot = TailShoot = NULL;
	g_pBullet = new Bullet1;
	g_pBullet->SetShader(g_mxModelView, g_mxProjection);

	Head = Tail = NULL;
	Head = new Bullet1;
	Head->SetShader(g_mxModelView, g_mxProjection);

	Tail = Head;

	for (int i = 0;i < 20;i++) {
		Get = new Bullet1;
		Get->SetShader(g_mxModelView, g_mxProjection);

		Get->next = NULL;
		Tail->next = Get;
		Tail = Get;
	}

}

void BgAction(float dt) {
	mat4 mxBg1;
	BGTime += dt;
	mat4 mxBg = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	g_pBG[0]->y = 6.0f;
	g_pBG[1]->y = 4.0f;
	g_pBG[2]->y = 2.0f;

	if (g_pBG[0]->y < -4.0f || g_pBG[1]->y <-4.0f || g_pBG[2]->y<-4.0f) {
		g_pBG[0]->SetTRSMatrix(Translate(0.0f, 8.0f, 0.0f)*Scale(2.0f, 2.0f, 0.0f));
		g_pBG[1]->SetTRSMatrix(Translate(-2.0f, 6.0f, 0.0f)*Scale(2.0f, 2.0f, 0.0f));
		g_pBG[2]->SetTRSMatrix(Translate(2.0f, 4.0f, 0.0f)*Scale(2.0f, 2.0f, 0.0f));
		g_pBG[0]->y = 8.0f;
		g_pBG[1]->y = 6.0f;
		g_pBG[2]->y = 4.0f;
	}
	else {
		if (BGTime >= 3.0f)BGTime -= 3.0f;
		mxBg[1][3] = (-1.0f) * 4.0f * BGTime;
		g_pBG[0]->SetTRSMatrix(Translate(0.0f, 8.0f, 0.0f)*mxBg*Scale(2.0f, 2.0f, 0.0f));
		g_pBG[1]->SetTRSMatrix(Translate(-2.0f, 6.0f, 0.0f)*mxBg*Scale(2.0f, 2.0f, 0.0f));
		g_pBG[2]->SetTRSMatrix(Translate(2.0f, 4.0f, 0.0f)*mxBg*Scale(2.0f, 2.0f, 0.0f));
		g_pBG[0]->y = mxBg[1][3] + 8.0f;
		g_pBG[1]->y = mxBg[1][3] + 6.0f;
		g_pBG[2]->y = mxBg[1][3] + 4.0f;
	}
}

void BallShow(float dt) {
	g_pBall[0]->SetTRSMatrix(Translate(1.0f, 1.0f, 0.0f)*Scale(3.0f,3.0f,0.0f));
	g_pBall[0]->x = 1.0f;g_pBall[0]->y = 1.0f;
	
}

void CheckEnemy1(Bullet1* pos) {
	if ((g_pEnemy1[0]->Flag == true) && (pos->x < (g_pEnemy1[0]->x+0.5f)) && (pos->x >(g_pEnemy1[0]->x- 0.5f)) && (pos->y < (g_pEnemy1[0]->y + 0.5f)) && (pos->y > (g_pEnemy1[0]->y - 0.5f))) {
		g_pEnemy1[0]->Flag = false;
		pos->BFlag = false;
	}
	else if ((g_pEnemy1[1]->Flag == true) && (pos->x < (g_pEnemy1[1]->x + 0.5f)) && (pos->x >(g_pEnemy1[1]->x - 0.5f)) && (pos->y < (g_pEnemy1[1]->y + 0.5f)) && (pos->y >(g_pEnemy1[1]->y - 0.5f))) {
		g_pEnemy1[1]->Flag = false;
		pos->BFlag = false;
	}
	else if ((g_pEnemy1[2]->Flag == true) && (pos->x < (g_pEnemy1[2]->x + 0.5f)) && (pos->x >(g_pEnemy1[2]->x - 0.5f)) && (pos->y < (g_pEnemy1[2]->y + 0.5f)) && (pos->y >(g_pEnemy1[2]->y - 0.5f))) {
		g_pEnemy1[2]->Flag = false;
		pos->BFlag = false;
	}
}
void CheckEnemy2(Bullet1* pos) {
	if ((g_pEnemy2[0]->Flag==true) && (pos->x < (g_pEnemy2[0]->x + 0.6f)) && (pos->x > (g_pEnemy2[0]->x - 0.6f)) && (pos->y < (g_pEnemy2[0]->y + 0.3f)) && (pos->y > (g_pEnemy2[0]->y - 0.3f))) {
		g_pEnemy2[0]->DetectBlood();
		pos->BFlag = false;
	}
}
void CheckEnemy2A(Bullet1* pos) {
	if ((g_pEnemy2[1]->Flag == true) && (pos->x < (g_pEnemy2[1]->x + 0.6f)) && (pos->x >(g_pEnemy2[1]->x - 0.6f)) && (pos->y < (g_pEnemy2[1]->y+0.3f)) && (pos->y >(g_pEnemy2[1]->y - 0.3f))) {
		g_pEnemy2[1]->DetectBlood();
		pos->BFlag = false;
	}
}
void CheckEnemy3(Bullet1* pos) {
	/*Print(g_pEnemy3[0]->x);*/
	/*Print(pos->y);*/
	/*Print(g_pEnemy3[0]->Flag);*/
	if ((g_pEnemy3[0]->Flag == true) && (pos->x < (g_pEnemy3[0]->x + 1.0f)) && (pos->x > (g_pEnemy3[0]->x - 1.0f)) && (pos->y < (g_pEnemy3[0]->y + 1.0f)) && (pos->y > (g_pEnemy3[0]->y - 1.0f))) {
		/*Print(g_pEnemy3[0]->blood);*/
		g_pEnemy3[0]->DetectBlood();
		pos->BFlag = false;
	}
}

void CheckBall(Bullet1* pos) {
	mat4 g_fGQuadT;

	if ((g_pBall[0]->Flag == true) && (pos->x < (g_pBall[0]->x + 0.2f)) && (pos->x > (g_pBall[0]->x - 0.2f)) && (pos->y < (g_pBall[0]->y + 0.2f)) && (pos->y > (g_pBall[0]->y - 0.2f))) {
		g_pBall[0]->Flag = false;
		Print("Eat");
		g_pQuad->Protect=3;
		g_pBall[1]->Flag = true;
		g_pBall[2]->Flag = true;
		g_pBall[3]->Flag = true;
	}
}
void CheckMain(VBullet *pos) {
	if ((g_pQuad->Flag == true) && (pos->x < (Pos[0] + 0.3f)) && (pos->x >(Pos[0] - 0.3f)) && (pos->y < (Pos[1] + 0.2f)) && (pos->y >(Pos[1] - 0.2f))) {
		g_pQuad->Detect();
	}
	pos->BFlag = false;
}

void Enemy1AutoRotateion(float dt) {
	mat4 mxRot, mxT, mxTT, mxTTT;
	mat4 mxS = (
		1, 0, 0, 0,
		0, 1, 0, 1,
		0, 0, 1, 0,
		0, 0, 0, 1
		);

	g_Enemy1Time += dt;
	if (g_Enemy1Time > 3.0f) {
		mxT = Translate(2.0f, 0.5f, 0.0f);
		mxTT = Translate(0.0f, 1.5f, 0.0f);
		mxTTT = Translate(-2.0f, 2.5f, 0.0f);
		g_fZAngle = 2.0f * g_Enemy1Time  * 90.0f;
		mxRot = RotateZ(g_fZAngle);
		g_pEnemy1[0]->SetTRSMatrix(mxT*mxRot);
		g_pEnemy1[1]->SetTRSMatrix(mxTT*mxRot);
		g_pEnemy1[2]->SetTRSMatrix(mxTTT*mxRot);
		g_pEnemy1[0]->x = 2.0f;g_pEnemy1[0]->y = 0.5f;
		g_pEnemy1[1]->x = 0.0f;g_pEnemy1[1]->y = 1.5f;
		g_pEnemy1[2]->x = -2.0f;g_pEnemy1[2]->y = 2.5f;
		if ((Pos[0] < mxT[0][3] + 1.8f && Pos[0] > mxT[0][3] - 1.8f) && (Pos[1] < mxT[1][3] + 1.8f && Pos[1] > mxT[1][3] - 1.8f)) {
			g_pEnemy1[0]->SetTRSMatrix(mxT*mxRot*Scale(2.0f, 2.0f, 0.0f));
		}
		else if ((Pos[0] < mxTT[0][3] + 1.8f && Pos[0] > mxTT[0][3] - 1.8f) && (Pos[1] < mxTT[1][3] + 1.8f && Pos[1] > mxTT[1][3] - 1.8f)) {
			g_pEnemy1[1]->SetTRSMatrix(mxTT*mxRot*Scale(2.0f, 2.0f, 0.0f));
		}
		else if ((Pos[0] < mxTTT[0][3] + 1.8f && Pos[0] > mxTTT[0][3] - 1.8f) && (Pos[1] < mxTTT[1][3] + 1.8f && Pos[1] > mxTTT[1][3] - 1.8f)) {
			g_pEnemy1[2]->SetTRSMatrix(mxTTT*mxRot*Scale(2.0f, 2.0f, 0.0f));
		}
	}
	if ((g_pEnemy1[0]->Flag==true) && (Pos[0] < (g_pEnemy1[0]->x + 1.1f)) && (Pos[0] > (g_pEnemy1[0]->x - 1.1f)) && (Pos[1] < (g_pEnemy1[0]->y + 1.1f)) && (Pos[1] > (g_pEnemy1[0]->y - 1.1f))) {
		g_pQuad->Detect();
	}
	else if ((g_pEnemy1[1]->Flag == true) && (Pos[0] < (g_pEnemy1[1]->x + 1.1f)) && (Pos[0] > (g_pEnemy1[1]->x - 1.1f)) && (Pos[1] < (g_pEnemy1[1]->y + 1.1f)) && (Pos[1] > (g_pEnemy1[1]->y - 1.1f))) {
		g_pQuad->Detect();
	}
	else if ((g_pEnemy1[2]->Flag == true) && (Pos[0] < (g_pEnemy1[2]->x + 1.1f)) && (Pos[0] > (g_pEnemy1[2]->x - 1.1f)) && (Pos[1] < (g_pEnemy1[2]->y + 1.1f)) && (Pos[1] > (g_pEnemy1[2]->y - 1.1f))) {
		g_pQuad->Detect();
	}
}

void Enemy2Action(float dt) {
	mat4 mxE2 = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	mat4 mxE2A = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	/*Print(g_pEnemy2[0]->x);*/
	
	g_Enemy2BTime += dt;
	g_Enemy2CTime += dt;
	mxE2[0][3] += (Dir)* g_Enemy2BTime*2.0f;
	mxE2A[0][3] += (DirA)* g_Enemy2CTime*2.0f;
	g_pEnemy2[0]->SetTRSMatrix(mxInitE2*mxE2*Scale(2.0f, 2.0f, 0.0f));
	g_pEnemy2[0]->x = Enemy2Init + mxE2[0][3];
	g_pEnemy2[0]->y = 3.0f;
	g_pEnemy2[1]->SetTRSMatrix(mxInitE2A*mxE2A*Scale(2.0f, 2.0f, 0.0f));
	g_pEnemy2[1]->x = Enemy2AInit + mxE2A[0][3];
	g_pEnemy2[1]->y = 3.0f;

	if ((g_pEnemy2[1]->x >= 3.0f))
	{
		DirA = -1.0f;
		mxInitE2A = Translate(3.0f, 3.0f, 0.0f);
		Enemy2AInit = 3.0f;
		g_Enemy2CTime = 0.0f;

	}
	else if ((g_pEnemy2[1]->x <= -3.0f)) {
		DirA = 1.0f;
		mxInitE2A = Translate(-3.0f, 3.0f, 0.0f);
		Enemy2AInit = -3.0f;
		g_Enemy2CTime = 0.0f;
	}

	if ((g_pEnemy2[0]->x >= 3.0f)) 
	{
		Dir = -1.0f;
		mxInitE2 = Translate(3.0f, 3.0f, 0.0f);
		Enemy2Init = 3.0f;
		g_Enemy2BTime = 0.0f;
		
	}
	else if ((g_pEnemy2[0]->x <= -3.0f)) {
		Dir = 1.0f;
		mxInitE2 = Translate(-3.0f, 3.0f, 0.0f);
		Enemy2Init = -3.0f;
		g_Enemy2BTime = 0.0f;
	}
	if ((g_pEnemy2[0]->Flag == true) && (Pos[0] < (g_pEnemy2[0]->x + 1.5f)) && (Pos[0] > (g_pEnemy2[0]->x - 1.5f)) && (Pos[1] < (g_pEnemy2[0]->y + 1.5f)) && (Pos[1] > (g_pEnemy2[0]->y - 1.5f))) {
		g_pQuad->Detect();
	}
	if ((g_pEnemy2[1]->Flag == true) && (Pos[0] < (g_pEnemy2[1]->x + 1.5f)) && (Pos[0] > (g_pEnemy2[1]->x - 1.5f)) && (Pos[1] < (g_pEnemy2[1]->y + 1.5f)) && (Pos[1] > (g_pEnemy2[1]->y - 1.5f))) {
		g_pQuad->Detect();
	}

	
	
}
void Enemy3Action(float dt) {
	mat4 mxE3 = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	mat4 mxE3T = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);

	g_Enemy3Time += dt;
	float a = f_Dir * g_Enemy3Time * 0.02f * 360.0f;
	float x = cos(a);
	float y = sin(a);
	
	mxE3[0][0] = x;mxE3[0][1] = y;mxE3[1][0] = -y;mxE3[1][1] = x;
	/*g_pEnemy3[0]->SetTRSMatrix(mxInitE3*mxE3T);
	g_pEnemy3[0]->x = Enemy3Init+ mxE3T[0][3];
	g_pEnemy3[0]->y = 2.0f;*/
	/*Print(g_pEnemy3[0]->blood);*/

if ((g_pEnemy3[0]->Flag == true) && (g_pEnemy3[0]->blood <= 20)&&(g_pEnemy3[0]->blood > 15)) {
	g_pEnemy3[0]->SetTRSMatrix(mxInitE3*mxE3T);
	g_pEnemy3[0]->x = Enemy3Init + mxE3T[0][3];
	g_pEnemy3[0]->y = 2.0f;
	g_pEnemy3[0]->SetColor(g_pEnemy3[0]->Blood1);//藍色
	/*g_pEnemy3[0]->SetTRSMatrix(mxInitE3*mxE3T);*/
	StarAttact();
	}
else if ((g_pEnemy3[0]->Flag == true) && (g_pEnemy3[0]->blood <= 15) && (g_pEnemy3[0]->blood>5)) {
		
		f_Dir = 1.0f;
		/*g_Enemy3BTime += dt;*/
		g_pEnemy3[0]->SetColor(g_pEnemy3[0]->Blood2);//橘色
	/*	mxE3T[0][3] += (Dir)* g_Enemy3BTime*2.0f;*/
	/*	Print(mxE3T[0][3], g_pEnemy3[0]->x);*/
		g_pEnemy3[0]->SetTRSMatrix(mxInitE3*mxE3);
		g_pEnemy3[0]->x = Enemy3Init + mxE3T[0][3];
	
	}
	else if ((g_pEnemy3[0]->Flag == true) && (g_pEnemy3[0]->blood <= 5)) {
		g_Enemy3CTime += dt;
		if (g_Enemy3CTime > 6.5f) { g_pEnemy3[0]->blood += 4;Print("OH NO!");g_Enemy3CTime = 0.0f;}
		/*g_pEnemy3[0]->AddBloodFlag = true;*/
		f_Dir = -1.0f;
		StarAttact();
		g_pEnemy3[0]->SetColor(g_pEnemy3[0]->Blood3);//綠色
		
	}
	
	else if ((g_pEnemy3[0]->Flag == true) && (g_pEnemy3[0]->blood == 0)) {
		g_pEnemy3[0]->Flag = false;
		g_pEnemy4[0]->Flag = false;
		g_pEnemy4[1]->Flag = false;
	}

	if ((g_pEnemy3[0]->Flag == true) && (Pos[0] < (g_pEnemy3[0]->x + 1.3f)) && (Pos[0] > (g_pEnemy3[0]->x - 1.3f)) && (Pos[1] < (g_pEnemy3[0]->y + 1.3f)) && (Pos[1] > (g_pEnemy3[0]->y - 1.3f))) {
		g_pQuad->Detect();
	}

}
void Enemy4BAction(float dt) {
	mat4 mxE4A = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	if (g_pEnemy4[1]->Flag == true) {
		g_Enemy4Atime += dt;
		mxE4A[0][3] += g_Enemy4Atime*E4ADirX*(-3.0f);
		mxE4A[1][3] += g_Enemy4Atime*E4ADirY*(-3.0f);
		g_pEnemy4[1]->SetTRSMatrix(mxInitE4A*mxE4A);
		g_pEnemy4[1]->x = Enemy4Ainit + mxE4A[0][3];
		g_pEnemy4[1]->y = Enemy4AInitY + mxE4A[1][3];
		/*Print(g_pEnemy4[0]->x);*/
		if (g_pEnemy4[1]->x >= (4.0f + 0.4f) || g_pEnemy4[1]->x <= (-4.0f + 0.4f)) {
			E4ADirX = -E4ADirX;
			mxInitE4A = Translate(g_pEnemy4[1]->x, g_pEnemy4[1]->y, 0.0f);
			Enemy4Ainit = g_pEnemy4[1]->x;
			Enemy4AInitY = g_pEnemy4[1]->y;
			g_Enemy4Atime = 0;
		}
		else if (g_pEnemy4[1]->y >= (4.0f + 0.4f) || g_pEnemy4[1]->y <= (-4.0f + 0.4f)) {
			E4ADirY = -E4ADirY;
			mxInitE4A = Translate(g_pEnemy4[1]->x, g_pEnemy4[1]->y, 0.0f);
			Enemy4Ainit = g_pEnemy4[1]->x;
			Enemy4AInitY = g_pEnemy4[1]->y;
			g_Enemy4Atime = 0;
		}
		if ((g_pEnemy4[1]->Flag == true) && (Pos[0] < (g_pEnemy4[1]->x + 0.8f)) && (Pos[0] > (g_pEnemy4[1]->x - 0.8f)) && (Pos[1] < (g_pEnemy4[1]->y + 0.8f)) && (Pos[1] > (g_pEnemy4[1]->y - 0.8f))) {
			g_pQuad->Detect();
		}

	}
}
void Enemy4Action(float dt) {
	mat4 mxE4 = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	if (g_pEnemy4[0]->Flag == true) {
		
		g_Enemy4Time += dt;
		mxE4[0][3] += g_Enemy4Time*E4DirX*2.0f;
		mxE4[1][3] += g_Enemy4Time*E4DirY*2.0f;
		g_pEnemy4[0]->SetTRSMatrix(mxInitE4*mxE4);
		g_pEnemy4[0]->x = Enemy4Init + mxE4[0][3];
		g_pEnemy4[0]->y = Enemy4InitY + mxE4[1][3];
		/*Print(g_pEnemy4[0]->x);*/
		if (g_pEnemy4[0]->x >= (4.0f-0.4f) || g_pEnemy4[0]->x<= (-4.0f+0.4f)) {
			E4DirX = -E4DirX;
			mxInitE4 = Translate(g_pEnemy4[0]->x, g_pEnemy4[0]->y, 0.0f);
			Enemy4Init = g_pEnemy4[0]->x;
			Enemy4InitY = g_pEnemy4[0]->y;
			g_Enemy4Time = 0;
		}
		else if (g_pEnemy4[0]->y >= (4.0f - 0.4f) || g_pEnemy4[0]->y <= (-4.0f + 0.4f)) {
			E4DirY = -E4DirY;
			mxInitE4 = Translate(g_pEnemy4[0]->x, g_pEnemy4[0]->y, 0.0f);
			Enemy4Init = g_pEnemy4[0]->x;
			Enemy4InitY = g_pEnemy4[0]->y;
			g_Enemy4Time = 0;
		}
		if ((g_pEnemy4[0]->Flag == true) && (Pos[0] < (g_pEnemy4[0]->x + 0.8f)) && (Pos[0] > (g_pEnemy4[0]->x - 0.8f)) && (Pos[1] < (g_pEnemy4[0]->y + 0.8f)) && (Pos[1] > (g_pEnemy4[0]->y - 0.8f))) {
			g_pQuad->Detect();
		}

	}
}
void BallAction(float dt) {
	mat4 mxBall = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	mat4 mxBall2 = (
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	g_BallTime += dt;
	f_Angle = 2.0f * g_BallTime  * 90.0f;

	mxBall = RotateZ(f_Angle);
	
	if (g_pBall[1]->Flag == true) {
		g_pBall[1]->SetTRSMatrix(Translate(Pos[0], Pos[1]+0.2f, 0.0f)*mxBall*Translate(0.5f, 0.0f, 0.0f));
	}
	if (g_pBall[2]->Flag == true) {
		g_pBall[2]->SetTRSMatrix(Translate(Pos[0], Pos[1] + 0.2f, 0.0f)*mxBall*Translate(-0.25f, 0.5f, 0.0f));
	}
	if (g_pBall[3]->Flag == true) {
		g_pBall[3]->SetTRSMatrix(Translate(Pos[0], Pos[1] + 0.2f, 0.0f)*mxBall*Translate(-0.5f, -0.25f, 0.0f));
	}

	if (g_pQuad->Protect == 2) { g_pBall[3]->Flag = false; }
	else if (g_pQuad->Protect == 1) { g_pBall[2]->Flag = false; }
	else if (g_pQuad->Protect == 0) { g_pBall[1]->Flag = false; }
}
void MainAdd(){
	if(g_pQuad->Mainblood!=5)g_pQuad->Mainblood +=1;
	Print("Add");
}
void AddBlood(){
	StarAttact();
	g_pEnemy3[0]->blood += 1;
	Print("OH NO!");
}
void StarAttact() {
	if (VBulletNum < 60) {

		VShoot(2.0f, 3.0f);
		VShoot(1.0f, 3.0f);
		VShoot(0.5f, 3.0f);
		VShoot(0.0f, 3.0f);
		VShoot(-0.5f, 3.0f);
		VShoot(-1.0f, 3.0f);
		VShoot(-2.0f, 3.0f);
	}
}
//void timer_function3(int n) {
//	if (g_pEnemy3[0]->blood <= 8 && VBulletNum < 80) {
//		g_pEnemy3[0]->blood += 4;
//		Print("OH NO!");
//	}
//	if (g_pEnemy3[0]->AddBloodFlag)glutTimerFunc(3000, timer_function3, 3);
//}
void timer_function2(int n) {
	g_pEnemy2[0]->BloodFlag = true;
	g_pEnemy2[1]->BloodFlag = true;
	g_pEnemy3[0]->BloodFlag = true;
	g_pQuad->BloodFlag = true;
	glutTimerFunc(1500, timer_function2, 2);
}
void timer_function1(int n) {
	if (VBulletNum < 80 && g_Enemy2Time >= 9.0f) {
		/*VShoot(g_pEnemy2[0]->x-0.02,3.0f);*/
		VShoot(g_pEnemy2[0]->x + 0.38f, 2.5f);
		VShoot(g_pEnemy2[0]->x - 0.38f, 2.5f);
		VShoot(g_pEnemy2[0]->x + 0.38f, 3.0f);
		VShoot(g_pEnemy2[0]->x - 0.38f, 3.0f);
	}
	if (g_pEnemy2[0]->Flag)glutTimerFunc(1000, timer_function1, 5);
}
void timer_function(int n){
	
	if (VBulletNum < 80 && g_Enemy2Time >= 9.0f) {
		VShoot(g_pEnemy2[1]->x + 0.38f, 2.5f);
		VShoot(g_pEnemy2[1]->x - 0.38f, 2.5f);
		VShoot(g_pEnemy2[1]->x + 0.38f, 3.0f);
		VShoot(g_pEnemy2[1]->x - 0.38f, 3.0f);
	}
	if (g_pEnemy2[1]->Flag)glutTimerFunc(1000, timer_function, 1);
}

void VRShoot() {
	VLink = NULL;
	VGetShoot->BFlag = true; //ADD
	VGetShoot = VHeadShoot;
	while (VGetShoot != NULL) {
		VGetShoot->SetMove();
		if (VGetShoot->GBulletPos() <= -4.0f) {
			VGetShoot->VShootTime = 0.0f;
			if (VLink == NULL) {
				VGet = VGetShoot;
				VHeadShoot = VGetShoot->next;
				VGetShoot = VGetShoot->next;
				VGet->next = VHead;
				VHead = VGet;
			}
			else {
				VGet = VGetShoot;
				VGetShoot = VLink;
				VGetShoot->next = VGet->next;
				VGet->next = VHead;
				VHead = VGet;
			}
			VBulletNum = VBulletNum - 1;
		}
		else {
			VLink = VGetShoot;
			VGetShoot = VGetShoot->next;
		}
	}
	
}

void VShoot(float x1, float y1) {
	if (VHeadShoot == NULL) {
		VHeadShoot = VHead;
		VHead = VHead->next;
		VGetShoot = VHeadShoot;
		VGetShoot->BFlag = true; //ADD
		VTailShoot = VHeadShoot;
		VGetShoot->next = NULL;
	}
	else {
		VGetShoot = VHead;
		VGetShoot->BFlag = true; //ADD
		VHead = VHead->next;
		VGetShoot->next = NULL;
		VTailShoot->next = VGetShoot;
		VTailShoot = VGetShoot;
	}
	VGetShoot->GetPos(x1, y1);
	
	EBx[0] = VGetShoot->mxT[0][3];
	EBx[1] = EBx[0] + 0.72f;
	EBy[0]=EBy[1] = VGetShoot->GBulletPos();
	VBulletNum += 1;
	/*Print(VBulletNum);*/
}

void RShoot() {
	Link = NULL;
	GetShoot->BFlag = true; //ADD
	GetShoot = HeadShoot;
	while (GetShoot != NULL) {
		GetShoot->SetMove();
		if (GetShoot->GBulletPos() >= 4.0)  {
			GetShoot->ShootTime = 0.0f;
			if (Link == NULL) {
				Get = GetShoot;
				HeadShoot = GetShoot->next;
				GetShoot = GetShoot->next;
				Get->next = Head;
				Head = Get;
				By = 0;
			}
			else {
				Get = GetShoot;
				GetShoot = Link;
				GetShoot->next = Get->next;
				Get->next = Head;
				Head = Get;
			}
			BulletCount = BulletCount - 1;
		}
		else {
			Link = GetShoot;
			GetShoot = GetShoot->next;
		}
	}
}
void Shoot() {
	if (g_ShootTime > 0.4f) {
		g_pQuad->BloodFlag = true;
		g_ShootTime = 0.0f;
		if (HeadShoot == NULL) {
			HeadShoot = Head;
			Head = Head->next;
			GetShoot = HeadShoot;
			GetShoot->BFlag = true; //ADD
			TailShoot = HeadShoot;
			GetShoot->next = NULL;
		}
		else {
			GetShoot = Head;
			
			Head = Head->next;
			GetShoot->next = NULL;
			TailShoot->next = GetShoot;
			TailShoot = GetShoot;
		}
		GetShoot->GetPos(Pos[0], Pos[1]);
		Bx = GetShoot->mxT[0][3];
		BulletCount += 1;
		/*Print(BulletCount);*/
	}
}
void AutomaticRotation(void) {
	mat4 mxRot;

	//glutPostRedisplay();     // 目前的視窗需要被重畫
}
//----------------------------------------------------------------------------

void GL_Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // clear the window
	g_pBG[0]->Draw();
	g_pBG[1]->Draw();
	g_pBG[2]->Draw();
	if(g_pBall[0]->Flag == true)g_pBall[0]->Draw();
	if(g_pBall[1]->Flag == true)g_pBall[1]->Draw();
	if (g_pBall[2]->Flag == true)g_pBall[2]->Draw();
	if (g_pBall[3]->Flag == true)g_pBall[3]->Draw();
	
	VGetShoot = VHeadShoot;
	while (VGetShoot != NULL) {
		if(VGetShoot->BFlag == true)VGetShoot->Draw();
		VGetShoot = VGetShoot->next;
	}

	GetShoot = HeadShoot;
	while (GetShoot != NULL) {
		if(GetShoot->BFlag == true)GetShoot->Draw();
		GetShoot = GetShoot->next;
	}

	if(g_pQuad->Flag)g_pQuad->Draw();

	if (g_pEnemy1[0]->Flag)g_pEnemy1[0]->Draw();
	if (g_pEnemy1[1]->Flag)g_pEnemy1[1]->Draw();
	if (g_pEnemy1[2]->Flag)g_pEnemy1[2]->Draw();
	if (g_pEnemy2[0]->Flag)g_pEnemy2[0]->Draw();
	if (g_pEnemy2[1]->Flag)g_pEnemy2[1]->Draw();
	if (g_pEnemy3[0]->Flag)g_pEnemy3[0]->Draw();
	if (g_pEnemy4[0]->Flag)g_pEnemy4[0]->Draw();
	if (g_pEnemy4[1]->Flag)g_pEnemy4[1]->Draw();
	glutSwapBuffers();	// 交換 Frame Buffer
}

void Check(){
	Flag = HeadShoot;
	while (Flag != NULL) {
		CheckEnemy1(Flag);
		CheckEnemy2(Flag);
		CheckEnemy2A(Flag);
		CheckEnemy3(Flag);
		CheckBall(Flag);
		Flag = Flag->next;
	}	
}
void VCheck() {
	{
		VFlag = VHeadShoot;
	
		while (VFlag != NULL) {
			CheckMain(VFlag);
			VFlag->BFlag = true;
			VFlag = VFlag->next;
		}
	}
}

void onFrameMove(float delta){
	g_ShootTime += delta;
	if (g_Enemy2Time > 0.0f && g_Enemy2Time < 1.0f) {
		g_pBall[1]->Flag = false;
		g_pBall[2]->Flag = false;
		g_pBall[3]->Flag = false;
		g_pEnemy4[0]->Flag = false;
		g_pEnemy4[1]->Flag = false;
		g_pEnemy3[0]->Flag = false;
		g_pEnemy3[0]->blood = 20;
	}
	if (g_Enemy2Time > 2.9f && g_Enemy2Time <3.0f) {
		g_pEnemy1[0]->Flag = true;
		g_pEnemy1[1]->Flag = true;
		g_pEnemy1[2]->Flag = true;
		g_pEnemy3[0]->Flag = false;
		
	}
	if (g_Enemy2Time > 8.9f && g_Enemy2Time <9.0f) {
		g_pEnemy2[0]->Flag = true;
		g_pEnemy2[1]->Flag = true;
		g_pEnemy2[1]->SetColor(g_pEnemy2[1]->Prank);
		g_pEnemy2[1]->SetColor2(g_pEnemy2[1]->Prank2);
		g_pEnemy3[0]->Flag = false;
	}
	if (g_Enemy2Time > 29.0f && g_Enemy2Time <31.0f) {
		g_pEnemy2[1]->Flag = 0;
		g_pEnemy3[0]->Flag = true;
	}
	g_Enemy2Time += delta;
	BgAction(delta);
	BallAction(delta);
	Enemy1AutoRotateion(delta);
	if (g_Enemy2Time > 9.0f)Enemy2Action(delta);
	if ((g_pBall[0]->Flag == true) && (g_pQuad->Mainblood<=3))BallShow(delta);
	if ((g_Enemy2Time > 31.0f) && (g_pEnemy3[0]->Flag == true))Enemy3Action(delta);
	if ((g_pEnemy3[0]->blood <= 15) && (g_pEnemy3[0]->blood != 0)) {
		g_pEnemy4[1]->Flag = true;
		Enemy4BAction(delta);
		g_pEnemy4[0]->Flag = true;
		Enemy4Action(delta);
	}
	VGetShoot = VHeadShoot;
	while (VGetShoot != NULL) {
		VGetShoot->GetTime(delta);
		VGetShoot->SetMove();
		EBy[0] = VGetShoot->mxT[1][3];
		if (EBy[0] <= -4.0f)VRShoot();
		else VGetShoot = VGetShoot->next;
	}
	
	if(g_Enemy2Time > 8.0f){glClearColor(0.87,0.39,0.47, 1.0);}
	
	if (g_Enemy2Time > 30.0f) { glClearColor(0.85, 0.3, 0.42, 1.0); }
	GetShoot = HeadShoot;
	while (GetShoot != NULL) {
		GetShoot->GetTime(delta);
		GetShoot->SetMove();
		By = GetShoot->mxT[1][3];
		if (By >= 4.0f)RShoot();
		else GetShoot = GetShoot->next;
		/*Print(By);*/
	}
	GL_Display();

	VCheck();
	Check();
	g_pQuad->BloodColor();
	if (g_pQuad->Mainblood == 0)Esc();
	if (g_pEnemy3[0]->blood == 0) { 
		g_pEnemy3[0]->Flag = false;
		g_pEnemy4[0]->Flag = false;
		g_pEnemy4[1]->Flag = false; }
}

//----------------------------------------------------------------------------
void reset()
{
	
	g_fAngle = 0;

	
	g_pQuad->SetTRSMatrix(g_mxModelView);
	/*g_pEnemy1->SetTRSMatrix(g_mxModelView);*/
	glutPostRedisplay();
}
//----------------------------------------------------------------------------

void Esc() {
	delete g_pQuad, g_pVBullet, g_pBullet;
	delete g_pEnemy2[0], g_pEnemy2[1];
	delete g_pBG[0], g_pBG[1], g_pBG[2];
	delete g_pEnemy1[0], g_pEnemy1[1], g_pEnemy1[2];
	delete g_pEnemy3[0];
	delete g_pBall[0], g_pBall[1], g_pBall[2], g_pBall[3];
	delete g_pEnemy4[0], g_pEnemy4[1];
	VGet = VHead;

	while (VGet != NULL) {
		VHead = VGet->next;
		delete(VGet);
		VGet = VHead;
	}
	VGetShoot = VHeadShoot;
	while (VGetShoot != NULL) {
		VHeadShoot = VGetShoot->next;
		delete(VGetShoot);
		VGetShoot = VHeadShoot;
	}
	delete(VHead);
	delete(VHeadShoot);

	Get = Head;

	while (Get != NULL) {
		Head = Get->next;
		delete(Get);
		Get = Head;
	}
	GetShoot = HeadShoot;
	while (GetShoot != NULL) {
		HeadShoot = GetShoot->next;
		delete(GetShoot);
		GetShoot = HeadShoot;
	}
	delete(Head);
	delete(HeadShoot);
	exit(EXIT_SUCCESS);
}
void Win_Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case  SPACE_KEY:
		
		break;
	case 68: // D key
	case 100: // d key
		MainAdd();
		break;
	case 82: // R key
	case 114: // r key
		reset();
		break;
	case 033:
		delete g_pQuad, g_pVBullet, g_pBullet;
		delete g_pEnemy2[0], g_pEnemy2[1];
		delete g_pBG[0], g_pBG[1], g_pBG[2];
		delete g_pEnemy1[0], g_pEnemy1[1], g_pEnemy1[2];
		delete g_pEnemy3[0];
		delete g_pBall[0], g_pBall[1], g_pBall[2], g_pBall[3];
		delete g_pEnemy4[0], g_pEnemy4[1];
		VGet = VHead;

		while (VGet != NULL) {
			VHead = VGet->next;
			delete(VGet);
			VGet = VHead;
		}
		VGetShoot = VHeadShoot;
		while (VGetShoot != NULL) {
			VHeadShoot = VGetShoot->next;
			delete(VGetShoot);
			VGetShoot = VHeadShoot;
		}
		delete(VHead);
		delete(VHeadShoot);

		Get = Head;

		while (Get != NULL) {
			Head = Get->next;
			delete(Get);
			Get = Head;
		}
		GetShoot = HeadShoot;
		while (GetShoot != NULL) {
			HeadShoot = GetShoot->next;
			delete(GetShoot);
			GetShoot = HeadShoot;
		}
		delete(Head);
		delete(HeadShoot);
		exit(EXIT_SUCCESS);
		break;
	}
}
//----------------------------------------------------------------------------
void Win_Mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:   // 目前按下的是滑鼠左鍵
		if (state == GLUT_DOWN) {  // 目前的滑鼠狀態是按住，換成 X 軸
			Shoot();
			HideB = true;
			// 換軸就重設
		}
		break;
	case GLUT_MIDDLE_BUTTON:  // 目前按下的是滑鼠中鍵 ，換成 Y 軸
		if (state == GLUT_DOWN) {
		}
		break;
	case GLUT_RIGHT_BUTTON:   // 目前按下的是滑鼠右鍵
		if (state == GLUT_DOWN) { // 目前按下的是滑鼠右鍵，換成 Z 軸
		}
		break;
	default:
		break;
	}
}
//----------------------------------------------------------------------------
void Win_SpecialKeyboard(int key, int x, int y) {

}
void Win_MouseMotion(int x, int y) {
	mat4 mxGT;
	g_fTx = 4.0f*(x - HALF_SIZE) / (HALF_SIZE);
	g_fTy = -4.0f*(y - HALF_SIZE) / (HALF_SIZE);
	Pos[0] = g_fTx;
	Pos[1] = g_fTy;
	mxGT = Translate(g_fTx, g_fTy, 0);
	g_pQuad->SetTRSMatrix(mxGT);
	Shoot();
	glutPostRedisplay();     // 目前的視窗需要被重畫
}

//----------------------------------------------------------------------------

void Win_PassiveMotion(int x, int y) {
	mat4 mxGT;
	g_fTx = 4.0f*(x - HALF_SIZE) / (HALF_SIZE);
	g_fTy = -4.0f*(y - HALF_SIZE) / (HALF_SIZE);
	Pos[0] = g_fTx;
	Pos[1] = g_fTy;
	mxGT = Translate(g_fTx, g_fTy, 0);
	g_pQuad->SetTRSMatrix(mxGT);
}

void GL_Reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	/*glEnable(GL_DEPTH_TEST);*/
}

//----------------------------------------------------------------------------

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);

	// If you use freeglut the two lines of code can be added to your application 
	glutInitContextVersion(3, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Draw two triangles");

	// The glewExperimental global switch can be turned on by setting it to GL_TRUE before calling glewInit(), 
	// which ensures that all extensions with valid entry points will be exposed.
	glewExperimental = GL_TRUE;
	glewInit();

	init();


	glutMouseFunc(Win_Mouse);
	glutMotionFunc(Win_MouseMotion);
	glutKeyboardFunc(Win_Keyboard);	// 處理 ASCI 按鍵如 A、a、ESC 鍵...等等
	glutSpecialFunc(Win_SpecialKeyboard);	// 處理 NON-ASCI 按鍵如 F1、Home、方向鍵...等等

	glutDisplayFunc(GL_Display);
	glutReshapeFunc(GL_Reshape);
	glutIdleFunc(IdleProcess);
	glutPassiveMotionFunc(Win_PassiveMotion);
	glutTimerFunc(1000,timer_function,1);
	glutTimerFunc(1000, timer_function1, 5);
	glutTimerFunc(1500, timer_function2, 2);
	//glutTimerFunc(3000, timer_function3, 3);
	glutMainLoop();
	return 0;
}
