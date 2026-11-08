# Guide C++ optionnel — stratégie d'implémentation

**Ce document sert de boîte à outils pour les projets en C++**. Il n'impose aucune bibliothèque ni aucun changement architectural. Inspecter d'abord la cible, le framework déjà présent et le moteur de composition. N'utiliser que les pistes compatibles avec le dépôt.

## 1. Identifier l'environnement réel

- UI native macOS (AppKit/Objective-C++), Windows (Win32/DirectComposition/WinUI), Linux (Qt/GTK/autre) ?
- Qt Widgets/Qt Quick, SDL, GLFW, SFML, JUCE, wxWidgets, Dear ImGui, Skia, OpenGL, Vulkan, Metal, Direct3D ou moteur maison ?
- Fenêtre native et effets de système disponibles, ou rendu entièrement personnalisé ?
- Comment sont rendus le texte, l'image de fond, le compositing, les masques, les animations, et comment se fait le hit-testing ?
- Les API et accélérations existent-elles sur **la version exacte** de plateforme ciblée ? Quels réglages système d'accessibilité sont exposés ?

## 2. Arbre de décision, sans solution universelle

1. **Composant/verre natif pertinent disponible ?** Préférer l'effet natif lorsqu'il prend en charge le contexte, l'adaptation et l'accessibilité. Sur les plateformes Apple récentes, examiner les API officiellement documentées et leurs conditions de disponibilité ; sur Windows, examiner les matériaux système pertinents (par ex. Mica/Acrylic) sans prétendre qu'ils sont du Liquid Glass Apple.
2. **Qt Quick / moteur de scène ?** Chercher les mécanismes de capture de contenu arrière, échantillonnage et composition, shader/effect et animation déjà intégrés ; mesurer les coûts avant de choisir une passe supplémentaire.
3. **Qt Widgets / raster traditionnel ?** Évaluer les surfaces natives et capacités existantes ; éviter les captures synchrones répétées d'écran qui pénalisent le défilement.
4. **Rendu GPU custom (OpenGL/Vulkan/Metal/Direct3D) ?** Considérer une chaîne conditionnelle : échantillonnage du contenu **réellement visible derrière la surface**, traitement multi-échelle ou flou contrôlé, modulation locale de clarté/teinte, micro-déviation des bords (lensing), reflets/bordures, ombre, et premier plan indépendant. Chaque passe est optionnelle si elle est inutile ou trop coûteuse.
5. **UI immédiate (Dear ImGui, etc.) ?** Vérifier si le pipeline de rendu, le z-order et le backend autorisent réellement l'échantillonnage de la scène sous la commande ; ne pas appliquer une recette de shader arbitraire.
6. **Pas d'accès fiable au fond ?** Utiliser un mode de substitution translucide prudent, ou un panneau opaque lisible ; **ne pas prétendre à l'adaptation parfaite**.

## 3. Mécanismes possibles à évaluer

- **Échantillonnage local** : analyser luminosité et contraste dans la zone pertinente derrière le composant, pas seulement le thème global de l'application.
- **Contraste du premier plan** : choisir la polarité et le niveau de protection du texte selon le **rendu final**, en tenant compte de la composition.
- **Hystérésis temporelle** : éviter le basculement blanc/noir en oscillation lorsque l'arrière-plan bouge près d'un seuil.
- **Masques et rayons** : préserver bord arrondi net et sans halo, même en haut DPI.
- **Flou** : filtrage adapté à l'échelle et au budget graphique, sans bloquer la boucle UI.
- **Lensing / réfraction de bord** : une déviation optique faible et contenue ; éviter de déformer les lettres.
- **Fresnel / reflets simulés** : uniquement si l'éclairage et le rendu restent subtils et cohérents.
- **Ombres adaptatives** : renforcer l'effet sur fond complexe, alléger sur fond plat.
- **Animation** : transitions d'état continues, basées sur le temps, sans dépendance arbitraire au nombre d'images.
- **Fallbacks** : contraste élevé, réduction de mouvement/transparence, absence de GPU/effets, plateforme non prise en charge.

Ce sont des **pistes**, pas des instructions de code obligatoires. Le rendu et les tests priment sur le choix des techniques.

## 4. Pistes de bibliothèques et documentation

À explorer **seulement si le projet les utilise ou si une migration est explicitement autorisée** :

| Écosystème | Capacités potentielles | Référence |
|---|---|---|
| Qt / Qt Quick | Graphe de scène, shaders, effets visuels, animations | https://doc.qt.io/ |
| JUCE | Dessin de composants, animations et rendering selon l'hôte | https://juce.com/learn/documentation |
| Skia | Composition 2D, filtres d'image, masques | https://skia.org/docs/ |
| SDL | Fenêtres, événements, backends de rendu et textures | https://wiki.libsdl.org/ |
| Vulkan | Contrôle explicite des pipelines et ressources GPU | https://docs.vulkan.org/ |
| OpenGL | Shaders et framebuffer si moteur existant | https://www.khronos.org/opengl/ |
| Metal | Graphismes GPU sur plateformes Apple | https://developer.apple.com/metal/ |
| DirectComposition | Composition de surfaces Windows | https://learn.microsoft.com/windows/win32/directcomp/directcomposition-portal |
| Dear ImGui | UI immédiate, à intégrer au pipeline de l'application | https://github.com/ocornut/imgui |

**Important** : Une bibliothèque ne garantit jamais le même rendu visuel ni les capacités adaptatives du moteur privé d'Apple. Ne pas recommander la réécriture d'une application pour un simple effet.
