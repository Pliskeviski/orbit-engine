#include "obtpch.h"
#include "Camera.h"

#include "Orbit/Renderer/Renderer.h"

//#include "Orbit/Application/Application.h"
#include "Orbit/Input/Input.h"

namespace Orbit {

	const float YAW = -1.0f;
	const float PITCH = 0.0f;
	const float FOV = 45.0f;
	
	const Math::vec3 WorldUp = Math::vec3(.0f, 1.f, .0f); // Y is up

	Camera::Camera() : m_Yaw(YAW), m_Pitch(PITCH), m_Fov(FOV) { // todo have a principal camera and others
		Transform* transform = new Transform();
		m_Transform = transform;
		Update();

		Renderer::setActiveCamera(this);
	}
	Camera::Camera(Math::vec3 pos) : m_Yaw(YAW), m_Pitch(PITCH), m_Fov(FOV) {
		Transform* transform = new Transform(pos);
		m_Transform = transform;
		Update();

		Renderer::setActiveCamera(this);
	}
	Camera::Camera(Math::vec3 pos, float fov) : m_Yaw(YAW), m_Pitch(PITCH), m_Fov(FOV) {
		Transform* transform = new Transform(pos);
		m_Transform = transform;
		Update();

		Renderer::setActiveCamera(this);
	}

	void Camera::Update() {
		Math::vec3 front;
		front.x = cos(glm::radians(this->m_Yaw)) * cos(glm::radians(this->m_Pitch));
		front.y = sin(glm::radians(this->m_Pitch));
		front.z = sin(glm::radians(this->m_Yaw)) * cos(glm::radians(m_Pitch));
		this->m_Front = glm::normalize(front);
		this->m_Right = glm::normalize(glm::cross(this->m_Front, WorldUp));
		this->m_Up = glm::normalize(glm::cross(this->m_Right, this->m_Front));
	}

	Math::vec3 Camera::getPosition() { return this->m_Transform->getPosition(); }

	Math::mat4 Camera::getViewMatrix() {
		return glm::lookAt(this->m_Transform->getPosition(), this->m_Transform->getPosition() + this->m_Front, this->m_Up);
	}

	void Camera::setPosition(Math::vec3 position) {
		this->m_Transform->setPosition(position);
		Update();
	}

	void Camera::setPositionX(float x) {
		this->m_Transform->setPositionX(x);
		Update();
	}

	void Camera::setPositionY(float y) {
		this->m_Transform->setPositionY(y);
		Update();
	}

	void Camera::setPositionZ(float z) {
		this->m_Transform->setPositionZ(z);
		Update();
	}

	void Camera::Forward(float v) {
		this->m_Transform->setPosition(this->m_Transform->getPosition() + this->m_Front * v);
		Update();
	}

	void Camera::Backwards(float v) {
		this->m_Transform->setPosition(this->m_Transform->getPosition() - this->m_Front * v);
		Update();
	}

	void Camera::Right(float v) {
		this->m_Transform->setPosition(this->m_Transform->getPosition() + this->m_Right * v);
		Update();
	}

	void Camera::Left(float v) {
		this->m_Transform->setPosition(this->m_Transform->getPosition() - this->m_Right * v);
		Update();
	}

	void Camera::addPosX(float v) {
		this->m_Transform->setPositionX(this->m_Transform->getPositionX() + v);
		Update();
	}

	void Camera::addPosY(float v) {
		this->m_Transform->setPositionY(this->m_Transform->getPositionY() + v);
		Update();
	}
	void Camera::addPosZ(float v) {
		this->m_Transform->setPositionZ(this->m_Transform->getPositionZ() + v);
		Update();
	}

	void Camera::addPitch(double v) {
		this->m_Pitch += v;
		if (this->m_Pitch > 89.f)
			this->m_Pitch = 89.f;
		if (this->m_Pitch < -89.f)
			this->m_Pitch = -89.f;
		Update();
	}

	void Camera::addYaw(double v) {
		this->m_Yaw += v;
		Update();
	}

	void Camera::setFov(float fov) {
		this->m_Fov = fov;
		Update();
	}

	float Camera::getFov() {
		return this->m_Fov;
	}

	float Camera::getYaw() {
		return this->m_Yaw;
	}

	float Camera::getPitch() {
		return this->m_Pitch;
	}

	void Camera::setYaw(float yaw) {
		this->m_Yaw = yaw;
	}

	void Camera::setPitch(float pitch) {
		this->m_Pitch = pitch;
	}
}