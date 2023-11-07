#pragma once
#include "Window.h"
#include "d3d11.h"

class Renderer {
public:
	Renderer(Window& window);

private:
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pDeviceContect = nullptr;
};