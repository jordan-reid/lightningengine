#ifndef CRENDERSHAPE_H
#define CRENDERSHAPE_H

#include "D3D11Includes.h"
#include "../mathLibrary/2DMath/vec2.h"

class CRenderShape
{

public:

	CRenderShape(void);
	~CRenderShape(void);

private:

	ID3D11ShaderResourceView* shaderResourceView;
	Vec2<float> postion;
};

#endif

