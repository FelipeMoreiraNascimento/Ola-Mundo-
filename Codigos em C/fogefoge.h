void liberamapa();
void lemapa();
void alocamapa();
int acabou();
void imprimemapa();
void move(char direcao);

struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;
