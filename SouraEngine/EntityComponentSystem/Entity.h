#pragma once
#include "Object.h"
#include "Components/Component.h"
#include <vector>

namespace SouraEngine
{
	class Entity : public Object
	{
	public:
		// Constructors =============================================
		Entity();
		Entity(std::string name);
		Entity(std::string name, Transform transform);
		~Entity();

		// Event Cycle ==============================================
		void OnInitialize();
		void OnStart();
		void OnUpdate();
		void OnStop();

		// Properties ===============================================
		virtual const uint32_t GetInstanceID() const override { return m_InstanceID; }

		virtual const std::string GetName() const override { return m_Name; }
		void SetName(const std::string& name) { m_Name = name; }

		virtual const bool IsActive() const { return m_Active; }
		void SetActive(const bool active) { m_Active = active; }

		bool isVisibleInHierarchy() const { return m_HierarchyVisbile; }
		void SetHierarchyVisibility(const bool hierarchyVisibility) { m_HierarchyVisbile = hierarchyVisibility; }

		// Public Methods ===========================================
		std::shared_ptr<Component> AddComponent(ComponentType type);

		template <class T> constexpr std::shared_ptr<T> AddComponent();

		template <class T> constexpr std::shared_ptr<T> GetComponent();

		template <class T> constexpr std::vector<std::shared_ptr<T>> GetComponents();

		bool HasComponent(const ComponentType type);

		template <class T> constexpr bool HasComponent();

		template <class T> constexpr void RemoveComponent();

		void RemoveComponent(uint32_t id);

		const auto& GetAllComponents() const { return m_Components; }

	private:
		uint32_t m_InstanceID;
		std::string m_Name;
		bool m_Active = true;
		bool m_HierarchyVisbile = true;

		std::unique_ptr<Transform> m_Transform;

		// Components =============================================
		std::vector<std::shared_ptr<Component>> m_Components;

		// To be Added:
		// Scene
		// Tag

		// Private Methods ========================================
		void GenerateInstanceID();
	};
}