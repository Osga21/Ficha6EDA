#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
	Ponto tl(0, 0);
	Ponto br(0, 0);
	top_left = tl;
	bottom_right = br;
}

Rectangulo::Rectangulo(Ponto tl, Ponto br)
{
	top_left = tl;
	bottom_right = br;
}

Rectangulo::Rectangulo(int x1, int y1, int x2, int y2, HWND janela)
{
	Ponto tl(x1, y1);
	Ponto br(x2, y2);
	top_left=tl;
	bottom_right = br;
}

void Rectangulo::desenhar(HWND janelaId, long cor)
{
	Ponto top_right(bottom_right.ObterX(), top_left.ObterY());
	Ponto bottom_left(top_left.ObterX(), bottom_right.ObterY());
	HDC DrawHDC = GetDC(janelaId);
	HBRUSH hOldBrush;
	HBRUSH hNewBrush;
	hNewBrush = CreateSolidBrush(cor);
	hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
	RECT rect;
	rect.bottom = bottom_right.ObterY();
	rect.left = top_left.ObterX();
	rect.right = bottom_right.ObterX();
	rect.top = top_left.ObterY();
	FillRect(DrawHDC, &rect, hNewBrush);
	DeleteObject(SelectObject(DrawHDC, hOldBrush));
	ReleaseDC(janelaId, DrawHDC);
}

bool Rectangulo::contem(Ponto p)
{
	if (p.ObterX() > top_left.ObterX() && p.ObterX() < bottom_right.ObterX() && p.ObterY() < top_left.ObterY() && p.ObterY() > bottom_right.ObterY())
		return true;
	else
		return false;
}

bool Rectangulo::contem(Rectangulo r)
{
	int rbrx, rbry, rtlx, rtly;

	rbrx = r.bottom_right.ObterX();
	rbry = r.bottom_right.ObterY();
	rtlx = r.top_left.ObterX();
	rtly = r.top_left.ObterY();
	
	int brx, bry, tlx, tly;
	brx = bottom_right.ObterX();
	bry = bottom_right.ObterY();
	tlx = top_left.ObterX();
	tly = top_left.ObterY();

	if (rbrx < brx && rtlx > tlx && rbry > bry && rbry < tly)
		return true;
	else
		return false;
}

double Rectangulo::obterArea()
{
	Ponto top_right(bottom_right.ObterX(), top_left.ObterY());
	Ponto bottom_left(top_left.ObterX(),bottom_right.ObterY());

	double altura = top_left.ObterDistancia(bottom_left);
	double base = bottom_left.ObterDistancia(bottom_right);

	return base*altura;
}

int Rectangulo::obterPerimetro()
{
	Ponto top_right(bottom_right.ObterX(), top_left.ObterY());
	Ponto bottom_left(top_left.ObterX(), bottom_right.ObterY());

	double altura = top_left.ObterDistancia(bottom_left);
	double base = bottom_left.ObterDistancia(bottom_right);
	
	return 2*base+2*altura;
}
