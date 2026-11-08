---
name: liquid-glass-visual-skill
description: Évalue et applique une direction visuelle Liquid Glass inspirée des principes Apple à une interface existante. À utiliser pour refonte, audit UX/UI, lisibilité adaptative, animation et fluidité.
---

# Liquid Glass — standard visuel et comportemental

## Mission

Produire **un rendu observable et testable**, inspiré des principes du Liquid Glass présentés par Apple à la WWDC25 : matériau translucide et réactif, profondeur, reflets subtils, contraste adaptatif, hiérarchie nette et mouvements fluides. Ce skill n'est **ni un composant prêt à l'emploi, ni une implémentation officielle Apple, ni une prescription technique**.

**Ne jamais déduire ou imposer le framework, le moteur de rendu, les variables, l'architecture, les noms de fichiers, les dépendances, les shaders, les bibliothèques, les styles ou les choix d'implémentation du projet.** Examiner le projet réel et retenir les moyens compatibles avec lui. Ne pas copier d'assets ou de code propriétaire Apple.

## Priorités non négociables, par ordre

1. **Lisibilité et accessibilité** : le texte, les pictogrammes et les contrôles restent compréhensibles dans toutes les conditions testées. Ne jamais sacrifier ce point à la transparence.
2. **Conservation fonctionnelle** : ne pas changer la logique métier, les interactions existantes, le contenu, ni les autres thèmes si ce n'est pas explicitement demandé.
3. **Adaptation locale du matériau** : le verre répond aux tons et détails visibles derrière et autour de lui ; il ne se contente pas d'une couleur globale définie pour toute la page.
4. **Hiérarchie et sobriété** : le verre est principalement réservé aux surfaces de navigation et d'action, au-dessus du contenu. Interdire la multiplication de plaques ou de « verre sur verre ».
5. **Présence optique crédible** : transparence contrôlée, diffraction/réfraction perçue aux bords, contours lumineux fins, ombres contextuelles douces, profondeur discrète ; jamais une simple plaque blanche semi-opaque avec un flou uniforme.
6. **Mouvement naturel et performant** : réactions immédiates, transformations continues, retour au repos apaisé ; pas de latence perceptible, de scintillement, de clignotement de thème ou de saccades pendant les actions normales.
7. **Respect des préférences d'accessibilité** : modes mouvement réduit, transparence réduite et contraste renforcé quand ils sont disponibles ; maintenir une solution lisible lorsque les effets avancés ne le sont pas.

## Directives d'apparence obligatoires

- **Variante courante : Regular** : effet translucide adaptatif et lisible, à privilégier sur les surfaces de navigation/commandes.
- **Variante exceptionnelle : Clear** : plus transparente et moins adaptative. La réserver à un contexte riche en images où un assombrissement compatible avec le contenu rend la lecture possible. Ne pas mélanger arbitrairement Regular et Clear dans une même famille de composants.
- **Petites surfaces** : contrôle et symboles peuvent passer naturellement du clair au foncé, ou inversement, selon le fond **réellement perçu à travers le matériau**. Éviter les basculements intempestifs.
- **Grandes surfaces** : stabiliser leur apparence globale ; adapter tonalité, densité et contraste sans alternance clair/sombre perturbante.
- **Contours et lumière** : reflets légers situés sur les courbures, bordure fine contextualisée, ombre plus perceptible sur fond chargé ; jamais de lueur néon permanente ou d'halo opaque.
- **Formes** : silhouettes arrondies cohérentes et relation claire entre contrôles, menus, barres et fenêtres ; ne pas rendre tous les éléments identiques.
- **Défilement** : le contenu passant sous les éléments flottants reste reconnaissable, mais ne parasite jamais leurs intitulés ; la séparation entre contenu et commandes est perceptible.
- **Interactions** : pression, survol, focus, sélection et ouverture de menu produisent une réponse réversible et continue ; une commande qui ouvre un panneau conserve une relation spatiale compréhensible.
- **Couleurs d'accent** : réservées aux actions primaires et aux états sémantiquement utiles. Les arrière-plans et le contenu gardent la priorité visuelle.

## Méthode d'application sans hypothèses techniques

1. Observer la structure réelle du projet, identifier la version/thème visé(e), les plateformes et les interactions existantes. En cas de conflit, suivre l'intention du projet et demander uniquement les informations réellement bloquantes.
2. Repérer les éléments candidats au verre : navigation, commandes, menus, panneaux flottants. Justifier explicitement les éléments **laissés sans verre**.
3. Appliquer les critères observables de `references/CHARTE_VISUELLE.md`, sans prescrire de technologie.
4. Vérifier les scènes et conditions de `references/VALIDATION_VISUELLE.md` avec captures ou observations du rendu réel, **pas seulement du code ni un mockup**.
5. Corriger les cas qui échouent, puis présenter un compte rendu clair : éléments modifiés, scènes testées, écarts restants et éventuelles limites plateforme/performance.

## Contrat d'acceptation

Considérer la tâche **inachevée** si un texte devient illisible, si des surfaces vitrées se superposent sans raison, si l'interface scintille/chute visiblement de fluidité, si les réglages d'accessibilité sont ignorés, ou si la fonctionnalité existante est altérée. Les repères WCAG 2.2 AA applicables sont détaillés dans la charte ; **ils ne constituent pas des valeurs optiques annoncées par Apple**.

**Preuves attendues** : comparaison avant/après, captures claires et sombres, fond image très contrasté, texte défilant sous un contrôle, démonstration du changement de thème et de l'interaction, contrôle des préférences d'accessibilité, constat de performance. Distinguer « vérifié », « non vérifié » et « non applicable » ; ne jamais annoncer une équivalence à l'implémentation propriétaire d'Apple.

## Fichiers de référence

- `references/CHARTE_VISUELLE.md` : critères précis d'apparence et de comportement.
- `references/VALIDATION_VISUELLE.md` : protocole d'acceptation.
- `references/CPP_GUIDE.md` : boîte à outils optionnelle pour C++ (Qt, JUCE, GPU natif, etc.), sans imposer de framework.
- `references/SOURCES.md` : sources publiques officielles et distinctions entre recommandations Apple et exigences du skill.