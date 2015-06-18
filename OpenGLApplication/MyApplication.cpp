#include "MyApplication.h"

void MyApplication::StartUp()
{
	m_shaderManager = new ShaderManager();

	m_previousTime = 0.0f;

	Gizmos::create();
	
	m_pCamera = new Camera(glm::pi<float>() * 0.25f, 16 / 9.0f, 0.1f, 1000.0f);
	m_pCamera->setLookAtFrom(vec3(0, 10, 10), vec3(0));

	m_shader = new Shader(m_shaderManager, m_pCamera, window);
}

void MyApplication::Update()
{
	float currentTime = (float)glfwGetTime();
	float deltaTime = currentTime - m_previousTime;
	m_previousTime = currentTime;

	glClearColor( 0.25f, 0.25f, 0.25f, 1 );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Gizmos::clear();

	//Camera
	m_pCamera->update(deltaTime);

	//Shader
	m_shader->Update(deltaTime, m_pCamera);
}

void MyApplication::Draw()
{
	//Draw Shader
	m_shader->Draw();

	Gizmos::draw(m_pCamera->getProjectionView());
}

void MyApplication::ShutDown()
{
	Gizmos::destroy();
	delete m_shaderManager;
	delete m_pCamera;

}
