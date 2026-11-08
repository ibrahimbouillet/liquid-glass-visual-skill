# Matrice d'acceptation visuelle

Une IA ne doit pas se contenter d'affirmer que le code semble correct : **tester le rendu effectif** sur les plateformes pertinentes.

| ID | Scène ou interaction | Attendu |
|---|---|---|
| V01 | Fond blanc / très clair | Verre discernable, texte contrasté, contours légers |
| V02 | Fond noir / très sombre | Icônes et texte clairement lisibles, sans halo envahissant |
| V03 | Photo à zones noires et blanches sous une même commande | Adaptation locale du verre et de la lecture sans disparition du premier plan |
| V04 | Photo détaillée, visages/texture, dégradé multicolore | Sens du contenu sous-jacent préservé, textes du contrôle non parasités |
| V05 | Défilement de textes sous une barre flottante | Séparation lisible, aucune collision perceptuelle ou scintillement |
| V06 | Fond animé / vidéo ou changements rapides | Pas d'oscillation gênante clair/sombre, composition stable |
| V07 | Clic/pression/focus/survol/relâchement | Réponse immédiate, continue et réversible, état actif identifiable |
| V08 | Ouverture d'un menu depuis son contrôle | Relation spatiale compréhensible, profondeur ajustée au panneau |
| V09 | Redimensionnement, changement DPI / densité, zoom | Géométrie, arrondis, bordures et zone de clic cohérents |
| V10 | Navigation clavier / technologies d'assistance applicables | Focus perceptible, noms fonctionnels, utilisabilité inchangée |
| V11 | Préférence mouvement réduit | Mouvement supprimé ou fortement simplifié |
| V12 | Préférence transparence réduite / contraste élevé | Substitution lisible sans dépendance au verre |
| V13 | Forte charge graphique + mouvement + défilement | Pas d'artefacts persistants, d'immobilisation ou de retard gênant |
| V14 | Plusieurs contrôles contigus | Pas de verre sur verre inutile ni d'empilement visuel |
| V15 | Basculer entre thèmes / apparences de l'application | Aucune altération des thèmes non concernés |

## Rapport demandé à l'agent

Pour chaque scène pertinente :
- plateforme, version, moteur UI et résolution/densité réellement testés ;
- capture ou enregistrement **du rendu réel** ;
- statut `PASS`, `FAIL`, `NOT_TESTED` ou `N/A` ;
- observations concrètes, causes et corrections éventuelles ;
- mesure ou observation de fluidité selon les moyens disponibles ;
- si la capture n'est pas possible, l'indiquer honnêtement.

## Refus de certification

Ne déclarer aucune équivalence « identique à Apple » basée uniquement sur une capture statique ; pas d'annonce de conformité accessibilité sans vérification concrète ; ne pas masquer les cas d'échec ou les plateformes non testées.
