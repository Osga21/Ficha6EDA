#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Janela.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
int main() {

	Janela janela;
	HWND janelaId;

	if (janela.Criar("Minha Janela","MAPA.bmp")) {
		if ((janelaId = janela.ObterId()) != NULL) {
			
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);
				if (janela.Click()) {
					
				}

			}
		}
	}
}