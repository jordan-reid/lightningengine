#ifndef CRENDERSET_H
#define CRENDERSET_H

#include "D3D11Includes.h"

class CRenderSet
{

public:

	CRenderSet(void);
	~CRenderSet(void);

private:

	ID3D11RasterizerState*		rasterizerState;
	ID3D11SamplerState*			samplerState;
	ID3D11BlendState*			blendState;
	ID3D11InputLayout*			inputLayout;
	ID3D11PixelShader*			pixelShader;
	ID3D11VertexShader*			vertexShader;
	ID3D11DepthStencilView*		depthStencilView;
	ID3D11DepthStencilState*	depthStencilState;
};

#endif

