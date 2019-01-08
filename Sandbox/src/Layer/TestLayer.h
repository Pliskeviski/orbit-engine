#pragma once

#include "Orbit.h"

class TestLayer : public Orbit::Layer {
public:
	TestLayer() : Layer("Test Layer") {};

	void OnUpdate() override {
		//ORBIT_INFO("TestLayer->Update");
	}

	void OnEvent(Orbit::Event& event) override {
		//ORBIT_TRACE("{0}", event);
	}
};