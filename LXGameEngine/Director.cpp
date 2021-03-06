#include "stdafx.h"
#include "Director.h"
#include "AutoReleasePool.h"
#include "ShaderCache.h"
#include "Texture2D.h"
#include "Sprite.h"
#include "Scene.h"

Director* g_pDirector = nullptr;

Director* Director::getInstance()
{
	if (!g_pDirector)
	{
		g_pDirector = new Director();
	}
	return g_pDirector;
}

Director::Director()
{

}


Director::~Director()
{
}

bool Director::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Scene::getInstance()->visit();
	// static_cast<Sprite*>(Scene::getInstance()->getChildren().at(0))->dump();
	AutoReleasePool::getInstance()->executeClear();
	return true;
}

bool Director::start()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	auto scene = Scene::getInstance();

	Sprite* sprite = new (std::nothrow) Sprite();
	sprite->initWithFile("Res/wall.jpg");
	//sprite->dump();
	sprite->setContentSize(512, 512);
	sprite->setPosition(512.0, 512.0f);
	sprite->setAnchorPoint(0.5f, 0.5f);
	sprite->setSwallowTouches(true);
	//sprite->setRotation(-45.0f);
	//sprite->setScale(1.0f, 2.0f);
	//sprite->visit(glm::mat4());
	scene->addChild(sprite);

	Sprite* sprite2 = new (std::nothrow) Sprite();
	sprite2->initWithFile("Res/test.png");
	sprite2->setPosition(0, 0);
	sprite2->setContentSize(512, 512);
	sprite2->autoRelease();
	sprite2->setLocalZ(-1);
	sprite->addChild(sprite2);

	Sprite* sprite3 = new (std::nothrow) Sprite();
	sprite3->initWithFile("Res/test.png");
	sprite3->setPosition(-512, -512);
	sprite3->setContentSize(512, 512);
	sprite3->setColor(0, 255, 0);
	sprite3->setOpacity(100);
	sprite3->autoRelease();
	sprite3->setLocalZ(0);
	sprite->addChild(sprite3);


	//sprite->autoRelease();
	/*Texture2D* texture = new Texture2D();
	texture->initWithFileName("Res/wall.jpg");
	texture->dump();
	texture->release();

	Texture2D* texture2 = new Texture2D();
	texture2->initWithFileName("Res/wall.jpg");
	texture2->dump();*/

	/*texture->initWithFileName("Res/wall.jpg", Image::IMAGE_RGB);
	texture->dump();*/
	/*Shader* s = new Shader();
	s->initWithFiles("Res\\Shaders\\default.vert", "Res\\Shaders\\default.frag");
	s->dump();*/

	//glCreateShader(GL_VERTEX_SHADER);
	/*Shader* shader = ShaderCache::getInstance()->getGlobalShader(ShaderCache::LX_SHADERS_PVM_DEFAULT);
	shader->dump();*/


	

	return true;
}

