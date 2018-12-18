typedef struct node {
	//char * type;
	char * label;
	struct node * prev;
	size_t nb_elem;
	struct node * filsNodes[nb_elem];
	int x, y; //coordonnées pour l'affichage
	int bool;
} node;

typedef struct {
	node * root;
} arbre;

void Init(arbre *l) {
	l->root = NULL;
}

void addBranch(arbre *l, char * nlabel, struct node * chicos,
	int bool, size_t nbelem, int number) {
	node *nouv = malloc(sizeof(node));
	if (!nouv)
		exit(EXIT_FAILURE);
	//Les Values
	nouv->label = nlabel;
	//Le Pere est la partie qui semble douteuse
	if (l->root == NULL) {
		nouv->prev = l->root;
	}
	else {
		nouv->prev = nouv->filsNodes[number];
	}
	//Les Enfants
	if (bool == 0) {
		//Cas Enum Value
		nouv->filsNodes = NULL;
	}
	else {
		//Cas Structure Message
		nouv->filsNodes = *chicos[nbelem];
	}
}