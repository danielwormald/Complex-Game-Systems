

#ifndef MY_APPLICATION
#define MY_APPLICATION

#include "Application.h"
#include "gl_core_4_4.h"
#include "GLFW\glfw3.h"
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "FlyCamera.h"
#include "Shader.h"
#include "ShaderManager.h"
#include "PerlinNoise.h"
#include "AntTweakBar.h"
#include "Particles.h"
#include "GPUParticleEmitter.h"

#include "CheckerPiece.h"
#include "Background.h"

/*#include "Player.h"*/

//#include "PlayerOne.h"
//#include "PlayerTwo.h"


using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat4;

class Shader;
class Camera;

enum Players
{
	Player_One,
	Player_Two
}; 

enum NeighbourPosition
{
	Top_Left,
	Top_Right,
	Bottom_Left,
	Bottom_Right
}; 

class MyApplication : public Application
{
public:
	virtual void StartUp();
	virtual void Update();
	virtual void Draw();
	virtual void ShutDown();

	void GenerateGrid(unsigned int rows, unsigned int cols);
		
	unsigned int m_programID;

	//Shader
	Shader* m_shader;

	//Camera 
	Camera* m_pCamera;

	//Shader Manager
	ShaderManager* m_shaderManager;

private:
	float m_previousTime;
	
	int m_ogl_Load;
};


#endif



