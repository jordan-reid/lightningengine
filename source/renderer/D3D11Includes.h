#include <d3d11.h>
#pragma comment (lib,"d3d11.lib")

#define SAFE_RELEASE(p) {if ((p)) {(p)->Release(); (p) = nullptr;}}