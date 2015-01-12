#include "Renderer.h"
#include "RenderSet.h"
#include "iostream"
#include <cassert>

#include "../gameapp/GameApp.h"




CRenderer::CRenderer(void)
{
}


CRenderer::~CRenderer(void)
{
	ShutDown();
}

bool CRenderer::InitD3D(HWND _window)
{	
	//Might not need a ZBuffer since this is a 2D game
	//ID3D11Texture2D*		zBuffer;	

	D3D_FEATURE_LEVEL featureLevels[1];
	featureLevels[0] = D3D_FEATURE_LEVEL_11_0;
	D3D_FEATURE_LEVEL feature;

	DXGI_SWAP_CHAIN_DESC swapDesc;

	ZeroMemory(&swapDesc,sizeof(swapDesc));

	swapDesc.BufferCount		= 1;
	swapDesc.BufferDesc.Format  = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapDesc.BufferDesc.Width   = WINDOW_WIDTH;
	swapDesc.BufferDesc.Height  = WINDOW_HEIGHT;
	swapDesc.BufferUsage		= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapDesc.Flags				= DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	swapDesc.SampleDesc.Count   = 1;
	swapDesc.OutputWindow		= _window;
	swapDesc.Windowed			= true;

	HRESULT hr;

#if(_DEBUG)
	{
		hr = D3D11CreateDeviceAndSwapChain(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_DEBUG,
			featureLevels,1,D3D11_SDK_VERSION,&swapDesc,&swapChain,&device,&feature,&deviceContext);
	}
#else
	{
		hr = D3D11CreateDeviceAndSwapChain(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr, NULL,
			featureLevels,1,D3D11_SDK_VERSION,&swapDesc,&swapChain,&device,&feature,&deviceContext);
	}
#endif

	if(FAILED(hr))
	{
		assert(FAILED(hr) && "D3D11CreateDeviceAndSwapChain() in Renderer.cpp");

		return false;
	}

	hr = swapChain->GetBuffer(0,__uuidof(backBuffer),reinterpret_cast<void**>(&backBuffer));

	if(FAILED(hr))
	{
		assert(FAILED(hr) && "swapChain->GetBuffer() in Renderer.cpp");
		return false;
	}

	hr = device->CreateRenderTargetView(backBuffer,nullptr,&renderTargetView);

	if(FAILED(hr))
	{
		assert(FAILED(hr) && "device->CreateRenderTargetView() in Renderer.cpp");
		return false;
	}

	viewPort.TopLeftX = 0;
	viewPort.TopLeftY = 0;
	viewPort.Width    = WINDOW_WIDTH;
	viewPort.Height   = WINDOW_HEIGHT;
	viewPort.MinDepth = 0;
	viewPort.MaxDepth = 1;


	return true;
}

void CRenderer::Render(CRenderSet* _renderSet)
{


}

void CRenderer::ShutDown()
{
	SAFE_RELEASE(renderTargetView);
	SAFE_RELEASE(backBuffer);
	SAFE_RELEASE(swapChain);
	SAFE_RELEASE(deviceContext);
	SAFE_RELEASE(device);
}
