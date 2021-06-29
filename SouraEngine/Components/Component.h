#pragma once
#include <any>
#include <functional>

namespace SouraEngine
{
	enum ComponentType
	{
		ComponentType_AudioListener,
		ComponentType_AudioSource,
		ComponentType_Camera,
		ComponentType_Collider,
		ComponentType_Constraint,
		ComponentType_Light,
		ComponentType_Renderable,
		ComponentType_RigidBody,
		ComponentType_Script,
		ComponentType_Skybox,
		ComponentType_Transform,
		ComponentType_Unknown
	};

	struct Attribute
	{
		std::function<std::any()> Get;
		std::function<void(std::any)> Set;
	};

	class Component : public Object
	{

	};
}