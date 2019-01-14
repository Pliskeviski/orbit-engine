#include "obtpch.h"
#include "Transform.h"

namespace Orbit {
	Transform::Transform(Math::vec3 position, Math::vec3 rotation, Math::vec3 scale)
	: m_Position(position), m_Rotation(rotation), m_Scale(scale), m_Parent(0) {
	}

	void Transform::setPosition(Math::vec3 position) {
		this->m_Position = position;
	}

	void Transform::setPositionX(float x) {
		this->m_Position.x = x;
	}

	void Transform::setPositionY(float y) {
		this->m_Position.y = y;
	}

	void Transform::setPositionZ(float z) {
		this->m_Position.z = z;
	}

	void Transform::setRotation(Math::vec3 m_Rotation) {
		this->m_Rotation = m_Rotation;
	}

	void Transform::setRotationX(float x) {
		m_Rotation.x = x;
	}

	void Transform::setRotationY(float y) {
		m_Rotation.y = y;
	}

	void Transform::setRotationZ(float z) {
		m_Rotation.z = z;
	}

	//void Transform::setParent(std::shared_ptr<Transform> parent) {
	//	this->m_Parent = parent.get();
	//}

	Math::vec3 Transform::getPosition() {
		return this->m_Position;
	}

	float Transform::getPositionX() {
		return this->m_Position.x;
	}

	float Transform::getPositionY() {
		return this->m_Position.y;
	}

	float Transform::getPositionZ() {
		return this->m_Position.z;
	}

	Math::vec3 Transform::getRotation() {
		return this->m_Rotation;
	}

	float Transform::getRotationX() {
		return this->m_Rotation.x;
	}

	float Transform::getRotationY() {
		return this->m_Rotation.y;
	}

	float Transform::getRotationZ() {
		return this->m_Rotation.z;
	}

	//std::shared_ptr<Transform> Transform::getParent() {
	//	return std::make_shared<Transform>(this->m_Parent);
	//}

	Math::vec3 Transform::getScale() {
		return this->m_Scale;
	}

	void Transform::setScale(Math::vec3 scale) {
		this->m_Scale = scale;
	}

	void Transform::setScale(float scale) {
		this->m_Scale = Math::vec3(scale);
	}

	Transform::~Transform() {
	}

}
