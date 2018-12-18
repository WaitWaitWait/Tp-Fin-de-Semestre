int IaMin(int) 
{
	
	if (ProfTab == 0 || fin du jeu)
	{
		eval(etat_du_jeu) //eval est la fonction qui compare le min max et fait son choix
	}

	int ValMin = 1000000; //IaMin et IaMax deux nombre tres eloigné pourfaciliter la comparaison eval

	for (tous les coups possibles)
	{
		simuler(coup_actuel);

		int val  = IaMax(etat_du_jeu, profondeur - 1); //on regarde ce qui est le plus grand la profondeur on l et

		if (val  < ValMin )
		{
			ValMin = val;
		}

		AnnulerCoup(coup_actuel);
	}

	return ValMin;
}


int IaMax(int) 
{
	if (ProfTab == 0 || fin du jeu)
	{
		eval(etat_du_jeu) //eval est la fonction qui compare le min max et fait son choix
	}

	int ValMax = -1000000; //IaMin et IaMax deux nombre tres eloigné pour faciliter la comparaison eval

	for (tous les coups possibles)
	{
		simuler(coup_actuel);

			int val  = Min(etat_du_jeu, profondeur - 1); //on regarde ce qui est le plus grand la profondeur on l et

		if (val  > ValMax)
		{
			ValMax = val;
		}

		AnnulerCoup(coup_actuel);
	}
	return ValMax;
}

void IaQuiJoue()
{
	int ValMax = -1000000;
	
	for (tous les coups possibles)
	{
		simuler(coup_actuel);

		val  = IaMin(etat_du_jeu, profondeur);

		if (val  > ValMax)
		{
			max_val  = val;
			meilleur_coup  = coup_actuel;
		}

		if (val > ValMax)
		{
			annuler_coup(coup_actuel);

		}
	}
	jouer(meilleur_coup)
}