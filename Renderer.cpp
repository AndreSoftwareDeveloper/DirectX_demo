#include "Renderer.h"

Renderer::Renderer(Window& window) {
	
	//defining the swap chain
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = window.getHandle();
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = true;

	//creation of the swap chain device and device context
	auto result = D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION, &swapChainDesc,
		&m_pSwapChain, &m_pDevice, nullptr, &m_pDeviceContect
	);

	//checking for error
	if (result != S_OK) {
		MessageBox(nullptr, L"Problem while creating DX11", L"Error", MB_OK);
		exit(0);
	}		
}
