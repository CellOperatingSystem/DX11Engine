#pragma once
#include "rendering/render_pass.h"
#include "rendering/constant_buffer.h"

class LightingPass : public RenderPass
{
private:
	ArrayConstantBuffer lightCB;
	ConstantBuffer lightCountCB;

	std::unique_ptr<Mesh> pScreenPlane;

public:
	static constexpr size_t uMaxLights = 50;

public:
	LightingPass();

public:
	void Render(std::unordered_map<std::string, std::shared_ptr<Resource>>& passResources) override;

private:
	void InitializeShaders();
	void InitializeRenderState();
	void InitializeScreenPlane();
};