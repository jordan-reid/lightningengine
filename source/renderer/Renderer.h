#ifndef CRENDERER_H
#define CRENDERER_H

#include "D3D11Includes.h"

class CRenderer
{

public:

	CRenderer(void);
	~CRenderer(void);

	bool InitD3D(HWND _window);
	void ShutDown();

private:

	ID3D11Device*			device;
	ID3D11DeviceContext*	deviceContext;
	IDXGISwapChain*			swapChain;
	D3D11_VIEWPORT			viewPort;
	ID3D11Resource*			backBuffer;
	ID3D11Texture2D*		zBuffer;
	ID3D11RenderTargetView* renderTargetView;

};

#endif

