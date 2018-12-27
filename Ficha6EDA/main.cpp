#define _CRT_SECURE_NO_WARNINGS
#include "Janela.h"
#include "Circulo.h"
#include "Graph.h"
#include "Linha.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
#define DEFAULT RGB(169,172,178)
#define SELECTED RGB(22,142,28)
int main() {
	//Cria��o de janela
	Janela janela;
	HWND janelaId;
	if (janela.Criar("Mapa Lisboa e arredores","MAPA.bmp")) {
		if ((janelaId = janela.ObterId()) != NULL) {
			
			FILE *ficheiro;//Leitura de ponto do mapa
			ficheiro = fopen("Mapa.txt", "r");
			if (ficheiro == NULL)
				exit(1);
			int npontos;
			fscanf(ficheiro, "%d", &npontos);
			Ponto* coords;
			Circulo* local;
			coords = new Ponto[npontos];
			local = new Circulo[npontos];
			int xcoord, ycoord;
			for (int i = 0; i < npontos; i++) {
				fscanf(ficheiro, "%d, %d", &xcoord, &ycoord);
				coords[i] = Ponto(xcoord, ycoord);
				local[i] = Circulo(coords[i], 8, i);
				local[i].desenhar(janelaId, DEFAULT);
			}
			Graph grafo(npontos);
			FILE *rede;
			rede = fopen("Rede.txt", "r");

			if (rede == NULL)
				exit(1);

			int nedges;
			fscanf(rede, "%d", &nedges);
			int startp, endp;
			float dist;
			Edge buff;
			Ponto temp;
			Linha ltemp;
			for (int i = 0; i < nedges; i++) {
				fscanf(rede, "%d %d", &startp, &endp);
				dist = coords[startp].ObterDistancia(coords[endp]);
				buff = Edge(startp, endp, dist);
				grafo.InsertEdge(buff);
				ltemp = Linha(coords[startp], coords[endp]);
				ltemp.desenhar(janelaId, DEFAULT);
				//printf("Inserido %d -- %d dist=%f\n", startp, endp, dist);
			}

			int locselect = 0;
			int firstvert = 0;
			int vert=-5;
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);

				
				if(janela.Click()) {
					Ponto cursor;
					cursor = janela.ObterPonto();
					
					bool select=FALSE;
					for (int i = 0; i < npontos; i++) {
						if (local[i].contem(cursor)) {
							select = TRUE;			
							locselect++;
							printf("\rSelecionados %d pontos",locselect);
							local[i].desenhar(janelaId, SELECTED);
							
							if (locselect == 2) {
								vert = i;
								while (vert != firstvert) {
									Linha(coords[vert], coords[grafo.PrevVert(vert)]).desenhar(janelaId, SELECTED);
									vert = grafo.PrevVert(vert);
									printf("\nVertice anterior: %d", vert);
									local[vert].desenhar(janelaId,SELECTED);
									
								}
								printf("\nDistancia de %d a %d:%.2f"
									,firstvert,vert,coords[vert].ObterDistancia(coords[firstvert]));
							}
							grafo.Dijkstra(i);
							firstvert = i;
							
						}
					}
					
					if (select == FALSE) {//des selecionar se clicar fora de qq circulo
						locselect = 0;
						firstvert = 0;
						vert = 0;
						for (int i = 0; i < npontos; i++)
							local[i].desenhar(janelaId, DEFAULT);
						}
					
				

					
				}

			}
		}
	}
}