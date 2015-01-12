#include "Renderer.h"
#include "RenderSet.h"

#include "../gameapp/GameApp.h"

#define SAFE_RELEASE(p) {if ((p)) {(p)->Release(); (p) = nullptr;}}


CRenderer::CRenderer(void)
{
}


CRenderer::~CRenderer(void)
{
}

bool CRenderer::InitD3D(HWND _window)
{
	/*
	ID3D11Device*			device;
	ID3D11DeviceContext*	deviceContext;
	IDXGISwapChain*			swapChain;
	D3D11_VIEWPORT*			viewPort;
	ID3D11Resource*			backBuffer;
	ID3D11Texture2D*		zBuffer;
	ID3D11RenderTargetView* renderTargetView;
	*/

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

//NEED TO CATCH AN HRESULT AND DEBUG ASSERT IF IT FAILED!!!
#if(_DEBUG)
	{
		D3D11CreateDeviceAndSwapChain(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_DEBUG,
			featureLevels,1,D3D11_SDK_VERSION,&swapDesc,&swapChain,&device,&feature,&deviceContext);
	}
#else
	{
			D3D11CreateDeviceAndSwapChain(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr, NULL,features,1,D3D11_SDK_VERSION,&swapDESC,&swapChain,&device,&feature,&devicecontext);
	}
#endif

	return true;
}

void CRenderer::ShutDown()
{
	SAFE_RELEASE(swapChain);
	SAFE_RELEASE(deviceContext);
	SAFE_RELEASE(device);
}
