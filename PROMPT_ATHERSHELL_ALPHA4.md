# Prompt à fournir à Claude — AtherShell Alpha 4

> À utiliser après avoir installé le skill `liquid-glass-visual-skill`, ou en fournissant son `SKILL.md` et ses trois références à Claude.

Je développe **AtherShell** et je prépare sa version **Alpha 4**. L'interface proposera au moins un style **Grain** et un style **Liquid**. Je te demande d'améliorer **uniquement la direction visuelle et les comportements observables du style Liquid**, en appliquant intégralement le skill `liquid-glass-visual-skill` que je te fournis.

**Mission :** obtenir un Liquid Glass remarquablement crédible, sobre, adaptatif et fluide, inspiré des principes décrits publiquement par Apple à la WWDC25 : matériau translucide avec profondeur, contours lumineux subtils, reflets et légère réfraction perceptuelle, contraste intelligent sur fonds clairs/sombres/chargés, typographie toujours lisible, transformations naturelles et excellentes performances. Il ne s'agit pas de reproduire le code propriétaire Apple.

**Contraintes fondamentales :**

- Commence par **examiner réellement le dépôt AtherShell** et son fonctionnement. N'invente aucune variable, bibliothèque, architecture, technologie ou nom de fichier. Adapte la réalisation à l'existant.
- Préserve entièrement les fonctionnalités et, sauf demande contraire, **ne modifie pas l'apparence du style Grain**. Ne confonds pas les deux styles.
- Applique les critères de `SKILL.md` puis lis `references/CHARTE_VISUELLE.md`, `references/VALIDATION_VISUELLE.md` et `references/SOURCES.md`.
- Privilégie une variante **Regular** adaptative. N'utilise un rendu **Clear** très transparent que lorsque ses conditions de lisibilité sont réunies ; interdis le « verre sur verre » et l'utilisation massive du verre dans le contenu principal.
- Je veux une **adaptation locale et cohérente au contraste réel** : texte ou symboles sombres sur fonds effectivement clairs, clairs sur fonds effectivement sombres, mais surtout lisibilité maintenue sur fonds mixtes, photos et contenus défilants. Ne te contente jamais d'un basculement global selon le thème.
- Les contrôles doivent réagir instantanément au survol, au clic et au focus, se transformer et revenir au repos avec une fluidité naturelle, sans sauts, flashs, scintillement ou perte visible de performances.
- Prends en charge les préférences de transparence réduite, contraste augmenté et mouvement réduit dans la mesure où les plateformes de l'application les exposent ; assure un rendu de secours lisible.
- Ne présente **pas un simple mockup** comme résultat final : réalise et vérifie le thème dans l'application réelle, dans la limite des outils et accès dont tu disposes.

**Livrable obligatoire :** montre ce que tu as effectivement modifié ; explique brièvement les choix visuels ; présente des captures ou démonstrations du rendu réel avant/après et des fonds clair, sombre, mixte et en défilement ; exécute le protocole de validation du skill et indique pour chaque scénario **Réussi / Échec / Non testé / Non applicable** ; indique sans les inventer les observations sur la fluidité et les limites restantes. Ne déclare pas le résultat terminé tant que des critères bloquants applicables échouent.

L'objectif n'est pas « une interface avec beaucoup de blur ». Je veux **l'impression de matière vivante et intelligente**, tout en conservant une interface réellement professionnelle, rapide et lisible.