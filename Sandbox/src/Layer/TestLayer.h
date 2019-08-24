#pragma once

#include "Orbit.h"

class TestLayer : public Orbit::Layer {
public:
	TestLayer() : Layer("Test Layer") {};

	void OnUpdate(Orbit::Timestep ts) override {
		//ORBIT_INFO("TestLayer->Update");
	}

	void OnEvent(Orbit::Event& event) override {
		//ORBIT_TRACE("{0}", event);
	}
};