# Charte visuelle universelle — Liquid Glass

Ce document décrit **ce que l'utilisateur doit percevoir**, pas une architecture. Les repères chiffrés d'accessibilité ci-dessous viennent de WCAG et sont des cibles de validation du skill, **pas des paramètres optiques d'Apple**.

## A. Verre crédible

- Une surface vitrée semble appartenir à un plan **au-dessus du contenu** ; le contenu sous-jacent reste perceptible sans concurrencer le premier plan.
- La matière donne une impression de *lensing* ou de légère déviation optique aux bords, et pas seulement une couche dépolie.
- Des reflets discrets suivent la forme et varient avec l'interaction ou le contexte ; aucun contour lumineux permanent trop fort.
- Les ombres définissent subtilement la séparation et deviennent plus affirmées derrière les détails/textes complexes, moins fortes sur les fonds calmes.
- La forme est arrondie, cohérente et proportionnée au type de commande ; les panneaux larges n'imitent pas forcément les boutons.

## B. Adaptation intelligente

- Prendre en compte **le contenu effectivement derrière le verre** : blanc, noir, gradient, texte, photographie, mouvement, transition de scène.
- La variante **Regular** adapte ombre, teinte, clarté et texte/symbole pour conserver la lecture.
- Sur de petites commandes, les glyphes et surfaces peuvent basculer clair/sombre selon leur contexte, **avec stabilité temporelle** pour éviter le clignotement au seuil.
- Les grandes surfaces ajustent leur contraste sans basculement intégral distrayant.
- Le texte n'est **pas obligatoirement noir sur fond blanc ou blanc sur fond noir** : choisir la combinaison qui conserve le meilleur contraste et la cohérence visuelle au point de lecture.
- L'effet de séparation pendant le défilement empêche les textes sous-jacents de concurrencer les commandes flottantes.

## C. Variantes, hiérarchie

- **Regular** est la variante principale : translucide, adaptative, accessible, sur commandes flottantes, barres d'outils, menus.
- **Clear** est beaucoup plus transparente et non adaptative de la même façon ; ne l'autoriser que sur fond média riche, avec assombrissement non nuisible du média et premier plan lumineux/gras lisible.
- Ne pas mélanger Regular et Clear arbitrairement dans une même expérience.
- Ne pas appliquer le matériau aux zones de contenu essentielles (paragraphes, grandes tables) lorsqu'il affaiblit leur hiérarchie.
- **Pas de verre sur verre** : des éléments au premier plan peuvent utiliser une simple surcouche colorée/contrastée sans seconde simulation de verre.
- Réserver les accents colorés aux actions importantes ou aux états sémantiques.

## D. Mouvement

- Le début de la réaction au pointeur, à la pression ou au focus paraît immédiat.
- Les animations d'ouverture, fermeture, fusion, morphing et déplacement préservent une continuité spatiale : l'élément semble se déformer, pas se téléporter.
- Les états de repos restent stables et visuellement discrets.
- L'éclairage des contours et la profondeur peuvent varier temporairement avec la pression et la position.
- Éviter les rebonds excessifs, la déformation de texte, les mouvements incessants et les effets qui détournent l'attention du contenu.
- Respecter la préférence « réduire les animations » ; privilégier transition simple ou changement d'état immédiat.

## E. Lisibilité et accessibilité

- Vérifier contrastes **sur le rendu réellement composé** avec des fonds représentatifs, **pas** seulement sur la couleur CSS/objet nominale.
- Cibles WCAG 2.2 AA quand applicables : texte normal ≥ **4,5:1**, grand texte ≥ **3:1**, composants graphiques significatifs et repères de contrôle ≥ **3:1**. Les exigences exactes varient selon la catégorie et les exceptions WCAG.
- Prévoir une alternative à plus forte opacité ou opaque lorsque réduction de transparence/contraste élevé est demandé.
- Conserver des états focus visibles, des tailles de cible adaptées, des icônes et textes compréhensibles même sans effet optique.
- Si un effet ne fonctionne pas sur la plateforme, privilégier la **lisibilité fonctionnelle** plutôt qu'une imitation incorrecte.

## F. Performance

- Vérifier mouvement + défilement + vidéo/fond animé + redimensionnement ; rechercher latence d'entrée, scintillements, artefacts de bord et chutes de fluidité.
- S'aligner sur la cadence et les contraintes de la plateforme réelle ; **ne pas prétendre qu'un FPS fixe garantit la qualité Apple**.
- Éviter tout recalcul visuellement instable du contraste ou tout saut brusque de matériau.
- Mesurer et documenter les compromis ; dégrader avec élégance les effets coûteux si nécessaire.

## Critère de réussite

Une personne doit pouvoir lire, comprendre et utiliser l'interface sur des arrière-plans difficiles, tout en percevant une matière légère, lumineuse, réactive et naturelle. Une simple opacité + flou, sans adaptation ni état dynamique, ne satisfait pas le skill.
