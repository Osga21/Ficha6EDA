#include "Janela.h"
Janela* Janela::objecto = NULL; // Objecto est�tico da classe Janela que � utilizado
// dentro da fun��o CALLBACK
Janela::Janela()
{
	janelaId = NULL;
	objecto = this; // Uma vez criado o objecto est�tico � o pr�prio objecto
	clickou = false;
}
Janela* Janela::ObterObjecto()
{
	return objecto;
}

bool Janela::Criar(const char* sTitulo,const char* sNome)
{
	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, DespacharMensagens,
	0, 0, GetModuleHandle(0), LoadIcon(0,IDI_APPLICATION),
	LoadCursor(0,IDC_ARROW),
	CreatePatternBrush((HBITMAP)LoadImage(0, sNome,
	IMAGE_BITMAP,0,0,
	LR_CREATEDIBSECTION | LR_LOADFROMFILE)),
	0, "minhaclasse", LoadIcon(0,IDI_APPLICATION) };
	if (RegisterClassEx(&wndclass))
	{ // Fun��o do SO Windows que cria janelas
		janelaId = CreateWindowEx(0, "minhaclasse", "titulo",
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			883, 566, 0, 0, GetModuleHandle(0), 0);
		if (janelaId)
		{
			ShowWindow(janelaId, SW_SHOWDEFAULT);
			return true;
		}
	}
	return false;
}

LRESULT CALLBACK Janela::DespacharMensagens(HWND janId, unsigned int msg,
	WPARAM wp, LPARAM lp)
{
	Janela* janela = ObterObjecto();
	janela->clickou = false;
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		if (wp == VK_ESCAPE) {
			PostQuitMessage(0);
			return 0;
		}
		break;
	case WM_LBUTTONDOWN:
		janela->clickou = true;
		janela->cur_coord = Ponto(LOWORD(lp), HIWORD(lp));
		break;
	default:
		break;
	}
	return DefWindowProc(janId, msg, wp, lp);
}

Rectangulo Janela::ObterJanelaRect()
{
	Rectangulo rect;
	RECT r;
	if (GetWindowRect(janelaId, &r))
		rect = Rectangulo(r.left, r.top, r.right, r.bottom,janelaId);
	return rect;
}
