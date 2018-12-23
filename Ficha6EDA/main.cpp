#define _CRT_SECURE_NO_WARNINGS
#include "Janela.h"
#include "Circulo.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
int main() {

	Janela janela;
	HWND janelaId;

	if (janela.Criar("Mapa Lisboa e arredores","MAPA.bmp")) {
		if ((janelaId = janela.ObterId()) != NULL) {
			
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);

				Ponto point(200, 100);

				Circulo circ(point,20,22);
				circ.desenhar(janelaId, VERMELHO);

				if (janela.Click()) {
					
				}

			}
		}
	}
}