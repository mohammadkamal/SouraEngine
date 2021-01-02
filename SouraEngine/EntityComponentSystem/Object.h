#pragma once
#include <string>
#include "Components/Transform.h"
#include "Math/Vector3.h"

namespace SouraEngine
{
	class Object
	{
	public:
		// Constructor ==============================================

		// Properties ==============================================
		//To be added: Flags

		// Public Methods ==========================================
		virtual const uint32_t GetInstanceID() const = 0;
		virtual const std::string GetName() const = 0;
		virtual const bool IsActive() const = 0;

		// Static Methods ==========================================
		static void Destroy(Object& obj) { delete &obj; }
		static void Instantiate(Object& original);
		static void Instantiate(Object& original, Transform parent);
		//static void Instantiate(Object &original, Transform parent, bool instantiateInWorldSpace);
		//static void Instantiate(Object &original, Reyadhah::Vector3 position, Quaternion rotation);
		//static void Instantiate(Object &original, Reyadhah::Vector3, Quaternion rotation, Transform parent);

		// Operators ===============================================
		//Existance ------------------------------------------------
		operator bool();

		//Equality -------------------------------------------------
		bool operator==(const Object& target);
		bool operator!=(const Object& target);

	};
}