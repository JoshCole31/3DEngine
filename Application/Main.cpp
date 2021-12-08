#include "Engine.h"

#define REGISTER_CLASS(class)        jc::ObjectFactory::Instance().Register<class>(#class);
#define CREATE_ENGINE_OBJECT(class) jc::ObjectFactory::Instance().Create<jc::class>(#class);

int main(int argc, char** argv)
{
	// create engine
	std::unique_ptr<jc::Engine> engine = std::make_unique<jc::Engine>();
	engine->Startup();
	engine->Get<jc::Renderer>()->Create("OpenGL", 800, 600);


	//


	// create scene
	std::unique_ptr<jc::Scene> scene = std::make_unique<jc::Scene>();
	scene->engine = engine.get();

	jc::SeedRandom(static_cast<unsigned int>(time(nullptr)));
	jc::SetFilePath("../Resources");

	// load scene
	rapidjson::Document document;
	bool success = jc::json::Load("scenes/main.scn", document);
	scene->Read(document);

	glm::vec3 translate{ 0 };
	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		SDL_PumpEvents();
		engine->Update();
		scene->Update(engine->time.deltaTime);



		// update actor new 
		auto actor = scene->FindActor("light");
		if (actor != nullptr)
		{
			glm::mat3 rotation = glm::rotate(engine->time.deltaTime, glm::vec3{ 0, 0, 1 });
			actor->transform.position = actor->transform.position * rotation;
		}

		//old 
		// update actor
		/*auto actor = scene->FindActor("model");
		if (actor != nullptr)
		{
			actor->transform.rotation.y += engine->time.deltaTime;
		}*/

		engine->Get<jc::Renderer>()->BeginFrame();

		scene->Draw(nullptr);

		engine->Get<jc::Renderer>()->EndFrame();
	}

	return 0;
}
